#include "Snake.h"

void snakeChangeDirection(Direction newDirection) 
{
	currentDirection = newDirection;
}

void snakeMove()
{
	switch (currentDirection) 
	{
		case Direction::NORTH: body.first->y++; break;
		case Direction::SOUTH: body.first->y++; break;
		case Direction::EAST: body.first->x++; break;
		case Direction::WEST: body.first->x--; break;
	}

	snakeBodyMove();
}

void snakeBodyMove()
{
	snakePart* tmp = body.first->next;
	while (tmp->next != nullptr) {
		tmp->x = tmp->next->x;
		tmp->y = tmp->next->y;
		tmp = tmp->next;
	}
}

void snakeEat()
{
	snakePart* tmp = body.first;
	while (tmp->next != nullptr)
		tmp = tmp->next;
	tmp->next = new snakePart{ tmp->x - 1, tmp->y };
}

bool isOccupiedBySnake(int x, int y)
{
	snakePart* tmp = body.first;
	if (tmp == nullptr)
		return false;
	while (tmp->next != nullptr) {
		if (x == tmp->x && y == tmp->y)
			return true;
		tmp = tmp->next;
	}

	return false;
}
