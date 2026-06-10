# Verification Strategy

This repository treats verification as part of the DSP implementation itself.

## Verification layers

| Layer | Goal |
|---|---|
| Unit tests | deterministic correctness checks |
| Golden vectors | stable reference behavior |
| Benchmarks | reproducible timing measurements |
| Visual plots | fast engineering diagnostics |
| Install/export smoke | prove the installed CMake package works for an external consumer |
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

## Installed package smoke test

The repository includes a small external consumer under `examples/install_consumer`.

The CI flow installs the library into a local prefix and then configures the consumer with:

```bash
cmake -S examples/install_consumer -B build-install-consumer -DCMAKE_PREFIX_PATH=<install-prefix>
cmake --build build-install-consumer --config Release
```

This verifies that:

- `cpp_dsp_showcaseConfig.cmake` is installed;
- exported targets are visible through `find_package(cpp_dsp_showcase CONFIG REQUIRED)`;
- downstream code can link against `dsp_core::dsp`;
- public headers are installed correctly.

## CI philosophy

The repository CI should answer five questions:

1. Does it build?
2. Does it pass deterministic tests?
3. Can it be installed as a CMake package?
4. Can an external consumer use the installed package?
5. Are benchmark and documentation assets still valid?

## Future extensions

- SIMD equivalence validation;
- FFT overlap-save stress testing;
- randomized property testing;
- fixed-point reference comparisons;
- HDL co-simulation alignment.
