#pragma once
#include "DrawingController.h"

constexpr int mapSize = 20;
constexpr int moveDelay = 1000;

struct food {
	int x;
	int y;
}foodPosition;

void startGame();
bool run();
void pickFoodSpot();