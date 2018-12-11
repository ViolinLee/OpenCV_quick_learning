#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int artc, char** argv) {
	Mat src = imread("E:/CV/OpenCV_zhaizhigang/code_002/LeeChan.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	imwrite("E:/CV/OpenCV_zhaizhigang/code_002/LeeChanGray.jpg", gray);

	waitKey(0);
	return 0;
}



