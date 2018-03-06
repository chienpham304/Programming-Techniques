#include "Header1.h"

void chuanHoaChuoi(wchar_t*&s)
{
	//int n = wcslen(s);
	//xoa khoang trắng '@'
	while (*s == ' ' || *s=='\n')
	{
		for (int i = 0; i < wcslen(s); i++)
			*(s + i) = *(s + i + 1);
	}
	
	//xoa ki tu trang thua o giua xau

	for (int i = 0; i<wcslen(s); i++)
	if (*(s + i) == ' ' && (*(s + i + 1) == ' ' || *(s + i + 1) == ',')||*(s + i + 1) == '.')
	{
		for (int j = i; j < wcslen(s); j++)
		{
			*(s + j) = *(s + j + 1);
			i--;
		}
		//*(s + i) = *(s + i + 1);
	}

	// xoa ki tu trang o cuoi xau
	while (*(s + wcslen(s) - 1) == ' '||*(s + wcslen(s) - 1) == '\n')
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
int viTriDauCachThuK(wchar_t*s, int k)
{//chuoi s da chua n hoa
	int n = wcslen(s);
	if (n == 0)
		return -1;
	int idex = 0, vt = -1;

	for (int i = 0; i < n; i++)
	if (s[i] == ' ')
	{
		idex++; vt = i;
		if (idex == k)
			if(kiemTraDauCau(s[vt-1]))
				return vt-1;
			else 
				return vt;
	}
	if (idex == k - 1)
		if (kiemTraDauCau(s[n-1]))
			return n-1;
		else return n;
	return -1;
}
bool kiemTraDauCau(wchar_t const x)
{
	if (x == L',' || x == L'.' || x == L':' || x == L';' || x == L'?' ||
		x == L'!' || x == L'(' || x == L')')
		return true;
	return false;
}