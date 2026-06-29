#include <dsp_core/dsp.hpp>

#include <iostream>
#include <vector>

int main() {
    const std::vector<double> samples{0.0, 1.0, 0.0, -1.0, 0.0};
    const std::vector<double> taps{0.25, 0.5, 0.25};

    const auto filtered = dsp_core::convolve_same(samples, taps);

    std::cout << "filtered_samples=" << filtered.size() << '\n';
    if (!filtered.empty()) {
        std::cout << "first=" << filtered.front() << " last=" << filtered.back() << '\n';
    }

    return filtered.size() == samples.size() ? 0 : 1;
}
