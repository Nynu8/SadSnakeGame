#pragma once

constexpr int mapSize = 21;
constexpr int moveDelay = 500;	//ms
static int score = 0;
static bool isPaused = false;
static bool gameOver = false;

struct food {
	int x;
	int y;
};

extern food foodPosition;

void startGame();
bool run();
void pickFoodSpot();
bool handleInput(char);
void checkFood();
bool isAlive();
void updateScore();
void exitGame();