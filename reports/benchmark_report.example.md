# DSP Benchmark Report Example

## Summary

This example report demonstrates the intended benchmark-report format for `cpp-dsp-showcase`.

The values below are placeholders for generated benchmark output and should be replaced by CI or local benchmark runs.

## Environment

| Field | Value |
|---|---|
| CPU | example engineering workstation |
| OS | Linux / Windows |
| Compiler | C++17 compiler |
| Build type | Release |
| SIMD | scalar / AVX2 |

## Kernel performance

| Kernel | Input size | Throughput | Cycles/sample | Notes |
|---|---:|---:|---:|---|
| FIR direct | 65536 | TBD | TBD | short and medium filters |
| FIR overlap-save | 65536 | TBD | TBD | long filter path |
| Goertzel | 65536 | TBD | TBD | narrowband tone detection |
| GCC-PHAT | 65536 | TBD | TBD | integer delay estimation |
| Rational resampler | 65536 | TBD | TBD | L/M conversion |

## Numerical validation

| Kernel | Reference | RMS error | Max error | Status |
|---|---|---:|---:|---|
| FIR | impulse/step vector | TBD | TBD | TBD |
| Goertzel | on-bin/off-bin tone | TBD | TBD | TBD |
| GCC-PHAT | known delay | TBD | TBD | TBD |
| Resampler | generated reference | TBD | TBD | TBD |

## Engineering interpretation

A benchmark report should explain:

- where SIMD improves throughput;
- where memory access dominates;
- where numerical error appears;
- which kernels are suitable for real-time use;
- which blocks are good candidates for FPGA mapping.

## Reproducibility checklist

- [ ] benchmark command recorded;
- [ ] compiler and flags recorded;
- [ ] CPU model recorded;
- [ ] generated JSON attached;
- [ ] plots regenerated from source data.
