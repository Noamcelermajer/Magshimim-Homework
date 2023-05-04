
#include "parallelogram.h"
#include "shape.h"
#include "circle.h"
#include "quadrilateral.h"
#include "shapeException.h"
#include <iostream>


parallelogram::parallelogram(std::string col, std::string nam, int h, int w, double ang, double ang2):quadrilateral(col, nam, h, w) {
	 setAngle(ang, ang2);
}
void parallelogram::draw()
{
	std::cout <<getName()<< std::endl << getColor() << std::endl << "Height is " << getHeight() << std::endl<< "Width is " << getWidth() << std::endl
		<< "Angles are: " << getAngle()<<","<<getAngle2()<< std::endl <<"Area is "<<CalArea(getWidth(),getHeight())<< std::endl;
}

double parallelogram::CalArea(double w, double h) {
	if (w < 0 || h < 0)
	{
		throw shapeException();
	}
	return w*h;
}
void parallelogram::setAngle(double ang, double ang2) {
	angle = ang;
	angle2 = ang2;
}
double parallelogram::getAngle() {
	return angle;
}
double parallelogram::getAngle2() {
		return angle2;
	}
