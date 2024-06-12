#pragma once
#include <raylib.h>
#include "constants.h"

using namespace constants;

class Paddle{
    private: 
        
    public:
        Paddle();
        float x;
        float y;
        float width;
        float height;
        float speed = PADDLE_SPEED;
        Color colour;
        void draw();
        void update();
        void limitMovement();
};

class CPUPaddle: public Paddle{
    private:

    public:
        CPUPaddle();
        void draw();
        void update(float ballHeight);
};

