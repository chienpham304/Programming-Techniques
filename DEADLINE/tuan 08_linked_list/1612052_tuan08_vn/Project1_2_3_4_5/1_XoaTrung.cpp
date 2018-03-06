#include "LinkedList.h"

void delelteLoop(LIST &pList)
{
	if (!isEmptyList(pList))
	for (NODE*p1 = pList.pHead; (p1!=NULL); p1 = p1->pNext)
	{
		for (NODE*p2 = p1->pNext; p2 != NULL; p2 = p2->pNext)
		{
			if (p1->data == p2->data && p2 != p1)
			{
				NODE *tmp = p2;
				p2 = getNodeBefore(pList, tmp);//p2 lùi 1 node
				deleteMiddle(pList, tmp);
			}
		}
	}
	else
	{
		printf("Empty LIST!!");
	}
}