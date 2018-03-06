#include "PointList.h"

NODE* getNode(xPOINT pt)
{
	NODE *p = NULL;
	p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL)
	{
		printf("Error: Not enough memory!!");
		_getch();
		exit(0);
	}
	p->data = pt;
	p->pNext = NULL;
	return p;
}

NODE* getNodeBefore(LIST pList, NODE *existNode)
{
	NODE *tmp = pList.pHead;
	for (tmp; tmp->pNext != existNode; tmp = tmp->pNext)
	if (tmp->pNext == NULL)
		return NULL;
	return tmp;
}
void initList(LIST &pList)
{
	pList.pHead = NULL;
	pList.pTail = NULL;
}

bool isEmptyList(LIST pList)
{
	if (pList.pHead == NULL)
		return true;
	return false;
}
void printList(LIST pList, char *s)
{
	printf("%s", s);
	if (isEmptyList(pList))
		printf("\nThis list is EMPTY!");
	else
	{
		//printf("\n[List Data]: ");
		for (NODE *pTmp = pList.pHead; pTmp != pList.pTail; pTmp = pTmp->pNext)
		{
			//printf("%d  ", pTmp->data);
			printPoint(pTmp->data);
			printf(" , ");
		}
		printPoint(pList.pTail->data);
	}
}

//Thêm
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
//Xóa
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
//khoang cach

float distanceNode(NODE *P1, NODE *P2)
{
	if (P1 == NULL || P2 == NULL)
	{
		printf("\nEmpty node!!!");
		return 0;
	}
	return distancePoint(P1->data, P2->data);
}
//khoang cach theo truc
float distanceByOx(NODE* P1, NODE* P2)
{
	return abs(P1->data.x - P2->data.x);
}
float distanceByOy(NODE* P1, NODE* P2)
{
	return abs(P1->data.y - P2->data.y);
}
//diem doi xung
xPOINT symmetry(NODE P)
{
	xPOINT result;
	result.x = -P.data.x;
	result.y = -P.data.y;
	return result;
}
xPOINT symmetryByOx(NODE P)
{
	xPOINT result;
	result.x = P.data.x;
	result.y = -P.data.y;
	return result;
}
xPOINT symmetryByOy(NODE P)
{
	xPOINT result;
	result.x = -P.data.x;
	result.y = P.data.y;
	return result;
}

xPOINT symmetrySparateI(NODE P)
{
	xPOINT result;
	result.x = P.data.y;
	result.y = P.data.x;
	return result;
}
xPOINT symmetrySparateII(NODE P)
{
	xPOINT result;
	result.x = -P.data.y;
	result.y = -P.data.x;
	return result;
}
//Đếm số điểm có hoành độ dương
int countPositiveAbsciss(LIST pList)
{
	int count = 0;
	for (NODE*tmp = pList.pHead; tmp != NULL; tmp = tmp->pNext)
	{
		if (tmp->data.x > 0)
			count++;
	}
	return count;
}
//Tìm điểm có tung độ max
NODE* maxOrdinate(LIST pList)
{
	NODE *re = pList.pHead;
	for (NODE*tmp = re; tmp != NULL;tmp=tmp->pNext)
	if (tmp->data.y > re->data.y)
		re = tmp;
	return re;
}
//Tìm điểm gần gốc tọa độ nhất
NODE* closestOrgin(LIST pList)
{
	xPOINT org; org.x = org.y = 0;
	NODE *re = pList.pHead;
	for (NODE*tmp = re; tmp != NULL; tmp = tmp->pNext)
	if (distancePoint(tmp->data, org)<distancePoint(re->data, org))
		re = tmp;
	return re;

}