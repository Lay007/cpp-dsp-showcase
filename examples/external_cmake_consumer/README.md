# External CMake Consumer Example

This example shows how a separate CMake project can consume an installed `cpp-dsp-showcase` package.

## Build the library package first

From the repository root:

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cmake --install build --config Release --prefix install
```

## Build this external consumer

```bash
cmake -S examples/external_cmake_consumer -B build-external -DCMAKE_PREFIX_PATH="$PWD/install"
cmake --build build-external --config Release
./build-external/external_consumer
```

On Windows, run the generated executable from the matching configuration directory if the generator is multi-config.

## What it proves

- `find_package(cpp_dsp_showcase CONFIG REQUIRED)` works.
- The exported target `dsp_core::dsp` is usable from another project.
- Public headers are sufficient for a minimal downstream DSP application.
