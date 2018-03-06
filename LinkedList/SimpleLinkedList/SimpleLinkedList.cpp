#include "SimpleLinkedList.h"

NODE* getNode(int k)
{
	NODE *p = NULL;
	p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL)
	{
		printf("Error: Not enough memory!!");
		_getch();
		exit(0);
	}
	p->data = k;
	p->pNext = NULL;
	return p;
}

NODE* getNodeBefore(LIST pList, NODE *existNode)
{
	NODE *tmp = pList.pHead;
	for (tmp; tmp->pNext != existNode; tmp = tmp->pNext)
		if(tmp->pNext == NULL)
			return NULL;
	return tmp;
}

void initList(LIST &pList)
{
	pList.pHead = NULL;
	pList.pTail = NULL;
}

void destroyList(LIST &pList)
{ 
	//xoa tung node mot
	while (pList.pHead != NULL)
	{
		NODE *pTmp = pList.pHead;
		pList.pHead = pList.pHead->pNext;
		free(pTmp);
	}
}

bool isEmptyList(LIST pList)
{
	if (pList.pHead == NULL)
		return true;
	return false;
}

void addFirst(LIST &pList, NODE *p)
{
	if (isEmptyList(pList))
	{
		pList.pHead = pList.pTail = p;
	}
	else
	{
		p->pNext = pList.pHead;
		pList.pHead = p;
	}
}

void addLast(LIST &pList, NODE *p)
{
	if (isEmptyList(pList))
	{
		pList.pHead = pList.pTail = p;
	}
	else
	{
		pList.pTail->pNext = p;
		pList.pTail = p;

	}
}

void addAfter(LIST &pList, NODE *existNode, NODE *p)
{
	p->pNext = existNode->pNext;
	existNode->pNext = p;
}

void addBefore(LIST &pList, NODE *existNode, NODE *p)
{ 
	//Tìm node trước node exist
	/*
	NODE *pTmp = pList.pHead;
	for (pTmp; pTmp->pNext != existNode; pTmp = pTmp->pNext)
		;
	*/
	NODE *pTmp = getNodeBefore(pList, existNode);
	//chèn sau node pTmp là ok ^^^^^^
	if (pTmp != NULL)
		addAfter(pList, pTmp, p);
	else
		printf("\nNode need to insert before is not existence!!");

}

void deleteBegin(LIST &pList)
{
	
	if (pList.pHead == pList.pTail)
	{
		free(pList.pHead);
		pList.pHead = pList.pTail = NULL;
	}
	else
	{
		NODE *p = pList.pHead;
		pList.pHead = pList.pHead->pNext;
		free(p);
	}
}

void deleteEnd(LIST &pList)
{
	if (pList.pHead == pList.pTail)
	{
		free(pList.pHead);
		pList.pHead = pList.pTail = NULL;
	}
	else
	{//tìm node trước node tail
		/*
		NODE *p = pList.pHead;
		for (p; p->pNext != pList.pTail; p = p->pNext)
			;	*/
		
		NODE *p = getNodeBefore(pList, pList.pTail);
		free(pList.pTail);
		pList.pTail = p;
		p->pNext = NULL;
	}
}

void deleteMiddle(LIST &pList,NODE *existNode)
{
	NODE *p = NULL;
	//tìm node trước node exist
	
	//for (p; p->pNext != exist ; p = p->pNext)
		//;
	p = getNodeBefore(pList, existNode);

	p->pNext = existNode->pNext;
	free(existNode);
}

void printList(LIST pList)
{
	if (isEmptyList(pList))
		printf("\nThis list is EMPTY!");
	else
	{
		printf("\n[List Data]: ");
		for (NODE *pTmp = pList.pHead; pTmp != pList.pTail; pTmp = pTmp->pNext)
		{
			printf("%d -> ", pTmp->data);
		}
		printf("%d", pList.pTail->data);
	}
}

//=============WIDE FUNCTION===============

//Hàm đếm số phần từ
int lengthOfList(LIST pList)
{ 
	if (isEmptyList(pList))
		return 0;
	int Result = 1;
	for (NODE *tmp = pList.pHead; tmp->pNext != NULL; tmp = tmp->pNext)
		Result++;
	return Result;
}

//Hàm chèn 1 phần từ vào vị trí xác định, (chen vao truoc)
void insertAt(LIST &pList, NODE *p, int pos)
{
	int n = lengthOfList(pList);
	if (pos == 0)
		addFirst(pList, p);
	else if (pos == n)
		addLast(pList, p);
	else if (pos < 0 || pos > n)
		printf("\nPositon need to insert is not available !!!");
	else
	{ 
		int count = 0;
		NODE *tmp = pList.pHead;
		while (count != pos-1)
		{ 
			tmp = tmp->pNext;
			count++;
		}
		addAfter(pList, tmp, p);
	}
}

//Hàm 1 phần từ tại vị trí xác định
void deleteAt(LIST &pList, int pos)
{
	int n = lengthOfList(pList);
	if (pos == 0)
		deleteBegin(pList);
	else if (pos == n-1)
		deleteEnd(pList);
	else if (pos < 0 || pos >= n)
		printf("\nPositon need to delete is not available !!!");
	else
	{
		int count = 0;
		NODE *tmp = pList.pHead;
		while (count != pos)
		{
			tmp = tmp->pNext;
			count++;
		}
		deleteMiddle(pList, tmp);
	}
}
//đảo ngược list
void reverse(LIST &l)
{
	NODE *tmpTail = l.pHead;
	NODE *parent = l.pHead;
	NODE *current = l.pHead->pNext;
	l.pHead = current->pNext;
	parent->pNext = NULL;
	current->pNext = parent;
	while (l.pHead->pNext != NULL)
	{
		parent = current;
		current = l.pHead;
		l.pHead = l.pHead->pNext;
		current->pNext = parent;
	}
	l.pHead->pNext = current;
	l.pTail = tmpTail;
}