#include <cmath>
#include <iostream>

#include <dsp_core/dsp.hpp>

int main() {
    const auto tone = dsp_core::dsp::generate_tone(128, 48000.0, 1000.0);
    const double level = dsp_core::dsp::rms(tone);

    if (!(level > 0.0)) {
        std::cerr << "Unexpected RMS level: " << level << '\n';
        return 1;
    }

    const auto taps = dsp_core::dsp::design_lowpass_fir(31, 0.1);
    if (taps.size() != 31) {
        std::cerr << "Unexpected FIR tap count: " << taps.size() << '\n';
        return 1;
    }

    std::cout << "install_consumer PASS: rms=" << level << ", taps=" << taps.size() << '\n';
    return 0;
}
