#include "Header1.h"
//kiểm tra từ đơn <Được phép trùng> 
int demTuDon(wchar_t**data)
{
	int count = 0;
	for (int i = 0; *(data + i) != NULL; i++)
	{
		if (demSoTu(data[i]) == 1)
		{
			//
			if (kiemTraCoNghia(data[i]))
			{
				wprintf(L" %s", *(data + i));
				wprintf(L",");
				//wprintf(L" => [Từ đơn]");
				count++;
			}
		}
	}
	return count;
}

//kiểm tra từ ghép <Không được trùng>
int demTuGhep(wchar_t**data)
{
	int count = 0;
	for (int i = 0; *(data + i) != NULL; i++)
	{
		if (demSoTu(data[i]) > 1 && kiemTraTrung(data,i)==false)//không trùng
		{
			//
			if (kiemTraCoNghia(data[i]))
			{
				wprintf(L" %s", *(data + i));
				wprintf(L",");
				//wprintf(L" => [Từ ghép]");
				count++;
			}
		}
	}
	
	return count;
}
//kiểm tra từ ghép <Không được trùng>
int demTuGhepNC(wchar_t**data)
{
	int count = 0;
	for (int i = 0; *(data + i) != NULL; i++)
	{
		if (demSoTu(data[i]) > 1 && kiemTraTrung(data, i) == false)//không trùng
		{
			//
			if (kiemTraCoNghia(data[i]))
			{
				wprintf(L" %s", *(data + i));
				wprintf(L",");
				//wprintf(L" => [Từ ghép]");
				count++;
			}
			else if (kiemTraNangCao(data[i]))
			{
				wprintf(L" %s", *(data + i));
				wprintf(L",");
				//wprintf(L" => [Từ ghép]");
				count++;
			}
		}
	}

	return count;
}


//dem so từ
int demTu3(wchar_t*strTest)
{
	int count = 0; int n = 0;
	wchar_t *strTmp = new wchar_t[1000];
	wchar_t *strSTW = new wchar_t[1000];
	wchar_t *strEND = new wchar_t[1000];
	wchar_t **data = new wchar_t*[200];
	data[n] = new wchar_t[1];
	wcscpy(data[n], L"0");
	int vt, vtSTW;
	bool flag;
	while (demSoTu(strTest)>0)
	{
		flag = false;
		for (int i = 4; i > 0; i--)
		{
			vt = LayKTuDauTien(strTest, strTmp, i);
			if (vt == -1)
				continue;
			if (wcscmp(strTmp, data[n]) != 0)//ko trùng với từ trước
			{
				if (kiemTraCoNghia(strTmp))
				{
					data[++n] = new wchar_t[wcslen(strTmp)];
					wcscpy(data[n], strTmp);
					//wprintf(L"\n- %s", strTmp);
					flag = true;

					strTest = strTest + vt + 1;
					break;
				}
				else
				{
					for (int j = 1; j < demSoTu(strTmp); j++)
					{
						vtSTW = LayKTuDauTien(strTmp, strSTW, j);
						if (vtSTW != -1 && kiemTraStopWords(strSTW))
						{
							wcscpy(strEND, strTmp);
							strEND += vtSTW + 1;
							if (kiemTraCoNghia(strEND))
							{
								data[++n] = new wchar_t[wcslen(strTmp)];
								wcscpy(data[n], strTmp);
								flag = true;
								strTest = strTest + wcslen(strTmp);
								i = 0;//thoat ra vong for
								break;
							}
						}
					}
				}
			}
		}
		if (flag == false)
			strTest += viTriDauCachThuK(strTest, 1);
	}
	//kiểm tra và đếm
	for (int i = 1; i <= n; i++)
	{
		wprintf(L" %s", *(data + i)); wprintf(L",");
		//wprintf(L" => [Từ]");
	}

	return n;
}
//kiểm tra từ <không được trùng>
int demTuLay(wchar_t**data)
{
	int count = 0;
	for (int i = 0; *(data + i) != NULL; i++)
	{
		if (demSoTu(data[i]) >1 && kiemTraTrung(data, i) == false)//không trùng
		{
			//
			if (kiemTraCoNghia(data[i]))
			{
				if (kiemTraTuLay(data[i]))
				{
					wprintf(L"\n- %s", *(data + i));
					//wprintf(L" => [Từ láy]");
					count++;
				}
			}
		}
	}
	return count;
}

