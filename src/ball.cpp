#include "ball.h"
#include <iostream>

Ball::Ball()
{
    this->x = static_cast<float>(SCREEN_WIDTH) / 2;
    this->y = static_cast<float>(SCREEN_HEIGHT) / 2;
    this->radius = BALL_RADIUS;
    this->colour = WHITE;
    this->speed_x = BALL_XSPEED;
    this->speed_y = BALL_YSPEED;
}

void Ball::Draw() const
{
    DrawCircle((int)x, (int)y, radius, colour);
}

void Ball::Update()
{
    x += speed_x;
    y += speed_y;  

    if(y + BALL_RADIUS >= SCREEN_HEIGHT){
        speed_y *= -1;
    }
    
    if(y - BALL_RADIUS <= 0){
        speed_y *= -1;
    }

    if(x + BALL_RADIUS >= SCREEN_WIDTH){
        computerScore = true;
        ResetBall();        
    }

    if(x - BALL_RADIUS <= 0){
        playerScore = true;
        ResetBall();
    }

}

void Ball::ResetBall()
{
    x = static_cast<float>(SCREEN_WIDTH) / 2;
    y = static_cast<float>(SCREEN_HEIGHT) / 2;

    time_t seconds = time(NULL);
    if(seconds % 2 == 0 ){
        speed_x *= -1;
    }
    else{
        speed_x *= 1;
    }
    

}
