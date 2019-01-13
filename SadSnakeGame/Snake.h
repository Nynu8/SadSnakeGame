#pragma once

struct snakePart {
	int x;
	int y;
	snakePart* next = nullptr;
};

extern struct snakeBody {
	snakePart* first;
} body;

extern enum class Direction {
	NORTH,
	WEST,
	SOUTH,
	EAST
} currentDirection;


void snakeChangeDirection(Direction);
void moveSnake();
void snakeBodyUpdate();
void snakeEat();
bool isOccupiedBySnake(int, int);
bool isSnakeEatingItself();