#include"snake.h"



int main()
{
	Setup();
	while (!gameOver)
	{
		cursor_off();

		Draw();
		Input();
		Logic();
		Sleep(25);
	}
	cin.get();
	return 0;
}
