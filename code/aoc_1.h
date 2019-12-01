#ifndef AOC2019_1_
#define AOC2019_1_

#include "./utils.h"
#include <cstdint>


namespace aoc_1 {
    int64_t calc_fuel(int64_t const mass) {
        return mass / 3 - 2;
    }

    int64_t calc_fuel_fuel(int64_t const mass) {
        int64_t fuel_all = 0;

        for (int64_t left_mass = mass;
             ((left_mass = left_mass / 3 - 2) > 0);
             fuel_all += left_mass);

        return fuel_all;
    }

    int64_t run_1(strvec_t const & input) {
        int64_t sum = 0;

        for (auto const mass: input) {
            sum += calc_fuel(std::stoi(mass));
        }
        return sum;
    }

    int64_t run_2(strvec_t const & input) {
        int64_t sum = 0;

        for (auto const mass: input) {
            sum += calc_fuel_fuel(std::stoi(mass));
        }
        return sum;
    }
} // namespace aoc_1
#endif
