#ifndef _BITMAPDEFINE_H
#define _BITMAPDEFINE_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
/*The bitmap-file header contains information about the type, size, and layout
of a device-independent bitmap file. The header is defined as a
BITMAPFILEHEADER structure.*/
struct BitmapHeader
{
	//The oder mustn't be changed
	char signature[2];//2 bytes
	unsigned int fileSize;//4 byte
	unsigned short reserved1;//2 byte
	unsigned short reserved2;//2 byte
	unsigned int dataOffset;//4 byte
	//Sizeof this structure is 16 (contain padding)
};
/*The bitmap-information header, defined as a BITMAPINFOHEADER structure,
specifies the dimensions, compression type, and color format for the bitmap.*/
struct BitmapInfo
{
	unsigned int dibSize;//4byte
	unsigned int imageWidth;//4
	unsigned int imageHeight;//4
	unsigned short colorPlane;//2byte
	unsigned short colorDepth;//2byte (1,4,8,16,24,32 bits)
	unsigned int compressMethod;//4byte ((0-No, 1-RLE, 3-Huffman, 4-JPEG, 5-PNG)
	unsigned int pixelArraySize;//4byte
	unsigned int horizontalResolution;//4byte (pixel/meter)
	unsigned int verticalResolution;//4byte (pixel/meter)
	unsigned int numOfColors;//4byte;
	unsigned int numOfImportantColors;//4byte
};

struct Pix
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

struct Bitmap
{
	BitmapHeader BmHeader;
	BitmapInfo BmInfo;
};

//============BITMAP DEFINE========================
//Read Bitmap Header of path_file image
void readBitmapHeader(char *path, Bitmap &Image);
//Print Bitmap Header on screen
void printBitmapHeader(Bitmap Image);

//Read Bitmap Info of path_file image
void readBitmapInfo(char *path, Bitmap &Image);
//Print Bitmap Info on screen
void printBitmapInfo(Bitmap Image);

//Read bitmap data
void readBitmapData(char *path, Bitmap &Image, char*&data);
//Write to other file
void writeBimapFile(char *path, Bitmap &Image, char*&data);

////Convert Data to Pixel Array
void convertDataToPixelArr(Bitmap &Image, char*&data, Pix **&pixArr);
//Convert Pixel Array to Data
void convertPixelArrToData(Bitmap &Image, Pix **&pixArr, char *&data);

//Init a 2D Pixel Array
void initPixArr(Pix**&pixArr, int height, int width);

//Copy a pixcel array
void copyPixelArray(Pix** pixSource, Pix**&pixDest, int height, int width);
//============BITMAP EDITOR=============================

//Flip Horizontal
void flip_Horizontal(Bitmap Image, Pix**&pixArr);

//Flip Vertical
void flip_Vertical(Bitmap Image, Pix**&pixArr);

//Convert image to back white mode(trắng đen)
void grayScale(Bitmap Image, Pix**&pixArr);
//Convert image to invert mode (âm bản)
void Invert(Bitmap Image, Pix**&pixArr);

//Filter image:'r','g','b'(red, green, blue) <lọc màu>
void Filter(Bitmap Image, Pix**&pixArr, char color);

//Add Frame SizeFrame(pixcel) <thêm khung>
void addFrame(Bitmap Image, Pix**&pixArr, int SizeFrame, Pix color);

//Zoom image
void zoomImage(Bitmap &Image, Pix**&pixArr, int x,int y);

//Blur image
void blurImage(Bitmap Image, Pix**&pixArr,int x);

//Adjust Contrast (độ tưởng phản)
void adjustContrast(Bitmap Image, Pix **&pixArr, float contrast);

//Draw a bitmap file on Screen at (x,y) (pixels)
void drawBmp(Bitmap Image, Pix **pixArr, int x, int y);
//========Graphic======================================
// Hàm tô màu.
void textcolor(int x);
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);
//Thay đổi kích thước console 
void resizeConsole(int width, int height);
// Hàm xóa màn hình.
void XoaManHinh();

//===================
void showMenu();
#endif