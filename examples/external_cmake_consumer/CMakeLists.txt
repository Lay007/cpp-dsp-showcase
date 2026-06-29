cmake_minimum_required(VERSION 3.20)
project(cpp_dsp_showcase_external_consumer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpp_dsp_showcase CONFIG REQUIRED)

add_executable(external_consumer main.cpp)
target_link_libraries(external_consumer PRIVATE dsp_core::dsp)
