cmake_minimum_required(VERSION 3.23)
project(calculator VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

add_library(my_math Addition.cpp Division.cpp)
add_library(my_print Print.cpp)

add_executable(calculator main.cpp)
target_link_libraries(calculator my_math my_print)
