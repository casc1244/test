#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

#define WINDOW_NAME "【程序窗口】"        
int g_nThresholdValue = 100;
int g_nThresholdType = 3;
Mat srcMat, g_grayImage, g_dstImage;


void on_Threshold(int, void*);

int main()
{
	system("color 1F");
    srcMat = imread("D:\\360downloads\\1.jpg");
	if (!srcMat.data) { printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"); return false; }
	imshow("原始图", srcMat);
	cvtColor(srcMat, g_grayImage, COLOR_RGB2GRAY);
	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	createTrackbar("模式",
		WINDOW_NAME, &g_nThresholdType,4, on_Threshold);
	createTrackbar("参数值",
		WINDOW_NAME, &g_nThresholdValue,
		255, on_Threshold);
	on_Threshold(0, 0);
	while (1)
	{
		int key;
		key = waitKey(20);
		if ((char)key == 27) { break; }
	}

}


void on_Threshold(int, void*)
{	
	threshold(g_grayImage, g_dstImage, g_nThresholdValue, 255, g_nThresholdType);
	imshow(WINDOW_NAME, g_dstImage);
}