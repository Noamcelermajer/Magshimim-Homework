#include "shape.h"
#include "rectangle.h"
#include "quadrilateral.h"
#include "shapeException.h"
#include <iostream>

rectangle::rectangle(std::string nam, std::string col, int w, int h):quadrilateral(nam,col,w, h){

	//void setName(string nam);
	//void setColor(string col);
	//setHeight( h); //void already defined in header prototype..
	 //setWidth( w);
}

void rectangle::draw()
{
	std::cout << getName() << std::endl << getColor() << std::endl << "Height is " << getHeight() << std::endl << "Width is " << getWidth() << std::endl
		<<"area is "<<CalArea(getWidth(), getHeight())<< std::endl<< "is square (1,0)?: " << isSquare(getWidth(), getHeight()) << std::endl;// getisSquare();<-do from main
}

double rectangle::CalArea(double w, double h) {
	if (w < 0 || h < 0)
	{
		throw shapeException();
	}
	return w*h;
}
/*double rectangle::setCalArea() {
	area;
}*/
bool rectangle::isSquare(int w, int h) {
	
	if (w == h)
	{
		return true;
	}
	else 
	{
		return 0;
	}	
}
/*bool rectangle::getisSquare() {
	if(width==height){}
}
/*bool rectangle::getisSquare() {
	 if(width==height) 
	return true;
	
	else return false;
}*/