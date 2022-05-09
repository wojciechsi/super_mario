#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

constexpr unsigned short SCREEN_HEIGHT = 256;
constexpr unsigned short SCREEN_WIDTH = 240;

constexpr unsigned short MAX_LEVEL_SIZE = 1000;

constexpr double FRAME_TIME = 0.017;

constexpr int MAX_JUMP = 20;

constexpr float GRAVITY_FACTOR = 2.0f;

constexpr float ITEM_COLL_WIDTH = 1.0f;
constexpr float ITEM_COLL_OFFSET = 3.0f; //to avoid sticking to the walls

constexpr int GUMBA_KILLING = 10;