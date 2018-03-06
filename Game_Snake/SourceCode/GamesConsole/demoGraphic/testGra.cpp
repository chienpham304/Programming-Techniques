#include "doHoa.h"
#include <dos.h>
void main(){
	resizeConsole(1080, 720);
	/*errno_t err;
	FILE*f;
	err= fopen_s(&f,"GioiThieu.txt","r");
	if (err != 0)
		cout << "Error!!";
	else
	{
		while (!feof(f)){
			char c = fgetc(f);
			printf("\a");
			Sleep(20);
			textcolor(14);
			cout << c;
		}

			err = fclose(f);
	}*/
	textcolor(85);
	for (int i = 1; i <= 6; i++)
	{
		gotoxy(16, 4 + i);
		for (int j = 1; j < 50; j++)
		{
			cout << i;
		}
		cout << endl;
	}

	textcolor(95);
	gotoxy(34, 6);
	cout << "GAME OVER";
	gotoxy(25, 7);
	cout << "Do you want to play again ?";

	gotoxy(30, 9);
	cout << "Yes";
	gotoxy(45, 9);
	cout << "No";

	gotoxy(28, 9);
	cout << "->";
	//XoaManHinh();
	_getch();
	char c='y';
	do{
		if (GetAsyncKeyState(VK_RIGHT)){
			gotoxy(28, 9);
			cout << "  ";
			gotoxy(43, 9);
			cout << "->";
			c = 'n';
		}
		else if (GetAsyncKeyState(VK_LEFT)){
			gotoxy(43, 9);
			cout << "  ";
			gotoxy(28, 9);
			cout << "->";
			c = 'y';
		}
	} while (!GetAsyncKeyState(VK_RETURN));//vk_return là phím ENTER
	
	switch (c){
	case 'y':gotoxy(3, 12); cout << "Ban chon YES"; break;
	case 'n':gotoxy(3, 12); cout << "Ban chon NO"; break;
	default:gotoxy(3, 12); cout << "Ban chon CLGT"; break;
	}
	fflush(stdin);
	_getch();
}