cmake_minimum_required(VERSION 3.21)
project(super_mario)

set(CMAKE_CXX_STANDARD 20)
IF(WIN32)
    set(SFML_ROOT "C:\\Pliki\\SFML_CLION\\SFML-2.5.1")
ENDIF()
add_executable(
        super_mario
        src/headers/defs.h src/Game.cpp src/headers/Game.h src/Level.cpp src/headers/Level.h src/Menu.cpp src/headers/Menu.h src/Item.cpp src/headers/Item.h src/MovingItem.cpp src/headers/MovingItem.h src/Brick.cpp src/headers/Brick.h src/BirickQuestionMark.cpp src/headers/BirickQuestionMark.h src/Mario.cpp src/headers/Mario.h src/Enemy.cpp src/headers/Enemy.h src/Turtle.cpp src/headers/Turtle.h src/Gumba.cpp src/headers/Gumba.h src/main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(super_mario ${SFML_LIBRARIES})
endif()