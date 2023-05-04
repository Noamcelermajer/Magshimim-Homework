#include <iostream>
#include <string.h>
class calcExeption : public std::exception
{
public:
	virtual const char* what() const;

};
const char* calcExeption::what() const

{
	return "This user is not authorised to access 8200, please enter different numbers, or try to get clearance in 1 year.\n";
}
int add(int a, int b) {
	if (a == 8200 || b == 8200 || a + b == 8200)
	{
		throw calcExeption();
	}

	return a + b;
}

int  multiply(int a, int b) {
	if (a == 8200 || b == 8200 || a + b == 8200)
	{
		throw calcExeption();
	}
	int sum = 0;
	for (int i = 0; i < b; i++) {
		if (add(sum, a) == 8200)
		{
			throw calcExeption();
		}
		else
		{
			sum = add(sum, a);
		}

	};
	return sum;
}

int  pow(int a, int b) {
	if (a == 8200 || b == 8200 || a + b == 8200)
	{
		throw calcExeption();
	}
	int exponent = 1;
	for (int i = 0; i < b; i++) {
		if (multiply(exponent, a) == 8200)
		{
			throw calcExeption();
		}
		else
		{
			exponent = multiply(exponent, a);
		}
	};
	return exponent;
}

int Pseudomain(void) {
	try 
	{
		std::cout << "Power result: " << pow(5, 5) << std::endl;
		std::cout << "Add result: " << add(5, 5) << std::endl;
		std::cout << "Multiply result: " << multiply(1640, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	system("pause");
}
