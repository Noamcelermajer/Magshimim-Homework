
#include "shape.h"
#include "circle.h"
#include <iostream>
#ifndef quadrilateral_H
#define quadrilateral_H

class quadrilateral :public Shape {
public:
	void draw();
	double CalArea();
	//quadrilateral();
	quadrilateral(std::string, std::string, int, int);
	double CalPerimater();
	double getCalPerimater();
	void setHeight(int h);
	void setWidth(int w);
	int getHeight();
	int getWidth();


private:
	int width;
	int height;

};
#endif