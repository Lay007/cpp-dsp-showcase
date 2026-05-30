# DSP quality gates

Use this checklist before merging algorithm, benchmark, or numerical changes.

## Correctness

- Add or update unit tests for every public DSP function touched by the change.
- Compare against a simple reference implementation where possible.
- Prefer deterministic test vectors over random-only tests.
- State numerical tolerances explicitly in tests and documentation.
- Cover edge cases: empty inputs, single-sample inputs, non-power-of-two lengths, invalid parameters, and extreme coefficient values.

## Numerical behavior

For each algorithm change, document the expected impact on at least one of:

- absolute or relative error;
- signal-to-noise ratio;
- tone detection error;
- delay estimation error;
- passband ripple and stopband attenuation;
- resampling ratio accuracy;
- overflow or saturation behavior for fixed-point variants.

## Performance

- Run the benchmark suite before and after performance-sensitive changes.
- Keep benchmark input sizes visible in the report.
- Separate algorithmic speedups from compiler or CPU-feature effects.
- Mention CPU model, compiler, build type, and operating system for published results.

## Reproducibility

- Generated figures should be reproducible from scripts.
- Generated reports should not require private data.
- CI should validate build and unit tests on at least Linux and Windows when possible.

## Review checklist

- CMake configure passes.
- Build passes.
- CTest passes.
- Performance report is updated when performance claims are made.
- Documentation explains changed assumptions, tolerances, or limitations.
