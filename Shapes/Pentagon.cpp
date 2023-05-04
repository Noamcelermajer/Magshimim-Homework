#include "Pentagon.h"
#include "shapeexception.h"
Pentagon::Pentagon(std::string nam, std::string col, double length) :Shape(col, nam)
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
void Pentagon::setLength(double length)
{
	_length = length;
}