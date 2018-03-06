#ifndef _STACK_H
#define _STACK_H
#include "SimpleLinkedList.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <Windows.h>

typedef struct Stack
{
	LIST sList;
}STACK;

void initStack(Stack &s);
void closeStack(Stack &s);
bool isEmptyStack(Stack s);
void topStack(Stack &s, int value);
int popStack(Stack &s);
int firstValueStack(Stack s);
int lastValueStack(Stack s);
#endif