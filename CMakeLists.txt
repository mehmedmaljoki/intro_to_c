cmake_minimum_required(VERSION 3.29)
project(c C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

#add_executable(c
#    all_data_types.c
#     implicit_signed.c
#    2D_arrays.c
#    arrays.c
#    firstfile.c
#    format_specifier.c
#    function_prototype.c
#    functions_arguments.c
#    intro.c
#    string_functions.c
#    user_input.c)
#)
#add_executable(c implicit_signed.c)
add_executable(c examples/tic_tac_toe.c)
#add_executable(c endian.c)
