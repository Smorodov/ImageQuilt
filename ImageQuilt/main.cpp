#include <iostream>
#include "ImageQuilt.h"

void progress_callback(cv::Mat& img)
{

	cv::imshow("progress", img);
	cv::waitKey(5);
}

void result_callback(cv::Mat& img)
{

	cv::imshow("progress", img);
	cv::waitKey();
}

int main()
{
	ImageQuilt* image_quilt = new ImageQuilt("../input/gems.bmp", "../output/", 32, 32, 8, 0.01);
	image_quilt->synthesize(progress_callback, result_callback);
	delete image_quilt;
	return 0;
}