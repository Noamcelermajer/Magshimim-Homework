#include "shape.h"
#include "circle.h"
#include "quadrilateral.h"
#include "shapeException.h"
#include <iostream>

//quadrilateral::quadrilateral() {}
quadrilateral::quadrilateral(std::string nam, std::string col, int h, int w):Shape(nam, col) {

	//void setName(string nam); //PRIVATE DATA
	//void setColor(string col);
	setHeight( h);
	 setWidth( w);
	
}
void quadrilateral::draw()
{
	//quadrilateral p;
	std::cout << getName()<< std::endl << getColor() << std::endl<< "Width is " << getWidth() << std::endl << "Height is " << getHeight() << std::endl <<"Area is "<<CalArea()<< std::endl<<"Perimeter is "<<getCalPerimater()<< std::endl;
	//cout << name << color;
}

double quadrilateral::CalArea()
{
	if (width < 0 || height < 0)
	{
		throw shapeException();
	}
	return width*height; //RECTANGLE 
}

void quadrilateral::setHeight(int h) {
	height = h;
}
void quadrilateral::setWidth(int w) {

	width = w;
}
double quadrilateral::CalPerimater() {
	return 2 * (height + width);
}
double quadrilateral::getCalPerimater() {
	return 2 * (height + width);

}
int quadrilateral::getHeight() {
	return height;
}
int quadrilateral::getWidth() {
	return width;
}