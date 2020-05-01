CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (DesignPatterns)

#-------------------------------------------------------------------------------
# Set Compiler
#-------------------------------------------------------------------------------
SET ( CMAKE_CXX_STANDARD 11)
SET ( CMAKE_CXX_CPPCHECK cppcheck )
SET ( CMAKE_CXX_CPPLINT cpplint)
ADD_COMPILE_OPTIONS ( -g -Wall )

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

add_subdirectory(test)