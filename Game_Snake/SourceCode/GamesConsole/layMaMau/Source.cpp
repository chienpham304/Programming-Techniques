#include <iostream>
#include <Windows.h>
#include <conio.h>
// H�m t� m�u.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void main(){

	for (int i = 0; i < 280; i++){
		textcolor(i);
		std::cout << "\t\t\tMa mau: " << i << "\t\t\t\t"<<std::endl;
	}
	_getch();
}