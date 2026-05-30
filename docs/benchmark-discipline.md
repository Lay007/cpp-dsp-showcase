# Benchmark discipline

This repository is most valuable when performance claims are reproducible and tied to real DSP workloads.

## Benchmark report must include

- algorithm name;
- input size or frame length;
- coefficient/filter length, when relevant;
- number of iterations or samples processed;
- mean or median runtime;
- throughput metric, when meaningful;
- build type and compiler;
- CPU and operating system for manually published results.

## Rules for performance changes

1. Do not compare debug builds against release builds.
2. Do not mix different input sizes in the same before/after claim.
3. Keep benchmark code separate from unit tests.
4. Include a correctness check for optimized implementations.
5. Explain whether the result is scalar, SIMD, FFT-based, or multi-threaded.

## Useful DSP benchmark scenarios

- FIR convolution: short, medium, and long filters.
- FFT convolution: block sizes around the expected crossover point.
- Goertzel detector: one tone, several tones, and noisy input.
- GCC-PHAT: clean delay, noisy delay, and ambiguous correlation peak.
- Rational resampler: small ratios and large interpolation/decimation factors.

## Reporting guidance

Prefer a small table with stable, machine-readable values over screenshots. Figures are useful when they are generated from the same benchmark data committed or published as an artifact.
