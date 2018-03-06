#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*Đọc dữ liệu vào data
- Input: đường dẫn file input, mảng nguyên, số phần tử mảng
- Ouput: Mảng a chứa n phần tử*/
void readData(char*path, int*&a, int&n);

/*Tìm tổng của mảng (tổng số kẹo)
- Input: mảng a, n phần tử
- Output: số nguyên tổng các phần tử*/
int sumArray(int*a, int n);

/*Xây dựng bảng phương án
- Input: Mảng nguyên a n phần từ, tổng T, mảng 2 chiều L nhị phân
- Output: Mảng 2 chiều L là bảng phương án*/

void buildSolutionTable(int*a, int n, int T, bool**&L);
/*Truy vết và in kết quả
- Input: tên file, mảng nguyên a, n phần từ, tổng T, ma trận truy vấn
- Output:mảng nguyen luu dãy con có tổng bằng s, không có sẽ in ra thong báo*/
void traceAndPrintResult(char*path, int*a, int n, int T, bool**L);