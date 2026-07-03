# Reviewer Quick Check

This page is a short review route for `cpp-dsp-showcase`. It is intended for a reviewer who wants to understand whether the repository demonstrates real DSP engineering discipline without reading every source file first.

## What to check first

| Step | Open | What it should prove |
|---:|---|---|
| 1 | `README.md` | The repository has a clear scope: C++ DSP kernels, tests, benchmarks and packaging. |
| 2 | `docs/algorithm-evidence-matrix.md` | Each algorithm is mapped to evidence: tests, reports, plots or next FPGA direction. |
| 3 | `docs/verification.md` | DSP behavior is protected by deterministic checks, not only by visual demos. |
| 4 | `docs/benchmark.md` | Performance claims have a repeatable measurement path. |
| 5 | `docs/fpga-mapping.md` | Selected kernels are written with hardware interpretation in mind. |

## Local build smoke check

Run from a clean checkout:

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release --parallel
ctest --test-dir build -C Release --output-on-failure
```

If AVX2 is available and should be included in the review:

```bash
cmake -S . -B build-avx2 -DBUILD_TESTING=ON -DDSP_ENABLE_AVX2=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build-avx2 --config Release --parallel
ctest --test-dir build-avx2 -C Release --output-on-failure
```

## Benchmark report check

After a successful build, generate the benchmark report:

```bash
cmake --build build --config Release --target benchmark_report
```

Review the generated report for:

- tested kernel name;
- input size or signal length;
- timing units;
- CPU/compiler context if available;
- comparison against a baseline or previous run where applicable.

## Acceptance checklist

A DSP kernel is mature enough to present when it has:

- a short description of the signal-processing task;
- deterministic unit tests with known expected behavior;
- edge-case coverage for empty, short or invalid inputs where relevant;
- benchmark or complexity notes for performance-sensitive code;
- documented numerical assumptions such as scaling, tolerance and precision;
- a clear note about whether it is intended for floating-point software, fixed-point migration or FPGA mapping.

## Current reviewer conclusion

The repository should be judged as a compact engineering showcase rather than a large framework. Its value is in traceability: algorithm -> test -> benchmark/report -> documentation -> possible SDR/FPGA use.
