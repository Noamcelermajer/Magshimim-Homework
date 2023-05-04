#pragma once

#include "Shape.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include "Cimg.h"

using namespace std;

class Polygon : public Shape
{
public:
	Polygon(const string& type, const string& name);
	virtual ~Polygon();
	virtual void move(const Point& other);
	virtual double getArea() const;
	virtual double getPerimeter() const;

protected:
	vector<Point> _points;
};