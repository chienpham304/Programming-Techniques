#include "LargeNumber.h"
#include "Stack.h"
//read data
stack scanNumber()
{
	stack st1; initStack(st1);
	char*s1 = new char[10000];
	printf("\nInput Num: ");
	gets(s1);
	while (*s1!=0)
	{
		topEndStack(st1, *s1);//read into stack 1
		s1++;
	}
	return st1;
}
void readNumberFromFile(char*path, stack&st1, stack&st2)
{
	errno_t err;
	FILE*f;
	err = fopen_s(&f, path, "rb");
	if (err != 0)
	{
		printf("\nCannot read input file!!!");
		fclose(f);
		return;
	}
	char key = 1;
	while (!feof(f))
	{
		char c = fgetc(f);
		if (c == '\n'||c=='\r')
			key++;
		if (key == 1)
			topEndStack(st1, c);//read into stack 1
		else if (c!='\n' && c!='\r' && c>0)
			topEndStack(st2, c);
	}
	fclose(f);
}

//operator logical
int compare(stack num1, stack num2)
{
	deleteFirstZero(num1); deleteLastZero(num1);
	deleteFirstZero(num2); deleteLastZero(num2);

	stack st1, st2; initStack(st1); initStack(st2);
	int dem = 0, dem1 = 0, dem2 = 0;
	//for double
	while (!isEmptyStack(num1))
	{
		if (lastValueStack(num1) != '.')
		{
			topStack(st1, popEndStack(num1)); dem++;
		}
		else
		{
			dem1 = dem;
			popEndStack(num1);
		}
	}
	dem = 0;
	while (!isEmptyStack(num2))
	{
		if (lastValueStack(num2) != '.')
		{
			topStack(st2, popEndStack(num2)); dem++;
		}
		else
		{
			dem2 = dem;
			popEndStack(num2);
		}
	}//
	
	dem = dem1 - dem2;

	if (dem>0)//chèn vào st2
	for (int i = 0; i < dem; i++)
		topEndStack(st2, '0');
	else
	for (int i = 0; i < -dem; i++)
		topEndStack(st1, '0');
	
	deleteFirstZero(st1);
	deleteFirstZero(st2);

	int key = lengthOfStack(st1) - lengthOfStack(st2);
	if (key == 0)
	{
		node*k1 = st1.pHead;
		node*k2 = st2.pHead;

		while (k1->data == k2->data && k1 != st1.pTail&&k2 != st2.pTail)
		{
			k1 = k1->pNext;
			k2 = k2->pNext;
		}
		key = k1->data - k2->data;
	}
	return key;
}
bool operator==(stack num1, stack num2)
{ 
	return compare(num1, num2) == 0;
}
bool operator!=(stack num1, stack num2)
{
	return compare(num1, num2) != 0;
}
bool operator>(stack num1, stack num2)
{
	return compare(num1, num2) > 0;
}
bool operator>=(stack num1, stack num2)
{
	return compare(num1,num2) >= 0;
}

bool operator<(stack num1, stack num2)
{ 
	return compare(num1, num2) < 0;
}
bool operator<=(stack num1, stack num2)
{
	return compare(num1, num2) <= 0;
}

