cmake_minimum_required(VERSION 3.21)
project(super_mario)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
#set(SDL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/SDL2-2.0.20/include)
#set(SDL2_LIBRARY ${CMAKE_SOURCE_DIR}/SDL2-2.0.20/lib/x64)

####set(CMAKE_MODULE_LINKER_FLAGS -lSDL2)
#set(CMAKE_MODULE_LINKER_FLAGS -lsfml-graphics -lsfml-window -lsfml-system)

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})


add_executable(
        super_mario
        #super_mario "Game Loop/game.cpp" "Game Loop/game.h" "Game Loop/main.cpp"
        src/headers/defs.h src/Game.cpp src/headers/Game.h src/Engine.cpp src/headers/Engine.h src/Level.cpp src/headers/Level.h src/Menu.cpp src/headers/Menu.h src/Object.cpp src/headers/Object.h src/MovingItem.cpp src/headers/MovingItem.h src/StillItem.cpp src/headers/StillItem.h src/Brick.cpp src/headers/Brick.h src/BirickQuestionMark.cpp src/headers/BirickQuestionMark.h src/Mario.cpp src/headers/Mario.h src/Enemy.cpp src/headers/Enemy.h src/Turtle.cpp src/headers/Turtle.h src/Gumba.cpp src/headers/Gumba.h src/main.cpp)


#find_package(SFML REQUIRED)
#target_link_libraries(super_mario sfml-graphics sfml-window sfml-system)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(super_mario ${SFML_LIBRARIES})
endif()