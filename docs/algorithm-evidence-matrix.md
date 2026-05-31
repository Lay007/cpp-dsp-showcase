# DSP Algorithm Evidence Matrix

This matrix shows how each DSP algorithm in the repository is backed by implementation, tests, benchmarks, plots and possible FPGA mapping notes.

The goal is to make the repository reviewable as an engineering portfolio artifact, not only as a collection of C++ source files.

## Evidence matrix

| Algorithm / area | Implementation | Unit tests | Benchmark | Plot / report | FPGA mapping | Next improvement |
|---|---|---|---|---|---|---|
| FIR low-pass design | active | active | active | FIR response figure | partial | add coefficient quantization example |
| Direct convolution | active | active | active | benchmark report | possible | compare against FFT overlap-save by signal size |
| FFT overlap-save convolution | active | active | active | benchmark dashboard | future | add block-size tuning notes |
| Goertzel detector | active | active | active | tone-detection plot | possible | add fixed-point detector notes |
| Batched Goertzel | active | active | active | benchmark report | possible | add SIMD comparison table |
| GCC-PHAT delay estimation | active | active | partial | delay-estimation plot | future | add noisy/multipath robustness sweep |
| Rational L/M resampler | active | active | active | generated response / demo | possible | add alias rejection metric |
| IQ file analysis demo | active | smoke/demo | planned | demo output | not direct | add small public CI16 vector |
| SIMD / AVX2 path | optional | active where supported | active | performance report | not direct | add scalar-vs-AVX2 summary table |
| CMake package export | active | install smoke possible | not applicable | README example | not applicable | add downstream consumer CI smoke |

## Reviewer checklist

A reviewer should be able to answer:

- Which algorithms are implemented and tested?
- Which algorithms have performance evidence?
- Which algorithms have generated visual artifacts?
- Which algorithms are candidates for fixed-point or FPGA mapping?
- Which claims are protected by CI and which are only documented?

## Recommended artifact standard

Each major algorithm should ideally have:

```text
source implementation
unit test
benchmark case
small generated plot
short engineering note
known limitations
```

## Suggested next additions

1. Add a scalar-vs-AVX2 benchmark summary table.
2. Add a small deterministic IQ vector under `data/` or `tests/data/`.
3. Add fixed-point notes for FIR and Goertzel.
4. Add a downstream CMake consumer smoke test.
5. Add a bridge page that maps this repository to `zynq-sdr-course` labs.
