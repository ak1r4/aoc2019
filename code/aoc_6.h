#ifndef AOC2019_6_
#define AOC2019_6_

#include "./utils.h"
#include <algorithm>

namespace aoc_6 {
    void get_input(std::vector<strvec_t> & data, strvec_t const & input) {
        for (auto const & row: input) {
            strvec_t splited;
            split_string_by_delimiter(row, splited, ")");
            data.push_back(splited);
        }
    }
    int64_t run_1(strvec_t const & input) {
        std::vector<strvec_t> data;
        get_input(data, input);

        return 0;
    }

    int64_t run_2(strvec_t const & input) {
        return 0;
    }

} // aoc_6

#endif
