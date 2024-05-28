cmake_minimum_required(VERSION 3.28)
project(binomial_heap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(binomial_heap "binomial heap.cpp"
        heaprealization.cpp
        heaprealization.h
        node.cpp
        node.h)
target_link_libraries(binomial_heap  sfml-graphics sfml-audio)
target_include_directories(binomial_heap PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testheap
        testheap.cpp
       heaprealization.cpp
        node.cpp
)
target_include_directories(testheap PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(testheap gtest gtest_main)

enable_testing()


add_test(NAME Testheap COMMAND testheap)