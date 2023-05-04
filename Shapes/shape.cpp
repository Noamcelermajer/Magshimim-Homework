#include "shape.h"
//#include "circle.h"
#include <iostream>

 Shape::Shape(std::string nam, std::string col)
{
	name = nam;
	color = col;
	count++;
}

 int Shape::count = 0;
 //Shape::Shape(){}
int Shape::getCount() {
	{
		return count;
	}
}
double Shape::CalArea() {
	std::cout << "Unknown area" << std::endl;
	return 0;
}
Shape::~Shape()
{
	count--;

	//cout << name << endl << color << endl << "Area is " << CalArea() << endl;; 
}
void Shape::setName(std::string nam) {
	name = nam;
}
std::string Shape::getName() {
	return name;
}
void Shape::setColor(std::string col) {
	color = col;
}
std::string Shape::getColor() {
	return color;
}