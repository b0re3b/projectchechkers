cmake_minimum_required(VERSION 3.28)
project(binominaltree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(binominaltree binomtree.cpp
        dpstrategy.h
        dpstrategy.cpp
        treetemplate.h
        treetemplate.cpp)


target_include_directories(binominaltree PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



add_executable(testbinom testbinom.cpp
        dpstrategy.cpp
        treetemplate.cpp
)
target_include_directories(testbinom PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(testbinom gtest gtest_main)

enable_testing()


add_test(NAME Testbinom COMMAND testbinom)
