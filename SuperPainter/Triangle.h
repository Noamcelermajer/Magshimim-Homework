#pragma once
#include "Polygon.h"

class Triangle : public Polygon
{
public:
	Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name);
	virtual ~Triangle();
	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
};