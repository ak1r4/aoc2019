#ifndef AOC2019_6_
#define AOC2019_6_

#include "./utils.h"
#include <algorithm>
#include <set>
#include <unordered_map>

namespace aoc_6 {
    using map_t = std::unordered_multimap<std::string, std::string>;
    using route_t = std::vector<std::string>;

    void get_input(map_t & data, strvec_t const & input, bool double_side = false) {
        for (auto const & row: input) {
            strvec_t splited;
            split_string_by_delimiter(row, splited, ")");
            data.emplace(splited.at(0), splited.at(1));
            if (double_side) {
                data.emplace(splited.at(1), splited.at(0));
            }
        }
    }

    void count_orbits(map_t const & map, std::string const & node, size_t & count) {
        auto range = map.equal_range(node);
        if ((range.first == map.end()) && (range.second == map.end())) {
            return;
        }

        for (auto it = range.first; it != range.second; it++) {
            count++;
            count_orbits(map, it->second, count);
        }
    }

    bool find_route(map_t const & map, route_t & route, std::string const & current, std::string const & target) {
        // when found the target
        if (current == target) {
            route.push_back(current);
            return true;
        }

        // when there is nothing down a level
        auto range = map.equal_range(current);
        if ((range.first == map.end()) && (range.second == map.end())) {
            return false;
        }

        // if there are more levels, let's explore
        for (auto it = range.first; it != range.second; it++) {
            // if the child node is the same as the current's parent node
            // means we are going backwards
            // we skip this node
            if ((route.size() > 0) && (it->second == route.back())) {
                continue;
            }

            // otherwise, we push the current node down and explore its children
            route.push_back(current);
            if (find_route(map, route, it->second, target)) {
                return true;
            }
            // if cannot find route in its children, we remove it from the route
            route.pop_back();
        }

        return false;
    }

    int64_t run_1(strvec_t const & input) {
        map_t data;
        get_input(data, input);

        std::set<std::string> keys;
        for (auto const & kv: data) {
            keys.emplace(kv.first);
        }

        size_t count = 0;
        for (auto const k: keys) {
            count_orbits(data, k, count);
        }

        return count;
    }

    int64_t run_2(strvec_t const & input) {
        map_t data;
        get_input(data, input, true);

        route_t route;
        find_route(data, route, "YOU", "SAN");

        return route.size() - 3;
    }

} // aoc_6

#endif
