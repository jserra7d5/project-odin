#ifndef UTIL_H
#define UTIL_H

#include <cmath>

// Apply a variable deadband to the given input
// Parameters:
// - input: The input value in the range [-1.0, 1.0]
// - deadband: The deadband threshold in the range [0.0, 1.0]
// Returns:
// - The adjusted input value after applying the deadband
inline double ApplyDeadband(double input, double deadband) {
    if (std::abs(input) < deadband) {
        return 0.0; // Input is within the deadband, return zero
    }

    // Scale input outside the deadband to maintain linear response
    double sign = (input > 0) ? 1.0 : -1.0;
    return sign * (std::abs(input) - deadband) / (1.0 - deadband);
}

#endif // UTIL_H
