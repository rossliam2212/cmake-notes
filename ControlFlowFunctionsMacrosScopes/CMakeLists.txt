cmake_minimum_required(VERSION 3.23)

set(VAR YES)
if(VAR)
    message("If block executed")
else()
    message("Else block executed")
endif()


set(VAR "")
if(VAR)
    message("If block executed")
else()
    message("Else block executed")
endif()


# Unary Tests
set(NAME Liam)
if(DEFINED NAME)
    message("Name: if block executed")
else()
    message("Name: else block executed")
endif()

if(DEFINED AGE)
    message("Age: if block executed")
else()
    message("Age: else block executed")
endif()


if(COMMAND target_link_libraries)
    message("target_link_libraries IS a command")
else()
    message("target_link_libraries is NOT a command")
endif()


if(EXISTS /Users/liam/Coding/cppProjects/cmake_course/ControlFlowFunctionsMacrosScopes/CMakeLists.txt)
    message("File exists")
else()
    message("File does not exist")
endif()


# Binary Tests
set(Name1 Liam)
set(Name2 Brian)

if(Name1 STRLESS Name2)
    message("${Name1} is less than ${Name2}")
elseif(Name1 STRGREATER Name2)
    message("${Name1} is greater than ${Name2}")
else()
    message("${Name1} is equal to ${Name2}")
endif()


# While Loop
set(VAR a)
while(NOT VAR STREQUAL "aaaaaaaaaa")
    set(VAR ${VAR}a)
    message(${VAR})
endwhile()

# Foreach Loop
foreach(Name Liam Erin Gerard)
    message(${Name})
endforeach()