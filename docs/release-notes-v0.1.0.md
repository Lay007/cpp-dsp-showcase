# Release notes: v0.1.0

`v0.1.0` is the first portfolio-oriented release candidate of `cpp-dsp-showcase`.

The goal of this release is to demonstrate a compact but professional DSP C++ codebase: deterministic algorithms, tests, benchmark tooling, CMake packaging and documentation that connects software behavior to SDR/FPGA engineering practice.

## What is included

| Area | Release content |
|---|---|
| FIR filtering | Windowed-sinc low-pass design, direct convolution and FFT overlap-save path |
| Tone detection | Goertzel power estimation for single and batched frequencies |
| Delay estimation | GCC-PHAT integer-delay baseline |
| Resampling | Rational `L/M` resampler with anti-alias filtering |
| Performance | Benchmark executable and markdown report generation |
| Packaging | CMake install/export flow and downstream `find_package` use case |
| Documentation | Verification, benchmark, evidence matrix and FPGA mapping notes |

## Reviewer checklist

A reviewer should be able to verify the release with the following path:

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DDSP_ENABLE_AVX2=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
ctest --test-dir build --build-config Release --output-on-failure
cmake --build build --config Release --target benchmark_report
```

Expected evidence:

- CTest passes for deterministic DSP behavior.
- Benchmark report is regenerated from source tooling.
- README commands match the actual build flow.
- CI is green on Linux and Windows before tagging the final release.

## Engineering value

This release is intentionally small. Its value is not the number of algorithms, but the engineering discipline around them:

- predictable public API surface;
- deterministic tests;
- reproducible benchmark artifacts;
- clear CMake packaging;
- documentation that explains algorithm evidence and future FPGA mapping.

## Known limitations

- The project is a showcase/reference, not a general-purpose DSP framework.
- AVX2 support is optional and should not be treated as a required platform feature.
- FPGA notes are design guidance; RTL implementation and synthesis reports are future work.

## Suggested tag message

```text
v0.1.0: initial C++ DSP showcase release

Includes FIR, Goertzel, GCC-PHAT, rational resampling, tests,
benchmark tooling, CMake packaging and reviewer documentation.
```
