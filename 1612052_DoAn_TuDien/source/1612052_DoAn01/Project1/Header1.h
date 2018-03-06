#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <wchar.h>
#include <string.h>
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
//time
#include <time.h>
#define MaxLength 255
#define MaxNum 4
using namespace std;

/*Đọc chuỗi từ file 
-Input: đường dẫn path_test, chuỗi strTest
-Output: chuỗi strTest chứa chuỗi trong file*/
void docChuoi(wchar_t*path_test, wchar_t *&strTest);

/*Nhập chuỗi từ bàn phím
-Input: biến chuỗi cần nhập
-Output: chuỗi s*/
void nhapTiengViet(wchar_t*&s);

/*Đếm số lượng từ đơn trong câu
-Input: mảng 2 chiều với mỗi dòng là một chuỗi
-Output: số lượng từ đơn có trong câu*/
int demTuDon(wchar_t**data);

/*Đếm số lượng từ ghép cơ bản
-Input: mảng 2 chiều với một dòng là một chuỗi
-Output: số lượng từ ghép có trong câu*/
int demTuGhep(wchar_t**data);

/*Đếm số lượng từ ghép nâng cao
-Input: mảng 2 chiều với một dòng là một chuỗi
-Output: số lượng từ ghép nâng cao có trong câu*/
int demTuGhepNC(wchar_t**data);

/*Đếm số lượng từ láy
-Input: mảng 2 chiều với một dòng là một chuỗi
-Output: số lượng từ láy có trong câu*/
int demTuLay(wchar_t**data);

/*Đếm số lượng từ có nghĩa (nâng cao)
-Input: mảng 2 chiều với một dòng là một chuỗi
-Output: số lượng từ có nghĩa có trong câu*/
int demTu3(wchar_t*strTest);


/*Kiểm tra chuỗi s có trong từ điển hay không
-Input: chuỗi s cần kiểm tra
-Output: true nêu có, false nếu không*/
bool kiemTraCoNghia(wchar_t*s);

/*Kiểm tra chuỗi s có trong từ điển hay không
-Input: chuỗi s cần kiểm tra
-Output: true nêu có, false nếu không*/
bool kiemTraNangCao(wchar_t*strTest);

/*Kiểm tra chuỗi s có trong file stopWords không
-Input: chuỗi s cần kiểm tra
-Output: true nêu có, false nếu không*/
bool kiemTraStopWords(wchar_t*s);

/*Kiểm tra chuỗi s có trùng trong data không
-Input: chuỗi s cần kiểm tra
-Output: true nêu có, false nếu không*/
bool kiemTraTrung(wchar_t**data, int vt);

/*Tạo mảng data 2 chiều từ câu đã cho
-Input: chuỗi strTest cần tách, số lượng từ tối đa
-Output: mảng data 2 chiều*/
wchar_t**getData(wchar_t*strTest, int Num);

/*Tạo chuỗi chứa phần đầu của từ (s)
-Input: chuỗi s cần lấy
-Output: chuỗi chứa phần đầu của s*/
wchar_t*layPhuAm(wchar_t*s);

/*Tạo chuỗi chứa phần sau của từ (s)
-Input: chuỗi s cần lấy
-Output: chuỗi chứa phần sau của s*/
wchar_t*layNguyenAm(wchar_t*s);


/*Tìm vị trí dấu cách thứ K trong chuỗi 
-Input: chuỗi s cần kiểm tra, số k
-Output: sô nguyên chỉ vị trí dâu cách thứ k, trường hợp sai trả về -1*/
int viTriDauCachThuK(wchar_t*s, int k);


/*Tạo chuỗi chứa K từ đầu tiên trong chuỗi source
-Input: chuỗi nguồn source, chuỗi đích dest, số nguyên k
-Output: chuỗi dest chứa k từ đầu của chuỗi source*/
int LayKTuDauTien(wchar_t *source, wchar_t *&dest, int k);

/*Chuẩn hóa chuỗi: xóa dầu cách thừa
-Input: chuỗi s chuẩn hóa
-Output: chuỗi s đã chuẩn hóa*/
void chuanHoaChuoi(wchar_t*&s);

/*Xóa kí tự thừa trong s
-Input: chuỗi s cần lấy
-Output: chuỗi chứa phần đầu của s*/
void xoaKyTuThua(wchar_t*&s);
void xoaKiTuThuI(wchar_t*&s, int vt);

/*Kiểm tra kí tự x có phải là một dấu câu hay không
-Input: kí tự x
-Output: true nếu phải, fase ngược lại*/
bool kiemTraDauCau(wchar_t const x);

/*Đếm số lượng từ phân cách bởi dấu cách trong câu
-Input: chuỗi s cần đếm
-Output: số nguyên chỉ số lượng từ trong chuỗi*/
int demSoTu(wchar_t*s);

/*Kiểm tra chuỗi s có phải là từ láy hay không
- Input: chuỗi s cần kiểm tra
- Output: true nếu phải, false ngược lại*/
bool kiemTraTuLay(wchar_t*s);
