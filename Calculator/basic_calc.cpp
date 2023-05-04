#include <iostream>
#define ERROR_NUM 8200
#define TRUE 0
#define FALSE !TRUE
int add(int a, int b) {
	if (a == ERROR_NUM || b == ERROR_NUM || a + b == ERROR_NUM)
	{
		return FALSE;
	}
	
	return a + b;
}

int  multiply(int a, int b) {
	if (a == ERROR_NUM || b == ERROR_NUM || a + b == ERROR_NUM)
	{
		return FALSE;
	}
	int sum = 0;
	for (int i = 0; i < b; i++) {
		if (add(sum, a) == ERROR_NUM)
		{
			return FALSE;
		}
		else
		{
			sum = add(sum, a);
		}
		
	};
	return sum;
}
	
int  pow(int a, int b) {
	if (a == ERROR_NUM || b == ERROR_NUM || a + b == ERROR_NUM)
	{
		return -1122;
	}
	int exponent = 1;
	for (int i = 0; i < b; i++) {
		if (multiply(exponent, a) == ERROR_NUM)
		{
			return FALSE;
		}
		else
		{
			exponent = multiply(exponent, a);
		}
	};
	return exponent;
}

int Pseudomain(void) {
	if (pow(5, 5)!=FALSE)
	{
		std::cout << pow(5, 5) << std::endl;
	}
	if (add(5, 5) != FALSE)
	{
		std::cout << add(5, 5) << std::endl;
	}
	if (multiply(5, 5) != FALSE)
	{
		std::cout << multiply(5, 5) << std::endl;
	}
}