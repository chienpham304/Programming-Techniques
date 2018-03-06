#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*Đọc dữ liệu vào data
- Input: đường dẫn file input, mảng nguyên, số phần tử mảng, tổng S
- Ouput: Mảng a chứa n phần tử, tổng S*/
void readData(char*path, int*&a, int&n, int&S);

/*Xây dựng bảng phương án
- Input: Mảng nguyên a n phần từ, tổng s, mảng 2 chiều L nhị phân
- Output: Mảng 2 chiều L là bảng phương án*/
void buildSolutionTable(int*a, int n, int S, bool**&L);

/*Truy vết và in kết quả
- Input: tên file, mảng a, n phần từ, tổng s, ma trận truy vấn
- Output: dãy con có tổng bằng s, không có sẽ in ra thong báo*/
void traceAndPrintResult(char*path, int*a, int n, int S, bool**L);