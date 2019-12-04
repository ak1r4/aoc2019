#include "./utils.h"
#include "./aoc_1.h"
#include "./aoc_2.h"
#include "./aoc_3.h"
#include <iostream>
#include <string>

std::string const DATA_ROOT = "/home/ryutlis/workspace/sandbox/aoc2019/code/data";


int main() {
    strvec_t input_1 = file_to_strvec(DATA_ROOT + "/aoc_1");
    std::cout << "Day 1 - run 1:  " << aoc_1::run_1(input_1) << "\n";
    std::cout << "Day 1 - run 2:  " << aoc_1::run_2(input_1) << "\n";

    vecint_t input_2 = file_to_vecint(DATA_ROOT + "/aoc_2");
    //vecint_t input_2 = vecint_t {1,1,1,4,99,5,6,0,99};

    std::cout << "Day 2 - run 1: " << aoc_2::run_1(input_2) << "\n";
    std::cout << "Day 2 - run 2: " << aoc_2::run_2(input_2) << "\n";

    strvec_t input_3 = file_to_strvec(DATA_ROOT + "/aoc_3");

    std::cout << "Day 3 - run 1: " << aoc_3::run_1(input_3) << "\n";
    std::cout << "Day 3 - run 2: " << aoc_3::run_2(input_3) << "\n";
    return 0;
}