//Đọc chuỗi từ file
void docChuoi(wchar_t*path_test,wchar_t *&strTest)
{
	int count = 0;
	//đọc file test vào chuỗi
	strTest = new wchar_t[1000];
	wchar_t *strTmp = new wchar_t[1000];
	strTest[0] = '\0'; strTmp[0] = '\0';
	FILE *fTest = _wfopen(path_test, L"r,ccs=UTF-8");
	if (!fTest)
	{
		wprintf(L"\nLỗi: Mở file Test thất bại !!!\n[[Bấm phím bất kì để thoát]]");
		_getch();
		exit(0);
		return;
	}
	else
	{
		while (!feof(fTest))
		{
			fgetws(strTmp, 1000, fTest);
			wcscat(strTest, L" ");
			wcscat(strTest, strTmp);
			*strTmp = '\0';
		}
	}
	chuanHoaChuoi(strTest);
	//wprintf(L"\nChuỗi cần kiểm tra: %s\n==============================\n", strTest);
	*strTmp = '\0';
	wcscpy(strTmp, strTest);
	//*(strTmp + wcslen(strTmp)+1) = L'\0';
	//*(strTmp + wcslen(strTmp)) = L' ';
}

wchar_t**getData(wchar_t*strTest,int Num)
{
	wchar_t*strTmp = new wchar_t[1000];
	*strTmp = '\0';
	wcscpy(strTmp, strTest);
	*(strTmp + wcslen(strTmp)+1) = L'\0';
	*(strTmp + wcslen(strTmp)) = L' ';
	
	//cấp phát mảng 2 chiều wchar_t
	wchar_t **data = new wchar_t*[200];
	vector <int> a;
	a.push_back(-1);
	for (int i = 0; i < wcslen(strTmp); i++)
	{
		if (*(strTmp + i) == L' ')
			a.push_back(i);
	}
	//a.push_back(wcslen(strTmp));
	//cắt mỗi phần tử thành đoạn có Num từ
	if (Num > demSoTu(strTest))
		Num = demSoTu(strTest);

	int i = 0;
	for (int k = 1; k <= Num;k++)
	{
		for (int j = 0; j + k < a.size(); j++)
		{
			int lenStr = a.at(j + k) - a.at(j) - 1;
			wchar_t *temp = new wchar_t[lenStr];
			wcsncpy(temp, (strTmp + a.at(j) + 1), lenStr);
			temp[lenStr] = L'\0';
			if (wcslen(temp)>0)
			{
				data[i] = new wchar_t[lenStr];
				wcscpy(data[i], temp);
				i++;
			}
		}
	}
	data[i] = NULL;
	//*(data + i) = L'\0';//đánh dấu kết thúc*/
	return data;
}

