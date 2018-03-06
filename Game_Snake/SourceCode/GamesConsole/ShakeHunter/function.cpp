#include "header.h"

using namespace std;
//lấy hướng đi của đầu, đuôi
void EnWay2(int&FrontWay){
	if (GetAsyncKeyState(VK_UP) && FrontWay != 2 && FrontWay != 1)
	{
		//Push(que, 1);
		FrontWay = 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) && FrontWay != 1 && FrontWay != 2)
	{
		//Push(que, 2);
		FrontWay = 2;
	}
	else if (GetAsyncKeyState(VK_LEFT) && FrontWay != 4 && FrontWay != 3)
	{
		//Push(que, 3);
		FrontWay = 3;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && FrontWay != 3 && FrontWay != 4)
	{
		//Push(que, 4);
		FrontWay = 4;
	}
	
}

//cập nhật đầu cuối
void Move(char**map, phamvi&p, int&FrontWay, int&RearWay, Queue &q, bool&gameOver, int&size,int&speed)
{
	bool getItem = false;
	map[p.cuoi.x][p.cuoi.y] = ' ';
	//Cập nhật vị trí đầu
	switch (FrontWay)//
	{
	case 1:
		if (p.dau.x - 1 <= 0 || map[p.dau.x - 1][p.dau.y] == c_snake || map[p.dau.x - 1][p.dau.y] == c_map)
		{
			gameOver = true;
			return;//ra khỏi mảng ko thể so sánh
		}
		else if (map[p.dau.x - 1][p.dau.y] == c_item)
		{
			size++;
			Push_Front(q, RearWay);
			setItem(map, size, speed);
			getItem = true;
		}
		p.dau.x--;
		break;//đi lên
	case 2:
		if (p.dau.x + 1 >= MaxRow - 1 || map[p.dau.x + 1][p.dau.y] == c_snake || map[p.dau.x + 1][p.dau.y] == c_map)
		{
			gameOver = true;
			return;//ra khỏi mảng ko thể so sánh
		}
		else 
		if (map[p.dau.x + 1][p.dau.y] == c_item)
		{
			size++;
			Push_Front(q, RearWay);
			setItem(map, size, speed);
			getItem = true;
		}
		p.dau.x++;
		break;//đi xuống
	case 3:
		if (p.dau.y - 1 <= 0 || map[p.dau.x][p.dau.y - 1] == c_snake || map[p.dau.x][p.dau.y - 1] == c_map)
		{
			gameOver = true;
			return;//ra khỏi mảng ko thể so sánh
		}
		else if (map[p.dau.x][p.dau.y - 1] == c_item)
		{
			size++;
			Push_Front(q, RearWay);
			setItem(map, size, speed);
			getItem = true;
		}
		p.dau.y--;
		break;//qua trái
	case 4:
		if (p.dau.y + 1 >= MaxColum - 1 || map[p.dau.x][p.dau.y + 1] == c_snake || map[p.dau.x][p.dau.y + 1] == c_map)
		{
			gameOver = true;
			return;//ra khỏi mảng ko thể so sánh
		}
		else if (map[p.dau.x][p.dau.y + 1] == c_item)
		{
			size++;
			Push_Front(q, RearWay);
			setItem(map, size, speed);
			getItem = true;
		}
		p.dau.y++;
		break;//qua phai
	}
	
	//cập nhật vị trí đuôi
	if (!getItem)//không ăn item mới được xóa đuôi
	switch (RearWay)
	{
		case 1:p.cuoi.x--; break;//đuôi đi lên
		case 2:p.cuoi.x++; break;//đuôi đi xuống
		case 3:p.cuoi.y--; break;//đuôi qua trái
		case 4:p.cuoi.y++; break;//đuôi qua phải
	}
	//cập nhật đầu
	map[p.dau.x][p.dau.y] = c_snake;
}

//vẽ map
void PaintMap(char**map, phamvi&p, diem First, int size,int speed){
	//ve map
	
	for (int i = 0; i < MaxRow; i++)
	{
		gotoxy(First.x, First.y + i);
		for (int j = 0; j < MaxColum; j++)
		{
			//if (i == 0 || i == MaxRow - 1 || j == 0 || j == MaxColum - 1){
			if (map[i][j]==c_map){
				textcolor(co_map);
			}
			else
			{
				textcolor(co_defaut);
			}
			if (map[i][j] == c_snake)
				textcolor(co_snake);

			if (map[i][j] == c_item)
				textcolor(co_item);
			cout << map[i][j];
		}
		cout << endl;
		
	}
	gotoxy(First.x, First.y +MaxRow);
	textcolor(10);
	cout << "Score: " << setw(4) << size-5;// << "                             Speed:" << setw(4) << 1 - (-Ogri_Speed + speed) / 5 << endl;
	gotoxy(First.x, First.y + MaxRow+1);
	cout << "Speed: " << setw(4) << (size-5)/5+1;
	textcolor(co_defaut);
	
}

