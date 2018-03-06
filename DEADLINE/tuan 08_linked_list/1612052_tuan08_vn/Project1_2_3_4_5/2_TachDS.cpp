#include "LinkedList.h"
//Bai 02: Tách list thanh 2 list chan le
void separateIndex(LIST &pList, LIST &Even, LIST &Odd)
{
	initList(Even); initList(Odd);
	NODE *tmp = pList.pHead;
	int i = 0;
	for (tmp,i; tmp != NULL; tmp = tmp->pNext,i++)
	{ 
		if (i % 2 == 0)
		{ 
			addLast(Even, getNode(tmp->data));
		}
		else
		{ 
			addLast(Odd, getNode(tmp->data));
		}
	}
}