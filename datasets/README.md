# DSP Datasets and Reference Vectors

This directory is intended for reusable DSP validation datasets.

## Recommended structure

```text
datasets/
  synthetic/
  reference/
  impaired/
```

## Dataset metadata

Every dataset should document:

- sample rate;
- signal type;
- duration;
- quantization;
- expected engineering behavior.

## Example dataset categories

| Dataset | Purpose |
|---|---|
| clean tone | Goertzel verification |
| multi-tone | FFT validation |
| delayed signal | GCC-PHAT testing |
| resampled waveform | rational resampler checks |
| noisy signal | robustness evaluation |

## Engineering principle

The same datasets should be reusable across:

- reference scripts;
- unit tests;
- benchmarks;
- FPGA-oriented validation.
