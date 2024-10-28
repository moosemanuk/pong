#include "paddles.h"
#include "constants.h"

Paddle::Paddle()
{
    this->x = SCREEN_WIDTH - 40;
    this->y = SCREEN_HEIGHT / 2 - 60;
    this->width = PADDLE_WIDTH;
    this->height = PADDLE_HEIGHT;
    this->colour = WHITE;
}

void Paddle::Draw() const
{
    DrawRectangle((int)x, (int)y, (int)width, (int)height, colour);
}

void Paddle::Update()
{
    if(IsKeyDown(KEY_DOWN)){
        this->y += PADDLE_SPEED;        
    }

    if(IsKeyDown(KEY_UP)){
        this->y -= PADDLE_SPEED;        
    }
    LimitMovement();
}

void Paddle::LimitMovement()
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
    this->x = 20;
    this->y = SCREEN_HEIGHT / 2 - 60;
    this->width = PADDLE_WIDTH;
    this->height = PADDLE_HEIGHT;
    this->colour = WHITE;
}

void CPUPaddle::Draw()
{
    DrawRectangle((int)x, (int)y, (int)width, (int)height, colour);
}

void CPUPaddle::Update(float ballHeight)
{
    if(this->y + PADDLE_HEIGHT/2 > ballHeight){
        this->y -= PADDLE_SPEED;
    }
    
    if(this->y + PADDLE_HEIGHT/2 <= ballHeight){
        this->y += PADDLE_SPEED;
    }
    LimitMovement();    
}
