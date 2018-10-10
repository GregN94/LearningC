cmake_minimum_required (VERSION 2.6)
project (run)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic)

IF(DEBUG_OPT)
    MESSAGE("Adding Debug flag...")
    ADD_DEFINITIONS(-DDEBUG)
    SET(CMAKE_BUILD_TYPE Debug)
    MESSAGE("Build type is " ${CMAKE_BUILD_TYPE})
ENDIF(DEBUG_OPT)


include_directories(include)

SET(SOURCES main.c
            src/stud_console.c
            src/stud_file.c
            src/stud_sort.c
            src/stud_utils.c.
            src/stud_mem.c)

add_executable(run ${SOURCES})
