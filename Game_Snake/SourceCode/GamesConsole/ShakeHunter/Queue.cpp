#include "Queue.h"
//#include "header.h"
//khởi tạo QUEUE
void Init(Queue &q){
	q.front = 0;//lúc nào front cũng bằng 0;
	q.rear = -1;//ban đầu chưa có phần tử nào
	q.count = 0;
	for (int i = 0; i < MaxRow; i++)
		q.a[i] = NULL;
}
//kiểm tra xem Q có trống không
bool IsEmpty(Queue q){
	if (q.count == 0)
		return true;
	return false;
}
//kiểm tra Queue đầy 
bool IsFull(Queue q){
	if (q.count == MaxRow)
		return true;
	return false;
}
//thêm phần tử n vào cuối Queue
void Push(Queue& q, int n){
	q.rear++;
	q.a[q.rear] = n;
	q.count++;
}
void Push_Front(Queue& q, int n){
	q.count++;
	q.rear++;
	for (int i = q.rear; i >= 1; i--)
		q.a[i] = q.a[i - 1];
	q.a[0] = n;
}
//lấy ra phần tử đầu tiên
int Pop(Queue&q){
	int kq = q.a[q.front];
	for (int i = q.front; i < q.rear; i++)
		q.a[i] = q.a[i + 1];
	q.a[q.rear] = NULL;
	q.rear--;
	q.count--;
	return kq;
}
//trả về phần tử đầu của queue(ko lấy ra)
int GetFirst(Queue q){
	return q.a[q.front];
}