#include "header.h"
int main(){
	diem first;
	first.x = X_Window / (2 * MaxRow)-3;
	first.y = Y_Window / (2 * MaxColum)+2;
	//======================
	textcolor(co_defaut);
	resizeConsole(X_Window, Y_Window);
	//=====================
	bool gameOver = false;
	bool victory=false;
	int size;
	int speed = Ogri_Speed;
	phamvi vitri;
	Queue que;
	char**map = Alloc2D(MaxRow, MaxColum);
	int FrontWay, RearWay;
	
	Introduction();
	while (gameOver == false && victory==false)
	{
		//Khởi trị
		map = Alloc2D(MaxRow, MaxColum);
		Init(que);
		size = 5;
		FrontWay = 4;
		RearWay = 4;//tren duoi trai phai = 1,2,3,4
		setMap(map, vitri, size, que);
		diem item = setItem(map, size, speed);
		gameOver = false;
		victory = false;
		//
		system("cls");
		textcolor(14);
		for (int i = 2; i >= 0; i--)
		{
			gotoxy(2, 2);
			cout << "Start in " << i << " seconds";
			Sleep(1000);
			system("cls");
		}
		gotoxy(1, 1);
		cout << "Go...\n<Dung phim mui ten de dieu khien> [ENTER] to start";
		PaintMap(map, vitri, first, size, speed);
		do{  Sleep(1000); } while (!GetAsyncKeyState(VK_RETURN));
		
		system("cls");
		///Start
		while (gameOver == false&&victory==false)
		{
			fflush(stdin);
			//cập nhật hướng đi
			EnWay2(FrontWay);
			//push dau, pop duoi
			RearWay = Pop(que);
			Push(que, FrontWay);

			Move(map, vitri, FrontWay, RearWay, que, gameOver, size, speed);

			PaintMap(map, vitri, first, size, speed);
			CleanScreen();
			Sleep(speed);
			//if (size >= (MaxRow - 2)*(MaxColum - 2))
			if (size >= (MaxRow - 3)*(MaxColum-3))
			{
				victory = true;
			}
		}
		if (victory == true)
			victory = RePlay(victory, "VICTORY");
		if (gameOver==TRUE)
			gameOver=RePlay(gameOver, "GAME OVER");
	}
		
	//sau khi game over
	system("cls");
	fflush(stdin);
	free(map);
	exit(0);
	return 0;
}