#include "LargeNumber.h"
#include "stack.h"

//node

node* getNode(char value)
{
	node *p = NULL;
	p = (node*)malloc(sizeof(node));
	if (p == NULL)
	{
		printf("Error: Not enough memory!!");
		_getch();
		exit(0);
	}
	p->data = value;
	p->pNext = NULL;
	return p;
}

node* getNodeBefore(stack st, node *existnode)
{
	if (existnode == st.pHead)
		return NULL;
	node *tmp = st.pHead;
	for (tmp; tmp->pNext != existnode; tmp = tmp->pNext)
	if (tmp->pNext == NULL)
		return NULL;
	return tmp;
}
//==
void initStack(stack &st)
{
	st.pHead = NULL;
	st.pTail = NULL;
}
void freeStack(stack &st)
{
	node *p=NULL;
	while (st.pHead)
	{
		p = st.pHead;
		st.pHead = st.pHead->pNext;
		free(p);
	}
}
bool isEmptyStack(stack st)
{
	if (st.pHead == NULL)
		return true;
	return false;
}

//thêm giá trị của value vào đầu stack
void topStack(stack &st, char value)
{
	//thêm vào đầu
	//addFirst(sT.sList, getnode(value));
	node *p = getNode(value);
	if (isEmptyStack(st))
	{
		st.pHead = st.pTail = p;
	}
	else
	{
		p->pNext = st.pHead;
		st.pHead = p;
	}
}

//thêm giá trị của value vào đầu stack
void topEndStack(stack &st, char value)
{

	node *p = getNode(value);
	if (isEmptyStack(st))
	{
		st.pHead = st.pTail = p;
	}
	else
	{
		p->pNext = NULL;
		st.pTail->pNext = p;
		st.pTail = p;

	}
}

//lấy và xóa cuối của stack
char popStack(stack &st)
{
	char result;
	if (isEmptyStack(st))
	{
		return '0';
	}
	if (st.pHead == st.pTail)
	{
		result = st.pHead->data;
		st.pHead = st.pTail = NULL;
		return result;
	}
	result = st.pHead->data;
	st.pHead = st.pHead->pNext;
	
	//free(tmp);
	return result;
}
//Xóa cuối 
char popEndStack(stack &st)
{
	if (isEmptyStack(st))
	{
		return '0';
	}
	else
	{
		stack tmp; initStack(tmp);
		while (st.pHead != st.pTail)
		{
			topStack(tmp, popStack(st));
		}
		char kq = popStack(st);
		initStack(st);
		while (!isEmptyStack(tmp))
			topStack(st, popStack(tmp));
		return kq;
	}
	return 0;
}

//lấy giá trị của phần tử đầu stack
char firstValueStack(stack st)
{
	if (isEmptyStack(st))
		return 0;
	return st.pHead->data;
}
//lấy giá trị của phần tử cuối stack
char lastValueStack(stack st)
{
	if (isEmptyStack(st))
		return 0;
	return st.pTail->data;
}

//print stack
void printStack(stack st, char*str)
{
	if (isEmptyStack(st))
		printf("\nThis stack is EMPTY!");
	else
	{
		if (isDouble(st))
			deleteLastZero(st);

		printf("%s", str);
		while (!isEmptyStack(st))
		{
			char c = popStack(st);
			printf("%c", c);
		}
	//	printf("%c", st.pTail->data);
	}
}
//đảo ngược list
void reverseStack(stack &st)
{
	if (isEmptyStack(st))
	{
		//printf("\nCannot reverse [Error]: Empty List!!");
		return;
	}
	else if (st.pHead == st.pTail)//list co 1 node
	{
		return;
	}
	else if (st.pHead->pNext == st.pTail)//list co 2 node
	{
		st.pTail->pNext = st.pHead;

		st.pHead = st.pTail;
		st.pTail = st.pHead->pNext;

		st.pTail->pNext = NULL;
	}
	else //list có 3 node trở lên
	{
		node *tmpTail = st.pHead;
		node *parent = st.pHead;
		node *pFlag = st.pHead->pNext;
		st.pHead = pFlag->pNext;
		parent->pNext = NULL;
		pFlag->pNext = parent;
		while (st.pHead->pNext != NULL)
		{
			parent = pFlag;
			pFlag = st.pHead;
			st.pHead = st.pHead->pNext;
			pFlag->pNext = parent;
		}
		st.pHead->pNext = pFlag;
		st.pTail = tmpTail;
	}
}

//Hàm đếm số phần từ
int lengthOfStack(stack st)
{
	if (isEmptyStack(st))
		return 0;
	int Result = 1;
	for (node *tmp = st.pHead; tmp->pNext != NULL; tmp = tmp->pNext)
		Result++;
	return Result;
}
void copyStack(stack source, stack&dest)
{
	initStack(dest);
	while (!isEmptyStack(source))
	{
		topEndStack(dest, popStack(source));
	}
}