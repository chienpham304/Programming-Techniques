#include <iostream>
#include <conio.h>
using namespace std;

int timUocChungLonNhat(int a,int b){
	//chỉ xét a,b>0
	if (a == b)
		return a;
	else{
		(a > b) ? timUocChungLonNhat(a - b, b) : timUocChungLonNhat(a, b - a);
	}
}

void main(){
	int a = 10, b = 5;
	cout << "UCLN(" << a << "," << b << ")=" << timUocChungLonNhat(a, b) << endl;
	_getch();
}