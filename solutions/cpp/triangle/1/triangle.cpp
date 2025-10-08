#include "triangle.h"
#include <array>
#include <algorithm>
#include <stdexcept>

namespace triangle {
flavor kind(double a, double b, double c) {
    std::array<double, 3> s{a, b, c};
    if (std::any_of(s.begin(), s.end(), [](double v){ return v <= 0; })) {
        throw std::domain_error("Sides must be positive");
    }

    std::sort(s.begin(), s.end());

    if (s[0] + s[1] <= s[2]) {
        throw std::domain_error("Triangle inequality violated");
    }

    if (s[0] == s[2])                  return flavor::equilateral;
    if (s[0] == s[1] || s[1] == s[2])  return flavor::isosceles;
    return flavor::scalene;
}

} // namespace triangle
