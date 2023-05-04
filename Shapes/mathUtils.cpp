#include "mathUtils.h"
#include <math.h>



double mathUtils::CalHexagonArea(double length)
{
	return  (sqrt(3)*pow(length, 2)/2);
}


double  mathUtils::CalPentagonArea(double length)
{
	double h = 0, a = 0;
	h = (length / 2) / tan(36);
	a = 0.5* length*h;
	return a * 10;
}
