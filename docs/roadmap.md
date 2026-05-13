# Engineering Roadmap

This roadmap keeps the repository focused on demonstrable DSP engineering value.

## Near-term improvements

| Area | Improvement | Result |
|---|---|---|
| Verification | Add reusable golden vectors | stable cross-language validation |
| Benchmarks | Publish reproducible benchmark tables | visible performance evidence |
| SIMD | Expand scalar vs AVX2 comparisons | optimization credibility |
| Documentation | Add FPGA mapping notes | bridge from C++ to RTL |
| Demo | Add IQ analysis report | practical SDR relevance |

## Medium-term improvements

- fixed-point reference layer;
- randomized DSP property tests;
- CI-generated benchmark dashboard;
- downloadable benchmark artifacts;
- optional Python reference scripts;
- example downstream CMake project.

## Long-term direction

The repository should become a compact reference for how to implement, validate and package DSP kernels in C++ before moving selected blocks into fixed-point and FPGA environments.

## Definition of done

A feature is considered complete when it has:

1. implementation;
2. deterministic tests;
3. benchmark or complexity note;
4. documentation;
5. connection to the portfolio-level engineering pipeline.
