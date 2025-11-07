add_subdirectory(src)

# this tells to create a converters static library
add_library(converters SHARED ${CONVERTERS_SRC})

# this attaches the include directory for this library so that whoever links to this library automatically includes the headers
target_include_directories(converters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})