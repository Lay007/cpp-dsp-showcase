# Generated Reports

This directory is intended for generated engineering artifacts.

## Typical outputs

| Artifact | Purpose |
|---|---|
| `benchmark_report.md` | benchmark summary |
| `benchmark_results.json` | machine-readable metrics |
| `simd_comparison.md` | scalar vs SIMD comparison |
| `performance_environment.md` | CPU and compiler environment |

## Recommended workflow

```text
build
-> benchmark
-> generate plots
-> export markdown/json reports
```

## Reproducibility principle

Generated reports should be reproducible from scripts and source data.

The repository should avoid manually edited benchmark claims.
