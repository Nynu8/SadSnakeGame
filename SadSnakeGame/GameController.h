#pragma once

constexpr int mapSize = 21;
extern int moveDelay;	//ms
extern int score;
extern bool isPaused;
extern bool gameOver;

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
void resetGame();