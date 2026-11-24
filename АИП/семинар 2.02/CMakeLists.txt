cmake_minimum_required(VERSION 3.16)
project(sem_2.02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(matrix src/matrix.cpp)
target_include_directories(matrix PUBLIC src)
target_compile_options(matrix PRIVATE -Wall -Wextra -Werror)

add_executable(app src/main.cpp)
target_compile_options(app PRIVATE -Wall -Wextra -Werror)
target_link_libraries(app PRIVATE matrix)

enable_testing()
find_package(GTest REQUIRED)
add_executable(tests tests/test_matrix.cpp)
target_link_libraries(tests PRIVATE matrix GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)
