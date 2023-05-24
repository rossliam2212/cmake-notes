# CMake Notes

### CMakeLists.txt Composition
```cmake
command1(arg_a1, arg_a2, arg_a3 ...)

command2(arg_b1, arg_b2, arg_b3 ...)

command3(arg_a1,
        arg_a2,
        ...)

command4(arg_d1, arg_d2, arg_d3)
```

### CMake Commands
#### `add_executable(<exec_name> <source_files>)`

- This command is used when we want an executable at the end of the process.
- We have to provide the name of the final executable and the source files required to build the executable.
- The naming sequence of the source files does not matter, BUT the name of the executable must be the first argument.

#### `project(<project_name> VERSION <project_version)`
- This command states the name of the project, e.g. 'calculator'
- The version of the project is stated using 'VERSION <version>', e.g. 1.0.0

#### `cmake_minimum_required(VERSION <cmake_version>)`
- This command states the minimum required CMake version.
- We are telling CMake that all the features in the CMakeLists.txt are supported by that version.
- It is important to test with other versions of CMake to ensure the most amount of people can use it.

#### `add_library(<library_name> <source_files>)`

#### `target_link_libraries(<executable> <lib1> <lib2>)`
- This command links a library to an executable.

#### `message(<mode_of_display> "the message")`
- Modes of Message Display
  - message("Hello World")
  - message(STATUS "Hello World")
  - message(DEBUG "Hello World")
  - message(WARNING "Hello World")
  - message(FATAL ERROR "Hello World")
    
| Message Command                      | Output         |
|:-------------------------------------|:---------------|
| `message(NAME ${NAME} ${${NAME}}`    | NAMELiamJames  |
| `message(NAME${NAME}${${NAME}})`     | NAMELiamJames  |
| `message("NAME ${NAME} ${${NAME}}")` | AME Liam James |

#### `set(<variable_name> <variable_value>)`
- **NOTE:** All the variables in CMake are of string type
  - Variable De-referencing: `${variable_name}`
  - If you try to de-reference a variable that has not been set, it will give you an empty string

- Strings & Lists:
  - `set(NAME "Liam Ross")` -> String 'NAME' = Liam Ross
  - `set(NAME Liam Ross)`   -> List 'NAME' = Liam;Ross

- Quoted & Unquoted Arguments

| Set Commands              | Value of VAR | message(${VAR}) | message("${VAR}") |
|:--------------------------|:-------------|:----------------|:------------------|
| `set(VAR aa bb cc)`       | aa;bb;cc     | aabbcc          | aa;bb;cc          |
| `set(VAR aa;bb;cc)`       | aa;bb;cc     | aabbcc          | aa;bb;cc          |
| `set(VAR "aa" "bb" "cc")` | aa;bb;cc     | aabbcc          | aa;bb;cc          |
| `set(VAR "aa bb cc")`     | aa bb cc     | aa bb cc        | aa bb cc          |
| `set(VAR "aa;bb;cc")`     | aa;bb;cc     | aabbcc          | aa;bb;cc          |

#### `list<subcommand> <name_of_list ... ... ... <return_variable>)`
- The subcommand tells CMake which operation is to be performed
  - `APPEND`
  - `INSERT`
  - `FILTER`
  - `GET`
  - `JOIN`
  
- Setting a List variable:
```cmake
set(VAR a b c;d "e;f" 2.718 "Hello There")
#       0 1 2 3  4 5    6         7  (Indexes)
#      -8-7-6-5 -4-3   -2        -1  (Indexes Reversed)
```

- List Commands:
  - `APPEND`
  - `REMOVE_ITEM`
  - `REMOVE_AT`
  - `INSERT`
  - `REVERSE`
  - `REMOVE_DUPLICATES`
  - `SORT`

`set(VAR a b c;d "e;f" 2.718 "Hello There")`

| List Commands                 | Output                    |
|:------------------------------|:--------------------------|
| `list(APPEND VAR 1.6 XX)`     | abcdef2.7Hello There1.6XX |
| `list(REMOVE_AT VAR 2 -3)`    | abdef2.71.6XX             |
| `list(REMOVE_ITEM VAR a 2.7)` | bdef1.6XX                 |
| `list(INSERT VAR 2 XX 2.7)`   | bdXX2.7ef1.6XX            |
| `list(REVERSE VAR)`           | XX1.6fe2.7XXdb            |
| `list(REMOVE_DUPLICATES VAR)` | XX1.6fe2.7db              |
| `list(SORT VAR)`              | 1.62.7XXbdef              |

- Current List: 1.6; 2.7; XX; b; d; e; f 
- These set of subcommands return a value
- **NOTE:** The `FIND` subcommand will return -1 if the specified element was not found

| List Commands                     | Output                            |
|:----------------------------------|:----------------------------------|
| `list(LENGTH VAR len_var)`        | len_var = 7                       |
| `list(GET VAR 2 5 7 sub_list)`    | sub_list = XX;e;f                 |
| `list(SUBLIST VAR 2 3 sub_list2)` | sub_list2 = XX;b;d                |
| `list(JOIN VAR 0 str_var)`        | str_var = 1.6++2.7+XX++b++d++e++f |
| `list(FIND VAR find_var)`         | find_var = 2                      |

#### `string()`
- `FIND`
- `REPLACE`
- `PREPEND`
- `APPEND`
- `TOLOWER`
- `TOUPPER`
- `COMPARE`

```cmake
set(VAR "CMake for Cross-Platform C++ Projects")
string(FIND ${VAR} "for" find_var)
message(${find_var}) # Outputs -> 5 (Returns -1 if the substring is not found)

string(REPLACE "Projects" "Project" replaced_var ${VAR})
message(${replaced_var}) # Outputs -> CMake for Cross-Platform C++ Project

string(PREPEND replaced_var "Master")
message(${replaced_var}) # Outputs -> Master CMake for Cross-Platform C++ Project

string(APPEND replaced_var "Building")
message(${replaced_var}) # Outputs -> Master CMake for Cross-Platform C++ Project Building

set(UPPER_CASE_VAR "MASTER CMAKE FOR CROSS-PLATFORM C++ PROJECT BUILDING")
string(COMPARE ${UPPER_CASE_VAR} "MASTER CMAKE FOR CROSS-PLATFORM C++ PROJECT BUILDING" equality_check_var)
message(${equality_check_var}) # Outputs 1
```

