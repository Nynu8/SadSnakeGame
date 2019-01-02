#pragma once
#include "DrawingController.h"
#include "Snake.h"

constexpr int mapSize = 21;
constexpr int moveDelay = 500;	//ms
static int score = 0;

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