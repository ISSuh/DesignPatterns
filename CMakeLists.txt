CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
 
PROJECT (DesignPatterns)

SET ( CMAKE_CXX_STANDARD 11)

ADD_COMPILE_OPTIONS ( -g -Wall )

SET (BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/bin )

SET (SAMPLES
    CreationalPatterns
    StructuralPatterns
    BehavioralPatterns
)

foreach(SAMPLE ${SAMPLES})
    add_subdirectory(src/${SAMPLE})
endforeach()