#include "dsp_core/dsp.hpp"

#include <cstdint>
#include <cstddef>

#include <gtest/gtest.h>

namespace {

dsp_core::dsp::Signal make_wideband_signal(std::size_t size) {
    dsp_core::dsp::Signal out(size, 0.0);
    uint32_t state = 0x12345678U;
    for (std::size_t i = 0; i < size; ++i) {
        // A low bit of a linear congruential generator merely alternates 0/1.
        // Use a deterministic xorshift generator and its high bit instead.
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        out[i] = (state & 0x80000000U) ? 1.0 : -1.0;
    }
    return out;
}

}  // namespace

TEST(DspGccPhat, RecoversPositiveNegativeAndZeroDelay) {
    constexpr std::size_t kSamples = 512;
    const auto reference = make_wideband_signal(kSamples);

    // Guard against accidentally replacing wideband excitation with an
    // alternating two-sample pattern, which masks ambiguous correlation peaks.
    std::size_t transitions = 0;
    for (std::size_t i = 1; i < kSamples; ++i) {
        if (reference[i] != reference[i - 1]) {
            ++transitions;
        }
    }
    EXPECT_GT(transitions, 150U);
    EXPECT_LT(transitions, 350U);

    for (const int delay : {-17, 0, 11}) {
        SCOPED_TRACE(delay);
        dsp_core::dsp::Signal delayed(kSamples, 0.0);
        for (std::size_t i = 0; i < kSamples; ++i) {
            const int source = static_cast<int>(i) - delay;
            if (source >= 0 && source < static_cast<int>(kSamples)) {
                delayed[i] = reference[static_cast<std::size_t>(source)];
            }
        }

        const auto result = dsp_core::dsp::estimate_delay_gcc_phat(reference, delayed, 32);
        EXPECT_EQ(result.lag_samples, delay);
        EXPECT_GT(result.score, 0.8);
    }
}
