#include "SolveExpression.h"

void inputExpression(char*&s)
{
	printf("\nNhap bieu thuc:");
	char tmp[255] = "(20+8)-3*(8/4)+3*(4-1)";
	//gets_s(tmp);
	for (int i = 0; i <= strlen(tmp); i++)
		s[i] = tmp[i];
	realloc(s, strlen(tmp) + 1);
}
int getElement(char *s, char *&dest)
{
	char tmp[10];
	int k = 0;
	if (s[0] >= '0' && s[0] <= '9')
	{
		for (int i = 0; i < strlen(s); i++)
		{
			if (*(s + i) < '0' || *(s + i) > '9')
			{
				break;
			}
			else
			{
				tmp[k] = *(s + i);
				k++;
			}
		}
		tmp[k] = '\0';
	}
	else
	{
		k = 1;
		tmp[0] = s[0];
		tmp[1] = '\0';
	}
	for (int i = 0; i <= strlen(tmp); i++)
		*(dest + i) = tmp[i];
	return k;
}
int symbolToDigit(char c)
{
	//quy ước
	switch (c)
	{
	case '(':
		return BRACKET_OPEN; break;
	case ')':
		return BRACKET_CLOSE; break;
	case '+':
		return SUB; break;
	case '-':
		return DEC; break;
	case '*':
		return MUL; break;
	case '/':
		return DIV; break;
	case '^':
		return POW; break;
	case '%':
		return MOD; break;

	default: return 0; break;
	}
}
char digitToSymbol(int x)
{
	//quy ước
	switch (x)
	{
	case BRACKET_OPEN:
		return '('; break;
	case BRACKET_CLOSE:
		return ')'; break;
	case SUB:
		return '+'; break;
	case DEC:
		return '-'; break;
	case MUL:
		return '*'; break;
	case DIV:
		return '/'; break;
	case POW:
		return '^'; break;
	case MOD:
		return '%'; break;

	default: return 0; break;
	}
}
float calculate(int x1, int x2, int oper)
{
	switch (oper)
	{
	case SUB: return x1 + x2; break;
	case DEC: return x1 - x2; break;
	case MUL: return x1 * x2; break;
	case DIV: return x1 / x2; break;
	case POW: return pow(1.0*x1, x2); break;
	case MOD: return x1%x2; break;
	}
	return -1;
}
int priority(int sym)
{
	if (sym == BRACKET_OPEN || sym == BRACKET_CLOSE)
		return 0;
	if (sym == SUB || sym == DEC)
		return 1;
	if (sym == MUL || sym == DIV || sym == POW || sym == MOD)
		return 2;
	return -1;
}
void covertToPostfix(char*s, Queue &q)
{
	STACK st;
	initStack(st);
	char tmp[10];
	char *pTmp = NULL;
	pTmp = tmp;
	int sym;
	int digit;
	int index = 0;
	while (*s != '\0')
	{
		*pTmp = '\0';//reset
		index = getElement(s, pTmp);//đọc vào phần từ đầu tiên
		s = s + index;
		digit = atoi(pTmp);
		if (digit != 0)//số hạng
		{
			enQueue(q, digit);
		}
		else
		{
			sym = symbolToDigit(*(s - index));
			if (sym == 0)
			{
				printf("\nBieu thuc chua toan tu chua duoc dinh nghia!!!");
				return;
			}
			if (sym == BRACKET_OPEN)//dấu '('
			{
				topStack(st, sym);
			}
			else if (sym == BRACKET_CLOSE)//dấu ')'
			{
				while (firstValueStack(st) != BRACKET_OPEN)
				{
					//pop ptu đầu tiên của stack đưa vào queue
					enQueue(q, popStack(st));
				}
				popStack(st);//pop dấu '(' ra vứt
			}
			else//là toán tử
			{
				while (MOD <= firstValueStack(st) && firstValueStack(st) <= SUB)
				{
					//pop toán tử từ stack và đưa vào queue (toán tử có độ ưu tiên<sym)
					if (priority(firstValueStack(st)) >= priority(sym))
						enQueue(q, popStack(st));
					else
						break;
				}
				topStack(st, sym);//đưa sym vào stack
			}
		}
	}
	//đưa tất cả phần tử còn lại của stack vào queue
	while (!isEmptyStack(st))
	{
		enQueue(q, popStack(st));
	}
	printfPostfix(q);
}
float solveExpression(Queue &q)
{
	STACK st; initStack(st);
	while (!isEmptyQueue(q))
	{
		int element = deQueue(q);
		if (element > 0)//số hạng
			topStack(st, element);
		else
		{
			int p1 = popStack(st);
			int p2 = popStack(st);
			float p3 = calculate(p2, p1, element);
			topStack(st, int(p3));
		}
	}
	if (firstValueStack(st) != lastValueStack(st))
	{
		printf("\nError Calculate!!");
		return -1;
	}
	else
		return firstValueStack(st);
}
void printfPostfix(QUEUE qt)
{
	QUEUE q;
	initQueue(q);
	for (NODE *pTmp = qt.qList.pHead; pTmp != qt.qList.pTail; pTmp = pTmp->pNext)
	{
		enQueue(q, pTmp->data);
	}
	enQueue(q, qt.qList.pTail->data);

	printf("\nPostfix:");

	for (NODE *pTmp = q.qList.pHead; pTmp != NULL; pTmp = pTmp->pNext)
	{
		if (pTmp->data > 0)
			printf("%d ", pTmp->data);
		else
			printf("%c ", digitToSymbol(pTmp->data));
	}
}
