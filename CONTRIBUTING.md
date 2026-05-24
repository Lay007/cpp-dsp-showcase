# Contributing

Thank you for improving `cpp-dsp-showcase`.

This repository is an engineering portfolio project for modern C++ digital signal processing. Contributions should make the code more reproducible, measurable, readable, or useful for DSP/FPGA-oriented review.

## Development principles

- Keep changes small and focused.
- Prefer deterministic algorithms and deterministic tests.
- Document non-trivial DSP assumptions.
- Keep generated artifacts reproducible from scripts.
- Do not commit machine-specific paths, private data, credentials, or large raw captures.
- Update documentation when public behavior, build options, benchmark format, or metrics change.

## Local validation

Recommended baseline:

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DDSP_BUILD_DEMOS=ON -DDSP_BUILD_BENCHMARKS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release --parallel
ctest --test-dir build --build-config Release --output-on-failure
```

Generate the benchmark report when benchmark-related code changes:

```bash
cmake --build build --config Release --target benchmark_report
```

Generate documentation assets when plots or generated figures change:

```bash
python tools/generate_dsp_svg_artifacts.py
python tools/generate_benchmark_plot.py
```

## DSP change checklist

For algorithmic changes, include or update at least one of the following:

- unit test;
- deterministic input/output vector;
- benchmark row;
- documentation note;
- error or tolerance explanation.

## C++ style expectations

- Prefer clear, reviewable code over clever micro-optimizations.
- Avoid hidden global state.
- Keep public API compact and documented.
- Use explicit units for rates, frequencies, delays and sizes.
- Explain numerical tolerances in tests.

## SIMD and performance changes

For SIMD, AVX2 or performance-oriented changes:

- keep a scalar baseline path;
- preserve deterministic results within documented tolerance;
- report benchmark impact;
- avoid architecture-specific assumptions in generic code paths.

## Pull request checklist

- [ ] Project configures with CMake.
- [ ] Project builds on the relevant platform.
- [ ] Tests pass through CTest.
- [ ] Documentation is updated when behavior changes.
- [ ] Generated figures/reports are reproducible.
- [ ] No credentials or private data are committed.
