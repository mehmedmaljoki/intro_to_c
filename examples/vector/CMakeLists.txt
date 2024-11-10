project(c/examples/vector C)

set(CMAKE_CXX_STANDARD 99)

include_directories(.)

add_executable(c test-framework/unity.c)
add_executable(c test_vector.c)
add_executable(c vector.c)