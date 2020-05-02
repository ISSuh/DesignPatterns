project(CreationalPatterns)

SET ( CREATIONAL_PATTERN_BUILD_DIR
    ${BUILD_DIR}/CreationalPatterns
)

SET ( CREATIONAL_PATTERN_SAMPLES
    Abstract_Factory
    Builder
    Factory_Method
    Prototype
)

foreach(SAMPLES ${CREATIONAL_PATTERN_SAMPLES})
    add_subdirectory(${SAMPLES})
endforeach()
