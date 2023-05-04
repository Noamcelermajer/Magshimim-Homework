#include "Rectangle.h"
myShapes::Rectangle::Rectangle(const Point& a, double length, double width, const string& type, const string& name) :
	Polygon(name, type)
{
	_points.push_back(a);
	_points.push_back(Point(a.getX() + width, a.getY()));

	_points.push_back(Point(a.getX() + width, a.getY() + length));
}
myShapes::Rectangle::~Rectangle()
{
}


void myShapes::Rectangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char WHITE[] = { 255, 255, 255 };
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), WHITE, 100.0f).display(disp);
}

void myShapes::Rectangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0};
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), BLACK, 100.0f).display(disp);
}


