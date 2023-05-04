#pragma once
#include <iostream>
#include <exception>
class NoCourseException : public std::exception
{
public:
	const char * what() const throw ();
};

