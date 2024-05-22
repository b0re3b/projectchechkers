cmake_minimum_required(VERSION 3.28)
project(obstree)

# Встановлюємо стандарт C++ на C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Підключаємо бібліотеку Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Додаємо виконуваний файл основного проекту
add_executable(obstree
        main.cpp
        obstree.cpp
        RecursiveStrategy.h
        TreeConstructionStrategy.h
)

# Підключаємо заголовкові файли основного проекту та бібліотеки Google Test
target_include_directories(obstree PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Додаткова настройка для тестів
add_executable(testfortree
        tyiu.cpp
        obstree.cpp
        RecursiveStrategy.h
        TreeConstructionStrategy.h
)

# Підключаємо заголовкові файли та бібліотеки Google Test для тестів
target_include_directories(testfortree PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Лінкуємо бібліотеки Google Test
target_link_libraries(testfortree gtest gtest_main)

# Включаємо можливість тестування
enable_testing()

# Додаємо команду для запуску тестів
add_test(NAME TestForTree COMMAND testfortree)
