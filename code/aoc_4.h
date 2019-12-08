#ifndef AOC2019_4_
#define AOC2019_4_

#include "./utils.h"
#include <cstdint>

namespace aoc_4 {
    bool check_number(std::string const & number, size_t expected_count) {
        char prev = '0';
        size_t count = 1;
        std::vector<size_t> counts;

        for (auto const & c: number) {
            if (c < prev) {
                return false;
            }

            if (c == prev) {
                ++count;
            } else {
                counts.push_back(count);
                count = 1;
            }
            prev = c;
        }
        counts.push_back(count);

        if (expected_count == 0) {
            return (*std::max_element(counts.begin(), counts.end())) >= 2;
        } else {
            return std::find(counts.begin(), counts.end(), expected_count) != counts.end();
        }
    }

    int64_t run_1(int64_t range_start, int64_t range_end) {
        size_t count = 0;
        for (int64_t n = range_start; n <= range_end; n++) {
            std::string str_n = std::to_string(n);
            if (check_number(str_n, 0)) {
                count++;
            }
        }
        return count;

    }
    int64_t run_2(int64_t range_start, int64_t range_end) {
        size_t count = 0;
        for (int64_t n = range_start; n <= range_end; n++) {
            std::string str_n = std::to_string(n);
            if (check_number(str_n, 2)) {
                count++;
            }
        }
        return count;
    }

} // namespace aoc_4

#endif
