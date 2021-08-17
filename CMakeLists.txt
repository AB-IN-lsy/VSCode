cmake_minimum_required(VERSION 3.19)
project(Vscode)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Vscode
        test.cpp)
