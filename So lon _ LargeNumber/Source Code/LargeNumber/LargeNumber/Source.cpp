#include "LargeNumber.h"
void main()
{
	stack st1,st2,st;
	initStack(st1); initStack(st2); initStack(st);
	//readNumberFromFile("input.txt", st1, st2);
	st1 = scanNumber();
	st2 = scanNumber();
	deleteFirstZero(st1); deleteLastZero(st1);
	deleteFirstZero(st2); deleteLastZero(st2);
	printStack(st1, "\nNum 1 : ");
	printStack(st2, "\nNum 2 : ");
	
	printStack(st1 + st2, "\nSum   : ");
	printStack(st1 - st2, "\nMinus : ");
	printStack(st1 * st2, "\nMul   : ");
	printStack(st1 / st2, "\nDiv   : ");
	printStack(st1%st2, "\nMod   : ");
	printStack(divFloat2(st1,st2), "\nDivF  : ");

	//sqrt
	printStack(st1, "\nSqrt("); printf(") = ");
	printStack(sqrt(st1), "");

	
	
	//factorial
	printStack(st1, "\nFactorial  :"); printf("! = ");
	printStack(factorial(st1), "");
	
	
	//power
	printStack(st1, "\nPower : ");
	printStack(st2, "^");
	printStack(powerFloat(st1, st2), " = ");

	//
	printStack(st1, "\ne^(");
	printStack(exp(st1), ")= : ");
	//printStack(ln(st1), "\nLn    : ");
	printf("\n==========End===========");
	freeStack(st); freeStack(st1); freeStack(st2);
	_getch();
}