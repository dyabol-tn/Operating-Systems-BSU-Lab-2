cmake_minimum_required(VERSION 3.12)
project(OS_Laboratory_Work_2)

# Установка стандарта C++ (более современный способ)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исполняемого файла со всеми исходниками
add_executable(OS_Laboratory_Work_2 
    "main.cpp"
    "main.h"
    "min_max.cpp" 
    "min_max.h"
    "average.cpp"
    "average.h"
    "structure.h"
 "test_average.h" "test_min_max.h" "test_main.h" "test_average.cpp" "test_min_max.cpp" "test_main.cpp")

# Включение каталогов для заголовочных файлов
target_include_directories(OS_Laboratory_Work_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})