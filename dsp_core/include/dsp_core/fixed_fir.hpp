#pragma once

#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace dsp_core::dsp {

// Full convolution, signed Q1.15 inputs/taps, zero initial state and zero tail.
// Accumulate exactly in int64, round once (nearest, ties away from zero),
// then saturate. The tap bound keeps even worst-case sums well inside int64.
inline std::vector<std::int16_t> convolve_q15(
    const std::vector<std::int16_t>& input,
    const std::vector<std::int16_t>& taps) {
    if (taps.size() > 65536) {
        throw std::invalid_argument("Q15 FIR supports at most 65536 taps");
    }
    if (input.empty() || taps.empty()) return {};
    std::vector<std::int16_t> output(input.size() + taps.size() - 1);
    for (std::size_t n = 0; n < output.size(); ++n) {
        std::int64_t sum = 0;
        const auto first = n >= input.size() ? n - input.size() + 1 : 0;
        const auto last = std::min(n + 1, taps.size());
        for (std::size_t k = first; k < last; ++k) {
            sum += static_cast<std::int64_t>(input[n - k]) * taps[k];
        }
        // Signed division is defined in C++17; no implementation-defined
        // right shift of a negative integer is used here.
        const auto rounded = sum < 0 ? -((-sum + 16384) / 32768) : (sum + 16384) / 32768;
        output[n] = static_cast<std::int16_t>(std::clamp<std::int64_t>(rounded, -32768, 32767));
    }
    return output;
}

}  // namespace dsp_core::dsp
