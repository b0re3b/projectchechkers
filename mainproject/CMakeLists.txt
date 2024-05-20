cmake_minimum_required(VERSION 3.28)
project(mainproject)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(mainproject main.cpp
        logic.cpp
        logic.h
        piece.h
        piece.cpp
        board.h
        board.cpp
        gameloop.h
        gameloop.cpp
        menu.h
        menu.cpp
        TSET.cpp
)
target_link_libraries(mainproject gtest sfml-graphics sfml-audio)