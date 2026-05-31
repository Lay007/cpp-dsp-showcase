# Bridge to zynq-sdr-course

`cpp-dsp-showcase` and `zynq-sdr-course` are complementary projects:

- `zynq-sdr-course` explains the SDR/DSP engineering path from theory to hardware-oriented experiments.
- `cpp-dsp-showcase` provides production-style C++ implementations, tests, benchmarks and packaging for selected DSP kernels.

This page maps course topics to C++ implementation evidence.

## Topic bridge

| Course topic | C++ showcase module | Engineering bridge |
|---|---|---|
| Sampling, tones and spectra | Goertzel detector, IQ analysis demo | detect tone energy in recorded or synthetic IQ data |
| FIR filtering | FIR design, direct convolution | connect frequency response to tested implementation |
| FFT-based processing | FFT overlap-save convolution | explain complexity boundary and block processing |
| Correlation and delay | GCC-PHAT | connect delay estimation theory to a deterministic implementation |
| Resampling | Rational L/M resampler | demonstrate interpolation, decimation and anti-alias filtering |
| Fixed-point / FPGA bridge | FIR and Goertzel candidates | prepare selected kernels for quantization and RTL mapping |
| Measurement reports | benchmark report generator | turn algorithm performance into reproducible evidence |

## Recommended cross-repository workflow

1. Use `zynq-sdr-course` to introduce the signal-processing concept.
2. Use MATLAB/Python or course plots as a readable reference.
3. Use `cpp-dsp-showcase` to inspect a tested C++ implementation.
4. Run the benchmark report to compare runtime behavior.
5. Document what would change for fixed-point or FPGA implementation.

## Candidate shared artifacts

| Artifact | Source | Consumer |
|---|---|---|
| Small CI16 tone vector | `zynq-sdr-course` IQ recording block | `cpp-dsp-showcase` IQ demo |
| FIR coefficient table | course FIR lab | C++ FIR test / benchmark |
| Delay test vector | synchronization lab | GCC-PHAT test |
| Resampling example | DSP modeling block | rational resampler test |

## Next steps

- Add a small public IQ vector shared by both repositories.
- Add a course page that links to C++ implementation evidence.
- Add fixed-point notes for FIR and Goertzel.
- Add a short benchmark interpretation page for SDR learners.
