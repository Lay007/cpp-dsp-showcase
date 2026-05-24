# Security Policy

## Supported scope

This repository is maintained as a public engineering portfolio and reference implementation. Security and safety fixes should target the current `main` branch.

## Reporting a vulnerability

Please do not open a public issue for suspected vulnerabilities or accidental secret exposure.

Report privately through the contact channel listed in the profile README and include:

- affected component or file;
- reproduction steps;
- expected impact;
- suggested mitigation, if known.

## Secrets and private data

Do not commit:

- API tokens;
- SSH keys;
- passwords;
- private `.env` files;
- proprietary signal recordings;
- personal data;
- machine-specific deployment credentials.

Use placeholders in examples and document required variables without exposing real values.

## Dependency and build hygiene

Recommended baseline for this repository:

- Dependabot for GitHub Actions;
- CodeQL for C++ static analysis;
- reproducible CMake build and CTest execution;
- generated artifacts traceable to scripts;
- no large binary data in normal Git history.
