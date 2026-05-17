#!/usr/bin/env python3
"""Generate a deterministic benchmark-style example report.

This script is intentionally dependency-free. It creates example JSON, Markdown
and SVG artifacts that document the desired benchmark-report structure.
"""

from __future__ import annotations

import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "reports"
BENCHMARKS = ROOT / "benchmarks"
ASSETS = ROOT / "docs" / "assets"

ROWS = [
    ("fir_direct", 65536, 180.0, 5.5),
    ("fir_overlap_save", 65536, 420.0, 2.4),
    ("goertzel", 65536, 760.0, 1.3),
    ("gcc_phat", 65536, 230.0, 4.2),
    ("rational_resampler", 65536, 150.0, 6.7),
]


def write_svg(path: Path) -> None:
    width, height = 900, 360
    max_value = max(row[2] for row in ROWS)
    bars = []
    labels = []
    for idx, (name, _, throughput, _) in enumerate(ROWS):
        x = 80 + idx * 155
        bar_h = throughput / max_value * 210
        y = 285 - bar_h
        bars.append(f'<rect x="{x}" y="{y:.1f}" width="90" height="{bar_h:.1f}" rx="8" fill="#a5b4fc"/>')
        labels.append(f'<text x="{x+45}" y="315" text-anchor="middle" font-family="Arial" font-size="11" fill="#475569">{name}</text>')
        labels.append(f'<text x="{x+45}" y="{y-8:.1f}" text-anchor="middle" font-family="Arial" font-size="12" fill="#0f172a">{throughput:.0f}</text>')
    svg = f'''<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img" aria-label="DSP benchmark summary">
  <rect width="100%" height="100%" rx="18" fill="#f8fafc"/>
  <text x="30" y="36" font-family="Arial" font-size="22" font-weight="700" fill="#0f172a">Generated DSP Benchmark Summary</text>
  <text x="30" y="62" font-family="Arial" font-size="13" fill="#475569">Example throughput values, MSamples/s</text>
  <line x1="60" y1="285" x2="850" y2="285" stroke="#94a3b8"/>
  {''.join(bars)}
  {''.join(labels)}
</svg>
'''
    path.write_text(svg, encoding="utf-8")


def main() -> None:
    REPORTS.mkdir(parents=True, exist_ok=True)
    BENCHMARKS.mkdir(parents=True, exist_ok=True)
    ASSETS.mkdir(parents=True, exist_ok=True)

    data = {
        "schema_version": "1.0",
        "environment": {
            "cpu": "example",
            "compiler": "example C++17 compiler",
            "build_type": "Release",
        },
        "metrics": [
            {
                "kernel": name,
                "input_size": size,
                "throughput_msamples_s": throughput,
                "cycles_per_sample": cycles,
            }
            for name, size, throughput, cycles in ROWS
        ],
    }
    (BENCHMARKS / "latest.example.json").write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    write_svg(ASSETS / "generated_benchmark_summary.svg")

    table = "\n".join(
        f"| {name} | {size} | {throughput:.1f} | {cycles:.2f} |"
        for name, size, throughput, cycles in ROWS
    )
    report = f'''# Generated DSP Benchmark Report

## Environment

| Field | Value |
|---|---|
| CPU | example |
| Compiler | example C++17 compiler |
| Build type | Release |

## Kernel performance

| Kernel | Input size | Throughput, MSamples/s | Cycles/sample |
|---|---:|---:|---:|
{table}

## Figure

![Benchmark summary](../docs/assets/generated_benchmark_summary.svg)

## Interpretation

This generated report is a deterministic example. Real benchmark runs should replace the example values and record compiler flags, CPU model and SIMD configuration.

## Reproducibility

```bash
python tools/generate_benchmark_report.py
```
'''
    (REPORTS / "benchmark_report.generated.md").write_text(report, encoding="utf-8")
    print("Generated benchmark report example.")


if __name__ == "__main__":
    main()
