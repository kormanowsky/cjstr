cmake_minimum_required(VERSION 3.26)
project(cjstr C)

set(CMAKE_C_STANDARD 23)

add_library(cjstr cjstr.c)

add_executable(cjstr_app main.c)

target_link_libraries(cjstr_app cjstr)