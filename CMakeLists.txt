CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (DesignPatterns)

#-------------------------------------------------------------------------------
# Set Compiler
#-------------------------------------------------------------------------------
# SET( CMAKE_CXX_COMPILER g++ )
SET( CMAKE_CXX_STANDARD 11)
SET( CMAKE_CXX_STANDARD_REQUIRED ON )
ADD_COMPILE_OPTIONS ( -g -Wall )


#-------------------------------------------------------------------------------
# Set SubDirectory
#-------------------------------------------------------------------------------
add_subdirectory(src)

#-------------------------------------------------------------------------------
# Set gTest
#-------------------------------------------------------------------------------
include(cmake/googletest.cmake)

fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()

add_subdirectory(test)