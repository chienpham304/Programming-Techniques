#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <WinUser.h>
#include <iostream>
using namespace std;

//Tô màu
void textcolor(int x);

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);

//Thay đổi kích thước console 
void resizeConsole(int width, int height);

// Hàm xóa màn hình.
void XoaManHinh();