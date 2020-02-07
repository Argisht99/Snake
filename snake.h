#pragma once
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <random>
#include <time.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}


//void draw()
//{
//	system("cls");
//	for (int i = 0; i < height-1; ++i)
//	{
//		for (int j = 0; j < width-1; ++j)
//		{
//			if (i == 0 || i == height - 2|| j == 0 || j == width - 2)
//			{
//				std::cout << "#";
//			}
//			else
//			{
//				std::cout << " ";
//			}
//			if (i == y-2 && j == x-2)
//			{
//				cout << "A";
//			}
//			else if (i == fruitY && j == fruitX)
//			{
//				cout << "F";
//			}
//
//			else
//			{
//				cout << " ";
//			}
//			
//			
//		}
//		
//		cout << endl;
//	}
//
//}


void Draw()
{
	system("cls"); //sysytem ("clear");
	for (int i = 0; i < width + 2; ++i)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (j == 0)
			{
				cout << "#";
			}

			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				cout << "F";
			}

			else
			{
				cout << " ";
			}

			if (j == width - 1)
			{
				cout << "#";
			}

		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; ++i)
	{
		cout << "#";

	}
	cout << endl << "Your Score is:" << score << endl;
}


//void Draw()
//{
//	system("cls"); //sysytem ("clear");
//	for (int i = 0; i < width+2; ++i)
//	{
//		cout << "#";
//	}
//	cout << endl;
//
//	for (int i = 0; i < height; ++i)
//	{
//		for (int j = 0; j < width; ++j)
//		{
//			if (j == 0 )
//			{
//				cout << "#";
//			}
//
//			if (i == y && j == x)
//			{
//				cout << "O";
//			}
//			else if (i == fruitY && j == fruitX)
//			{
//				cout << "F";
//			}
//
//			else
//			{
//				cout << " ";
//			}
//
//			if (j == width - 1)
//			{
//				cout << "#";					
//			}
//			
//		}
//		cout << endl;
//	}
//
//	for (int i = 0; i < width+2; ++i)
//	{
//		cout << "#";
//	
//	}
//	cout <<endl<<"Your Score is:"<< score << endl;
//}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case'a':
			dir = LEFT;
			break;

		case'd':
			dir = RIGHT;
			break;

		case'w':
			dir = UP;
			break;

		case 's':
			dir = DOWN;
			break;

		case'e':
			gameOver = true;
			break;

		}


	}
}

//w
//ad
//s

void Logic()
{
	switch (dir)
	{

	case LEFT:
		--x;
		break;

	case RIGHT:
		++x;
		break;

	case UP:
		--y;
		break;

	case DOWN:
		++y;
		break;

	}
	if (x<0 || x>height || y<0 || y>width)
	{
		gameOver = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}


}
void cursor_off() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

//void gotoxy(short x, short y) {
//	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD position = { x, y };
//	SetConsoleCursorPosition(hStdout, position);
//}


