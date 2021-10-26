cmake_minimum_required(VERSION 3.20)
project(KeyboardNinja)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(tests)

add_executable(KeyboardNinja src/main.cpp src/Texts.cpp src/Texts.h src/Game.cpp src/Game.h)
