#include "header.h"
#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct Queue
{
	int front;
	int rear;
	int count;
	int a[(MaxRow - 2)*(MaxColum - 2)];
}QUEUE;

void Init(Queue &q);
bool IsEmpty(Queue q);
bool IsFull(Queue q);
void Push_Front(Queue& q, int n);
void Push(Queue& q, int n);//thêm phần tử vào cuối Queue 
int Pop(Queue&q);//lấy ra phần tử đầu tiên
int GetFirst(Queue q);

#endif