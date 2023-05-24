# Responsible for managing the my_math library

add_library(my_math src/Addition.cpp
                    src/Division.cpp)

# target    -> my_math
# scope     -> PUBLIC
# directory -> include (Where the header files are located

# This command makes it so that you don't have to include the relative path when using #include
# #include "../include/my_math/Addition.h" => #include "my_math/Addition.h"
target_include_directories(my_math PUBLIC include)

# Changing the scope to INTERFACE -> Will mean that 'Addition.cpp' won't be able to find 'Addition.h'
# Changing the scope to PRIVATE -> Will mean that 'main.cpp' won't be able to find 'Addition.h'