cmake_minimum_required(VERSION 3.10)

# set the project name
project(Gcpu)
include_directories(include/)
# add the executable
add_executable(Gcpu main.cpp src/gcpu.cpp src/opcodes.cpp src/assembler.cpp)
set(CMAKE_BUILD_TYPE Debug)
