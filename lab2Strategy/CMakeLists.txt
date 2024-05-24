cmake_minimum_required(VERSION 3.28)
project(perfecthashing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(perfecthashing perfecthashing.cpp
        hashfunction.h
        hashfunction.cpp
        hashtable.h
        hashtable.cpp
        ihashstrategy.h
        ihashstrategy.cpp
        )
target_include_directories(perfecthashing PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testhash
        testhash.cpp
        hashfunction.cpp
        hashtable.cpp
        ihashstrategy.cpp
)
target_include_directories(testhash PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(testhash gtest gtest_main)

enable_testing()


add_test(NAME Testhash COMMAND testhash)