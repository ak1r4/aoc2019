#ifndef AOC2019_2_
#define AOC2019_2_

#include "./utils.h"
#include <cstdint>

namespace aoc_2 {
    int64_t compute(vecint_t const & origin_input, int64_t noun, int64_t verb) {
        vecint_t input = origin_input;

        input.at(1) = noun;
        input.at(2) = verb;

        // start execution
        size_t pos = 0;

        while (pos < input.size()) {
            int64_t opcode = input.at(pos);

            if (opcode == 99) {
                break;
            }

            int64_t opand_1 = input.at(input.at(pos + 1));
            int64_t opand_2 = input.at(input.at(pos + 2));

            switch(opcode) {
                case 1 :
                    input.at(input.at(pos + 3)) = opand_1 + opand_2;
                    break;
                case 2 :
                    input.at(input.at(pos + 3)) = opand_1 * opand_2;
                    break;
                default:
                    std::cerr << "Invalid opcode: " << opcode << "\n";
            }

            pos += 4;
        }

        // return result at 0
        return input.at(0);
    }

    int64_t run_1(vecint_t & input) {
        return compute(input, 12, 2);
    }

    int64_t run_2(vecint_t & input) {
        for (int64_t noun = 0; noun < 100; noun++) {
            for (int64_t verb = 0; verb < 100; verb++) {
                if (compute(input, noun, verb) == 19690720) {
                    return noun * 100 + verb;
                }
            }
        }
        return -1;
    }
} // namespace aoc_2

#endif
