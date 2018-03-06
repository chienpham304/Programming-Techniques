//==========DEFINE POINT LIST==========
#ifndef _POINTLIST_H
#define _POINTLIST_H
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <malloc.h>
#include <Windows.h>

#include "Point.h"

struct NODE
{
	xPOINT data;
	NODE* pNext;
};

struct LIST
{
	NODE *pHead;
	NODE *pTail;
};
//=====================
float distanceNode(NODE *P1, NODE *P2);
//khoang cach theo truc
float distanceByOx(NODE* P1, NODE* P2);
float distanceByOy(NODE* P1, NODE* P2);
//Đối xứng
xPOINT symmetry(NODE P);
//Đối xứng qua Ox
xPOINT symmetryByOx(NODE P);
//Đối xứng qua Oy
xPOINT symmetryByOy(NODE P);
//Đối xứng qua phân giác I
xPOINT symmetrySparateI(NODE P);
//Đối xứng qua phân giác II
xPOINT symmetrySparateII(NODE P);
//Đếm số điểm hoành độ dương
int countPositiveAbsciss(LIST pList);
//Tìm điểm có tung độ max
NODE* maxOrdinate(LIST pList);
//Tìm điểm gần gốc tọa độ nhất
NODE* closestOrgin(LIST pList);
//=====================
//khởi tạo 1 node
NODE* getNode(xPOINT pt);
NODE* getNodeBefore(LIST pList, NODE *existNode);
//khởi tạo 1 danh sách
void initList(LIST &pList);
//kiểm tra 1 danh sách rỗng 
bool isEmptyList(LIST pList);
//Xuất List
void printList(LIST pList, char*s);
//Thêm
void addFirst(LIST &pList, NODE *p);
void addLast(LIST &pList, NODE *p);
//xóa
void deleteEnd(LIST &pList);
#endif