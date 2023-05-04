#pragma once
#include <iostream>
class InputException : public std::exception
{
public:
		virtual const char* what() const
		{
			return "Please enter Integer only When needed\n";
		}


};