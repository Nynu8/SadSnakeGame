#include "GameController.h"
#include <windows.h>
#include <time.h>
#include <random>

bool run()
{
	//drawSnake();
	Sleep(moveDelay);
	return true;
}

void pickFoodSpot()
{
	int x, y;
	srand(time(NULL));
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
	body.first = new snakePart{ mapSize / 2, mapSize / 2 };
	drawMap();
	pickFoodSpot();
	while (run());
} 