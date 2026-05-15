# DSP Benchmark Report

## Summary

This report template is intended for generated benchmark results.

## Environment

| Field | Value |
|---|---|
| CPU | TBD |
| OS | TBD |
| Compiler | TBD |
| Build type | Release |
| SIMD | scalar / AVX2 |

## Kernel performance

| Kernel | Input size | Throughput | Cycles/sample | Notes |
|---|---:|---:|---:|---|
| FIR direct | TBD | TBD | TBD | baseline |
| FIR overlap-save | TBD | TBD | TBD | long-filter path |
| Goertzel | TBD | TBD | TBD | tone detection |
| Rational resampler | TBD | TBD | TBD | L/M conversion |

## Numerical validation

| Kernel | Reference | RMS error | Max error | Status |
|---|---|---:|---:|---|
| FIR | golden vector | TBD | TBD | TBD |
| Goertzel | golden vector | TBD | TBD | TBD |
| GCC-PHAT | golden vector | TBD | TBD | TBD |
| Resampler | golden vector | TBD | TBD | TBD |

## Interpretation

Document:

- bottlenecks;
- SIMD effect;
- memory sensitivity;
- real-time suitability;
- recommended optimization targets.
