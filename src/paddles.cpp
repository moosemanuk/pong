#include "paddles.h"
#include "constants.h"

Paddle::Paddle()
{
    
}

void Paddle::draw()
{
    DrawRectangle(x, y, width, height, colour);
}

void Paddle::update()
{
    if(IsKeyDown(KEY_DOWN)){
        y += PADDLE_SPEED;        
    }

    if(IsKeyDown(KEY_UP)){
        y -= PADDLE_SPEED;        
    }
    limitMovement();
}

void Paddle::limitMovement()
{
    if(y <= 0){
        y =0;
    }
    if(y >= SCREEN_HEIGHT - PADDLE_HEIGHT){
        y = SCREEN_HEIGHT - PADDLE_HEIGHT;
    }
}

CPUPaddle::CPUPaddle()
{

}

void CPUPaddle::draw()
{
    DrawRectangle(x, y, width, height, colour);
}

void CPUPaddle::update(float ballHeight)
{
    if(y + PADDLE_HEIGHT/2 > ballHeight){
        y -= PADDLE_SPEED;
    }
    
    if(y + PADDLE_HEIGHT/2 <= ballHeight){
        y += PADDLE_SPEED;
    }
    limitMovement();    
}
