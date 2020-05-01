CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (DesignPatterns)

#-------------------------------------------------------------------------------
# Set Compiler
#-------------------------------------------------------------------------------
SET ( CMAKE_CXX_STANDARD 11)
ADD_COMPILE_OPTIONS ( -g -Wall )
SET ( CMAKE_CXX_CPPCHECK cppcheck )
SET ( CMAKE_CXX_CPPLINT cpplint)

#-------------------------------------------------------------------------------
# Set SubDirectory
#-------------------------------------------------------------------------------
SET (BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/bin )

SET (SAMPLES
    CreationalPatterns
    StructuralPatterns
    BehavioralPatterns
)

foreach(SAMPLE ${SAMPLES})
    add_subdirectory(src/${SAMPLE})
endforeach()

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