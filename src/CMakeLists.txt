PROJECT (DesignPatternsExamples)

#-------------------------------------------------------------------------------
# Set Analysis
#-------------------------------------------------------------------------------
SET ( CMAKE_CXX_CPPCHECK cppcheck )
SET ( CMAKE_CXX_CPPLINT cpplint)

#-------------------------------------------------------------------------------
# Set SubDirectory
#-------------------------------------------------------------------------------
SET ( BUILD_DIR ${CMAKE_SOURCE_DIR}/build/bin )

SET ( SAMPLES
    CreationalPatterns
    StructuralPatterns
    BehavioralPatterns
)

foreach(SAMPLE ${SAMPLES})
    add_subdirectory(${SAMPLE})
endforeach()