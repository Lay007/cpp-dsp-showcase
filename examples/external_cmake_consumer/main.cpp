#include <dsp_core/dsp.hpp>

#include <iostream>
#include <vector>

int main() {
    const dsp_core::dsp::Signal samples{0.0, 1.0, 0.0, -1.0, 0.0};
    const dsp_core::dsp::Signal taps{0.25, 0.5, 0.25};

    const auto filtered = dsp_core::dsp::convolve(samples, taps);

    std::cout << "filtered_samples=" << filtered.size() << '\n';
    if (!filtered.empty()) {
        std::cout << "first=" << filtered.front() << " last=" << filtered.back() << '\n';
    }

    return filtered.empty() ? 1 : 0;
}
