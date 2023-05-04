#pragma once
#include "shape.h"
#include "mathUtils.h"
#include <iostream>
class Pentagon :public Shape
{
	double _length;

public:
	void draw();
	void setLength(double length);
	Pentagon(std::string nam, std::string col, double length);

};
