#include "dsp_core/dsp.hpp"

#include <gtest/gtest.h>
#include <limits>

TEST(DspApiValidation, GenerateToneRejectsOutOfRangeFrequency) {
    EXPECT_THROW(dsp_core::dsp::generate_tone(128, 48'000.0, 24'000.0), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::generate_tone(128, -1.0, 1'000.0), std::invalid_argument);
}

TEST(DspApiValidation, GoertzelBatchValidatesInput) {
    EXPECT_THROW(dsp_core::dsp::goertzel_power_batch({}, 48'000.0, {1'000.0}), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::goertzel_power_batch({1.0, 2.0}, 48'000.0, {-10.0}), std::invalid_argument);
}

TEST(DspApiValidation, ResamplerValidatesTapCountAndCutoffScale) {
    const dsp_core::dsp::Signal input(64, 1.0);
    EXPECT_THROW(dsp_core::dsp::resample_rational(input, 2, 1, 32, 0.9), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::resample_rational(input, 2, 1, 63, 0.0), std::invalid_argument);
}

TEST(DspApiValidation, RejectsNonFiniteNumericParameters) {
    const double nan = std::numeric_limits<double>::quiet_NaN();
    const double infinity = std::numeric_limits<double>::infinity();
    const dsp_core::dsp::Signal signal(64, 1.0);

    EXPECT_THROW(dsp_core::dsp::generate_tone(64, nan, 1'000.0), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::generate_tone(64, infinity, 1'000.0), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::generate_tone(64, 48'000.0, nan), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::goertzel_power(signal, 48'000.0, nan), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::goertzel_power_batch(signal, infinity, {}), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::design_lowpass_fir(31, nan), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::frequency_response_magnitude({1.0}, nan), std::invalid_argument);
    EXPECT_THROW(dsp_core::dsp::resample_rational(signal, 2, 1, 31, nan), std::invalid_argument);
}
