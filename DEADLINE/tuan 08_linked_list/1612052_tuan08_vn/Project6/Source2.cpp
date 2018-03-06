#include "PointList.h"

void main()
{
	LIST pList;
	initList(pList);
	printf("Nhap danh sach diem:<nhap y = -100 de dung>\n");
	do
	{
		addLast(pList, getNode(inputPoint()));
		if (pList.pTail->data.y == -100)
		{
			deleteEnd(pList);
				break;
		}
	} while (true);
	
	printList(pList,"DS diem: ");
	//khoang cach
	//printf("\nKhoang cach giua head va tail: %f", distanceNode(pList.pHead, pList.pTail));
	////doi xung
	printf("\n*Diem doi xung cua: "); 
	printPoint(pList.pHead->data);
	printf("\n- Qua goc toa do:  ");
	printPoint(symmetry(*pList.pHead));
	printf("\n- Qua truc Ox:  ");
	printPoint(symmetryByOx(*pList.pHead));
	printf("\n- Qua truc Oy:  ");
	printPoint(symmetryByOy(*pList.pHead));
	printf("\n- Qua phan giac I:  ");
	printPoint(symmetrySparateI(*pList.pHead)); 
	printf("\n- Qua phan giac II:  ");
	printPoint(symmetrySparateII(*pList.pHead));
	//Đếm hoan do duong
	printf("\n - So diem co hoanh do duong: %d", countPositiveAbsciss(pList));
	printf("\n - Diem co tung do lon nhat:");
	printPoint(maxOrdinate(pList)->data);
	printf("\n - Diem gan goc to do nhat:");
	printPoint(closestOrgin(pList)->data);
	_getch();
}