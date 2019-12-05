#ifndef AOC2019_4_
#define AOC2019_4_

#include "./utils.h"
#include <cstdint>

namespace aoc_4 {
    bool check_number(std::string const & number, size_t expected_count) {
        char prev = '0';
        size_t count = 1;
        size_t highest_count = 0;

        for (auto const & c: number) {
            if (c < prev) {
                return false;
            }

            if (c == prev) {
                ++count;
            } else {
                highest_count = std::max(count, highest_count);
                count = 1;
            }
            prev = c;
        }

        highest_count = std::max(count, highest_count);

        if (expected_count == 0) {
            return highest_count >= 2;
        } else {
            return highest_count == expected_count;
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
