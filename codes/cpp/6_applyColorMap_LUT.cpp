#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
void customColorMap(Mat &image);
int main(int argc, const char *argv[])
{
	Mat src = imread("E:/CV/OpenCV_zhaizhigang/code_006/cocoon.jpg");
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}

	imshow("input", src);

	Mat gray, dst;
	// 使用 API 之 LUT：applyColorMap（彩色风格查找表映射）
	applyColorMap(src, dst, COLORMAP_SUMMER);
	// 显示结果
	imshow("colorMap", dst);

	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);
	customColorMap(gray); // 使用手写 单通道LUT

	waitKey(0);
	return 0;
}

void customColorMap(Mat &image) {
	int lut[256];
	for (int i = 0; i < 256; i++) {
		if (i < 127)
			lut[i] = 0;
		else
			lut[i] = 255;
	}

	int h = image.rows;
	int w = image.cols;
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			int pv = image.at<uchar>(row, col);
			image.at<uchar>(row, col) = lut[pv];
		}
	}
	imshow("lut demo", image);
}

