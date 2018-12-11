#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int artc, char** argv) {
	Mat src = imread("E:/CV/OpenCV_zhaizhigang/code_004/LeeChan.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	// 直接读取图像像素
	int height = src.rows;
	int width = src.cols;
	int ch = src.channels();
	for (int c = 0; c < ch; c++) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				if (ch == 3) {
					Vec3b bgr = src.at<Vec3b>(row, col); // 8U 类型的 RGB 彩色图像 -> src.at<Vec3b>()
					bgr[0] = 255 - bgr[0];
					bgr[1] = 255 - bgr[1];
					bgr[2] = 255 - bgr[2];
					src.at<Vec3b>(row, col) = bgr;
				} else if(ch == 1) {
					int gray = src.at<uchar>(row, col);
					src.at<uchar>(row, col) = 255 - gray;
				}
			}
		}
	}
	imshow("output", src);

	// 指针读取
	Mat result = Mat::zeros(src.size(), src.type());
	int blue = 0, green = 0, red = 0;
	int gray;
	for (int c = 0; c < ch; c++) {
		for (int row = 0; row < height; row++) {
			uchar* curr_row = src.ptr<uchar>(row);
			uchar* result_row = result.ptr<uchar>(row);
			for (int col = 0; col < width; col++) {
				if (ch == 3) {
					blue = 255 - *curr_row++;
					green = 255 - *curr_row++;
					red = 255 - *curr_row++;

					*result_row++ = blue;
					*result_row++ = green;
					*result_row++ = red;
				}
				else if (ch == 1) {
					gray = *curr_row++;
					*result_row++ = 255 - gray;
				}
			}
		}
	}
	imshow("result", result);

	waitKey(0);
	return 0;
}