//operator caculate
stack operator+(stack num1, stack num2)
{
	stack st_0=makeStack_0();
	
	stack st1, st2;
	copyStack(num1, st1);
	copyStack(num2, st2);
	if (isMinus(st1) && isMinus(st2))
	{
		delMinus(st1); delMinus(st2);
		return st_0 - (st1 + st2);
	}
	else if (isMinus(st1))
	{
		delMinus(st1);
		return st2 - st1;
	}
	else if (isMinus(st2))
	{
		delMinus(st2);
		return st1 - st2;
	}
	fillZeroForDouble(st1, st2);
	stack st; initStack(st);
	char carray = 0;//nhớ
	bool dot = false;
	while (!isEmptyStack(st1) || !isEmptyStack(st2))//empty=>pop=0
	{
		if (lastValueStack(st1) == '.')
		{
			popEndStack(st1);
			popEndStack(st2);
			topStack(st, '.');
			dot = true;
			continue;
		}
		char tmp = carray + popEndStack(st1) + popEndStack(st2) - 48;
		if (tmp >= 58)
		{
			tmp = tmp - 10;
			carray = 1;
		}
		else
			carray = 0;
		topStack(st, tmp);
	}
	if (carray == 1)
		topStack(st, '1');
	if (dot == true)//có phần thập phân
		deleteLastZero(st);

	freeStack(st_0); freeStack(st1); freeStack(st2);

	return st;
}
stack operator-(stack num1, stack num2)
{
	stack st1, st2;
	stack st_0 = makeStack_0();
	copyStack(num1, st1);
	copyStack(num2, st2);
	if (isMinus(st1) && isMinus(st2))
	{
		delMinus(st1); delMinus(st2);
		return st2 - st1;
	}
	else if (isMinus(st1))
	{
		delMinus(st1);
		return st_0 - (st1 + st2);
	}
	else if (isMinus(st2))
	{
		delMinus(st2);
		return st1 + st2;
	}
	fillZeroForDouble(st1, st2);
	stack st; initStack(st); 
	if (st1 == st2)
	{
		return st_0;
	}
	char carray = 0;//nhớ
	//xét số nào lớn hơn
	bool key = st1 > st2;
	bool dot = false;
	//tính
	while (!isEmptyStack(st1) || !isEmptyStack(st2))//empty=>pop=0
	{
		if (lastValueStack(st1) == '.')
		{
			dot = true;
			popEndStack(st1);
			popEndStack(st2);
			topStack(st, '.');
			continue;
		}
		char tmp;
		if (key>0)
			tmp = popEndStack(st1) - carray - popEndStack(st2);
		else
			tmp = popEndStack(st2) - carray - popEndStack(st1);

		if (tmp < 0)
		{
			carray = 1;
			tmp = tmp + 58;
		}
		else
		{
			carray=0;
			tmp = tmp + 48;
		}
		topStack(st, tmp);
	}
	//xóa số 0 ở đầu
	deleteFirstZero(st);
	if (!key)
		topStack(st, '-');
	if (dot = true)//có phần thập phaan
		deleteLastZero(st);

	freeStack(st1); freeStack(st2); freeStack(st_0);

	return st;
}
stack operator*(stack num1, stack num2)
{
	stack temp_1, temp_2, st; initStack(st); topStack(st, '0');
	copyStack(num1, temp_1); copyStack(num2, temp_2);
	if (isMinus(temp_1) && isMinus(temp_2))
	{
		delMinus(temp_1); delMinus(temp_2);
		return temp_1*temp_2;
	}
	else if (isMinus(temp_1))
	{
		delMinus(temp_1);
		st = st - (temp_1*temp_2);
		return st;
	}
	else if (isMinus(temp_2))
	{
		delMinus(temp_2);
		st = st - (temp_1*temp_2);
		return st;
	}
	stack st1, st2, mul;
	initStack(st1); initStack(st2);
	//copy to temp stack và tính vị trí dấu '.'
	int dem1 = 0, dem2 = 0, dem = 0, n1 = lengthOfStack(num1), n2 = lengthOfStack(num2);
	while (!isEmptyStack(num1))
	{
		if (lastValueStack(num1) != '.')
		{
			topStack(st1, popEndStack(num1)); dem++;
		}
		else
		{
			dem1 = dem;
			popEndStack(num1);
		}
	}
	dem = 0;
	while (!isEmptyStack(num2))
	{
		if (lastValueStack(num2) != '.')
		{
			topStack(st2, popEndStack(num2)); dem++;
		}
		else
		{
			dem2 = dem;
			popEndStack(num2);
		}
	}
	////////////////
	
	char carray = 0;//nhớ
	int space=0;//số lần lùi
	while (!isEmptyStack(st2))//empty=>pop=0
	{
		initStack(mul);
		node*k1 = st1.pTail;
		char m = popEndStack(st2) - 48;
		while (k1 != NULL)
		{
			char tmp = carray + m*(k1->data - 48);
			if (tmp > 9)
			{
				carray = tmp / 10;
				tmp = tmp % 10;
			}
			else
				carray = 0;
			topStack(mul, tmp+48);
			k1 = getNodeBefore(st1, k1);
		}
		if (carray > 0)
			topStack(mul, carray + 48);
		for (int i = 0; i < space; i++)
			topEndStack(mul, '0');
		st = st + mul;
		carray = 0;
		space++;
	}
	//điền dấu .
	initStack(mul);
	for (int i = 1; i <= dem1 + dem2; i++)
		topStack(mul, popEndStack(st));
	topEndStack(st, '.');
	int decimal = 1;
	while (!isEmptyStack(mul))// && decimal <= Max_Of_Decimal)
	{
		topEndStack(st, popStack(mul)); decimal++;
	}
	deleteFirstZero(st);
	deleteLastZero(st);

	freeStack(st1); freeStack(st2); freeStack(temp_1); freeStack(temp_2); freeStack(mul);

	return st;
}
stack operator/(stack bichia, stack sochia)
{
	stack st1, st2,st=makeStack_0();
	initStack(st1);
	initStack(st2);

	copyStack(bichia, st1);
	copyStack(sochia, st2);
	if (isMinus(st1) && isMinus(st2))
	{
		delMinus(st1); delMinus(st2);
		return st1/st2;
	}
	else if (isMinus(st1))
	{
		delMinus(st1);
		st = st - (st1/st2);
		return st;
	}
	else if (isMinus(st2))
	{
		delMinus(st2);
		st = st - (st1/st2);
		return st;
	}
	stack result, tmp, tmp2, tmp3;
	initStack(result);
	initStack(tmp);
	initStack(tmp2);
	initStack(tmp3);
	if (st2.pHead == st2.pTail && firstValueStack(st2) == '0' || isDouble(st1) || isDouble(st2))
	{
		return makeError();
	}
	else if (st2 >= st1)
	{
		if (st2 == st1)
			topStack(result, '1');
		else
			topStack(result, '0');
		return result;
	}
	while (!isEmptyStack(st1) || tmp >= st2)
	{
		while (st2>tmp && !isEmptyStack(st1))
		{
			topEndStack(result, '0');
			topEndStack(tmp, popStack(st1));
		}
		//popEndStack(result);
		if (tmp >= st2)
		{
			for (int i = 9; i >= 1; i--)
			{
				initStack(tmp2);
				initStack(tmp3);
				topStack(tmp3, i + 48);
				tmp2 = st2*tmp3;
				if (tmp2 <= tmp)
				{
					topEndStack(result, i + 48);
					break;
				}
			}
			tmp = tmp - tmp2;
			if (!isEmptyStack(st1))
			{
				topEndStack(tmp, popStack(st1));
				if (isEmptyStack(st1) && tmp<st2)
					topEndStack(result, '0');
			}
		}
		else
		{
			topEndStack(result, '0');
		}
	}
	while (firstValueStack(result) == '0')
		popStack(result);

	freeStack(st); freeStack(st1); freeStack(st2); freeStack(tmp); freeStack(tmp2);
	freeStack(tmp3);

	return result;
}
stack operator%(stack bichia, stack sochia)
{
	if (isMinus(bichia) || isMinus(sochia) || sochia.pHead == sochia.pTail && firstValueStack(sochia) == '0' || isDouble(bichia) || isDouble(sochia))
	{
		return makeError();
	}
	return bichia - (bichia / sochia)*sochia;
}

