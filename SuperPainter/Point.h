#pragma once
#include <vector>
#include "CImg.h"

class Point
{
public:
	Point();
	Point(double x, double y);
	Point(const Point& other);
	virtual ~Point();
	
	Point operator+(const Point& other) const;
	Point& operator+=(const Point& other);

	double getX() const;
	double getY() const;

	double distance(const Point& other) const;
protected :
	double _x;
	double _y;
	
};