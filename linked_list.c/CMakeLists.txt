cmake_minimum_required(VERSION 3.6)
project(linked_list_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ajita.c)
add_executable(linked_list_c ${SOURCE_FILES})