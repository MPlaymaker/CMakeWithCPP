CMake variables:

CMAKE_CURRENT_SOURCE_DIR	Absolute path to the current folder containing the CMakeLists.txt being processed. Useful for add_subdirectory() or including headers.
CMAKE_CURRENT_BINARY_DIR	Absolute path to the build folder corresponding to the current source folder. For example, if you have math/ in source, CMake will create build/math/ for object files.
CMAKE_SOURCE_DIR	Absolute path to the top-level source folder of the project. Useful for referring to project root from any subdirectory.
CMAKE_BINARY_DIR	Absolute path to the top-level build folder.

Example:

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/math)  # headers in this folder
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/math)    # add subfolder

2️⃣ Scope-related keywords
PARENT_SCOPE	When you set(VAR value PARENT_SCOPE), it exports the variable to the parent CMake scope. Used to propagate info from a subdirectory back to the root.
CACHE	When you do set(VAR value CACHE TYPE "description"), the variable is stored in CMake cache and can be reused or overridden later (e.g., cmake -DVAR=value ..). Common for options like BUILD_TESTS.
OPTION()	Creates a boolean cache variable that can be toggled by users. Example: option(USE_MYMATH "Use my math library" ON)
add_subdirectory()	Processes another folder with its own CMakeLists.txt. Variables in that subdirectory are local to that scope, unless you export them with PARENT_SCOPE.

3️⃣ Target-related keywords
Keyword	Meaning / Use
PRIVATE	For target_include_directories, target_link_libraries, or target_compile_definitions. Applies only to the current target.
PUBLIC	Applies to the current target and everything that links to it. Used for libraries.
INTERFACE	Applies only to consumers, not the target itself. Example: headers that a library exposes but doesn’t need to compile itself.

Example:

target_include_directories(MyLib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include  # users also get this include path
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src    # only MyLib sees this
)

4️⃣ File globbing / source listing
Command	Use
file(GLOB variable pattern)	Automatically find files matching a pattern. Example: file(GLOB SOURCES "src/*.cpp")
file(GLOB_RECURSE variable pattern)	Finds files recursively in subdirectories.
5️⃣ Other commonly used variables
Variable	Meaning
CMAKE_CXX_STANDARD	Set C++ standard (e.g., 11, 17, 20).
CMAKE_BUILD_TYPE	Build type (Debug, Release, RelWithDebInfo, MinSizeRel).
PROJECT_NAME	The name of the current project.
PROJECT_VERSION	Version of the project (if defined).

🔹 Summary

Paths: CMAKE_CURRENT_SOURCE_DIR, CMAKE_CURRENT_BINARY_DIR, CMAKE_SOURCE_DIR
Scope / variable passing: PARENT_SCOPE, CACHE
Subdirectory: add_subdirectory()
Target usage: PRIVATE, PUBLIC, INTERFACE
Source files: file(GLOB ...) or list manually

Build configuration: CMAKE_BUILD_TYPE, CMAKE_CXX_STANDARD

