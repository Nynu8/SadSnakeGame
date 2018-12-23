#include "GameController.h"
#include <windows.h>
#include <time.h>
#include <random>

bool run()
{
	drawSnake(&body);
	Sleep(moveDelay);
	return true;
}

void pickFoodSpot()
{
	int x, y;
	do {
		x = rand() % mapSize + 1;
		y = rand() % mapSize + 1;
	} while (isOccupiedBySnake(x, y));
	foodPosition.x = x;
	foodPosition.y = y;
	drawFood(); 
}

void startGame()
{
	drawMap();
	pickFoodSpot();
	while (run());
}