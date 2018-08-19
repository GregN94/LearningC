set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required (VERSION 2.6)

add_compile_options(-Wall -Wextra -Wpedantic)
project (main)
add_executable(main main.c stud_console.c stud_file.c stud_sort.c stud_utils.c)
