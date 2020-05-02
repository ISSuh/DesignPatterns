project(abstract_factory)

message("Abstract Factory Pattern Example")

#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
SET( HEADERES
    abstract_factory.hpp
)

SET( SOURCES
    main.cpp
)

#-------------------------------------------------------------------------------
# Final target
#-------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CREATIONAL_PATTERN_BUILD_DIR} )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERES})
target_link_libraries(${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "CreationalPatterns")
