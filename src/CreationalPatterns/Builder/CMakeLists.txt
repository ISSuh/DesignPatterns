project(builder)

message("Builder Pattern Example")

#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
SET( HEADERES
    builder.hpp
)

SET( SOURCES
    main.cpp
)

#-------------------------------------------------------------------------------
# Final target
#-------------------------------------------------------------------------------
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CREATIONAL_PATTERN_BUILD_DIR} )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERES})
target_link_libraries(${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "CreationalPatterns")
