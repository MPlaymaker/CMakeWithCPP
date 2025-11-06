cmake_minimum_required(VERSION 3.10)
project(hello VERSION 1.0)

add_subdirectory(math)

#Here we are listing all the cpp files into the executable
add_executable(hello main.cpp ${MATH_SOURCES})

#Here we add the include directories
#When to use target_include_directories
#   Any headers in your project that are not in the same folder as the source file:

# We could have also done
#   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/math)
# This is old way, it Applies globally to all targets after the command.
# so, we use modern target_include_directories, which targets specific target with PRIVATE, PUBLIC etc notion

target_include_directories(hello PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/math)

