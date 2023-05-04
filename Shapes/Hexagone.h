#pragma once
#include "shape.h"
#include "mathUtils.h"
#include <iostream>
class Hexagon :public Shape
{
	double _length;
public:
	void draw();
	Hexagon(std::string nam, std::string col, double length);
	void setLength(double length);
};
