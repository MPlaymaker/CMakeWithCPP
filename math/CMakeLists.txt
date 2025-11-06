add_subdirectory(src)

# This following line just forwards the variable to the parent scope
set(MATH_SOURCES
    ${MATH_SOURCES}
    PARENT_SCOPE
)