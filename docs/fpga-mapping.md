# FPGA Mapping Notes

Several DSP kernels in this repository are intentionally compatible with streaming FPGA architectures.

## FIR filtering

Typical FPGA implementation:

```text
sample stream
-> delay line
-> multiply
-> accumulate
-> output
```

Important FPGA considerations:

- coefficient quantization;
- pipeline depth;
- multiplier count;
- accumulator width;
- throughput vs latency.

## Goertzel detector

The Goertzel algorithm maps efficiently to FPGA because:

- state memory is small;
- coefficient count is low;
- streaming operation is natural.

Typical applications:

- tone detection;
- telemetry;
- synchronization markers;
- narrowband spectral monitoring.

## Rational resampler

An FPGA-oriented resampler typically contains:

```text
interpolator
-> FIR filter
-> decimator
```

Critical implementation topics:

- polyphase decomposition;
- coefficient reuse;
- clock-domain considerations;
- deterministic latency.

## FFT overlap-save filtering

FFT-based filtering is more resource-intensive but becomes attractive for long filters.

Key engineering tradeoffs:

| Area | Direct FIR | FFT overlap-save |
|---|---|---|
| Latency | low | medium |
| Small filters | efficient | inefficient |
| Long filters | expensive | efficient |
| Control complexity | low | higher |
| Memory usage | low | medium/high |

## Verification alignment

A practical engineering flow should compare:

```text
MATLAB/Python reference
-> C++ implementation
-> fixed-point model
-> RTL simulation
```

using the same vectors and metrics.
