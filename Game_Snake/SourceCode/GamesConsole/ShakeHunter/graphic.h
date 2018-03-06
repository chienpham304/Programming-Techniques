
#ifndef _GRAPHIC_H
#define _GRAPHIC_H
#include "header.h"
// Graphics
//Tô màu
void textcolor(int x);
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);
//Thay đổi kích thước console 
void resizeConsole(int width, int height);
// Hàm xóa màn hình.
void CleanScreen();

#endif