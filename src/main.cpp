#include <raylib.h>
#include <iostream>
#include "ball.h"
#include "paddles.h"
#include "constants.h"
#include "game.h"

int main(){

    // pong!

    Game game;   

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();
        EndDrawing();
    }

    game.Cleanup();
    CloseWindow();
    return 0;

}