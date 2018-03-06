#include "LinkedList.h"

int main()
{
	int n;
	LIST pList;
	initList(pList);
	//Nhập SDLK
	printf("\nNhap DSLK: <nhap -100 de dung nhap>\n");
	do
	{
		printf("- Nhap gia tri:");
		scanf_s("%d", &n);
		if (n == -100)
			break;
		addLast(pList, getNode(n));
	} while (true);
	printList(pList, "\nDanh sach vua nhap:\n");
	
	//Bai 01: Xóa trùng
	delelteLoop(pList);
	printList(pList, "\nBai 01. Danh sach sau khi xoa trung:\n");
	//Bai 02: Tách DSLK (tách xong hỏng cái ds gốc)

	LIST Even, Odd;
	initList(Even); initList(Odd);

	printList(pList, "\nBai 02. Danh sach ban dau:\n");
	separateIndex(pList, Even, Odd);
	printList(Even, "\n- [Even]:");
	printList(Odd , "\n -[Odd ]:");

	//Bai 03: Đảo ngược
	printList(Odd, "\nBai 03. Danh sach ban dau:\n");
	reverseList(Odd);
	printList(Odd, "\n- Danh sach sau khi dao chieu:\n");
	
	//Bài 04:Sap xep mang tang
	printList(pList, "\nBai 04. Danh sach ban dau:\n");
	sortIncList(pList);
	printList(pList, "\n- Danh sach sau Sap tang:\n");
	//Bài 05:Sap xep mang giam
	//printList(pList, "\nBai 04. Danh sach ban dau:\n");
	sortDecList(pList);
	printList(pList, "\n- Danh sach sau Sap giam:\n");


	_getch();
	return 0;
}