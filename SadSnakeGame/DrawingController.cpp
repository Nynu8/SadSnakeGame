#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "DrawingController.h"
#include "GameController.h"
#include "Snake.h"

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void drawGame()
{
	//set console size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, mapSize * 21, mapSize * 21, TRUE);

	//hide console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);

	//change font size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.Y = 17;
	cfi.dwFontSize.X = 17;
	cfi.FontFamily = FF_DECORATIVE;
	cfi.FontWeight = FW_BOLD;
	SetCurrentConsoleFontEx(out, FALSE, &cfi);

	//drawing map borders
	SetConsoleTextAttribute(out, 12);
	for (int i = 0; i <= mapSize; i++) {
		setCursorPosition(i, 0);
		std::cout << '#';
		setCursorPosition(0, i);
		std::cout << '#';
		setCursorPosition(i, mapSize);
		std::cout << '#';
		setCursorPosition(mapSize, i);
		std::cout << '#';
	}
	SetConsoleTextAttribute(out, 12);
	
	//drawing score
	SetConsoleTextAttribute(out, 8);
	for (int i = 0; i < 12; i++) {
		setCursorPosition(mapSize + 2 + i, 0);
		std::cout << '#';
	}

	for (int i = 0; i < 12; i++) {
		setCursorPosition(mapSize + 2 + i, 2);
		std::cout << '#';
	}

	setCursorPosition(mapSize + 2, 1);
	std::cout << "#SCORE: 0  #";

	//drawing menu
	setCursorPosition(mapSize + 2, 5);
	std::cout << "Help:";
	setCursorPosition(mapSize + 2, 6);
	std::cout << "WSAD or arrow keys to move";
	setCursorPosition(mapSize + 2, 7);
	std::cout << "P to pause/resume";
	setCursorPosition(mapSize + 2, 8);
	std::cout << "Q to quit";
	setCursorPosition(mapSize + 2, 9);
	std::cout << "R to reset";
}

void drawFood()
{
	SetConsoleTextAttribute(out, 6);
	setCursorPosition(foodPosition.x, foodPosition.y);
	std::cout << 'X';
	SetConsoleTextAttribute(out, 11);
}

void drawSnake()
{
	snakePart* tmp = body.first;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	setCursorPosition(tmp->x, tmp->y);
	std::cout << " ";

	SetConsoleTextAttribute(out, 10);
	setCursorPosition(body.first->x, body.first->y);
	std::cout << 'O';
	SetConsoleTextAttribute(out, 11);
}

void setCursorPosition(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void displayUpdatedScore(int score)
{
	SetConsoleTextAttribute(out, 8);
	setCursorPosition(mapSize + 10, 1);
	std::cout << score;
	SetConsoleTextAttribute(out, 11);
}