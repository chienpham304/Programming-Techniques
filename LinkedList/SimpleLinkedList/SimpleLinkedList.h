#ifndef _SIMPLELINKEDLIST_H
#define _SIMPLELINKEDLIST_H
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <Windows.h>
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
void printList(LIST pList);

/*Hàm bổ sung*/

//Hàm đếm số phần từ
int lengthOfList(LIST pList);

//Hàm chèn 1 node p vào vị trí pos (chèn vào trước), tính từ [0...n-1]
void insertAt(LIST &pList, NODE *p, int pos);

//Hàm 1 phần từ tại vị trí xác định
void deleteAt(LIST &pList, int pos);
//đảo ngược list
void reverse(LIST &l);
#endif