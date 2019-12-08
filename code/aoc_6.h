#ifndef AOC2019_6_
#define AOC2019_6_

#include "./utils.h"
#include <algorithm>
#include <map>

namespace aoc_6 {
    void get_input(std::multimap<std::string, std::string> & data, strvec_t const & input) {
        for (auto const & row: input) {
            strvec_t splited;
            split_string_by_delimiter(row, splited, ")");
            data.emplace(splited.at(0), splited.at(1));
        }
    }
    int64_t run_1(strvec_t const & input) {
        std::multimap<std::string, std::string> data;
        get_input(data, input);
        print_multimap(data);

        return 0;
    }

    int64_t run_2(strvec_t const & input) {
        return 0;
    }

} // aoc_6

#endif
