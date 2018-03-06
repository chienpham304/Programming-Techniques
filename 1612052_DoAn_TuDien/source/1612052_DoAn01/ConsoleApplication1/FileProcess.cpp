#include "FileProcess.h"

void taoTuDien(wchar_t*path_source, wchar_t*path_dest)
{
	FILE *fSource = _wfopen(path_source, L"r,ccs=UTF-8");
	FILE *fDest = _wfopen(path_dest, L"w,ccs=UTF-8");

	if (!fSource || !fDest)
	{
		wprintf(L"Lỗi: Mở file thất bại !!!");
		return;
	}
	else
	{
		//wprintf(L"Mở file thành công !!!\n");
		//đọc chuỗi từ file test
		wchar_t *strTest = (wchar_t*)calloc(255, sizeof(wchar_t));

		while (!feof(fSource))
		{
			fgetws(strTest, 255, fSource);
			if (strTest[0] == '@')
			{
				chuanHoaChuoi(strTest);
				xoaKyTuThua(strTest);
				wprintf(L"%s", strTest);
				fwprintf(fDest, L"%s", strTest);
			}

			
		}
		//đếm số từ
	}
	_fcloseall();
}

//tao file tu dien co ki tu ch "ch.txt"
void taoFileTuDienTheoKiTu(wchar_t*path_source, wchar_t ch, wchar_t const ch_next)
{ 
	wchar_t next_sym = ch_next;
	wchar_t*path_dest = new wchar_t[255];
	path_dest = &ch;
	wcscat(path_dest, L".txt");
	FILE *fsource = _wfopen(path_source, L"r,ccs=UTF-8");
	FILE *fdest = _wfopen(path_dest, L"w,ccs=UTF-8");
	if (!fsource || !fdest)
	{
		wprintf(L"Lỗi: Mở file thất bại !!!");
		return;
	}
	else
	{
		//wprintf(L"Mở file thành công !!!\n");
		//đọc chuỗi từ file test
		wchar_t *strTest = (wchar_t*)calloc(255, sizeof(wchar_t));

		/*while (!feof(fsource))
		{
			fgetws(strTest, 255, fsource);
			if (strTest[0] == '@' && (int)strTest[1] >=(int)ch)
			{
				if ((int)strTest[1] == (int)ch_next)
					break;
				chuanHoaChuoi(strTest);
				xoaKyTuThua(strTest);
				wprintf(L"%s", strTest);
				fwprintf(fdest, L"%s", strTest);
			}
		}*/
		while (!feof(fsource))
		{
			fgetws(strTest, 255, fsource);
			if (strTest[0] == '@' && (int)strTest[1] == (int)ch)
			{
				do
				{
					chuanHoaChuoi(strTest);
					xoaKyTuThua(strTest);
					wprintf(L"%c_%s",ch, strTest);
					fwprintf(fdest, L"%s", strTest);
					fgetws(strTest, 255, fsource);
				} while ((int)strTest[1] != (int)next_sym);
				fseek(fsource,0L,SEEK_END);
			}
		}
		//đếm số từ
	}
	_fcloseall();

}

void taoFileTuDienTheoTenRieng(wchar_t*path_source, wchar_t ch)
{
	wchar_t*path_dest = (wchar_t*)calloc(20, sizeof(wchar_t));
	path_dest = &ch;
	wcscat(path_dest, L"_ten_rieng.txt");
	FILE *fsource = _wfopen(path_source, L"r,ccs=UTF-8");
	FILE *fdest = _wfopen(path_dest, L"w,ccs=UTF-8");
	if (!fsource || !fdest)
	{
		wprintf(L"Lỗi: Mở file thất bại !!!");
		return;
	}
	else
	{
		//wprintf(L"Mở file thành công !!!\n");
		//đọc chuỗi từ file test
		wchar_t *strTest = (wchar_t*)calloc(255, sizeof(wchar_t));

		while (!feof(fsource))
		{
			fgetws(strTest, 255, fsource);
			if (strTest[0] == '@' && (int)strTest[1] == (int)ch)
			{
				chuanHoaChuoi(strTest);
				xoaKyTuThua(strTest);
				wprintf(L"%s", strTest);
				fwprintf(fdest, L"%s", strTest);
			}
		}
		//đếm số từ
	}
	_fcloseall();

}


void chuanHoaChuoi(wchar_t*&s)
{
	//int n = wcslen(s);
	//xoa khoang trắng '@'
	while (*s == ' ')
	{
		for (int i = 0; i < wcslen(s); i++)
			*(s + i) = *(s + i + 1);
	}


	//xoa ki tu trang thua o giua xau

	for (int i = 0; i<wcslen(s); i++)
	if (*(s + i) == ' ' && *(s + i + 1) == ' ')
	{
		for (int j = i; j < wcslen(s); j++)
		{
			*(s + j) = *(s + j + 1);
			i--;
		}
		//*(s + i) = *(s + i + 1);
	}

	// xoa ki tu trang o cuoi xau
	while (*(s + wcslen(s) - 1) == ' ')
		*(s + wcslen(s) - 1) = *(s + wcslen(s));

	//viet Thuong het, (chuẩn hóa Wchar_t) 

	for (int i = 0; i < wcslen(s); i++)
	{
		//đoạn từ [65-89] và[224-253]: viết thường = x+32
		if ((65 <= *(s + i) && *(s + i) <= 89) || (192 <= *(s + i) && *(s + i) <= 221))
			*(s + i) = *(s + i) + 32;

		//đoạn từ [258-416]: chữ hoa là chẵn, chữ thường tương ứng = hoa +1
		//riêng kí tự 'Ư' (431) - 'ư' (432) độc lập
		else if ((((258 <= *(s + i) && *(s + i) <= 416) && (int)*(s + i) % 2 == 0)) || ((int)*(s + i) == 431))
			*(s + i) += 1;
		//đoạn từ[7840 - 7928]: chữ hoa là chẵn, chữ thường tương ứng = hoa + 1
		else if (((7840 <= *(s + i) && *(s + i) <= 7928) && (int)*(s + i) % 2 == 0))
			*(s + i) += 1;
	}


}
void xoaKiTuThuI(wchar_t*&s, int vt)
{
	for (int i = vt; i < wcslen(s); i++)
		*(s + i) = *(s + i + 1);
}
void xoaKyTuThua(wchar_t*&s)
{
	for (int i = 0; i < wcslen(s); i++)
	{
		if (*(s + i) == ',' || *(s + i) == '(')
		{
			*(s + i) = '\0';
			break;
		}
	}
	//xóa khoảng trắng cuối
	while (*(s + wcslen(s) - 1) == ' ')
		*(s + wcslen(s) - 1) = *(s + wcslen(s));
}