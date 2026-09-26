#!/usr/bin/env python3
"""Independent integer-convolution fixtures, shared as plain CSV; no numpy needed."""
import argparse
from fractions import Fraction
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1] / "verification/vectors/fir_q15"
CASES = {
    "impulse": ([32767, 0, 0, 0], [8192, 16384, 8192]),
    "signed": ([1234, -2345, 32767, -32768, 1, -1, 0], [16384, -8192, 4096]),
    "ties": ([1, -1, 3, -3, 32767, -32768], [16384]),
    "saturation": ([32767, 32767, -32768, -32768], [32767, 32767]),
    "negative_taps": ([-32768, 32767, 0, 0], [-32768, -32768]),
}


def fixtures():
    for name, (samples, taps) in CASES.items():
        products = [0] * (len(samples) + len(taps) - 1)
        for i, sample in enumerate(samples):
            for j, tap in enumerate(taps):
                products[i + j] += sample * tap
        yield f"{name}_input.csv", "q15\n" + "".join(f"{v}\n" for v in samples)
        yield f"{name}_taps.csv", "q15\n" + "".join(f"{v}\n" for v in taps)
        rows = ["q15,float64\n"]
        for value in products:
            exact = Fraction(value, 32768)
            rounded = int(abs(exact) + Fraction(1, 2)) * (-1 if exact < 0 else 1)
            rows.append(f"{max(-32768, min(32767, rounded))},{value / 1073741824:.17g}\n")
        yield f"{name}_expected.csv", "".join(rows)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    ROOT.mkdir(parents=True, exist_ok=True)
    for name, value in fixtures():
        path = ROOT / name
        if args.check:
            if not path.exists() or path.read_bytes() != value.encode("ascii"):
                raise SystemExit(f"stale vector: {path}")
        else:
            path.write_bytes(value.encode("ascii"))
    print("FIR Q15 shared vectors: PASS")


if __name__ == "__main__":
    main()
