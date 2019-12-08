#include "./utils.h"
#include "./aoc_1.h"
#include "./aoc_2.h"
#include "./aoc_3.h"
#include "./aoc_4.h"
#include "./aoc_6.h"
#include <iostream>
#include <string>

std::string const DATA_ROOT = "/home/ryutlis/workspace/sandbox/aoc2019/code/data";


int main() {
    strvec_t input_1 = file_to_strvec(DATA_ROOT + "/aoc_1");
    std::cout << "Day 1 - run 1: " << aoc_1::run_1(input_1) << "\n";
    std::cout << "Day 1 - run 2: " << aoc_1::run_2(input_1) << "\n";

    vecint_t input_2 = file_to_vecint(DATA_ROOT + "/aoc_2");

    std::cout << "Day 2 - run 1: " << aoc_2::run_1(input_2) << "\n";
    std::cout << "Day 2 - run 2: " << aoc_2::run_2(input_2) << "\n";

    strvec_t input_3 = file_to_strvec(DATA_ROOT + "/aoc_3");

    std::cout << "Day 3 - run 1: " << aoc_3::run_1(input_3) << "\n";
    std::cout << "Day 3 - run 2: " << aoc_3::run_2(input_3) << "\n";

    std::cout << "Day 4 - run 1: " << aoc_4::run_1(108457, 562041) << "\n";
    std::cout << "Day 4 - run 2: " << aoc_4::run_2(108457, 562041) << "\n";

    strvec_t input_6 = file_to_strvec(DATA_ROOT + "/aoc_6");
    std::cout << "Day 6 - run 1: " << aoc_6::run_1(input_6) << "\n";
    std::cout << "Day 6 - run 2: " << aoc_6::run_2(input_6) << "\n";

    return 0;
}
