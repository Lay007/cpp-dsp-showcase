# External CMake Consumer Example

This directory documents the intended way to use `cpp-dsp-showcase` from another CMake project after installation.

The goal is to prove that the repository is not only self-buildable, but also usable as a small DSP library by a downstream project.

## 1. Build and install the library

From the repository root:

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
ctest --test-dir build --build-config Release --output-on-failure
cmake --install build --config Release --prefix install
```

## 2. Minimal downstream `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.20)
project(dsp_external_consumer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpp_dsp_showcase CONFIG REQUIRED)

add_executable(dsp_external_consumer main.cpp)
target_link_libraries(dsp_external_consumer PRIVATE dsp_core::dsp)
```

## 3. Minimal downstream `main.cpp`

```cpp
#include <dsp_core/dsp.hpp>

#include <iostream>
#include <vector>

int main() {
    const std::vector<double> samples{1.0, 0.0, -1.0, 0.0, 1.0};

    // Replace this smoke call with a real API call from dsp.hpp when creating
    // a standalone integration test project. Keep the example intentionally
    // small so it can be copied into another repository.
    std::cout << "sample_count=" << samples.size() << "\n";
    return 0;
}
```

## 4. Configure downstream project

Assuming `cpp-dsp-showcase` was installed into `../cpp-dsp-showcase/install`:

```bash
cmake -S . -B build \
  -DCMAKE_PREFIX_PATH=../cpp-dsp-showcase/install \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

## 5. Acceptance criteria

The external consumer example is valid when:

- `find_package(cpp_dsp_showcase CONFIG REQUIRED)` works outside the source tree;
- the exported target `dsp_core::dsp` links successfully;
- the public include path exposes `dsp_core/dsp.hpp`;
- no private source paths from `cpp-dsp-showcase` are required;
- the downstream build can be reproduced from a clean directory.

## 6. Future improvement

A later CI job can build a tiny downstream project after installation. That would turn the package export from a documented promise into a tested integration contract.