//sửa lại là tự động bắt file resource luôn cho máu
bool kiemTraCoNghia(wchar_t*s)
{
	bool kq = false;
	wchar_t ch = *s;//lay kis tu dau;
	//xét các trường hợp đặc biệt có dấu: (chắc chắn là toàn chữ thường)
	if ((224 <= ch && ch <= 227) || ch == 259 || (7840 <= ch && ch <= 7863))
		ch = L'a';
	else
	if (272<=ch && ch<=273)
		ch = L'd';
	else
	if ((232 <=ch && ch<= 234) || (7864 <=ch && ch<= 7879))
		ch = L'e';
	else
	if ((236 <=ch && ch<= 237) || (7880 <=ch && ch<= 7883))
		ch = L'i';
	else
	if ((242 <=ch && ch<= 245) || (7884 <=ch && ch<= 7907))
		ch = L'o';
	else
	if ((249 <=ch && ch<= 250) || (7908 <=ch && ch<= 7921))
		ch = L'u';
	else
	if ((ch == 253) || (7922 <= ch && ch <= 7929))
		ch = L'y';
	else if (ch <= 65 || ch >= 'z')
		return false;//kí tự

	wchar_t*path_resource = new wchar_t[255];
	wcscpy(path_resource, L"File/File_Alphabet/");

	//*path_resource = ch;
	*(path_resource + 19) = ch; *(path_resource + 20) = '\0';
	wcscat(path_resource, L".txt");
	//*(path_resource + 23) = '\0';
	//
	FILE *fSource = _wfopen(path_resource, L"r,ccs=UTF-8");
	if (!fSource)
	{
		wprintf(L"\nLỗi: Mở file tu dien thất bại!!! \n[Bấm phím bất kì để thoát]");

		_getch();
		//exit(0);
		return false; 
	}
	else
	{
		//wprintf(L"Mở file tu dien thành công !!!\n");
		//đọc chuỗi từ file tạm từ file nguồn
		wchar_t *strTest = (wchar_t*)calloc(255, sizeof(wchar_t));
		
		while (!feof(fSource))
		{
			//đọc từng dòng
			fgetws(strTest, 255, fSource);
			xoaKiTuThuI(strTest, 0);//xóa @
			xoaKiTuThuI(strTest, wcslen(strTest)-1);//xóa '\n'
			//wprintf(L"\n%s", strTest);
			if (wcscmp(s, strTest) == 0)
			{
				_fcloseall();
				return true;
			}
		}
	}
		//đếm số từ
	_fcloseall();
	return kq;
}
//kiem tra nang cao
bool kiemTraNangCao(wchar_t*strTest)
{
	bool kq = false;
	wchar_t *strTmp = new wchar_t[1000];
	wchar_t *strSTW = new wchar_t[1000];
	wchar_t *strEND = new wchar_t[1000];
	int vtSTW;
	wcscpy(strTmp, strTest);
	if (kiemTraCoNghia(strTmp))
	{
		kq = true;
	}
	else
	{
		for (int j = 1; j < demSoTu(strTmp); j++)
		{
			vtSTW = LayKTuDauTien(strTmp, strSTW, j);
			if (vtSTW != -1 && kiemTraStopWords(strSTW))
			{
				wcscpy(strEND, strTmp);
				strEND += vtSTW + 1;
				if (kiemTraCoNghia(strEND))
				{
					kq = true;
					strTest = strTest + wcslen(strTmp);
					break;
				}
			}
		}
	}
	return kq;
}

//
bool kiemTraStopWords(wchar_t*s)
{
	bool kq = false;
	wchar_t*path_resource = new wchar_t[255];
	wcscpy(path_resource, L"File/stopWords.txt");

	FILE *fSource = _wfopen(path_resource, L"r,ccs=UTF-8");
	if (!fSource)
	{
		wprintf(L"\nLỗi: Mở file tu dien thất bại!!! \n[Bấm phím bất kì để thoát]");
		_getch();
		return false;
	}
	else
	{
		//wprintf(L"Mở file tu dien thành công !!!\n");
		//đọc chuỗi từ file tạm từ file nguồn
		wchar_t *strTest = (wchar_t*)calloc(255, sizeof(wchar_t));

		while (!feof(fSource))
		{
			//đọc từng dòng
			fgetws(strTest, 255, fSource);
			xoaKiTuThuI(strTest, 0);//xóa @
			xoaKiTuThuI(strTest, wcslen(strTest) - 1);//xóa '\n'
			//wprintf(L"\n%s", strTest);
			if (wcscmp(s, strTest) == 0)
			{
				_fcloseall();
				return true;
			}
		}
	}
	fclose(fSource);
	return kq;
}
int demSoTu(wchar_t*s)
{
	if (*s == '\0')
		return 0;
	int count = 0;
	for (int i = 0; i < wcslen(s);i++)
	if (s[i] == L' ')
		count++;
	return count + 1;
}

