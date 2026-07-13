## Summary

Describe the DSP kernel, test, benchmark, packaging, or documentation change.

## Validation

- [ ] CMake configure and build succeed.
- [ ] `ctest --output-on-failure` passes.
- [ ] Baseline behavior works without AVX2-specific assumptions.
- [ ] Numerical tolerance, units, sample rate, and scaling are documented where relevant.
- [ ] New or changed public API remains covered by an install-consumer check.
- [ ] Benchmark changes identify hardware, build type, and measurement method.
- [ ] Generated reports and plots are reproducible from committed scripts.
- [ ] No generated build directories, large captures, or machine-specific paths are committed.

## Evidence

List commands, tests, benchmark results, plots, or reports used to verify the change.
