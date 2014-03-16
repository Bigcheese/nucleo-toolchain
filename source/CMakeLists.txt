cmake_minimum_required(VERSION 2.8.10)
project(toolchain C CXX ASM)

include_directories(include)

add_library(startup OBJECT startup_stm32f10x_md.s init.cpp)

add_subdirectory(core)
add_subdirectory(peripherals)
add_subdirectory(pdclib)
add_subdirectory(libc++)
