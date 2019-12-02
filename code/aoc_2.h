#ifndef AOC2019_2_
#define AOC2019_2_

#include "./utils.h"
#include <cstdint>

namespace aoc_2 {
    int64_t run_1(vecint_t & input) {
        // start 1202 program
        input.at(1) = 12;
        input.at(2) = 2;

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

        //print_vecint(input);
        
        // return result at 0
        return input.at(0);
    }

    int64_t run_2(vecint_t & input) {
        return 0;
    }
} // namespace aoc_2

#endif
