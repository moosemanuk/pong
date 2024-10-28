#include "ball.h"
#include <iostream>

Ball::Ball()
{
    this->x = SCREEN_WIDTH / 2;
    this->y = SCREEN_HEIGHT / 2;
    this->radius = BALL_RADIUS;
    this->colour = white;
    this->speed_x = BALL_XSPEED;
    this->speed_y = BALL_YSPEED;
}

void Ball::draw() const
{
    DrawCircle(x, y, radius, colour);
}

void Ball::update()
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
        resetBall();        
    }

    if(x - BALL_RADIUS <= 0){
        playerScore = true;
        resetBall();
    }

}

void Ball::resetBall()
{
    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT / 2;

    time_t seconds = time(NULL);
    if(seconds % 2 == 0 ){
        speed_x *= -1;
    }
    else{
        speed_x *= 1;
    }
    

}
