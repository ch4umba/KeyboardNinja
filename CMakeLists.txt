cmake_minimum_required(VERSION 3.20)
project(KeyboardNinja)

set(CMAKE_CXX_STANDARD 14)

add_executable(KeyboardNinja main.cpp Texts.cpp Texts.h Game.cpp Game.h)
