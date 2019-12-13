#ifndef AOC2019_8_
#define AOC2019_8_

#include <limits>
#include "./utils.h"

namespace aoc_8 {
    size_t const wide = 25;
    size_t const tall = 6;

    void get_input(strvec_t & data, std::string const & raw_string, size_t const wide, size_t const tall) {
        size_t layer_size = wide * tall;

        size_t pos = 0;
        while (pos < raw_string.size()) {
            data.push_back(raw_string.substr(pos, layer_size));
            pos += layer_size;
        }
    }

    size_t count_char(std::string const & str, char const & target) {
        size_t count = 0;
        for (auto const & c: str) {
            if (c == target) {
                count++;
            }
        }
        return count;
    }

    int64_t run_1(strvec_t const & input) {
        strvec_t data;
        get_input(data, input.at(0), wide, tall);

        size_t idx = 0;
        size_t min_idx = 0;
        size_t min_0_count = std::numeric_limits<size_t>::max();

        for (auto const & layer: data) {
            size_t count_0 = count_char(layer, '0');
            if (count_0 < min_0_count) {
                min_0_count = count_0;
                min_idx = idx;
            }
            idx++;
        }

        return count_char(data.at(min_idx), '1') * count_char(data.at(min_idx), '2');
    }

    int64_t run_2(strvec_t const & input) {
        strvec_t data;
        get_input(data, input.at(0), wide, tall);
        size_t layer_size = wide * tall;
        std::string final_layer;

        for (size_t idx_col = 0; idx_col < layer_size; idx_col++) {
            char c = '2';
            for (size_t idx_row = 0; idx_row < data.size(); idx_row++) {
                char cur = data.at(idx_row).at(idx_col);
                if (cur != '2') {
                    c = cur;
                    break;
                }
            }
            final_layer.push_back(c);
        }

        strvec_t final_layer_vec;
        get_input(final_layer_vec, final_layer, 5, 5);
        std::cout << "\n";
        print_strvec(final_layer_vec);
        return 0;
    }
}

#endif
