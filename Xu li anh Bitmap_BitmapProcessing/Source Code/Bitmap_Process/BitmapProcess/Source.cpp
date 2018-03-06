#include "BitmapDefine.h"
#include <stdlib.h>
int main()
{
start:
	showMenu();
	Bitmap Image; errno_t err; FILE*f;
	gotoxy(1, 9);
	char *inputPath = new char[255];
	do
	{
		printf("->Load image (path): "); textcolor(14);
		fflush(stdin);
		scanf("%s", inputPath); textcolor(7);
		//inputPath = "mario.bmp";
		f = fopen(inputPath, "rb");
		if (f == NULL)
		{
			//gotoxy(1, 9);
			printf(" <This path is wrong!>\n");
		}
		if (strcmp(inputPath, "exit") == 0)
			exit(0);
	} while ( f == NULL);
	
	//gotoxy(1, 9);
	
	char*data1 = NULL;
	Pix **pixArr1 = NULL;//Lưu ảnh gốc	
	Pix **pixArr2 = NULL;//Lưu ảnh sau apply
	Pix **pixArr3 = NULL;//Lưu ảnh xem trước
	readBitmapHeader(inputPath, Image);
	readBitmapInfo(inputPath, Image);
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	int x=55, y=11;// x = 400; y = 220;
	
	gotoxy(x + 1, y - 2); textcolor(240);
	printf("Orginal:");
	gotoxy(x+2 + width / 9, y-2);//1 cursor trong console = 9x20 pixcel
	printf("Preview:"); textcolor(7);
	printf("\n- Loading image: %s", inputPath);
	readBitmapData(inputPath, Image,data1);
	convertDataToPixelArr(Image, data1, pixArr1);
	copyPixelArray(pixArr1, pixArr2, height, width);
	copyPixelArray(pixArr1, pixArr3, height, width);
	
	//Draw a bitmap file on Screen
	//zoomImage(Image, pixArr2, 1,2);
	drawBmp(Image, pixArr2, x*9, y*20);
	//adjustContrast(Image, pixArr3, 50);

	drawBmp(Image, pixArr3,x*9+Image.BmInfo.imageWidth+10,y*20);
	printf("\n- Successful!\n");
	Bitmap Image2 = Image;
	//=====================
	int key = 0;
	while (TRUE)
	{

		if (key != 11)
		{
			drawBmp(Image, pixArr3, x * 9 + Image.BmInfo.imageWidth + 10, y * 20);
			copyPixelArray(pixArr2, pixArr3, height, width);
		}
		
		textcolor(14); int tmpHeight, tmpWidth, weight1; float weight2; char c; char *outPath = new char[255];
		printf("-> Choose: "); textcolor(7); scanf_s("%d", &key);
		switch (key)
		{
		case 0: _fcloseall(); free(inputPath); inputPath = nullptr; free(data1); free(pixArr1); free(pixArr2); free(pixArr3); height = 0; width = 0;
			data1 = nullptr; pixArr1 = nullptr; pixArr2 = nullptr; pixArr3 = nullptr;
			::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); system("cls");
			goto start;
			break;
		case 1:grayScale(Image, pixArr3); 
			break;
		case 2:Invert(Image, pixArr3); 
			break;
		case 3:printf("- Filter:\n + Choose a color(r,b,g):");
			fflush(stdin); scanf_s("%c", &c);
			if (c != 'r' && c != 'R' && c != 'g' && c != 'G' && c != 'b' && c != 'B')
			{
				 printf("- Error: '%c' type is not supported!!\n", c);
				 continue;
			}
			Filter(Image, pixArr3, c); 
			break;
		case 4:printf("- Zoom Rate(x:y): ");  scanf_s("%d:%d", &tmpHeight, &tmpWidth);
			zoomImage(Image, pixArr3,tmpWidth,tmpHeight);
			height = Image.BmInfo.imageHeight;
			width = Image.BmInfo.imageWidth;
			break;
		case 5:printf("- Blur weight(px): ");  scanf_s("%d", &weight1);
			blurImage(Image, pixArr3, weight1); 
			break;
		case 6:printf("- Contrast weight[-100,100]: ");  scanf_s("%f", &weight2);
			adjustContrast(Image, pixArr3, weight2); 
			break;
		case 7:printf("- Frame\n + Size(px): ");  scanf_s("%d", &weight1);
			Pix tmp; printf(" + Color(R:G:B): "); scanf_s("%d:%d:%d", &tmp.R, &tmp.G, &tmp.B);
			addFrame(Image, pixArr3, weight1, tmp); 
			break;
		case 8:printf("- Flip\n + Horizontal(H)\n + Vertical  (V)\n =>Choose: "); fflush(stdin); scanf_s("%c", &c);
			if (c == 'h' || c == 'H')
				flip_Horizontal(Image, pixArr3);
			else if (c == 'v' || c == 'V')
				flip_Vertical(Image, pixArr3);
			else
			{
				printf("'%c' is not supported!!\n",c);
				continue;
			}
			//drawBmp(Image, pixArr3, x * 9 + Image.BmInfo.imageWidth + 10, y * 20); 
			continue;
			break;
		case 9:case 10: printf("\nThis effect is not avaiable\n"); break;
		case 11:
			break;
		case 12:printBitmapHeader(Image); printBitmapInfo(Image);
			//drawBmp(Image, pixArr3, x * 9 + Image.BmInfo.imageWidth + 10, y * 20); 
			continue;
			break;
		case 13:fclose(f); printf("Writing...");
			copyPixelArray(pixArr2, pixArr1, height, width);
			convertPixelArrToData(Image, pixArr1, data1);
			writeBimapFile(inputPath, Image, data1);
			continue;
			break;
		case 14:fclose(f); 
			printf("-> Save as: "); textcolor(14);
			fflush(stdin);
			scanf("%s",outPath);textcolor(7);
			printf("- Writing...");
			copyPixelArray(pixArr2, pixArr1, height, width);
			convertPixelArrToData(Image, pixArr1, data1);
			writeBimapFile(outPath, Image, data1); 
			continue;
			break;
		case 15:exit(0);
		default:
			break;
		}
		drawBmp(Image, pixArr3, x * 9 + Image.BmInfo.imageWidth + 10, y * 20);
		textcolor(14);
		printf("-> Do you want to apply this effect?(Y/N):"); textcolor(7);
		fflush(stdin); scanf_s("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			if (key == 4)//zoom
			{
				Image2 = Image;
			}
			copyPixelArray(pixArr3, pixArr2, height, width);
		}
		else
		{
			if (key == 4)//zoom
			{
				Image = Image2;
				height = Image.BmInfo.imageHeight;
				width = Image.BmInfo.imageWidth;
			}
			copyPixelArray(pixArr2, pixArr3, height, width);
			drawBmp(Image, pixArr3, x * 9 + Image.BmInfo.imageWidth + 10, y * 20);
		}
		drawBmp(Image, pixArr2, x * 9, y * 20);
		
	}


	//=====================
	//char *data2=NULL;
	//convertPixelArrToData(Image, pixArr, data2);
	//Pix **pixArr2 = NULL;
	//convertDataToPixelArr(Image, data2, pixArr2);
	//drawBmp(Image, pixArr2, 50, 50);
	//convertDataToPixelArr(Image, data2, pixArr);
	
	//zoomImage(Image, pixArr2,2,2);
	//drawBmp(Image, pixArr2, x+width+10, y);

	//grayScale(Image, pixArr2);// trắng đen
	//addFrame(Image, pixArr2, 10, { 150, 0, 255 });
	//drawBmp(Image, pixArr2, x, y);
	//convertPixelArrToData(Image, pixArr2, data1);
	//writeBimapFile("../../../Image/minhtam_GrayScale.bmp", Image, data1);
	
	
	//flip_Horizontal(Image, pixArr2);//lật ngang
	//drawBmp(Image, pixArr2, x + width + 10, y);
	//flip_Vertical(Image, pixArr2);//lật dọc
	//drawBmp(Image, pixArr2, 13*x, y);
	//flip_Vertical(Image, pixArr2);//lật dọc
	//flip_Horizontal(Image, pixArr2);//lật ngang
	//grayScale(Image, pixArr2);// trắng đen
	//drawBmp(Image, pixArr2, 19*x, y);
	
	//âm bản
	//copyPixelArray(pixArr, pixArr2, height, width);
	//Invert(Image, pixArr2);
	//addFrame(Image, pixArr2, 7, { 255,255,255 });
	//drawBmp(Image, pixArr2, 25 * x, y);
	
	//lọc màu
	//copyPixelArray(pixArr, pixArr2, height, width);
	//Filter(Image, pixArr2,'r');
	//drawBmp(Image, pixArr2, x, 9*y);
	//copyPixelArray(pixArr, pixArr2, height, width);
	//Filter(Image, pixArr2, 'g');
	//drawBmp(Image, pixArr2, 7*x, 9 * y);
	//copyPixelArray(pixArr, pixArr2, height, width);
	//Filter(Image, pixArr2, 'b');
	//drawBmp(Image, pixArr2, 13*x, 9 * y);
	//Add frame
	//copyPixelArray(pixArr, pixArr2, height, width);
	//addFrame(Image, pixArr2, 7, { 0, 0, 255 });
	//drawBmp(Image, pixArr2, 19 * x, 9 * y);
	//addFrame(Image, pixArr2, 7, { 150, 0, 255 });
	//drawBmp(Image, pixArr2, 25 * x, 9 * y);

	//fclose(f);
	_getch();
	//printf("%d", sizeof(unsigned short));
	//int a = 9;
	return 0;
}