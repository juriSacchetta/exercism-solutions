#pragma once

namespace triangle {
    enum class flavor {
    equilateral,
    isosceles,
    scalene
    };

    flavor kind(double i, double j, double k);

}  // namespace triangle
