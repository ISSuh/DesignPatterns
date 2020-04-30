project(BehavioralPatterns)

SET ( BEHAVIORAL_PATTERN_BUILD_DIR
    ${BUILD_DIR}/BehavioralPatterns
)

SET ( BEHAVIORAL_PATTERN_SAMPLES
    
)

foreach(SAMPLES ${BEHAVIORAL_PATTERN_SAMPLES})
    add_subdirectory(${SAMPLES})
endforeach()
