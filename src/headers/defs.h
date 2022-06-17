#ifndef DEFS_H
#define DEFS_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

constexpr unsigned short SCREEN_HEIGHT = 256;
constexpr unsigned short SCREEN_WIDTH = 240;
constexpr int TILE = 16;

constexpr unsigned int FRAMES = 80;
constexpr float SCREEN_LOAD_OFFSET = 5;

constexpr int MAX_JUMP = 20;
constexpr float JUMP_VELOCITY = -5.0f;

constexpr float GRAVITY_FACTOR = 1.8f;

constexpr float BASIC_ENEMY_SPEED = -0.6f;

constexpr float ITEM_COLL_WIDTH = 2.0f;
constexpr float ITEM_COLL_OFFSET = 3.0f; //to avoid sticking to the walls

constexpr int GUMBA = 10;
constexpr int COIN = 1;

constexpr int DIE_TIME = 2 * MAX_JUMP;
constexpr int PROTECTED_TIME = 100;

constexpr float FINISH = 1000;

#endif
