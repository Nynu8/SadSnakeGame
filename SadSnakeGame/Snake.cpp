#include "Snake.h"

Direction currentDirection = Direction::EAST;
snakeBody body;

void snakeChangeDirection(Direction newDirection) 
{
	currentDirection = newDirection;
}

void moveSnake()
{
	snakeBodyUpdate();
	switch (currentDirection) 
	{
		case Direction::NORTH: body.first->y--; break;
		case Direction::SOUTH: body.first->y++; break;
		case Direction::EAST: body.first->x++; break;
		case Direction::WEST: body.first->x--; break;
	}
}

void snakeBodyUpdate()
{
	std::queue<snakePart> positions;
	snakePart* tmp = body.first;
	while (tmp->next != nullptr) {
		positions.push({ tmp->x, tmp->y });
		tmp = tmp->next;
	}

	tmp = body.first->next;
	while (!positions.empty())
	{
		snakePart pos = positions.front();
		positions.pop();
		tmp->x = pos.x;
		tmp->y = pos.y;
		tmp = tmp->next;
	}
}

void snakeEat()
{
	snakePart* tmp = body.first;
	while (tmp->next != nullptr)
		tmp = tmp->next;
	tmp->next = new snakePart{ tmp->x +100, tmp->y };
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

bool isSnakeEatingItself()
{
	snakePart* head = body.first;
	snakePart* tmp = head->next;
	while (tmp != nullptr && tmp->next != nullptr) {
		if (tmp->x == head->x && tmp->y == head->y)
			return true;
		tmp = tmp->next;
	}

	return false;
}