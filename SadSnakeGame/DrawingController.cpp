#include "DrawingController.h"

#include <iostream>
#include <iomanip>
#include <Windows.h>

void drawMap()
{
	for (int i = 0; i <= mapSize+1; i++) {
		setCursorPosition(i, 0);
		std::cout << "#";
		setCursorPosition(0, i);
		std::cout << "#";
		setCursorPosition(i, mapSize+1);
		std::cout << "#";
		setCursorPosition(mapSize+1, i);
		std::cout << "#";
	}
}

void drawFood()
{
	setCursorPosition(foodPosition.x, foodPosition.y);
	std::cout << "x";
}

void drawSnake()
{
	snakePart* tmp = body.first;
	setCursorPosition(tmp->x, tmp->y);
	std::cout << "o";
	while (tmp->next != nullptr)
		tmp = tmp->next;
	setCursorPosition(tmp->x, tmp->y);
	std::cout << "o";
}

void setCursorPosition(int x, int y) {
	COORD pos = { x*2, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}