#include "DaThuc.h"

void nhapDaThuc(SDaThuc &P, char thongBao[])
{
	//DATHUC P;
	printf("%s", thongBao);
	do
	{
		printf("\nNhap so mu n:");
		scanf_s("%d", &P.n);
	} while (P.n < 0);
	for (int i = P.n; i >= 0; i--)
	{
		float tmp;
		printf("\nNhap he so bac %d: ", i);
		scanf_s("%f", &tmp);
		P.a[i] = tmp;
	}
}

void xuatDaThuc(SDaThuc P, char thongBao[])
{
	printf("%s", thongBao);
	if (P.n < 0) printf(" Empty !!");
	else
	{
		//printf("\nDa thuc: ");
		if (P.a[P.n] != 0)
			printf(" %0.2fx^%d ", P.a[P.n], P.n);

		for (int i = (P.n) - 1; i >= 0; i--)
		if (P.a[i] >= 0)
			printf(" + %0.2fx^%d", P.a[i], i);
		else if (P.a[i] < 0)
			printf(" - %0.2fx^%d", -P.a[i], i); //xu li cai so am cho dep thoi
		//else
			//printf("0");//truong hop p.a[i] = 0 thi khoi xuat 
	}
}

SDaThuc operator-(SDaThuc P1, SDaThuc P2)// p1-p2
{
	SDaThuc P;
	P.n = (P1.n>P2.n) ? P1.n : P2.n;
	int i = 0, j = 0, k = 0;

	while (i <= P1.n && j <= P2.n)
	{
		P.a[k] = P1.a[i] - P2.a[j];
		k++; i++; j++;
	}
	if (i > P1.n)//P1 co bac nho hon P2
	{
		for (int j = i; j <= P.n; j++)
			P.a[j] = -P2.a[j]; //
	}
	else if (j > P2.n)//P1 co bac nho hon P2
	{
		for (int i = j; i <= P.n; i++)
			P.a[i] = P1.a[i];
	}
	int kt = 1; //kiem tra da thuc P co rong khong ( P1-P2 = 0)
	for (int i = P.n; i >= 0; i--)
	if (P.a[i] != 0)
	{
		kt = 0;
		P.n = i;
		break;
	}
	//kiem tra thu P co bang rong hay khong
	if (kt == 1)
		P.n = -1;
	return P;
}
SDaThuc operator+(SDaThuc P1, SDaThuc P2)// p1+p2
{
	SDaThuc P;
	P.n = (P1.n > P2.n) ? P1.n : P2.n;
	int i = 0, j = 0, k = 0;
	while (i <= P1.n && j <= P2.n)
	{
		P.a[k] = P1.a[i] + P2.a[j];
		k++; i++; j++;
	}
	if (i > P1.n)//P1 co bac nho hon P2
	{
		for (int j = i; j <= P.n; j++)
			P.a[j] = P2.a[j]; //
	}
	else if (j > P2.n)//P1 co bac nho hon P2
	{
		for (int i = j; i <= P.n; i++)
			P.a[i] = P1.a[i];
	}
	return P;
}


SDaThuc operator*(SDaThuc P1, SDaThuc P2)
{
	SDaThuc P;
	P.n = P1.n + P2.n;
	SDonThuc arr[MAX];
	int k = 0;
	for (int i = P1.n; i >= 0; i--)
	for (int j = P2.n; j >= 0; j--)
	{
		arr[k].a = P1.a[i] * P2.a[j];
		arr[k].n = i + j;
		k++;
	}
	for (int i = 0; i <= P.n; i++)
	{
		float tmp = 0;
		for (int j = 0; j <= k; j++)
		if (arr[j].n == i)
		{
			tmp = tmp + arr[j].a;
		}
		P.a[i] = tmp;//truog hop khong xay ra if thi van gan cho 0
	}
	return P;
}

SDaThuc daoHamCapMot(SDaThuc p)
{
	SDaThuc kq;
	if (p.n == 0)
	{
		kq.n = 0;
		kq.a[0] = 0;
		return kq;
	}
	else
	{
		kq.n = p.n - 1;
		for (int i = kq.n; i >= 0; i--)
			kq.a[i] = p.a[i + 1] * (i+1);
	}
	return kq;
}

SDaThuc daoHamCapK(SDaThuc p, int k)
{
	SDaThuc kq;
	if (k > p.n)
	{
		kq.n = 0;
		kq.a[0] = 0;
		return kq;
	}
	kq = p;
	for (int i = 1; i <= k; i++)
		kq = daoHamCapMot(kq);
	return kq;
}

float tinhGiaTri(SDaThuc p, float x)
{
	float kq = 0;
	for (int i = p.n; i >= 0; i--)
	{
		kq += p.a[i] * pow(x, i);
	}
	return kq;
}