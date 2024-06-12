#include <raylib.h>
#include <iostream>
#include "ball.h"
#include "paddles.h"
#include "constants.h"

enum gameScreen {TITLE, GAME, GAMEOVER};

using namespace constants;

int main(){

    // pong!

    // game objects
    Ball ball;
    Paddle player;
    CPUPaddle computer;
    gameScreen currentScreen = TITLE;
    bool gamestart = true;

    // window parameters
    const int screen_width = 1280;
    const int screen_height = 800;
    const int target_fps = 60;

    // scoring
    int player_score = 0;
    int computer_score = 0;
    
    // colours
    Color white = {255,255,255,255};

    // load sounds
    InitAudioDevice();
    Sound pong_miss = LoadSound("pong_miss.mp3");
    Sound pong_hit = LoadSound("pong_hit.mp3");

    // game objects
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.radius = BALL_RADIUS;
    ball.colour = white;
    ball.speed_x = BALL_XSPEED;
    ball.speed_y = BALL_YSPEED;
    
    player.x = screen_width - 40;
    player.y = screen_height/2 - 60;
    player.width = PADDLE_WIDTH;
    player.height = PADDLE_HEIGHT;
    player.colour = white;
    
    computer.x = 20;
    computer.y = screen_height/2 - 60;
    computer.width = PADDLE_WIDTH;
    computer.height = PADDLE_HEIGHT;
    computer.colour = white;
    
    InitWindow(screen_width, screen_height, "pong");
    SetTargetFPS(target_fps);

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);

        if(gamestart){
            currentScreen = TITLE;
        }
        else if(player_score == 10 || computer_score == 10){
            currentScreen = GAMEOVER;
        }
        else{
            currentScreen = GAME;
        }

        switch(currentScreen){
            case TITLE:{
                DrawText("PONG", SCREEN_WIDTH/3, SCREEN_HEIGHT/2, 150, WHITE);
                DrawText("Press P to play", SCREEN_WIDTH/3, SCREEN_HEIGHT/3*2, 50, WHITE);
                if(IsKeyPressed(KEY_P)){
                    player_score = 0;
                    computer_score = 0;
                    gamestart = false;
                    currentScreen = GAME;                    
                } break;

            }
            case GAME:{                
                for(int i = 0; i < 800; i=i+35){
                    DrawRectangle(screen_width/2-10, i, 20, 20, white);
                }       

                ball.update();
                player.update();
                computer.update(ball.y);

                if(ball.playerScore){
                    PlaySound(pong_miss);
                    player_score++;
                    ball.playerScore = false;
                }
                if(ball.computerScore){
                    PlaySound(pong_miss);
                    computer_score++;
                    ball.computerScore = false;
                }

                // check collisions
                if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, 
                                        ball.radius, 
                                        Rectangle{player.x, player.y, player.width, player.height})){
                    PlaySound(pong_hit);
                    ball.speed_x *= -1;                      
                }
                
                if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, 
                                        ball.radius, 
                                        Rectangle{computer.x, computer.y, computer.width, computer.height})){
                    PlaySound(pong_hit);
                    ball.speed_x *= -1;                      
                }

                ball.draw();
                player.draw();
                computer.draw();

                DrawText(TextFormat("%i", computer_score), SCREEN_WIDTH/4-20, 20, FONT_SIZE, WHITE);
                DrawText(TextFormat("%i", player_score), (SCREEN_WIDTH/4)*3-20, 20, FONT_SIZE, WHITE);                
                
           } break;
           case GAMEOVER:{
                DrawText("GAME OVER", SCREEN_WIDTH/3, SCREEN_HEIGHT/2, 75, WHITE);
                if(computer_score == 10){                    
                    DrawText("Computer wins", SCREEN_WIDTH/3 - 40, SCREEN_HEIGHT/3, 75, WHITE);                    
                }
                else{
                    DrawText("Player wins", SCREEN_WIDTH/3 + 20, SCREEN_HEIGHT/3, 75, WHITE);
                } 
                DrawText("Press P to play again", SCREEN_WIDTH/3 - 50, SCREEN_HEIGHT/3*2, 50, WHITE); 
                if(IsKeyPressed(KEY_P)){
                    player_score = 0;
                    computer_score = 0;
                    currentScreen = GAME;                    
                }
           } break;
        }
        EndDrawing();
    }

    UnloadSound(pong_hit);
    UnloadSound(pong_miss);
    CloseAudioDevice();
    ClearBackground(BLACK);
    CloseWindow();
    return 0;

}