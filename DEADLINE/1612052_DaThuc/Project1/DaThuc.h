#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

struct SDonThuc
{
	float a;
	int n;
};
struct SDaThuc
{
	float a[MAX];
	int n;
};

void nhapDaThuc(SDaThuc &P,char thongBao[]);
void xuatDaThuc(SDaThuc P, char thongBao[]);

SDaThuc operator+(SDaThuc p1, SDaThuc p2);
SDaThuc operator-(SDaThuc p1, SDaThuc p2);
SDaThuc operator*(SDaThuc p1, SDaThuc p2);

SDaThuc daoHamCapMot(SDaThuc p);
SDaThuc daoHamCapK(SDaThuc, int);

float tinhGiaTri(SDaThuc p, float x);