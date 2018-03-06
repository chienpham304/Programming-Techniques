#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <Windows.h>
#include <WinUser.h>
struct NODE
{
	int data;
	NODE* pNext;
};

struct LIST
{
	NODE *pHead;
	NODE *pTail;
};
//Bai 01: Xóa giá trị trùng
void delelteLoop(LIST &pList);

//Bai 02: Tách list thanh 2 list chan le
void separateIndex(LIST &pList, LIST &Even, LIST &Odd);

//Bai 03: Đảo ngược LIST
void reverseList(LIST &pList);

//Bai 04: sắp xếp tăng
void sortIncList(LIST &pList);

//Bai 05: sắp xếp giảm
void sortDecList(LIST &pList);


//========================================
//khởi tạo 1 node
NODE* getNode(int k);
//lấy địa chỉ node trước node exit
NODE* getNodeBefore(LIST pList, NODE *existNode);
//khởi tạo 1 danh sách
void initList(LIST &pList);

//hủy một LIST (xóa triệt để ô nhớ tránh rò rỉ thông tin)
void destroyList(LIST &pList);
//kiểm tra 1 danh sách rỗng 
bool isEmptyList(LIST pList);

//Thêm 1 node vào đầu list
void addFirst(LIST &pList, NODE *p);

//Thêm 1 node vào cuoi list
void addLast(LIST &pList, NODE *p);

//Thêm 1 node p vào sau node cho sẵn
void addAfter(LIST &pList, NODE *existNode, NODE *p);

//Thêm 1 node p vào truoc node cho sẵn
void addBefore(LIST &pList, NODE *existNode, NODE *p);

//Xóa phần tử đầu List
void deleteBegin(LIST &pList);

//Xóa phần tử cuoi List
void deleteEnd(LIST &pList);

//Xóa node bất kì ở giữa 
void deleteMiddle(LIST &pList, NODE *exist);

//Xuất List
void printList(LIST pList,char*s);

/*Hàm bổ sung*/

//Hàm đếm số phần từ
int lengthOfList(LIST pList);

//Hàm chèn 1 node p vào vị trí pos (chèn vào trước), tính từ [0...n-1]
void insertAt(LIST &pList, NODE *p, int pos);

//Hàm 1 phần từ tại vị trí xác định
void deleteAt(LIST &pList, int pos);

#endif