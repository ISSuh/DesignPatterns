project(StructuralPatterns)

SET ( STRUCTURAL_PATTERN_BUILD_DIR
    ${BUILD_DIR}/StructuralPatterns
)

SET (STRUCTURAL_PATTERN_SAMPLES
    Adapter
    Bridge
    Composite
    Decorator
    Facade
    Flyweight
    Proxy
)

foreach(SAMPLES ${STRUCTURAL_PATTERN_SAMPLES})
    add_subdirectory(${SAMPLES})
endforeach()
