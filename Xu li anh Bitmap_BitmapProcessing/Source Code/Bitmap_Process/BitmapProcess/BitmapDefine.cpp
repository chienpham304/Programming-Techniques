#include "BitmapDefine.h"

//Bitmap Header Function
void readBitmapHeader(char*path, Bitmap &Image)
{
	FILE *f = fopen(path, "rb");
	if (f == NULL)
	{
		printf("\nBitmap file is not avaiable!!");
		return;
	}
	fseek(f, 0, 0);
	fread(&Image.BmHeader.signature, 1, 2, f);
	Image.BmHeader.signature[2] = 0;
	fread(&Image.BmHeader.fileSize, 4, 1, f);
	fread(&Image.BmHeader.reserved1, 2, 1, f);
	fread(&Image.BmHeader.reserved2, 2, 1, f);
	fread(&Image.BmHeader.dataOffset, 4, 1, f);
	fclose(f);
}
void printBitmapHeader(Bitmap Image)
{
	printf("\n================<HEADER>===============");
	printf("\n - Type       : %s", Image.BmHeader.signature);
	printf("\n - File size  : %d KB (%d bytes)", Image.BmHeader.fileSize / 1024, Image.BmHeader.fileSize);
	printf("\n - Reserved 1 : %d byte", Image.BmHeader.reserved1);
	printf("\n - Reserved 2 : %d byte", Image.BmHeader.reserved2);
	printf("\n - Data offset: %d \n", Image.BmHeader.dataOffset);
	//printf("\n====================================");
}

//Bitmap Info Function
void readBitmapInfo(char*path, Bitmap &Image)
{
	FILE *f = fopen(path, "rb");
	if (f == NULL)
	{
		printf("\nBitmap file is not avaiable!!");
		return;
	}
	fseek(f,sizeof(BitmapHeader)-2,0L);
	fread(&Image.BmInfo, sizeof(Image.BmInfo), 1, f);
	fclose(f);
}
void printBitmapInfo(Bitmap Image)
{
	printf("\n=============<IMAGE_INFO>==============");
	printf("\n - DIB size    : %d byte", Image.BmInfo.dibSize);
	printf("\n - Width       : %d pixels", Image.BmInfo.imageWidth);
	printf("\n - Height      : %d pixels", Image.BmInfo.imageHeight);
	printf("\n - Color Planes: %d", Image.BmInfo.colorPlane);
	printf("\n - Color Depth : %d bits", Image.BmInfo.colorDepth);
	printf("\n - Compression algorithm : %d", Image.BmInfo.compressMethod);
	printf("\n - Pixel Array size      : %d", Image.BmInfo.pixelArraySize);
	printf("\n - Horizontal resolution : %d (pixels/m)", Image.BmInfo.horizontalResolution);
	printf("\n - Vertical resolution   : %d (pixcels/m)", Image.BmInfo.verticalResolution);
	printf("\n - Number of colors      : %d", Image.BmInfo.numOfColors);
	printf("\n - NUmber of important colors: %d", Image.BmInfo.numOfImportantColors);
	printf("\n");
	//printf("\n====================================");
}

//Read Bitmap Data
void readBitmapData(char *path, Bitmap &Image,char*&data)
{
	FILE *f = fopen(path, "rb");
	if (f == NULL)
	{
		printf("\nBitmap file is not avaiable!!");
		return;
	}
	fseek(f, Image.BmHeader.dataOffset, 0L);
	//read Bitmap data into temp memory
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	int padding = width % 4;//phần bù
	int sizeOfData = (height * width*(Image.BmInfo.colorDepth / 8)) + (padding*height);
	//colorDepth/8 : số kênh màu
	//tmpData = (char*)malloc(sizeOfData*sizeof(char));
	data = new char[sizeOfData];
	fread(data, sizeof(char), sizeOfData, f);
	//show bitmap data in hexa (sizeofData implements)
	/*for (int i = 0; i < sizeOfData;i++)
	{
		printf("%x ", *(data+i));

	}*/
	fclose(f);
}
//Write data to other file
void writeBimapFile(char *path, Bitmap &Image, char*&data)
{
	FILE *f = fopen(path, "wb+");
	if (f == NULL)
	{
		printf("\n- Error writing file!!\n");
		return;
	}
	//write header
	fseek(f, 0, 0);
	fwrite(&Image.BmHeader.signature, 1, 2, f);
	fwrite(&Image.BmHeader.fileSize, 4, 1, f);
	fwrite(&Image.BmHeader.reserved1, 2, 1, f);
	fwrite(&Image.BmHeader.reserved2, 2, 1, f);
	fwrite(&Image.BmHeader.dataOffset, 4, 1, f);
	//write info
	fwrite(&Image.BmInfo, sizeof(BitmapInfo), 1, f);
	//write data
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	int padding = width % 4;//phần bù
	int sizeOfData = (height * width*(Image.BmInfo.colorDepth / 8)) + (padding*height);
	//colorDepth/8 : số kênh màu
	fwrite(data, 1, sizeOfData, f);
	printf("\n- Done!!\nPath: %s\n", path);
	fclose(f);
}

