cmake_minimum_required(VERSION 3.14)
project(OS_Laboratory_Work_2)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение FetchContent для загрузки Google Test
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# Для Windows: предотвращение переопределения настроек компилятора
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Загрузка Google Test
FetchContent_MakeAvailable(googletest)

# Основной исполняемый файл
add_executable(OS_Laboratory_Work_2 
    "main.cpp"
    "main.h"
    "min_max.cpp" 
    "min_max.h"
    "average.cpp"
    "average.h"
    "structure.h"
)

# Включение каталогов для заголовочных файлов
target_include_directories(OS_Laboratory_Work_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Исполняемый файл для тестов
add_executable(OS_Laboratory_Work_2_Tests
    "test_average.cpp"
    "test_min_max.cpp" 
    "test_main.cpp"
    "average.cpp"
    "min_max.cpp"
)

# Включение каталогов для заголовочных файлов тестов
target_include_directories(OS_Laboratory_Work_2_Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Линковка с Google Test
target_link_libraries(OS_Laboratory_Work_2_Tests gtest gtest_main)

# Включение тестов
enable_testing()
add_test(NAME OS_Laboratory_Work_2_Tests COMMAND OS_Laboratory_Work_2_Tests)