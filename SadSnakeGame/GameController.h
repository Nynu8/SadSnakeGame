#pragma once
#include "DrawingController.h"

constexpr int mapSize = 20;
constexpr int moveDelay = 500;	//ms

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