//Function
stack div2Int(stack bichia, stack sochia)
{
	int carry = 0; 
	stack result, tmp, tmp2, tmp3; initStack(result); initStack(tmp); initStack(tmp2); initStack(tmp3);
	
	result = bichia / sochia;
	bichia = bichia % sochia;

	//chia hết
	if (firstValueStack(bichia) == '0')
		return result;
	
	topEndStack(result, '.');

	while (carry < Max_Of_Decimal &&firstValueStack(bichia)!='0')
	{
		carry++;
		topEndStack(bichia, '0');
		tmp = bichia / sochia;
		bichia = bichia%sochia;
		if (carry == Max_Of_Decimal && firstValueStack(tmp) >= '5'&&firstValueStack(tmp) != '9')
			;// topEndStack(result, popStack(tmp) + 1);
		else 
			topEndStack(result, popStack(tmp));
	}
	
	while (firstValueStack(result) == '0')
		popStack(result);
	if (firstValueStack(result) == '.')
		topStack(result, '0');

	freeStack(tmp); freeStack(tmp2); freeStack(tmp3);

	return result;
}
stack divFloat2(stack bichia, stack sochia)
{
	stack temp_1, temp_2, st; initStack(st); topStack(st, '0');
	copyStack(bichia, temp_1); copyStack(sochia, temp_2);
	if (isMinus(temp_1) && isMinus(temp_2))
	{
		delMinus(temp_1); delMinus(temp_2);
		return divFloat2(temp_1, temp_2);
	}
	else if (isMinus(temp_1))
	{
		delMinus(temp_1);
		st = st - divFloat2(temp_1, temp_2);
		return st;
	}
	else if (isMinus(temp_2))
	{
		delMinus(temp_2);
		st = st - divFloat2(temp_1, temp_2);
		return st;
	}
	if (!isDouble(bichia) && !isDouble(sochia))
		return div2Int(bichia, sochia);
	//phép chia 2 số thực
	int dem1 = 0, dem2 = 0, dem = 0, n1 = lengthOfStack(bichia), n2 = lengthOfStack(sochia);
	stack st1, st2, result;
	initStack(st1); initStack(st2); initStack(result);
	while (!isEmptyStack(bichia))
	{
		if (lastValueStack(bichia) != '.')
		{
			topStack(st1, popEndStack(bichia)); dem++;
		}
		else
		{
			dem1 = dem;
			popEndStack(bichia);
		}
	}
	dem = 0;
	while (!isEmptyStack(sochia))
	{
		if (lastValueStack(sochia) != '.')
		{
			topStack(st2, popEndStack(sochia)); dem++;
		}
		else
		{
			dem2 = dem;
			popEndStack(sochia);
		}
	}
	for (int i = 0; i < dem2;i++)
		topEndStack(st1, '0');
	for (int i = 0; i < dem1; i++)
		topEndStack(st2, '0');
	result = div2Int(st1, st2);

	deleteLastZero(result);
	deleteFirstZero(result);
	freeStack(temp_1); freeStack(temp_2); 
	freeStack(st); freeStack(st1); freeStack(st2);

	return result;
}
stack powerInt(stack x, stack y)
{
	clock_t start = clock(); 
	stack result,st_0=makeStack_0(),st_1=makeStack_1(),tmp=makeStack_1(); 
	initStack(result);
	if (isDouble(y))
	{
		return makeError();
	}
	if (isMinus(y))
		return divFloat2(st_1, powerInt(x,st_0 - y));

	copyStack(x, result);
	while (tmp < y)
	{
		if (((double)(clock() - start) / CLOCKS_PER_SEC) > Time_Limit)
		{
			return makeOutOfTime();
		}
		result = result*x;
		tmp = tmp + st_1;
	}
	freeStack(st_0); freeStack(st_1); freeStack(tmp);
	return result;
}
stack powerFloat(stack x, stack y)
{
	if (!isDouble(y))
		return powerInt(x, y);
	stack a, st_1=makeStack_1(); initStack(a);
	a = x - st_1;
	stack s = makeStack_1();
	stack p = makeStack_1();
	stack l = makeStack_1();
	stack gt = makeStack_1();
	stack k = makeStack_1();
	stack tmp; initStack(tmp); stack tmp2; initStack(tmp2);
	clock_t start = clock();
	for (int i = 1; i <= NaN; i++, k = k + st_1)
	{
		if (((double)(clock() - start) / CLOCKS_PER_SEC) > Time_Limit)
		{
			return makeOutOfTime();
		}
		p = p*(y - k + st_1);
		l = l*a;
		gt = gt*k;
		tmp = p*l;
		tmp2 = divFloat2(tmp, gt);
		s = s + tmp2;
	}
	freeStack(a);
	freeStack(p);
	freeStack(l);
	freeStack(k);
	freeStack(gt);
	freeStack(tmp);
	freeStack(tmp2);
	return s;
}
stack factorial(stack st1)
{
	stack result, tmp, st_1=makeStack_1(); 
	initStack(result); 
	initStack(tmp);
	if (isDouble(st1)||isMinus(st1))
	{
		return makeError();
	}
	node*p = st1.pHead;
	while (p != NULL)
	{
		topEndStack(tmp, p->data);
		p = p->pNext;
	}
	clock_t start = clock();
	topStack(result, '1');
	if (firstValueStack(st1) != '0')
	{
		while (firstValueStack(tmp) != '0')
		{
			result = result*tmp;
			tmp = tmp - st_1;
			if (((double)(clock() - start) / CLOCKS_PER_SEC) > Time_Limit)
			{
				return makeOutOfTime();
			}
		}
	}
	freeStack(st_1);
	freeStack(tmp);

	return result;
}
stack abs(stack st)
{
	stack kq; copyStack(st, kq);
	if (isMinus(kq))
		popStack(kq);
	return kq;
}
stack sqrt(stack st)
{ 
	int n = 0;
	
	for (node*p = st.pHead; p->data != '.' && p->pNext!= NULL; p = p->pNext)
	{
		n++;
	}
	if (n > 3)
		n = 3;
	else n = 6;

	stack complex = makeStack_0();
	topEndStack(complex, '.');
	for (int i = 1; i < n;i++)
		topEndStack(complex, '0');
	
	topEndStack(complex, '1');
	stack kq = makeStack_1();
	stack st_2 = makeStack_1();
	st_2 = st_2 + st_2;
	stack m = abs((kq*kq - st));
	int loop = 0;
	while (m>= complex)
	{
		loop++;
		kq = divFloat2(kq + divFloat2(st,kq), st_2);
		m = abs((kq*kq - st));
	}
	freeStack(complex);
	freeStack(st_2);
	freeStack(m);

	return kq;
}
stack exp(stack x)
{
	stack st_1 = makeStack_1();
	stack kq = makeStack_1();
	stack mu = makeStack_1();
	stack gt = makeStack_1();
	stack k = makeStack_1();
	
	for (int i = 1; i <= 3*NaN; i++, k = k + st_1)
	{
		mu = mu*x;
		gt = gt*k;
		kq = kq + divFloat2(mu, gt);
	}
	freeStack(st_1);
	freeStack(mu);
	freeStack(gt);
	freeStack(k);
	return kq;
}
stack ln(stack st)
{
	if (st <= makeStack_0())
		return makeError();

	stack st_0 = makeStack_0();
	stack st_1 = makeStack_1();
	stack kq = makeStack_0();
	stack mu = makeStack_1();
	stack gt = makeStack_1();
	stack k = makeStack_1();
	stack x = st - st_1;
	for (int i = 1; i <= 5*NaN || kq <st_0; i++, k = k + st_1)
	{
		mu = mu*x;
		gt = gt*k;
		if (i%2!=0)
			kq = kq + divFloat2(mu, gt);
		else 
			kq = kq - divFloat2(mu, gt);
	}
	freeStack(st_1); freeStack(mu); freeStack(gt); freeStack(k); freeStack(x);
	return kq;
}

