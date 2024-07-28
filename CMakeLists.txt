cmake_minimum_required(VERSION 3.23)
project(cjstr C)

set(CMAKE_C_STANDARD 23)

include(ExternalProject)

ExternalProject_Add(cjstr_c SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/c)
ExternalProject_Add(cjstr_js SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/js CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${CMAKE_EM_TOOLCHAIN_FILE})