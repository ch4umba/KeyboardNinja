# 'Google_test' is the subproject name
project(tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run testGameClass.cpp ../src/Game.cpp ../src/Texts.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)