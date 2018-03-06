#include "SimpleLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "SolveExpression.h"

void main()
{
	char *s;
	s = (char*)calloc(255, sizeof(char));
	printf("[Cac toan tu hop le: + - * / % ^]");
	inputExpression(s);

	QUEUE q;
	initQueue(q);
	covertToPostfix(s, q);
	float result = solveExpression(q);
	printf("\nResult: %0.0f", result);
	closeQueue(q);
	_getch();

}