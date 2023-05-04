#include "Point.h"
#include <math.h>
Point::Point()
{

}
Point::Point(double x, double y)
{
	_x = x;
	_y = y;
}
Point::Point(const Point& other)
{
	*this = other;
}
Point::~Point()
{
}

Point Point::operator+(const Point& other) const
{
	
	return Point(_x + other._x, _y + other._y);
}
Point& Point::operator+=(const Point& other)
{
	_x = _x + other._x;
	_y = _y + other._y;
	return *this;
}

double Point::getX() const
{
	return _x;
}
double Point::getY() const
{
	return _y;
}

double Point::distance(const Point& other) const
{
	double xA = this->getX(), yA = this->getY(), xB = other.getX(), yB = other.getY();
	return sqrt(pow(xA - xB, 2) - pow(yA - yB, 2));

}