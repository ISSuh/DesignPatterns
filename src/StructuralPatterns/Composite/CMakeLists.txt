project(composite)

message("Composite Pattern Example")

#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
SET( HEADERES
    composite.hpp
)

SET( SOURCES
    main.cpp
)

#-------------------------------------------------------------------------------
# Final target
#-------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${STRUCTURAL_PATTERN_BUILD_DIR} )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERES})
target_link_libraries(${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "StructuralPatterns")
