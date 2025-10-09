# CMakeList.txt: проект CMake для OS_Laboratory_Work_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (OS_Laboratory_Work_2 "main.cpp" "main.h" "min_max.cpp" "min_max.h" "average.cpp" "average.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OS_Laboratory_Work_2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
