cmake_minimum_required(VERSION 3.28)
project(mainproject)

# Встановлюємо стандарт C++ на C++17
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

# Додаємо виконуваний файл основного проекту
add_executable(mainproject
        main.cpp
        logic.cpp
        piece.cpp
        board.cpp
        gameloop.cpp
        menu.cpp
        player.cpp
        move.cpp
        movenode.cpp
        drawobjects.cpp
        gamefacade.h
        piecestate.h
        piecestate.cpp
        observer.h
        observer.cpp
        gameobserver.h
        paralel.h
)
target_link_libraries(mainproject sfml-graphics sfml-audio)
# Підключаємо заголовкові файли основного проекту та бібліотеку Google Test
target_include_directories(mainproject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Додаткова настройка для тестів
add_executable(testproject
        testproject.cpp
        logic.cpp
        piece.cpp
        board.cpp
        gameloop.cpp
        menu.cpp
        player.cpp
        move.cpp
        movenode.cpp
        drawobjects.cpp
)

# Підключаємо заголовкові файли та бібліотеку Google Test для тестів
target_include_directories(testproject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Лінкуємо бібліотеку Google Test
target_link_libraries(testproject gtest gtest_main sfml-graphics sfml-audio)

# Включаємо можливість тестування
enable_testing()

# Додаємо команду для запуску тестів
add_test(NAME TestProject COMMAND testproject)
