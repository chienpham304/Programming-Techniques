#include "FileProcess.h"

void main(){
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	//tạo file từ điển từ file gốc của eDict Bkav
	//taoTuDien(L"vvDict.txt", L"library_File.txt");
	for (int i = L'a'; i <= L'y'; i++)
		taoFileTuDienTheoKiTu(L"abc.txt", char(i),char(i+1));
	getch();
}