#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture(0);
	int delay = 1000 / 30;
	string a[] = { "cam01.jpg","cam02.jpg","cam03.jpg","cam04.jpg","cam05.jpg","cam06.jpg",
		"cam07.jpg","cam08.jpg","cam09.jpg","cam10.jpg","cam11.jpg","cam12.jpg" };
	int i = 0;
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("show", frame);
		//imwrite("camera1.jpg", frame);
		int key;
		key = waitKey(delay);
		if (27 == (char)key)
		{
			imwrite(a[i], frame);
			i++;
		}

	}
}
