cmake_minimum_required(VERSION 3.16)
project(cpp_dsp_showcase_install_consumer LANGUAGES CXX)

find_package(cpp_dsp_showcase CONFIG REQUIRED)

add_executable(install_consumer main.cpp)
target_link_libraries(install_consumer PRIVATE dsp_core::dsp)
target_compile_features(install_consumer PRIVATE cxx_std_17)
