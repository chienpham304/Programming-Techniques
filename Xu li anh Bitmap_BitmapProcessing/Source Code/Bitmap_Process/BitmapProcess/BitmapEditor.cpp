#include "BitmapDefine.h"

//Flip Horizontal
void flip_Horizontal(Bitmap Image, Pix**&pixArr)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	Pix **tmp;
	initPixArr(tmp, height, width);
	//copy pixArr to TmpArr
	copyPixelArray(pixArr, tmp, height, width);
	//Flip Horizontal pixArr
	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		pixArr[i][j] = tmp[i][width - 1 - j];
	}
}

//Flip Vertical
void flip_Vertical(Bitmap Image, Pix**&pixArr)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	Pix **tmp;
	initPixArr(tmp, height, width);
	//copy pixArr to TmpArr
	copyPixelArray(pixArr, tmp, height, width);
	//Flip Vertical pixArr
	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		pixArr[i][j] = tmp[height - i - 1][j];
	}
}

//Convert image to back white mode
void grayScale(Bitmap Image, Pix**&pixArr)
{ 
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	
	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		int value = 0.2126*pixArr[i][j].R + 0.7152*pixArr[i][j].G + 0.0722*pixArr[i][j].B;
		pixArr[i][j].R = value;
		pixArr[i][j].G =value;
		pixArr[i][j].B =value;
	}
}

//Convert image to invert mode <âm bản>
void Invert(Bitmap Image, Pix**&pixArr)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	
	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		pixArr[i][j].R = 255 - pixArr[i][j].R;
		pixArr[i][j].G = 255 - pixArr[i][j].G;
		pixArr[i][j].B = 255 - pixArr[i][j].B;
	}
}

//Filter image (red, green, blue)
void Filter(Bitmap Image, Pix**&pixArr,char color)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	switch (color)
	{
	case 'r':case'R':
		for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			//pixArr[i][j].R = 255 - pixArr[i][j].R;
			pixArr[i][j].G = 255 - pixArr[i][j].G;
			pixArr[i][j].B = 255 - pixArr[i][j].B;
		}
		break;
	case'g':case'G':
		for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			pixArr[i][j].R = 255 - pixArr[i][j].R;
			//pixArr[i][j].G = 255 - pixArr[i][j].G;
			pixArr[i][j].B = 255 - pixArr[i][j].B;
		}
		break;
	case'b':case'B':
		for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			pixArr[i][j].R = 255 - pixArr[i][j].R;
			pixArr[i][j].G = 255 - pixArr[i][j].G;
			//pixArr[i][j].B = 255 - pixArr[i][j].B;
		}
		break;
	default:
		printf("\nError: '%c' type is not supported!!\n",color);
		break;
	}
	
}

//Add Frame <thêm khung>
void addFrame(Bitmap Image, Pix**&pixArr,int SizeFrame,Pix color)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	//
	for (int i = 0; i < height; i++)
	for (int j = 0; j < SizeFrame; j++)
	{
		pixArr[i][j] = color;
		pixArr[i][width - SizeFrame + j] = color;
	}
	for (int i = 0; i < SizeFrame; i++)
	for (int j = SizeFrame; j < width-SizeFrame; j++)
	{
		pixArr[i][j] = color;
		pixArr[height-SizeFrame+i][j] = color;
	}
}

//Zoom image
void zoomImage(Bitmap &Image, Pix**&pixArr, int x,int y)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	Image.BmInfo.imageHeight = height*x;
	Image.BmInfo.imageWidth = width*y;
	Pix **tmp;
	copyPixelArray(pixArr, tmp, height, width);
	initPixArr(pixArr, height*x, width*y);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			{
				for (int d = i*x; d <= i*x + x - 1; d++)
				for (int c = j*y; c <= j*y + y - 1; c++)
				{
					pixArr[d][c] = tmp[i][j];
				}
			}
		}
	}
}

//Blur image
void blurImage(Bitmap Image, Pix**&pixArr,int x)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;
	
	Pix**tmp; initPixArr(tmp, height, width);
	copyPixelArray(pixArr, tmp, height, width);

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		int sumB = 0, sumG = 0, sumR = 0, dem = 0;
		for (int ii = -x; ii <= x; ii++)
		for (int jj = -x; jj <= x; jj++)
		{
			if ((i + ii >= 0) && (ii + i < height) && (jj + j >= 0) && (jj + j < width))
			{
				dem++;
				sumB += tmp[i + ii][j + jj].B;
				sumG += tmp[i + ii][j + jj].G;
				sumR += tmp[i + ii][j + jj].R;
			}
		}
		pixArr[i][j].B = sumB / dem;
		pixArr[i][j].G = sumG / dem;
		pixArr[i][j].R = sumR / dem;
	}
}

//Adjust Contrast (độ tưởng phản)
void adjustContrast(Bitmap Image, Pix **&pixArr, float contrast)
{
	int height = Image.BmInfo.imageHeight;
	int width = Image.BmInfo.imageWidth;

	Pix tempPix; double tmpR, tmpG, tmpB;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		tempPix = pixArr[i][j];
		
		tmpR = tempPix.R / 255.0;
		tmpR -= 0.5;
		tmpR *= contrast;
		tmpR += 0.5;
		tmpR *= 255;

		if (tmpR > 255)
		{
			tmpR = 255;
		}
		else if (tmpR < 0)
		{
			tmpR = 0;
		}

		tmpG = tempPix.G / 255.0;
		tmpG -= 0.5;
		tmpG *= contrast;
		tmpG += 0.5;
		tmpG *= 255;
		if (tmpG > 255)
		{
			tmpG = 255;
		}
		else if (tmpG < 0)
		{
			tmpG = 0;
		}

		tmpB = tempPix.B / 255.0;
		tmpB -= 0.5;
		tmpB *= contrast;
		tmpB += 0.5;
		tmpB *= 255;
		if (tmpB > 255)
		{
			tmpB = 255;
		}
		else if (tmpB < 0)
		{
			tmpB = 0;
		}
		pixArr[i][j].R = tmpR;
		pixArr[i][j].G = tmpG;
		pixArr[i][j].B = tmpB;

	}
}
