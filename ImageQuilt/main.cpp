#include <iostream>
#include "ImageQuilt.h"

int main()
{
	ImageQuilt* image_quilt = new ImageQuilt("../input/gems.bmp", "../output/", 32, 32, 8, 0.01);
	image_quilt->synthesize();
	delete image_quilt;
	return 0;
}