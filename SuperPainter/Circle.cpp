#include "Circle.h"
Circle::Circle(const Point& center, double radius, const string& type, const string& name)
	: Shape(name, type)
{
	_center = center;
	_radius = radius;
}
Circle::~Circle()
{
}

const Point& Circle::getCenter() const
{
	return _center;
}

double Circle::getRadius() const
{
	return _radius;
}


void Circle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLUE[] = { 0, 0, 255 };
	const Point& c = getCenter();
	board.draw_circle(c.getX(), c.getY(), getRadius(), BLUE, 100.0f).display(disp);	
}

void Circle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };
	const Point& c = getCenter();
}

void  Circle::move(const Point& other)
{
 
}
double Circle::getArea() const
{
	return (PI *pow(_radius, 2));
}
double Circle::getPerimeter() const
{
	return 2 * (PI*_radius);
}