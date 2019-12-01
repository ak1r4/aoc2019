#include "./utils.h"
#include "./aoc_1.h"
#include <iostream>
#include <string>

std::string const DATA_ROOT = "/home/ryutlis/workspace/sandbox/aoc2019/code/data";


int main() {
    strvec_t input = file_to_vec(DATA_ROOT + "/aoc_1");
    std::cout << "Day 1 - run 1:  " << aoc_1::run_1(input) << "\n";
    std::cout << "Day 1 - run 2:  " << aoc_1::run_2(input) << "\n";

}
