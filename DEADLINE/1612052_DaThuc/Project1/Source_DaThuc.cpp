#include "DaThuc.h"	

void main()
{
	SDaThuc p1,p2;
	nhapDaThuc(p1,"Nhap da thuc 1:");
	nhapDaThuc(p2,"\nNhap da thuc 2:");
	xuatDaThuc(p1, "\nDa thuc 1: ");
	xuatDaThuc(p2, "\nDa thuc 2: ");
	xuatDaThuc(p1 + p2, "\nP1 + P2: ");
	xuatDaThuc(p1 - p2, "\nP1 - P2: ");
	xuatDaThuc(p1 * p2, "\nP1 * P2: ");
	xuatDaThuc(daoHamCapMot(p1), "\n(P1)'=");
	xuatDaThuc(daoHamCapK(p1, 3), "\nDao ham cap K (k la tham so) cua p1: \n");
	float x, kq;
	printf("\nTinh gia tri tai x=x0\n");
	printf("Nhap x = ");
	scanf_s("%f", &x);
	kq = tinhGiaTri(p1, x);
	printf("\nGia tri cua p1 tai x = %f la: %f", x, kq);
	_getch();
}