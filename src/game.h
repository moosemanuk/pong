#pragma once

#include <raylib.h>
#include "ball.h"
#include "constants.h"
#include "paddles.h"

enum gameScreen { TITLE, GAME, GAMEOVER };

class Game
{
private:
	int computer_score = 0;
	int player_score = 0;
	bool gamestart = true;
	Ball ball;
	Paddle player;
	CPUPaddle computer;
	Sound pong_hit;
	Sound pong_miss;

public:
	Game();
	void Initialise();
	void ShowTitleScreen();
	void ShowGameScreen();
	void ShowGameOverScreen();
	void HandleEvents();
	void Draw();
	void Cleanup() const;
};
