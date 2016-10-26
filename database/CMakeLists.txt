cmake_minimum_required(VERSION 3.6)
project(database)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES invent.c readline.c)
add_executable(database ${SOURCE_FILES})