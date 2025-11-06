# Define all .cpp files in this folder
# This following line forwards the cpp files to the parent scope
set(MATH_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/operations.cpp
    PARENT_SCOPE
)