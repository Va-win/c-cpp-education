cmake_minimum_required(VERSION 3.16)
project(sem_2.01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(arrays src/arrays.cpp)
target_include_directories(arrays PUBLIC src)
target_compile_options(arrays PRIVATE -Wall -Wextra -Werror)

add_executable(app src/main.cpp)
target_compile_options(app PRIVATE -Wall -Wextra -Werror)
target_link_libraries(app PRIVATE arrays)

enable_testing()
find_package(GTest REQUIRED)
add_executable(tests tests/test_arrays.cpp)
target_link_libraries(tests PRIVATE arrays GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)
