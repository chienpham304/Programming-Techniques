//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <wchar.h>
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
//time
#include <time.h>
using namespace std;

void taoTuDien(wchar_t*path_source, wchar_t*path_dest);
void taoFileTuDienTheoKiTu(wchar_t*path_source, wchar_t ch, wchar_t const ch_next);
void taoFileTuDienTheoTenRieng(wchar_t*path_source, wchar_t ch);
void chuanHoaChuoi(wchar_t*&s);
void xoaKyTuThua(wchar_t*&s);
void xoaKiTuThuI(wchar_t*&s, int vt);