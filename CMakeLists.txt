cmake_minimum_required(VERSION 3.8)
project(DataStructures)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c hash_table.c linked_list.c linked_list.h)
add_executable(DataStructures ${SOURCE_FILES})