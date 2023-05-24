cmake_minimum_required(VERSION 3.23)
project(calculator VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(my_math_dir) # Tells CMake to go into these directories and find the CMakeLists.txt file in them
add_subdirectory(my_print_dir)

#add_library(my_math Addition.cpp Division.cpp) # Moved to my_math_dir/CMakeLists.txt
#add_library(my_print Print.cpp)                # Moved to my_print_dir/CMakeLists.txt

add_executable(calculator main.cpp)
target_link_libraries(calculator PRIVATE my_math my_print)
