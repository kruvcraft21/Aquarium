cmake_minimum_required(VERSION 3.0.0)
project(Aquarium VERSION 0.1.0)

add_subdirectory(libs/raylib)

add_library(water_world STATIC
    src/water_entity.h
    src/aquarium.h
    src/aquarium.cpp
    src/fish.cpp
    src/fish.h
    src/rock.h
    src/rock.cpp)

target_link_libraries(water_world PUBLIC raylib)

add_executable(Aquarium 
    main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    water_world)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
