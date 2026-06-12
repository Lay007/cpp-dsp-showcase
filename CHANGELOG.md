# Changelog

All notable changes to this project are documented here.

The project follows a lightweight release discipline: each release should summarize implemented DSP modules, verification coverage, benchmark evidence, and known limitations.

## v0.1.0 - release candidate

### Added

- C++17 DSP library with an installable public API under `dsp_core/dsp.hpp`.
- FIR low-pass design, direct convolution, and FFT overlap-save convolution.
- Goertzel tone-power estimation, including batched frequency checks.
- GCC-PHAT integer-delay estimation baseline.
- Rational `L/M` resampler with anti-alias filtering.
- Deterministic unit tests and smoke-style demo executables.
- Optional AVX2 acceleration for selected hot paths.
- Benchmark executable and generated benchmark/report assets.
- Multi-platform CMake CI for Linux and Windows.
- Installed-package consumer smoke test through `find_package(cpp_dsp_showcase CONFIG REQUIRED)`.
- Documentation for verification, benchmarking, algorithm evidence and FPGA-oriented interpretation.

### Verification

- Deterministic unit tests cover FIR, Goertzel, GCC-PHAT and rational resampling behavior.
- CI is expected to validate Linux and Windows builds.
- Benchmark reports are generated from repository tooling rather than written by hand.

### Known limitations

- The current library is a showcase and teaching-oriented engineering reference, not a complete DSP framework.
- AVX2 acceleration is optional and should be treated as an optimization layer, not a required API contract.
- FPGA mapping notes are architectural guidance; RTL implementations live outside this repository.

### Release readiness notes

- README build, test and install commands are documented.
- Generated benchmark artifacts are part of the reviewer path.
- The final release still requires publishing/tagging the archive as `v0.1.0`.

## Release checklist

Before tagging `v0.1.0`:

- [ ] Linux CI is green.
- [ ] Windows CI is green.
- [ ] README build commands are verified from a clean checkout.
- [ ] Benchmark report is regenerated.
- [ ] Release notes are reviewed.
- [ ] GitHub release is created with the generated benchmark artifact attached or linked.

## Unreleased

### Next

- Add coverage reporting.
- Stabilize scalar versus AVX2 benchmark comparison.
- Add more package-consumer examples if downstream usage grows.
