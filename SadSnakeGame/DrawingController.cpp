#include "DrawingController.h"

#include <iostream>
#include <iomanip>
#include <Windows.h>

void drawGame()
{
	//set console size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, mapSize * 21, mapSize * 21, TRUE);

	//hide console cursor
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
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

	//drawing menu
	setCursorPosition(mapSize + 2, 1);
	std::cout << "Help:";
	setCursorPosition(mapSize + 2, 2);
	std::cout << "WSAD or arrow keys to move";
	setCursorPosition(mapSize + 2, 3);
	std::cout << "P to pause/resume";
	setCursorPosition(mapSize + 2, 4);
	std::cout << " Q to quit";
	setCursorPosition(mapSize + 2, 4);
	std::cout << "R to reset";
}

void drawFood()
{
	setCursorPosition(foodPosition.x, foodPosition.y);
	std::cout << "X";
}

void drawSnake()
{
	snakePart* tmp = body.first;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	setCursorPosition(tmp->x, tmp->y);
	std::cout << " ";

	setCursorPosition(body.first->x, body.first->y);
	std::cout << "O";
}

void setCursorPosition(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void displayUpdatedScore()
{

}