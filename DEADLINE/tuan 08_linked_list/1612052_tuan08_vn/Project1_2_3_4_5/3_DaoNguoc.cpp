#include "LinkedList.h"

//đảo ngược list
void reverseList(LIST &pList)
{
	if (isEmptyList(pList))
	{
		printf("\nCannot reverse [Error]: Empty List!!");
		return;
	}
	else if (pList.pHead == pList.pTail)//list co 1 node
	{
		return;
	}
	else if (pList.pHead->pNext == pList.pTail)//list co 2 node
	{
		pList.pTail->pNext = pList.pHead;

		pList.pHead = pList.pTail;
		pList.pTail = pList.pHead->pNext;

		pList.pTail->pNext = NULL;
	}
	else //list có 3 node trở lên
	{
		NODE *tmpTail = pList.pHead;
		NODE *parent = pList.pHead;
		NODE *pFlag = pList.pHead->pNext;
		pList.pHead = pFlag->pNext;
		parent->pNext = NULL;
		pFlag->pNext = parent;
		while (pList.pHead->pNext != NULL)
		{
			parent = pFlag;
			pFlag = pList.pHead;
			pList.pHead = pList.pHead->pNext;
			pFlag->pNext = parent;
		}
		pList.pHead->pNext = pFlag;
		pList.pTail = tmpTail;
	}
}