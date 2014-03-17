cmake_minimum_required(VERSION 2.8.10)
project(toolchain C CXX ASM)

include_directories(include)

add_library(startup OBJECT init.c)
set_source_files_properties(init.c PROPERTIES COMPILE_FLAGS -fno-builtin)

add_subdirectory(core)
add_subdirectory(peripherals)
add_subdirectory(pdclib)
add_subdirectory(libc++)
