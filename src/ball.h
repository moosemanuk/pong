#pragma once
#include <raylib.h>
#include <time.h>
#include "constants.h"

using namespace constants;

class Ball{
    private:
        
    public:
        float x;
        float y;
        float radius; 
        float speed_x;
        float speed_y;
        bool playerScore = false;
        bool computerScore = false;
        Color colour;
        Ball();
        void draw();
        void update();
        void resetBall();


};