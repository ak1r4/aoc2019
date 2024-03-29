#ifndef AOC2019_UTILS_
#define AOC2019_UTILS_

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iostream>
#include <cstdint>

using strvec_t = std::vector<std::string>;
using vecint_t = std::vector<int64_t>;


strvec_t file_to_strvec(std::string const & filename) {
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

void split_string_by_comma(std::string const & str, strvec_t & strvec) {
    std::stringstream ss {str};

    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, ',');
        strvec.push_back(substr);
    }
}

void split_string_by_delimiter(std::string const & str, strvec_t & strvec, std::string const & delimiter) {
    size_t pos = 0;
    size_t delimiter_len = delimiter.size();
    size_t n;

    while((n = str.find(delimiter, pos)) != std::string::npos) {
        strvec.push_back(str.substr(pos, n - pos));
        pos = n + delimiter_len;
    }
    strvec.push_back(str.substr(pos));
}


void print_strvec(strvec_t const & vec, bool newline = true) {
    for (auto const s: vec) {
        std::cout << s;
        if (newline) {
            std::cout << "\n";
        } else {
            std::cout << " ";
        }
    }
}

void print_vecint(vecint_t const & vec) {
    for (auto const s: vec) {
        std::cout << s << ", ";
    }
    std::cout << "\n";
}

// TODO need to have some constraint on T
template<class T>
void print_map(T const & map) {
    for (auto const & element: map) {
        std::cout << element.first << " -> " << element.second << "\n";
    }
}

#endif
