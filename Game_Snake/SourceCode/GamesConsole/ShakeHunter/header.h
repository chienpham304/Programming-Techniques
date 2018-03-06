#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <WinUser.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <processenv.h>
#include "graphic.h"
//sound include
#ifndef UNICODE
#define UNICODE
#endif

#pragma comment(lib, "winmm.lib")
//khai bao
#define X_Window 1050
#define Y_Window 680
#define MaxRow 30
#define MaxColum 70
#define Ogri_Speed 0
//color
#define co_backgroud 0
#define co_defaut 7
#define co_green 10
#define co_snake 236
#define co_map 104
#define co_item 31
//character
#define c_map char(176)
#define c_snake '@'
#define c_item '$'

using namespace std;
//===================
#include "Queue.h"
/*
typedef struct Queue
{
	int front;
	int rear;
	int count;
	int a[MaxRow];
}QUEUE;
void Init(Queue &q);
bool IsEmpty(Queue q);
bool IsFull(Queue q);
void Push(Queue& q, int n);//thêm phần tử vào cuối Queue 
void Push_Front(Queue& q, int n);//them phan tu n vao dau Queue 
int Pop(Queue&q);//lấy ra phần tử đầu tiên
int GetFirst(Queue q);

*/

//============================
typedef struct diem
{
	int x;
	int y;
}DIEM;
typedef struct phamvi
{
	diem dau;
	diem cuoi;
}PhamVi;

//function control
void Move(char**map, phamvi&p, int&FrontWay, int&RearWay, Queue &q,bool&,int&,int&);
void EnWay2(int&FrontWay);
void PaintMap(char**map, phamvi&p, diem FirstPoin, int size,int speed);

//setting
void setMap(char**map, phamvi &p, int &size, Queue&q);
diem setItem(char**map,int&size,int &speed);

//Alloc, free
char**Alloc2D(int m, int n);
void free(char**p);


/*Graphics
//Tô màu
void textcolor(int x);
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);
//Thay đổi kích thước console 
void resizeConsole(int width, int height);
// Hàm xóa màn hình.
void CleanScreen();

*/
/////////
void Introduction();
bool RePlay(bool&GameOver, char *s);
#endif