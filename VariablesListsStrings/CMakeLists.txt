cmake_minimum_required(VERSION 3.23)

# This will cause an error because the project command is not scriptable
#project(variables-lists-strings VERSION 1.0.0)

message("Hello World") # Command: $ cmake -P CMakeLists.txt

set(NAME "Liam Ross")
set(HEIGHT 6)
message("Hello my name is ${NAME}, I am ${HEIGHT} foot tall")


set(NAME1 Liam)
set(Liam James)
message(NAME ${NAME1} ${${NAME1}}) # Prints -> NAMELiamJames
message(NAME${NAME1}${${NAME1}}) # Prints -> NAMELiamJames
message("NAME ${NAME1} ${${NAME1}}") # Prints -> NAME Liam James


# Lists
set(VAR a b c;d "e;f" 2.7 "Hello There")
list(APPEND VAR 1.6 XX)
message(${VAR}) # Prints -> abcdef2.7Hello There1.6XX

list(REMOVE_AT VAR 2 -3) # Removing the items at index 2 (c) & index -3 (Hello There)
message(${VAR}) # Prints -> abdef2.71.6XX

list(REMOVE_ITEM VAR a 2.7) # Removing a & 2.7 from the list
message(${VAR}) # Prints -> bdef1.6XX

list(INSERT VAR 2 XX 2.7) # Inserting XX & 2.7 at index 2
message(${VAR}) # Prints -> bdXX2.7ef1.6XX

list(REVERSE VAR) # Reversing the list
message(${VAR}) # Prints -> XX1.6fe2.7XXdb

list(REMOVE_DUPLICATES VAR) # Removing all duplicates from the list
message(${VAR}) # Prints -> XX1.6fe2.7db

list(SORT VAR) # Sorting the list
message(${VAR}) # Prints -> 1.62.7XXbdef