//Init a 2D Pixel Array
void initPixArr(Pix**&pixArr, int height, int width)
{
	pixArr = new Pix*[height];
	for (int i = 0; i < height; i++)
		pixArr[i] = new Pix[width];
}

//Convert Data to Pixel Array
void convertDataToPixelArr(Bitmap &Image, char *&data,Pix **&pixArr)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	int padding = width % 4;
	char *temp = data;
	//Init 2DArr
	initPixArr(pixArr, height, width);
	if (pixArr == NULL)
	{
		printf("\nError: Not enough memory!!!");
		return;
	}
	//Get Pixel
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pixArr[i][j].B = *(temp++);
			pixArr[i][j].G = *(temp++);
			pixArr[i][j].R = *(temp++);
		}
		temp += padding;
	}
}

//Convert Pixel Array to Data
void convertPixelArrToData(Bitmap &Image, Pix**&pixArr,char*&data)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;	
	int padding = width % 4;
	int sizeOfData = (height * width*(Image.BmInfo.colorDepth / 8)) + (padding*height);

	//data = new char[sizeOfData];
	char*temp = new char[sizeOfData];
	data = temp;
	if (data == NULL)
	{
		printf("\nError: Not enough memory!!!");
		return;
	}
	//Get Pixel
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			*(temp++) = pixArr[i][j].B;
			*(temp++) = pixArr[i][j].G;
			*(temp++) = pixArr[i][j].R;
		}
		for (int k = 0; k < padding; k++)
			*(temp++) = 0;
	}
}

//Copy a pixcel array
void copyPixelArray(Pix**pixSource, Pix**&pixDest,int height,int width)
{
	initPixArr(pixDest, height, width);
	//copy pixArr to TmpArr
	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		pixDest[i][j] = pixSource[i][j];
	}
}

//Draw image on screen
void drawBmp(Bitmap Image, Pix **pixArr,int x,int y)
{
	//system("cls");
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);

	for (int i = Image.BmInfo.imageHeight - 1;i>=0; i--)
	//for (int i = 0; i < Image.BmInfo.imageHeight ; i++)
	for (int j = 0; j < Image.BmInfo.imageWidth  ; j++)
	//for (int j = 0; j < Image.BmInfo.imageWidth; j++)
	{
		Pix pixel = pixArr[i][j];
		SetPixel(hdc, j+x,Image.BmInfo.imageHeight-i+y, RGB(pixel.R, pixel.G, pixel.B));
	}

	ReleaseDC(console, hdc);
}

//===========
void showMenu()
{
	//Fullscreen
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//Read menufile
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	//đọc file test vào chuỗi
	wchar_t *menu = new wchar_t[1000];
	menu[0] = '\0'; menu[0] = '\0';
	FILE *fTest = _wfopen(L"Menu.txt", L"r,ccs=UTF-8");
	if (!fTest)
	{
		wprintf(L"\nError: Cannot open file !!!\nPress any key to exit");
		_getch();
		exit(0);
		return;
	}
	else
	{
		textcolor(11);
		while (!feof(fTest))
		{
			fgetws(menu, 1000, fTest);
			wprintf(L"%s", menu);
		}
	}
	textcolor(7);
	fclose(fTest);
	_setmode(_fileno(stdout), _O_TEXT);
	_setmode(_fileno(stdin), _O_TEXT);
	//Decorate screen
	
}