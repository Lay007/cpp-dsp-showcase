# Downstream CMake Project Example

This example documents how an external project should consume `cpp-dsp-showcase` as an installed CMake package.

## Intended workflow

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cmake --install build --config Release --prefix install
```

Then from a downstream project:

```cmake
find_package(cpp_dsp_showcase CONFIG REQUIRED)

add_executable(downstream_demo main.cpp)
target_link_libraries(downstream_demo PRIVATE dsp_core::dsp)
```

## Why this matters

A DSP repository is stronger when it is not only a demo, but also a reusable library.

A downstream example demonstrates:

- installable package exports;
- stable public headers;
- clean CMake integration;
- separation between library code and applications.

## Recommended next step

Add a minimal compiling example with:

```text
examples/downstream_cmake_project/
  CMakeLists.txt
  main.cpp
```

The example should call one or two public DSP functions and remain small enough for CI.
