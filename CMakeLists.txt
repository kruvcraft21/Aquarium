cmake_minimum_required(VERSION 3.0.0)
project(Aquarium VERSION 0.1.0)

add_subdirectory(libs/raylib)

add_executable(Aquarium main.cpp)

target_link_libraries(${PROJECT_NAME} raylib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
