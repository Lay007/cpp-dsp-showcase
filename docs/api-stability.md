# API Stability and Integration Contract

This note defines what downstream users can rely on when using `cpp-dsp-showcase` as a small DSP library rather than only as a demonstration repository.

## Public surface

The public integration point is the installed CMake package and the public header:

```text
dsp_core/dsp.hpp
```

Downstream projects should include only public headers and link the exported target:

```cmake
find_package(cpp_dsp_showcase CONFIG REQUIRED)
add_executable(example main.cpp)
target_link_libraries(example PRIVATE dsp_core::dsp)
```

Files under `src/`, `tests/`, `bench/`, and `tools/` are internal implementation or verification assets unless explicitly documented otherwise.

## Compatibility expectations

The project should try to preserve:

- function names and argument order in public headers;
- documented units and normalization conventions;
- deterministic behavior of reference implementations;
- CMake package target names;
- test vector meaning and accepted tolerances.

Breaking changes are acceptable while the repository is still a learning and portfolio project, but they should be explicit in commit messages and documentation.

## Numerical behavior contract

DSP APIs should document the following when applicable:

| Topic | Required note |
|---|---|
| Sampling rate | Units and relationship to normalized frequency |
| Frequency | Hz, rad/sample, or normalized cycles/sample |
| Gain | Linear, dB, or normalized amplitude |
| Phase | Radians or degrees |
| Delay | Samples or seconds |
| Windowing | Window type and normalization |
| Error tolerance | Absolute, relative, RMS, or algorithm-specific |

A reviewer should be able to tell whether a mismatch is a real algorithm bug or only a difference in convention.

## Determinism rules

For tests and examples:

- keep random seeds fixed;
- avoid wall-clock dependent expected results;
- separate correctness tests from performance benchmarks;
- store canonical tolerances next to the algorithm being tested;
- keep benchmark reports informational, not pass/fail gates, unless a stable threshold is justified.

## Performance policy

Optimized code paths such as AVX2 should preserve the reference result within documented tolerance.

Recommended comparison pattern:

1. Run scalar/reference implementation.
2. Run optimized implementation on the same input.
3. Compare numerical error using a documented metric.
4. Record speedup separately from correctness.

## Adding a new DSP primitive

A new primitive is considered reviewable when it includes:

- public API entry or intentionally internal API note;
- short theory note or engineering comment;
- deterministic unit test;
- at least one edge-case test;
- benchmark entry if performance is a project claim;
- documentation link from the README or reviewer path.

## Release-readiness gate

Before treating the repository as reusable engineering code, check:

- clean configure/build/test on Linux and Windows;
- no generated binaries committed to Git;
- public header examples compile;
- exported CMake package works from an external project;
- README commands match the current build system;
- benchmark report can be regenerated.
