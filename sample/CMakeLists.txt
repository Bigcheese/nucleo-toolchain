cmake_minimum_required(VERSION 2.8.12)
project(sample C CXX ASM)

include_directories(C:/Users/Michael/Projects/mbed/libraries/mbed/include)
link_directories(K:/Build/mbed/libraries)

add_executable(sample sample.cpp)
target_link_libraries(sample libmbed.a)
