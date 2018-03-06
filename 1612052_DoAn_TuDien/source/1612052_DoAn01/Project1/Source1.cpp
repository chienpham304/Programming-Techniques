#include "Header1.h"
int main()
{
	//_setmode(_fileno(stdout), _O_U16TEXT); //cần để viết được ký tự utf-16 ra stdout
	//_setmode(_fileno(stdin),  _O_U16TEXT); //cần để đọc được ký tự utf-16 từ stdin
	
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	int choice = 0;
	wchar_t*strTest = new wchar_t[];
	//nhapTiengViet(strTest);

	int soTuDon;
	int soTuGhep,soTuGhepNC;
	int soTuLay; 
	int soTu;
	//std::wcin >> strTest;
	///menu
	wprintf(L"\n=================<ĐẾM TỪ LOẠI TIẾNG VIỆT>=====================");
	wprintf(L"\n  01. Nhập từ file");
	wprintf(L"\n  02. Nhập trực tiếp");
	wprintf(L"\n  03. Đếm từ đơn");
	wprintf(L"\n  04. Đếm từ ghép");
	wprintf(L"\n  05. Đếm từ ghép nâng cao");
	wprintf(L"\n  06. Đếm từ láy");
	wprintf(L"\n  07. Đếm từ");
	wprintf(L"\n  08. Thoát");
	wprintf(L"\n=============================<>===============================");
	
	wchar_t**data=NULL;
	docChuoi(L"File/test_File.txt", strTest);
	data = getData(strTest, 4);
	//wprintf(L"\n[Đầu vào]: %s", strTest);
//	wchar_t**data = getData(strTest, 4);
	do
	{
		wprintf(L"\n  ->  Chọn:");
		wscanf(L"%d", &choice);
		switch (choice)
		{
		case 1:
			wprintf(L"\n[Đầu vào]: %s", strTest);
			wprintf(L"\n------------------------------------");
			break;
		case 2:
			*strTest = 0;
			wprintf(L"\nMời nhập: %s");
			nhapTiengViet(strTest);
			wprintf(L"\n[Đầu vào]: %s", strTest);
			data = getData(strTest, 4);
			wprintf(L"\n------------------------------------");
			break;
		case 3:
			wprintf(L"\n- TỪ ĐƠN: ");
			soTuDon = demTuDon(data);
			wprintf(L"\n  Tổng: %d", soTuDon);
			wprintf(L"\n------------------------------------");
			break;
		case 4:
			wprintf(L"\n- TỪ GHÉP: ");
			soTuGhep = demTuGhep(data);
			wprintf(L"\n  Tổng: %d", soTuGhep);
			wprintf(L"\n------------------------------------");
			break;
		case 5:
			wprintf(L"\n- TỪ GHÉP NÂNG CAO: ");
			soTuGhepNC = demTuGhepNC(data);
			wprintf(L"\n  Tổng: %d", soTuGhepNC);
			wprintf(L"\n------------------------------------");
			break;

		case 6: 
			wprintf(L"\n- TỪ LÁY: ");
			soTuLay = demTuLay(data);
			wprintf(L"\n  Tổng: %d", soTuLay);
			wprintf(L"\n------------------------------------");
			break;
		case 7:
			wprintf(L"\n- TỪ: ");
			//int soTu = demTu2(strTest);
			soTu = demTu3(strTest);
			wprintf(L"\n  Tổng: %d", soTu);
			wprintf(L"\n------------------------------------");
			break;
		case 8: exit(0); break;
		default:
			wprintf(L"\n(#-#) <>>>>>Chọn lại<<<<>>>");
			wprintf(L"\n------------------------------------");
			break;
		}
	} while (choice != 8);
	
	//_getch();
	return EXIT_SUCCESS;
}