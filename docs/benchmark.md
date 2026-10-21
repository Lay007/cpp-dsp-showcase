# Benchmark Guide

This project ships with a small benchmark executable so that algorithm changes can be evaluated with reproducible numbers instead of assumptions.

## Run the benchmark

Generate the markdown report from CMake:

```bash
cmake --build build --config Release --target benchmark_report
```

Run the benchmark executable directly:

```bash
./build/dsp_core/dsp_core_benchmark --iterations 20 --report build/reports/dsp_performance.md
```

The report is written as a markdown table to make it easy to review in CI artifacts or commit into documentation when needed.

## What is measured

The current benchmark compares representative kernels:

- direct FIR convolution
- FFT overlap-save convolution
- scalar Goertzel evaluation
- batched Goertzel evaluation

These measurements are intended as engineering guidance, not as a vendor-grade microbenchmark suite.

The committed benchmark uses a 32,768-sample tone at 48 ksample/s and a
127-tap FIR filter. The batched Goertzel case evaluates four frequencies, while
the scalar case evaluates one. These are intentionally different workloads;
even a ratio between the two Goertzel times is not a like-for-like speedup.
The sample values below illustrate report formatting, not a cross-machine
performance guarantee.

For a meaningful before/after comparison, record the commit SHA, CPU,
compiler/version/flags, build preset (including AVX2), iteration count, input
length and filter length. Run on the same host with the same workload. Report
functional/numerical test results alongside the runtime.

## Reading the results

The generated table includes:

- average execution time in milliseconds for each measured operation;
- relative speedup against **direct FIR** only for FFT overlap-save FIR with the same input and filter;
- `n/a` for Goertzel methods: they do different work and cannot be compared against FIR as a speedup.

Representative example:

| Method | Time (ms) | Speedup vs FIR direct |
|---|---:|---:|
| FIR direct | 2.693 | 1.00x |
| FIR overlap-save FFT | 1.816 | 1.48x |
| Goertzel scalar | 0.130 | n/a |
| Goertzel batched (four frequencies) | 0.485 | n/a |

The interpretation matters more than the raw numbers:

```text
short filters -> direct FIR can stay competitive
longer filters -> FFT methods become more attractive
single tone -> scalar Goertzel is simple and efficient
multiple tones -> batching can simplify multi-target analysis
```

## Caveats

Benchmark numbers depend on:

- compiler and flags
- CPU microarchitecture
- memory subsystem behavior
- selected iteration count
- signal size and filter length

Always compare runs on the same hardware and toolchain before drawing conclusions.

## Visual summary

![Benchmark dashboard](assets/benchmark_dashboard.svg)
