#include "GameController.h"
#include <windows.h>
#include <time.h>
#include <random>
#include <conio.h>

#include <iostream>

food foodPosition;

bool run()
{
	if (_kbhit()) {
		char ch;
		bool inputHandled = false;
		while (_kbhit()) {
			ch = _getch();
			if (!inputHandled) {
				if (handleInput(ch)) {
					inputHandled = true;
				}
			}
		}
	}

	moveSnake();
	checkFood();
	drawSnake();
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
	body.first->next = new snakePart{ (mapSize / 2) - 1, mapSize / 2 };
	drawMap();
	pickFoodSpot();
	while (run());
} 

bool handleInput(char input)
{
	switch (input) {
		case 'w':
		case 72: if(currentDirection != Direction::SOUTH) currentDirection = Direction::NORTH; break;
		case 's':
		case 80: if (currentDirection != Direction::NORTH) currentDirection = Direction::SOUTH; break;
		case 'd':
		case 77: if (currentDirection != Direction::WEST) currentDirection = Direction::EAST; break;
		case 'a':
		case 75: if (currentDirection != Direction::EAST) currentDirection = Direction::WEST; break;
		default: return false;
	}

	return true;
}

void checkFood()
{
	if (body.first->x == foodPosition.x && body.first->y == foodPosition.y) {
		snakeEat();
		pickFoodSpot();
	}
}
