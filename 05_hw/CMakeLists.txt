cmake_minimum_required(VERSION 3.10)
project(stack)

# ������������� ����� ��� �������� ����
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

# ��������� ���������� ��� ���������� �����
add_library(stack stack.c)

# ��������� ����������� ���� main
add_executable(main main.c)
target_link_libraries(main stack)

# ��������� ����������� ���� ��� ������
add_executable(test test.c stack.c)
target_link_libraries(test stack)

# ��������� ����������� ���� ��� ����������
add_executable(benchmark benchmark.c stack.c)
target_link_libraries(benchmark stack)


