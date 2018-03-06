#include "Stack.h"

void initStack(Stack &sT)
{
	initList(sT.sList);
}
bool isEmptyStack(Stack sT)
{
	if (isEmptyList(sT.sList) == true)
	{
		//printf("Empty Stack!");
		return true;
	}
	return false;
}

//thêm giá trị của value vào đầu Stack
void topStack(Stack &sT, int value)
{
	//thêm vào đầu
	addFirst(sT.sList, getNode(value));
}

int popStack(Stack &sT)
{
	if (isEmptyStack(sT))
	{
		return MININT;
	}
	int result = sT.sList.pHead->data;
	deleteBegin(sT.sList);
	return result;
}
//lấy giá trị của phần tử đầu Stack
int firstValueStack(Stack sT)
{
	if (isEmptyStack(sT))
		return MININT;
	return sT.sList.pHead->data;
}
//lấy giá trị của phần tử cuối Stack
int lastValueStack(Stack sT)
{
	if (isEmptyStack(sT))
		return MININT;
	return sT.sList.pTail->data;
}
void closeStack(Stack &sT)
{
	destroyList(sT.sList);
}