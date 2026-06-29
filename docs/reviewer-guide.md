# Reviewer Guide

This guide gives a compact path for evaluating `cpp-dsp-showcase`.

## What to review first

| Step | Page | What it proves |
|---:|---|---|
| 1 | [README](../README.md) | Project scope, build commands and implemented modules |
| 2 | [Algorithm evidence matrix](algorithm-evidence-matrix.md) | Test and benchmark coverage by DSP algorithm |
| 3 | [Verification strategy](verification.md) | Deterministic checks and tolerance policy |
| 4 | [Benchmark guide](benchmark.md) | How performance reports are generated |
| 5 | [FPGA mapping notes](fpga-mapping.md) | Which kernels have a hardware-oriented interpretation |
| 6 | [Release checklist](release-checklist.md) | What must pass before tagging a release |

## Local review commands

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DDSP_ENABLE_AVX2=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release --parallel
ctest --test-dir build --build-config Release --output-on-failure
cmake --build build --config Release --target benchmark_report
```

## Review checklist

- Public API headers are small and readable.
- Every implemented DSP kernel has a deterministic test.
- Benchmark output states build configuration and platform assumptions.
- SIMD acceleration has a scalar fallback.
- FPGA mapping notes avoid claiming board-level validation unless evidence exists.
- The repository can be used as a CMake package from another project.

## Current next improvements

1. Add an external CMake consumer example.
2. Add benchmark trend notes for future releases.
3. Add more edge-case tests for empty input, short vectors and extreme filter sizes.
4. Keep the bridge to `zynq-sdr-course` synchronized.
