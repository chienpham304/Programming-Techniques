#ifndef _LARGENUMBER_H
#define _LARGENUMBER_H
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define NaN 10
#define Max_Of_Decimal 5
#define Time_Limit 200000//seconds
//read data
stack scanNumber();
void readNumberFromFile(char*path, stack &st1, stack &st2);

//operator logical
bool operator==(stack st1, stack st2);
bool operator!=(stack st1, stack st2);
bool operator>=(stack st1, stack st2);
bool operator<=(stack st1, stack st2);
bool operator>(stack st1, stack st2);

//operator caculate
int compare(stack num1, stack num2);
stack operator+(stack st1, stack st2);
stack operator-(stack st1, stack st2);
stack operator*(stack st1, stack st2);
stack operator/(stack st1, stack st2);
stack operator%(stack st1, stack st2);

//Function
stack pow(stack st, int n);
stack factorial(stack st1);
stack powerInt(stack x, stack y);
stack powerFloat(stack x, stack y);
stack div2Int(stack bichia, stack sochia);
stack divFloat2(stack bichia, stack sochia);
stack logarith(stack a);
stack abs(stack st);
stack sqrt(stack st);
stack exp(stack x);
stack ln(stack st);
//Spupporting Func
void fillZeroForDouble(stack &st1, stack&st2);
void deleteFirstZero(stack &st);
void deleteLastZero(stack &st);
bool isDouble(stack st);
bool isMinus(stack st);
void addMinus(stack &st);
void delMinus(stack &st);
stack makeError();
stack makeStack_1();
stack makeStack_0();
stack makeOutOfTime();
#endif