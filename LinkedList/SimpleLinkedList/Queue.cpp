#include "Queue.h"

void initQueue(Queue &q)
{
	initList(q.qList);
}
bool isEmptyQueue(Queue q)
{
	if (isEmptyList(q.qList) == true)
	{
		//printf("EMpty Queue!");
		return true;
	}	
	return false;
}

//thêm giá trị của value vào đầu queue
void enQueue(Queue &q, int value)
{ 
	//thêm vào đầu
	addFirst(q.qList, getNode(value));
}

int deQueue(Queue &q)
{
	if (isEmptyQueue(q))
	{
		return MININT;
	}
	int result = q.qList.pTail->data;
	deleteEnd(q.qList);
	return result;
}
//lấy giá trị của phần tử đầu queue
int firstValueQueue(Queue q)
{
	if (isEmptyQueue(q))
		return MININT;
	return q.qList.pHead->data;
}
//lấy giá trị của phần tử cuối queue
int lastValueQueue(Queue q)
{
	if (isEmptyQueue(q))
		return MININT;
	return q.qList.pTail->data;
}
void closeQueue(QUEUE &q)
{
	destroyList(q.qList);
}