//kiểm tra xem chuỗi data[vt] đã xuất hiện trong data chưa
bool kiemTraTrung(wchar_t**data, int vt)
{
	for (int i = 0; i < vt;i++)
	if (wcscmp(data[i], data[vt]) == 0)
		return true;
	return false;//không trùng
}

//kiểm tra từ láy
bool kiemTraTuLay(wchar_t*s)
{
	int soTu = demSoTu(s);
	wchar_t **data = new wchar_t*[soTu];
	//lấy từng chữ ghép vào data
	int k = -1;
	int prevPos = 0;
	//s = "anh chien dep chai"
	for (int i = 0; i <= wcslen(s); i++)
	{
		if (s[i] == ' ' || s[i]=='\0')
		{
			k++;
			data[k] = new wchar_t[i-prevPos+1];
			wcsncpy(data[k], s+prevPos, i-prevPos);
			data[k][i - prevPos] = '\0';
			prevPos = i + 1;
		}
	}
	wchar_t * nguyenDau = layNguyenAm(data[0]);
	wchar_t * phuDau = layPhuAm(data[0]);
	wchar_t * nguyenSau = layNguyenAm(data[0]);
	wchar_t * phuSau = layPhuAm(data[0]);
	//xử lí thằng sau
	for (int i = 1; i <= k; i++)
	{
		//tách nguyên âm, phụ âm
		nguyenSau = layNguyenAm(data[i]);
		phuSau = layPhuAm(data[i]);
		//so sánh với phần tử ở trước, nếu sai fasle ngay
		if (wcscmp(nguyenDau, nguyenSau) != 0 && wcscmp(phuDau, phuSau) != 0)
			return false;
		else
		{
			nguyenDau = layNguyenAm(data[i]);
			phuDau= layPhuAm(data[i]);
		}
	}
	return true;
}

wchar_t*layPhuAm(wchar_t*s)//s chỉ gồm 1 từ
{
	//phụ âm là thuộc từ b=>z trừ 5 nguyên âm: ue oai
	wchar_t*PhuAm = new wchar_t[wcslen(s)];
	int i = 0;
	while (i < wcslen(s) && (L'b' <= s[i] && s[i] <= 'z'&&s[i] != L'u'&&s[i] != L'e'&&s[i] != L'o'&& s[i] != L'i'))
	{
		PhuAm[i] = s[i];
		i++;
	}
	PhuAm[i] = '\0';

	return PhuAm;
}

wchar_t*layNguyenAm(wchar_t*s)//s chỉ gồm 1 từ
{
	//nguyên âm là phần sau phụ âm
	wchar_t*NguyenAm= new wchar_t[wcslen(s)];
	int i = 0;
	while (i < wcslen(s) && (L'b' <= s[i] && s[i] <= 'z'&&s[i] != L'u'&&s[i] != L'e'&&s[i] != L'o'&&s[i] != L'i'))
	{
		i++;
	}
	int j;
	for(j = 0;i<wcslen(s);i++,j++)
		NguyenAm[j] = s[i];
	NguyenAm[j] = '\0';
	return NguyenAm;
}

int LayKTuDauTien(wchar_t *source, wchar_t *&dest, int k)
{
	if (k > demSoTu(source) || *source==0)
		return -1;
	else
	{
		chuanHoaChuoi(source);//xóa các kí tự không llieen quan
		int viTri = viTriDauCachThuK(source,k);
		wcscpy(dest, source);
		dest[viTri] = 0;
		return viTri;
	}
}
void nhapTiengViet(wchar_t*&s)
{

}
