#ifndef AOC2019_3_
#define AOC2019_3_

#include "./utils.h"
#include <cstdint>
#include <sstream>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <algorithm>


using coord_t = std::pair<int64_t, int64_t>;

struct coord_comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        return (abs(l.first) + abs(l.second)) < (abs(r.first) + abs(r.second));
    }
};

struct coord_hash
{
    inline std::size_t operator()(coord_t const & v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};

bool coord_sort_key(coord_t const  & a, coord_t const & b) {
    return (abs(a.first) + abs(a.second)) < (abs(b.first) + abs(b.second));
}

using coord_vec = std::vector<coord_t>;
using coord_set = std::set<coord_t, coord_comp>;
using coord_unordered_set = std::unordered_set<coord_t, coord_hash>;


namespace aoc_3 {
    template<class T>
    void print_coord_set(T const & coord_set) {
        for (auto const coord: coord_set) {
            std::cout << "(" << coord.first << "," << coord.second << "), ";
        }
        std::cout << "\n";
    }

    void steps_to_coords(coord_vec & coords, strvec_t const & steps, bool sort) {
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
        if (sort) {
            std::sort(coords.begin(), coords.end(), coord_sort_key);
        }
    }

    int64_t run_1(strvec_t const & input) {
        strvec_t wire_1;
        strvec_t wire_2;

        split_string_to_strvec(input[0], wire_1);
        split_string_to_strvec(input[1], wire_2);

        coord_vec distant_1;
        coord_vec distant_2;

        steps_to_coords(distant_1, wire_1, true);
        steps_to_coords(distant_2, wire_2, true);

        for (auto const coord: distant_1) {
            if (std::find_if(
                    distant_2.begin(),
                    distant_2.end(),
                    [coord](coord_t const & el){
                        return (coord.first == el.first) && (coord.second == el.second);
                    }) != distant_2.end()) {
                std::cout << "coord" << coord.first << ", " << coord.second << "\n";
                return abs(coord.first) + abs(coord.second); 
            }
        }

        return 0;
    }

    int64_t run_2(strvec_t const & input) {
        strvec_t wire_1;
        strvec_t wire_2;

        //std::string input_0 = "R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51";
        //std::string input_1 = "U98,R91,D20,R16,D67,R40,U7,R15,U6,R7";
        //split_string_to_strvec(input_0, wire_1);
        //split_string_to_strvec(input_1, wire_2);

        split_string_to_strvec(input[0], wire_1);
        split_string_to_strvec(input[1], wire_2);

        coord_vec distant_1;
        coord_vec distant_2;

        steps_to_coords(distant_1, wire_1, false);
        steps_to_coords(distant_2, wire_2, false);

        //print_coord_set(distant_1);
        //print_coord_set(distant_2);

        for (size_t i = 0; i < distant_1.size(); i++) {
            for (size_t j = 0; j < distant_2.size(); j++) {
                if ((distant_1.at(i).first == distant_2.at(j).first)
                        && (distant_1.at(i).second == distant_2.at(j).second)) {
                    std::cout << distant_1.at(i).first << ", " << distant_1.at(i).second << "\n";
                    std::cout << "i: " << i << "j: " << j << "\n";
                    return i + j + 2;
                }
                
            }
        }
        return 0;
    }
}
#endif
