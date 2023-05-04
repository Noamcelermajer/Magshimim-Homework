#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "circle.h"
#include "quadrilateral.h"
#include <iostream>

class rectangle : public quadrilateral {
public:
	void draw();
	double CalArea(double, double);
	bool isSquare(int, int);
	//bool getisSquare();
	rectangle(std::string, std::string, int, int);


private:


};
#endif