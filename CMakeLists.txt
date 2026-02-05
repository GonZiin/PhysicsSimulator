cmake_minimum_required(VERSION 3.10)

project(PhysicsSimulator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(main 
    main.cpp 
    core/WindowRenderer.cpp
    graphics/Circle.cpp
)

target_link_libraries(main ${SDL2_LIBRARIES})