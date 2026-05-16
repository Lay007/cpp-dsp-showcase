# Direct FIR vs FFT Overlap-Save

This page documents the main engineering tradeoff between direct FIR filtering and FFT-based overlap-save filtering.

## Summary

Direct FIR is simple, low-latency and efficient for short filters.
FFT overlap-save becomes attractive when the filter length grows and the cost of direct convolution dominates.

## Rule-of-thumb comparison

| Filter length | Direct FIR | FFT overlap-save | Recommendation |
|---:|---|---|---|
| 16-64 taps | low overhead | overhead dominates | prefer direct FIR |
| 128-512 taps | depends on CPU/cache | can become competitive | benchmark both |
| 1024+ taps | expensive | usually better | prefer overlap-save |

## Engineering dimensions

| Dimension | Direct FIR | FFT overlap-save |
|---|---|---|
| Latency | low | block-based |
| Control complexity | low | medium |
| Memory usage | low | medium/high |
| SIMD friendliness | high | depends on FFT backend |
| Long filters | poor scaling | good scaling |
| FPGA mapping | straightforward | more complex |

## Verification requirements

Both implementations should be validated against the same reference response:

```text
input vector
-> direct FIR output
-> FFT overlap-save output
-> error metrics
```

Recommended metrics:

- RMS error;
- max absolute error;
- boundary block behavior;
- latency or group delay;
- throughput.

## Portfolio value

This comparison is useful because it shows not only algorithm knowledge, but also implementation judgment: the best DSP method depends on latency, memory, throughput, filter length and target hardware.
