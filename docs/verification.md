# Verification Strategy

This repository treats verification as part of the DSP implementation itself.

## Verification layers

| Layer | Goal |
|---|---|
| Unit tests | deterministic correctness checks |
| Golden vectors | stable reference behavior |
| Benchmarks | reproducible timing measurements |
| Visual plots | fast engineering diagnostics |
| CI | prevent regressions |

## Recommended golden-vector structure

```text
test_vectors/
  fir/
  goertzel/
  gcc_phat/
  resampler/
```

Each vector should include:

- input samples;
- expected output;
- tolerance definition;
- generation script reference.

## Floating-point vs fixed-point

For DSP systems that later move into FPGA or embedded targets:

- floating-point behavior should be treated as a golden reference;
- fixed-point behavior should be compared using explicit error metrics;
- plots should include deviation visibility when possible.

## Suggested engineering metrics

| Metric | Why it matters |
|---|---|
| RMS error | implementation accuracy |
| Max absolute error | overflow and clipping visibility |
| SNR | signal quality preservation |
| Execution time | real-time feasibility |
| Throughput | scalability |

## CI philosophy

The repository CI should answer four questions:

1. Does it build?
2. Does it pass deterministic tests?
3. Are benchmark artifacts generated?
4. Are documentation assets still valid?

## Future extensions

- SIMD equivalence validation;
- FFT overlap-save stress testing;
- randomized property testing;
- fixed-point reference comparisons;
- HDL co-simulation alignment.
