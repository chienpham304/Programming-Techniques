#ifndef _STACK_H
#define _STACK_H
#include "LargeNumber.h"

struct node
{
	char data;
	node*pNext;
};
struct stack
{
	node*pHead;
	node*pTail;
};
/*Stack:  (top & push)Head-># # # # # # # # # #<-Tail */

//node
//khởi tạo 1 node
node* getNode(char value);
//lấy địa chỉ node trước node exit
node* getNodeBefore(stack st, node *existnode);

//Thêm vào đầu stack
void topStack(stack &st, char value);

//thêm cuối tack
void topEndStack(stack &st, char value);

//đảo ngược list
void reverseStack(stack &st);
//Xóa cuối 
char popEndStack(stack &st);


//Lấy ra (từ đầu)
char popStack(stack &st);

void printStack(stack st, char*str);

void initStack(stack &st);
void freeStack(stack &st);
void closeStack(stack &st);
bool isEmptyStack(stack st);

char firstValueStack(stack st);
char lastValueStack(stack st);
void copyStack(stack source, stack&dest);
//Hàm đếm số phần từ
int lengthOfStack(stack st);
#endif