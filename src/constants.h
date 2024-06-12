#pragma once
#include <raylib.h>

namespace constants
{
    // custom colours
    const Color white = {255,255,255,255};

    // screen
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 800;

    // game objects
    const float BALL_RADIUS = 15;
    const float BALL_XSPEED = 7; 
    const float BALL_YSPEED = 7; 
    const float PADDLE_WIDTH = 25;
    const float PADDLE_HEIGHT = 120;
    const float PADDLE_SPEED = 5;

    // score properties
    const int FONT_SIZE = 150;   
}