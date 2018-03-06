#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
// Hàm.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void main(){
	resizeConsole(1000, 600);
	
	errno_t err;
	FILE*f;
	err = fopen_s(&f, "GioiThieu.txt", "r+");
	if (err != 0)
		cout << "Error!!";
	else
	{
		cout << "(Press any key to skip)";
		
		while (!feof(f)){
			char c = fgetc(f);
			printf("\a");
			Sleep(60);
			textcolor(14);
			cout << c;
			if (_kbhit())//press any key
			{
				break;
			}
		}

		err = fclose(f);
	}
	_getch();
}