//cấp phát mảng 2 chiều 
char**Alloc2D(int m, int n){
	char**a;
	a = (char**)calloc(m, sizeof(char*));
	if (a == NULL)
		return NULL;
	for (int i = 0; i < m; i++)
	{
		a[i] = (char*)calloc(n, sizeof(char));
		if (a[i] == NULL)
		{
			return NULL;
		}
	}
	return a;
}

//khởi tạp map
void setMap(char**map, phamvi&p,int &size,Queue&q){
	int x = MaxRow/3-2, y = MaxColum/3+5;

	for (int i = 0; i < MaxRow; i++)
		for (int j = 0; j < MaxColum; j++)
			map[i][j] = ' ';

	for (int i = 0; i < MaxRow; i++)
	{
		for (int j = 0; j < MaxColum; j++)
		{
			if (i == 0 || i == MaxRow - 1 || j == 0 || j == MaxColum - 1)
				map[i][j] = c_map;
			else
				/*if (i == MaxRow/2)
				{
				if (j != 1 && j && j!= MaxColum-2 && j!=MaxColum/2-1)
				map[i][j] = c_map;
				}*/
			if (i == x)
			{
				if ((j >= y&&j<=y+1) || (MaxColum - y - 5 <= j && j <= MaxColum - y + 4))
					map[i][j] = c_map;
			}
			else if (i>x && i<MaxRow-x)
			{
				if ((j >= y&&j <= y + 1) || j == MaxColum - y||j==MaxColum-y-1)
					map[i][j] = c_map;
			}
		}
	}
	p.cuoi.x = 1; p.dau.x = 1;
	p.cuoi.y = 1; p.dau.y = size;
	for (int i = 1; i <= p.dau.y; i++)
	{
		map[1][i] = c_snake;
		if (i!=1)
		Push(q, 4);
	}

}

//cài tọa độ item
diem setItem(char**map,int&size,int &speed){
	//item(x,y) phải random trong map (1->MaxRow-2)x(1->MaxColum-2)
	// khong được trùng với rắn
	int x, y;
	do{
		srand(time(NULL));
		x = rand() % (MaxRow - 2) + 1;//dư[0..MaxRow-3]+1
		y = rand() % (MaxColum - 2) + 1;//dư[0..MaxColum-3]+1
	} while (map[x][y] == c_map || map[x][y] == c_snake || x <= 0 || x >= MaxRow - 1 || y <= 0 || y >= MaxColum - 1);
	//while (map[x][y] == c_snake || x <= 0 || x >= MaxRow - 1 || y <= 0 || y >= MaxColum - 1);
	diem item;
	item.x = x;
	item.y = y;
	map[x][y] = c_item;
	if ((speed - 10)>0)
		speed -= 10;
	return item;
}
void free(char**p){
	for (int i = 0; i < MaxRow; i++)
		free(*(p + i));
}

///
void Introduction()
{
#ifndef UNICODE
#define UNICODE
#endif
#ifndef WINDOWS_H
#define WINDOWS_H
#endif
#pragma comment(lib, "winmm.lib")
	//Sound
		//SND_FILENAME: tuần tự
		// SND_ASYNC: song song
		//bool isPlay = PlaySound(L"STDIO_SOUND_LOGO.wav", NULL, SND_FILENAME);
		bool isPlay = PlaySound("INTRO_TRACK.wav", NULL, SND_ASYNC);
	//text
	errno_t err;
	FILE*f;
	err = fopen_s(&f, "Introduction.txt", "r");
	if (err != 0)
		std::cout << "Error!!";
	else
	{
		
		while (!feof(f)&& !GetAsyncKeyState(VK_SPACE))
		{
			char c = fgetc(f);
			printf("\a");
			Sleep(2);
			textcolor(co_green);
			std::cout << c;
		}
		err = fclose(f);
	}
	_getch();
	cout << endl << "                             <Press SPACE key to continue>";
	do{ Sleep(300); } while (!GetAsyncKeyState(VK_SPACE));
	fflush(stdin); fflush(stdin);
}
bool RePlay(bool&GameOver,char *s)
{
	GameOver = false;
	system("cls");
	textcolor(85);
	for (int i = 1; i <= 6; i++)
	{
		gotoxy(18, 4 + i);
		for (int j = 1; j < 50; j++)
		{
			cout << i;
		}
		cout << endl;
	}

	textcolor(95);
	gotoxy(36, 6);
	cout << s;
	gotoxy(27, 7);
	cout << "Do you want to play again ?";

	gotoxy(32, 9);
	cout << "Yes";
	gotoxy(47, 9);
	cout << "No";

	gotoxy(30, 9);
	cout << "->";
	//XoaManHinh();
	_getch();
	do{
		if (GetAsyncKeyState(VK_RIGHT)){
			gotoxy(30, 9);
			cout << "  ";
			gotoxy(45, 9);
			cout << "->";
			GameOver = TRUE;
		}
		else if (GetAsyncKeyState(VK_LEFT)){
			gotoxy(45, 9);
			cout << "  ";
			gotoxy(30, 9);
			cout << "->";
			GameOver = FALSE;
		}
	} while (!GetAsyncKeyState(VK_RETURN));//vk_return là phím ENTER

	fflush(stdin);
	fflush(stdin);
	fflush(stdin);
	return GameOver;
}