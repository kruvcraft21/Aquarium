cmake_minimum_required(VERSION 3.0.0)
project(Aquarium VERSION 0.1.0)

add_subdirectory(libs/raylib)

add_library(water_world STATIC
    src/water_entity.h
    src/water_entity.cpp
    src/aquarium.h
    src/aquarium.cpp
    src/fish.cpp
    src/fish.h
    src/rock.h
    src/rock.cpp)

target_link_libraries(water_world PUBLIC raylib)


IF(WIN32)
SET(GUI_TYPE WIN32)
ENDIF(WIN32)
# Set some Apple MacOS Specific settings
IF (APPLE)
SET(GUI_TYPE MACOSX_BUNDLE)
ENDIF (APPLE)

add_executable(${PROJECT_NAME} ${GUI_TYPE}
    main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    water_world)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
