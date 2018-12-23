#pragma once

struct snakePart {
	int x;
	int y;
	snakePart* next = nullptr;
};

struct snakeBody {
	snakePart* first;
};

enum class Direction {
	NORTH,
	WEST,
	SOUTH,
	EAST
};

Direction currentDirection;
snakeBody body;

void snakeChangeDirection(Direction);
void snakeMove();
void snakeBodyMove();
void snakeEat();
bool isOccupiedBySnake(int, int);