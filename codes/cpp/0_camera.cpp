#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/core/core.hpp> 
using namespace cv;

int main()
{
	VideoCapture cap(0);
	Mat frame;
	while (waitKey(30) != 27)
	{
		cap >> frame;
		imshow("µ÷ÓÃÉãÏñÍ·", frame);
	}
	return 0;
}