#include "shape.h"
#include "circle.h"
#include "shapeException.h"
#include <iostream>

Circle::Circle(std::string nam, std::string col, double rad):Shape(col, nam) {
	//void setName(string nam);
	//void setColor(string col); <-this redefines it d/n use
	setRad(rad);		
}
void Circle::draw()
{
	std::cout << std::endl<<"Color is "<<getColor() << std::endl <<"Name is "<< getName()<< std::endl<<"radius is "<<getRad()<< std::endl<<"Circumference: "<< CalCircumference()<< std::endl;;
}

void Circle::setRad(double rad) {
	radius = rad;
}

double Circle::CalArea() {
	double area = 3.14*radius*radius;
	
	return area;
	
}

double Circle:: getRad() {
	return radius;
}


double Circle::CalCircumference() {
	double circumference = 2 * (3.14)*radius;
	if (circumference < 0)
	{
		throw shapeException();
	}
	return circumference;


}