cmake_minimum_required(VERSION 3.14)
project(OOP_LAB4_variant31 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_library(shapes INTERFACE)
target_include_directories(shapes INTERFACE include)

add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE shapes)

add_executable(tests tests/test_main.cpp)
target_link_libraries(tests PRIVATE shapes gtest_main)

enable_testing()
add_test(NAME shapes_tests COMMAND tests)
