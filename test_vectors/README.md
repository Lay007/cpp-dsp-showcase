# Test Vectors

This directory is intended for deterministic DSP reference vectors.

## Purpose

Golden vectors make DSP behavior reviewable and reproducible across:

- reference scripts;
- C++ implementations;
- SIMD paths;
- future fixed-point models;
- possible RTL mappings.

## Recommended structure

```text
test_vectors/
  fir/
  goertzel/
  gcc_phat/
  resampler/
```

## Vector metadata

Every vector set should document:

| Field | Meaning |
|---|---|
| sample_rate | signal sampling rate |
| input_format | scalar, complex, interleaved IQ or CSV |
| reference_tool | Python, MATLAB or analytical reference |
| tolerance | numerical acceptance threshold |
| expected_behavior | what the test proves |

## Recommended workflow

```text
generate reference vector
-> run C++ kernel
-> compare output
-> report RMS and max error
-> keep vector stable in CI
```

## Initial vector candidates

| Kernel | Vector idea |
|---|---|
| FIR | impulse and step response |
| Goertzel | tone on-bin and off-bin cases |
| GCC-PHAT | known integer delay |
| Resampler | rational L/M waveform conversion |

## Engineering rule

A DSP kernel should not be considered portfolio-grade until it has deterministic tests, a documented vector strategy and a benchmark path.
