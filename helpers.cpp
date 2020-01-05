#include "helpers.hpp"

std::random_device rd;
std::mt19937 rng(rd());

double get_random() {
    return std::generate_canonical<double, 10>(rng);
}

