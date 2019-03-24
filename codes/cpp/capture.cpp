#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture(0);
	int delay = 1000;
	string name = "tool";
	int i = 0;
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("show", frame);
		//imwrite("camera1.jpg", frame);
		int key;
		key = waitKey(delay);
		if (27 != (char)key)
		{
			imwrite(name + to_string(i) + ".jpg", frame);
			i++;
		}
		else return 0;
	}
}
