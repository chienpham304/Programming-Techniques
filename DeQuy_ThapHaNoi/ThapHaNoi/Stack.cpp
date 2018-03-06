#include <conio.h>
#include <iostream>
using namespace std;
#define max 100
struct stack
{
	int e[max];
	char a[max];
	char b[max];
	char c[max];
	int top;
};
//-------------------
void Init(stack &s)
{
	s.top = -1;
}
//-------------------
int isEmptyStack(stack s)
{
	return (s.top == -1);
}
//-------------------
void push(stack &s, int &x, char &a, char &b, char &c)
{
	if (s.top == max - 1) exit(0);
	memcpy(&s.e[++s.top], &x, sizeof(int));//gán s.e[++s.top] = x;
	memcpy(&s.a[s.top], &a, sizeof(char));
	memcpy(&s.b[s.top], &b, sizeof(char));
	memcpy(&s.c[s.top], &c, sizeof(char));
}
//-------------------
void pop(stack &s, int &x, char &a, char &b, char &c)
{
	if (s.top == -1) exit(0);
	memcpy(&x, &s.e[s.top], sizeof(int));//x=s.e[s.top]
	memcpy(&a, &s.a[s.top], sizeof(char));
	memcpy(&b, &s.b[s.top], sizeof(char));
	memcpy(&c, &s.c[s.top], sizeof(char));
	s.top--;
}
void ThapHaNoi(int n,stack &s, char c1, char c2, char c3)
{
	int k = 1;
	push(s, n, c1,c2,c3);//top++,s[top] c1.c2.c3
	while (!isEmptyStack(s))
	{
		pop(s, n, c1, c2, c3);//n=top,c1,c2,c3 = top, top--
		if (n == 1)
			cout << "\nChuyen " << c1 << " qua " << c3;
		else
		{
			int l = n - 1;
			push(s, l, c2, c1, c3);
			push(s, k, c1, c2, c3);
			push(s, l, c1, c3, c2);
		}
	}
}
void main()
{
	stack s;
	int n, l, k = 1;
	char a = 'A';
	char b = 'B';
	char c = 'C';
	cout << "Nhap so: "; 
	cin >> n;
	Init(s);
	push(s, n, a, b, c);
	while (!isEmptyStack(s))
	{
		pop(s, n, a, b, c);
		if (n == 1)
			cout << "\nChuyen " << a << " qua " << c;
		else
		{
			l = n - 1;
			push(s, l, b, a, c);
			push(s, k, a, b, c);
			push(s, l, a, c, b);
		}
	}
}