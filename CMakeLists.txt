cmake_minimum_required(VERSION 3.29)
project(c C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(c examples/endian.c)
