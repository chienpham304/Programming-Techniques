#ifndef _SOLVEEXPRESSION_H
#define _SOLVEEXPRESSION_H
#include "SimpleLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define BRACKET_OPEN -1
#define BRACKET_CLOSE -2
#define SUB -3
#define DEC -4
#define MUL -5
#define DIV -6
#define POW -7
#define MOD -8
//Hàm nhập biểu thức
void inputExpression(char*&s);
//Hàm lấy phần từ từ biểu thức, trả ra số kí tự được lấy, giá trị gán vào chuỗi dest
int getElement(char *s, char *&dest);
//Chuyển số sang kí hiệu của toán tử
char digitToSymbol(int x);
//Chuyển toán tử thành số(theo quy ước)
int symbolToDigit(char c);
//Hàm tính toán theo toán tử
float calculate(int x1, int x2, int oper);
//Hàm tính độ ưu tiên của toán tử
int priority(int sym);
//Hàm chuyển biểu thức trung tố sang hậu tố
void covertToPostfix(char*s, Queue &q);
//Hàm tính giá trị của biểu thức hậu tố (tính GTBN)
float solveExpression(Queue &q);
//In ra man hinh bieu thuc hau to
void printfPostfix(QUEUE qt);
#endif