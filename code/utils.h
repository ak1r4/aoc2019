#ifndef AOC2019_UTILS_
#define AOC2019_UTILS_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using strvec_t = std::vector<std::string>;


strvec_t file_to_vec(const std::string& filename) {
    std::ifstream ifs(filename);
    strvec_t lines;

    if (!ifs) {
        std::cerr << "Cannot open file: " << filename << "\n";
    }
    for (std::string line; std::getline(ifs, line); ) {
        lines.push_back(line);
    }

    return lines;
}


void print_vec(strvec_t const vec) {
    for (auto const s: vec) {
        std::cout << s << "\n";
    }
}

#endif
