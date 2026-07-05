# Golden Vector Policy

Golden vectors are small deterministic datasets used to protect DSP behavior across implementations, refactors and future language ports.

## What belongs in a golden vector

| Field | Purpose |
|---|---|
| vector name | stable identifier for tests and reports |
| algorithm | FIR, Goertzel, GCC-PHAT, resampler or another kernel |
| input samples | small deterministic input sequence |
| parameters | taps, frequency bin, delay, ratio or other algorithm settings |
| expected output | reference values or summary metrics |
| tolerance | acceptable numeric error |
| source | script, hand-derived case or external reference |

## Rules

- Keep vectors small enough for code review.
- Prefer text formats such as CSV or JSON for reviewability.
- Store generation scripts when values are not hand-derived.
- Include edge cases: empty input, short input, impulse, constant signal and simple sinusoid where relevant.
- Never replace a golden vector silently. Explain why the old expected result was wrong or why the algorithm contract changed.

## Acceptance criteria

A new DSP kernel should have at least one golden-vector test before it is presented as portfolio evidence. Performance benchmarks are useful, but they do not replace correctness vectors.

## Suggested location

```text
verification/vectors/<algorithm_name>.csv
verification/vectors/<algorithm_name>.json
```

If a vector is generated, place the generator under:

```text
tools/generate_<algorithm_name>_vectors.py
```

## Review question

A reviewer should be able to answer:

```text
Given this input and these parameters, what exact behavior is this DSP kernel expected to preserve?
```
