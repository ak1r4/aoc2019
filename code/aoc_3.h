#ifndef AOC2019_3_
#define AOC2019_3_

#include "./utils.h"
#include <algorithm>

using coord_t = std::pair<int64_t, int64_t>;
using coord_vec = std::vector<coord_t>;

bool coord_sort_key(coord_t const  & a, coord_t const & b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

namespace aoc_3 {
    template<class T>
    void print_coord_set(T const & coord_set) {
        for (auto const coord: coord_set) {
            std::cout << "(" << coord.first << "," << coord.second << "), ";
        }
        std::cout << "\n";
    }

    void steps_to_coords(coord_vec & coords, strvec_t const & steps) {
        int64_t x = 0;
        int64_t y = 0;

        for (auto const step: steps) {
            if (step.at(0) == 'U') {
                for (int64_t i = 0; i < std::stoi(step.substr(1)); i++) {
                    y++;
                    coords.emplace_back(x, y);
                }
            } else if (step.at(0) == 'R') {
                for (int64_t i = 0; i < std::stoi(step.substr(1)); i++) {
                    x++;
                    coords.emplace_back(x, y);
                }
            } else if (step.at(0) == 'D') {
                for (int64_t i = 0; i < std::stoi(step.substr(1)); i++) {
                    y--;
                    coords.emplace_back(x, y);
                }
            } else if (step.at(0) == 'L') {
                for (int64_t i = 0; i < std::stoi(step.substr(1)); i++) {
                    x--;
                    coords.emplace_back(x, y);
                }
            }
        }
    }

    void find_intersections(coord_vec & vec_intersect,
                            coord_vec const & coord_vec_1,
                            coord_vec const & coord_vec_2) {
        coord_vec coord_vec_1_copy = coord_vec_1;
        coord_vec coord_vec_2_copy = coord_vec_2;

        std::sort(coord_vec_1_copy.begin(), coord_vec_1_copy.end(), coord_sort_key);
        std::sort(coord_vec_2_copy.begin(), coord_vec_2_copy.end(), coord_sort_key);

        std::set_intersection(coord_vec_1_copy.begin(), coord_vec_1_copy.end(),
                              coord_vec_2_copy.begin(), coord_vec_2_copy.end(),
                              std::back_inserter(vec_intersect));
    }

    void input_to_coords_and_intersections(strvec_t const & input,
                                           coord_vec & coord_vec_1,
                                           coord_vec & coord_vec_2,
                                           coord_vec & intersections) {
        strvec_t wire_1;
        strvec_t wire_2;

        split_string_to_strvec(input[0], wire_1);
        split_string_to_strvec(input[1], wire_2);

        steps_to_coords(coord_vec_1, wire_1);
        steps_to_coords(coord_vec_2, wire_2);

        find_intersections(intersections, coord_vec_1, coord_vec_2);
    }

    int64_t run_1(strvec_t const & input) {
        coord_vec intersections;
        coord_vec distant_1;
        coord_vec distant_2;

        input_to_coords_and_intersections(input, distant_1, distant_2, intersections);

        std::vector<int64_t> distants;

        for (auto const coord: intersections) {
            distants.push_back(abs(coord.first) + abs(coord.second));
        }

        return *std::min_element(distants.begin(), distants.end());
    }

    int64_t run_2(strvec_t const & input) {
        coord_vec intersections;
        coord_vec distant_1;
        coord_vec distant_2;

        input_to_coords_and_intersections(input, distant_1, distant_2, intersections);

        std::vector<int64_t> distants;

        for (auto const coord: intersections) {
            int64_t dist_1 = std::distance(distant_1.begin(), std::find(distant_1.begin(), distant_1.end(), coord));
            int64_t dist_2 = std::distance(distant_2.begin(), std::find(distant_2.begin(), distant_2.end(), coord));
            distants.push_back(dist_1 + dist_2 + 2);
        }

        return *std::min_element(distants.begin(), distants.end());
    }
}
#endif
