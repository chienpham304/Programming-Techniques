#include "LinkedList.h"

void sortIncList(LIST &pList)
{
	for (NODE *p1 = pList.pHead; p1->pNext != NULL;p1=p1->pNext)
	for (NODE *p2 = p1->pNext; p2 != NULL;p2=p2->pNext)
	if (p1->data > p2->data)
	{
		int tmp = p1->data;
		p1->data = p2->data;
		p2->data = tmp;
	}
}
void sortDecList(LIST &pList)
{
	for (NODE *p1 = pList.pHead; p1->pNext != NULL; p1 = p1->pNext)
	for (NODE *p2 = p1->pNext; p2 != NULL; p2 = p2->pNext)
	if (p1->data < p2->data)
	{
		int tmp = p1->data;
		p1->data = p2->data;
		p2->data = tmp;
	}
}