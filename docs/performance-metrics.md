# DSP Performance Metrics

This document defines recommended engineering metrics for DSP benchmarking.

## Throughput metrics

| Metric | Meaning |
|---|---|
| MSamples/s | processed sample throughput |
| MB/s | memory-oriented throughput |
| Real-time factor | realtime feasibility |

## CPU efficiency metrics

| Metric | Meaning |
|---|---|
| cycles/sample | computational efficiency |
| SIMD gain | acceleration effectiveness |
| cache sensitivity | memory behavior |

## Numerical metrics

| Metric | Meaning |
|---|---|
| RMS error | average implementation deviation |
| max absolute error | overflow visibility |
| SNR degradation | signal-quality preservation |

## Benchmark environment

Reports should document:

- CPU model;
- compiler version;
- optimization flags;
- SIMD configuration;
- operating system.

## Reporting principle

Performance claims should be reproducible and generated from scripts rather than manually edited values.
