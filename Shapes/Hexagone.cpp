#include "Hexagone.h"
#include "shapeexception.h"
Hexagon::Hexagon(std::string nam, std::string col, double length) :Shape(col, nam)
{
	if (length < 0)
	{
		throw shapeException();
	}
	_length = length;
}
void draw()
{

}
void Hexagon::setLength(double length)
{
	_length = length;
}