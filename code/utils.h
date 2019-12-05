#ifndef AOC2019_UTILS_
#define AOC2019_UTILS_

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstdint>

using strvec_t = std::vector<std::string>;
using vecint_t = std::vector<int64_t>;


strvec_t file_to_strvec(const std::string& filename) {
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


vecint_t file_to_vecint(std::string const& filename) {
    std::ifstream ifs(filename);

    std::string s;
    vecint_t vec;

    if (!std::getline(ifs, s)) {
        std::cerr << "Cannot open file: " << filename << "\n";
    }

    std::istringstream ss {s};

    while (ss) {
        std::string s_;

        if (!std::getline(ss, s_, ',')) {
            break;
        }
        vec.push_back(std::stoi(s_));
    }

    return vec;
}

void split_string_to_strvec(std::string const & str, strvec_t & strvec) {
    std::stringstream ss {str};

    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, ',');
        strvec.push_back(substr);
    }
}


void print_strvec(strvec_t const vec) {
    for (auto const s: vec) {
        std::cout << s << "\n";
    }
}

void print_vecint(vecint_t const vec) {
    for (auto const s: vec) {
        std::cout << s << ", ";
    }
    std::cout << "\n";
}

#endif
