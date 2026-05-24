# Release checklist

Use this checklist before publishing a public release of `cpp-dsp-showcase`.

## 1. Build and test

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DDSP_BUILD_DEMOS=ON -DDSP_BUILD_BENCHMARKS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release --parallel
ctest --test-dir build --build-config Release --output-on-failure
```

## 2. Benchmark artifacts

```bash
cmake --build build --config Release --target benchmark_report
python tools/generate_dsp_svg_artifacts.py
python tools/generate_benchmark_plot.py
```

Check that generated figures and reports are reproducible:

- `build/reports/dsp_performance.md`
- `docs/assets/benchmark_dashboard.svg`
- `docs/assets/benchmark_results.png`
- DSP demonstration figures under `docs/assets/`

## 3. Documentation review

- README build commands are current.
- Implemented modules table matches the code.
- Benchmark guide is current.
- Verification notes describe deterministic tests and tolerances.
- FPGA mapping notes are not overstated.

## 4. Release notes draft

Suggested release summary:

```text
v0.1.0 introduces a compact modern C++ DSP showcase with FIR design, direct and overlap-save convolution, Goertzel detection, GCC-PHAT delay estimation, rational resampling, unit tests, CMake packaging, CI and generated benchmark artifacts.
```

## 5. Final checks

- Linux CI is green.
- Windows CI is green.
- CodeQL is green or known issues are documented.
- No private data or generated junk is committed.
- `CHANGELOG.md` has a release section.
