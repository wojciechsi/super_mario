cmake_minimum_required(VERSION 3.21)
project(super_mario)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
#set(SDL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/SDL2-2.0.20/include)
#set(SDL2_LIBRARY ${CMAKE_SOURCE_DIR}/SDL2-2.0.20/lib/x64)

set(CMAKE_MODULE_LINKER_FLAGS -lSDL2)

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})


add_executable(super_mario main.cpp Window.cpp Window.h)


find_package(SDL2 REQUIRED)
target_link_libraries(super_mario ${SDL2_LIBRARIES})