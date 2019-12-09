#ifndef AOC2019_6_
#define AOC2019_6_

#include "./utils.h"
#include <algorithm>
#include <set>
#include <unordered_map>

namespace aoc_6 {
    using map_t = std::unordered_multimap<std::string, std::string>;

    void get_input(map_t & data, strvec_t const & input) {
        for (auto const & row: input) {
            strvec_t splited;
            split_string_by_delimiter(row, splited, ")");
            data.emplace(splited.at(0), splited.at(1));
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
        return 0;
    }

} // aoc_6

#endif
