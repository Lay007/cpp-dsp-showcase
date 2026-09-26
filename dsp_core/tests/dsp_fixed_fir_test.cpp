#include "dsp_core/dsp.hpp"
#include "dsp_core/fixed_fir.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <gtest/gtest.h>

namespace {
std::vector<std::int16_t> load(const std::string& path) {
    std::ifstream stream(path);
    if (!stream) throw std::runtime_error("missing vector: " + path);
    std::string line;
    std::getline(stream, line);
    std::vector<std::int16_t> values;
    while (std::getline(stream, line)) values.push_back(static_cast<std::int16_t>(std::stoi(line)));
    return values;
}
}

TEST(DspFixedFir, SharedPythonVectorsMatchFixedAndFloatingConvolution) {
    for (const auto* name : {"impulse", "signed", "ties", "saturation", "negative_taps"}) {
        SCOPED_TRACE(name);
        const std::string base = std::string(DSP_FIR_VECTOR_DIR) + "/" + name;
        const auto input = load(base + "_input.csv");
        const auto taps = load(base + "_taps.csv");
        const auto fixed = dsp_core::dsp::convolve_q15(input, taps);
        dsp_core::dsp::Signal x, h;
        for (auto value : input) x.push_back(value / 32768.0);
        for (auto value : taps) h.push_back(value / 32768.0);
        const auto floating = dsp_core::dsp::convolve(x, h);
        std::ifstream expected(base + "_expected.csv");
        ASSERT_TRUE(expected.good());
        std::string line;
        std::getline(expected, line);
        std::size_t n = 0;
        while (std::getline(expected, line)) {
            ASSERT_LT(n, fixed.size());
            ASSERT_LT(n, floating.size());
            const auto comma = line.find(',');
            ASSERT_NE(comma, std::string::npos);
            EXPECT_EQ(fixed[n], std::stoi(line.substr(0, comma)));
            const auto reference = std::stod(line.substr(comma + 1));
            EXPECT_NEAR(floating[n], reference, 1e-12);
            if (reference >= -1.0 && reference <= 32767.0 / 32768.0) {
                EXPECT_LE(std::abs(reference - fixed[n] / 32768.0), 0.5 / 32768.0);
            }
            ++n;
        }
        EXPECT_EQ(n, fixed.size());
        EXPECT_EQ(n, floating.size());
    }
}

TEST(DspFixedFir, EmptyInputsAndAccumulatorBound) {
    EXPECT_TRUE(dsp_core::dsp::convolve_q15({}, {1}).empty());
    EXPECT_TRUE(dsp_core::dsp::convolve_q15({1}, {}).empty());
    EXPECT_THROW(dsp_core::dsp::convolve_q15({1}, std::vector<std::int16_t>(65537)), std::invalid_argument);
    EXPECT_EQ(dsp_core::dsp::convolve_q15({-32768}, {-32768})[0], 32767);
}
