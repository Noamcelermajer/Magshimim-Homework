#pragma once
#include <exception>

class shapeException : public std::exception
{
	virtual const char* what() const
	{
		return "This is a shape exception!";
	}
};