//Supporting Function
void fillZeroForDouble(stack &st1, stack&st2)
{
	int dem1 = 0, dem2 = 0, n1 = lengthOfStack(st1), n2 = lengthOfStack(st2);
	node*p = st1.pHead;
	while (p != NULL&&p->data != '.')
	{
		dem1++; p = p->pNext;
	}
	p = st2.pHead;
	while (p != NULL&&p->data != '.')
	{
		dem2++; p = p->pNext;
	}

	if (dem1 == n1 && dem2 == n2)
		;
	else if (dem1 == n1 || dem2 == n2)
	{
		if (dem1 == n1)
			topEndStack(st1, '.');
		else if (dem2 == n2)
			topEndStack(st2, '.');
	}
	//fill zero
	n1 = lengthOfStack(st1); n2 = lengthOfStack(st2);

	if (n1 - dem1 == n2 - dem2)
		;
	else
	{
		int n = (n1 - dem1) > (n2 - dem2) ? n1 - dem1 - (n2 - dem2) : n2 - dem2 - (n1 - dem1);
		//n--;
		for (int i = 1; i <= n; i++)
		{
			if (n2 - dem2 > n1 - dem1)
				topEndStack(st1, '0');
			else
				topEndStack(st2, '0');
		}
	}
}
void deleteFirstZero(stack &st)
{
	while (firstValueStack(st) == '0')
		popStack(st);
	if (isEmptyStack(st)||firstValueStack(st)=='.')
		topStack(st, '0');
}
void deleteLastZero(stack &st)
{
	if (isDouble(st))
	{
		while (lastValueStack(st) == '0')
			popEndStack(st);
		if (lastValueStack(st) == '.')
			popEndStack(st);

	}
}
bool isDouble(stack st)
{
	for (node*p = st.pHead; p != NULL; p = p->pNext)
	if (p->data == '.')
	{
		return true;
	}
	return false;
}
bool isMinus(stack st)
{
	if (st.pHead->data == '-')
	{
		return true;
	}
	return false;
}
void addMinus(stack &st)
{
	topStack(st, '-');
}
void delMinus(stack &st)
{
	popStack(st);
}

stack makeError()
{
	stack err; initStack(err);
	topEndStack(err, 'E');
	topEndStack(err, 'R');
	topEndStack(err, 'R');
	topEndStack(err, 'O');
	topEndStack(err, 'R');
	return err;
}
stack makeOutOfTime()
{
	stack err; initStack(err);
	topEndStack(err, 'O');
	topEndStack(err, 'u');
	topEndStack(err, 't');
	topEndStack(err, ' ');
	topEndStack(err, 'o');
	topEndStack(err, 'f');
	topEndStack(err, ' ');
	topEndStack(err, 'T');
	topEndStack(err, 'i');
	topEndStack(err, 'm');
	topEndStack(err, 'e');
	topEndStack(err, '!');
	return err;
}
stack makeStack_1()
{
	stack st_1; initStack(st_1);
	topEndStack(st_1, '1');
	return st_1;
}
stack makeStack_0()
{
	stack st_0; initStack(st_0);
	topEndStack(st_0, '0');
	return st_0;
}