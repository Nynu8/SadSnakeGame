#pragma once

struct snakePart {
	int x;
	int y;
	snakePart* next = nullptr;
};

static struct snakeBody {
	snakePart* first;
}body;

static enum class Direction {
	NORTH,
	WEST,
	SOUTH,
	EAST
}currentDirection;

void snakeChangeDirection(Direction);
void snakeMove();
void snakeBodyMove();
void snakeEat();
bool isOccupiedBySnake(int, int);