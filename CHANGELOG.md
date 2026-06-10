# Changelog

## v0.1.0 - release candidate

### Added
- C++17 DSP library with an installable public API under `dsp_core/dsp.hpp`.
- FIR low-pass design, direct convolution, and FFT overlap-save convolution.
- Goertzel tone-power estimation, including batched frequency checks.
- GCC-PHAT integer-delay estimation baseline.
- Rational `L/M` resampler with anti-alias filtering.
- Deterministic unit tests and smoke-style demo executables.
- Benchmark executable and generated benchmark/report assets.
- Multi-platform CMake CI for Linux and Windows.
- Installed-package consumer smoke test through `find_package(cpp_dsp_showcase CONFIG REQUIRED)`.
- Documentation for verification, benchmarking, algorithm evidence and FPGA-oriented interpretation.

### Release readiness notes
- README build, test and install commands are documented.
- Generated benchmark artifacts are part of the reviewer path.
- The final release still requires publishing/tagging the archive as `v0.1.0`.

## Unreleased

### Next
- Add coverage reporting.
- Stabilize scalar versus AVX2 benchmark comparison.
- Add more package-consumer examples if downstream usage grows.
