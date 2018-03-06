#include "SimpleLinkedList.h"

#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct Queue
{
	LIST qList;
}QUEUE;

//Khởi tạo queue
void initQueue(Queue &q);

//Đóng queue (xóa bộ nhớ)
void closeQueue(QUEUE &q);

//Kiểm tra Queue có rỗng hay không
bool isEmptyQueue(Queue q);

//Thêm giá trị value vào đầu queue 
void enQueue(Queue& q, int value);

//lấy ra phần tử cuối và xóa khỏi queue
int deQueue(Queue&q);

//lấy giá trị phần tử ĐẦU queue (không xóa)
int firstValueQueue(Queue q);

//lấy giá trị phần tử CUỐI queue (không xóa)
int lastValueQueue(Queue q);
#endif