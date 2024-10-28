#include "game.h"

Game::Game()
{
    Initialise();
}

void Game::Initialise()
{
    InitAudioDevice();
    this->pong_miss = LoadSound("pong_miss.mp3");
    this->pong_hit = LoadSound("pong_hit.mp3");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "pong");
    SetTargetFPS(TARGET_FPS);

    this->gamestart = true;
}

void Game::ShowTitleScreen()
{
    DrawText("PONG", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, 150, PONGWHITE);
    DrawText("Press P to play", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 * 2, 50, PONGWHITE);
    if (IsKeyPressed(KEY_P))
    {
        this->player_score = 0;
        this->computer_score = 0;
        this->gamestart = false;        
    }
}

void Game::ShowGameScreen()
{
    for (int i = 0; i < 800; i = i + 35)
    {
        DrawRectangle(SCREEN_WIDTH / 2 - 10, i, 20, 20, WHITE);        
    }

    ball.Update();
    player.Update();
    computer.Update(ball.y);

    if (ball.playerScore)
    {
        PlaySound(pong_miss);
        this->player_score++;
        ball.playerScore = false;
    }

    if (ball.computerScore)
    {
        PlaySound(pong_miss);
        this->computer_score++;
        ball.computerScore = false;
    }

    if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y },
        ball.radius,
        Rectangle{ player.x, player.y, player.width, player.height })) {
        PlaySound(pong_hit);
        ball.speed_x *= -1;
    }

    if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y },
        ball.radius,
        Rectangle{ computer.x, computer.y, computer.width, computer.height })) {
        PlaySound(pong_hit);
        ball.speed_x *= -1;
    }

    ball.Draw();
    player.Draw();
    computer.Draw();

    DrawText(TextFormat("%i", computer_score), SCREEN_WIDTH / 4 - 20, 20, FONT_SIZE, WHITE);
    DrawText(TextFormat("%i", player_score), (SCREEN_WIDTH / 4) * 3 - 20, 20, FONT_SIZE, WHITE);
}

void Game::ShowGameOverScreen()
{
    DrawText("GAME OVER", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, 75, WHITE);
    if (this->computer_score == 10) {
        DrawText("Computer wins", SCREEN_WIDTH / 3 - 40, SCREEN_HEIGHT / 3, 75, WHITE);
    }
    else {
        DrawText("Player wins", SCREEN_WIDTH / 3 + 20, SCREEN_HEIGHT / 3, 75, WHITE);
    }
    DrawText("Press P to play again", SCREEN_WIDTH / 3 - 50, SCREEN_HEIGHT / 3 * 2, 50, WHITE);
    if (IsKeyPressed(KEY_P)) {
        this->player_score = 0;
        this->computer_score = 0;
        this->gamestart = false;
    }
}

void Game::HandleEvents()
{

}

void Game::Draw()
{
    if (gamestart)
    {
        ShowTitleScreen();
    }
    else if (player_score == 10 || computer_score == 10)
    {
        ShowGameOverScreen();
    }
    else
    {
        ShowGameScreen();
    }
}

void Game::Cleanup() const
{
    UnloadSound(pong_hit);
    UnloadSound(pong_miss);
    CloseAudioDevice();
    ClearBackground(BLACK);
}
