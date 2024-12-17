cmake_minimum_required(VERSION 3.10)
project(stack)

# Устанавливаем флаги для покрытия кода
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

# Добавляем библиотеку для реализации стека
add_library(stack stack.c)

# Добавляем исполняемый файл main
add_executable(main main.c)
target_link_libraries(main stack)

# Добавляем исполняемый файл для тестов
add_executable(test test.c stack.c)
target_link_libraries(test stack)

# Добавляем исполняемый файл для бенчмарков
add_executable(benchmark benchmark.c stack.c)
target_link_libraries(benchmark stack)


