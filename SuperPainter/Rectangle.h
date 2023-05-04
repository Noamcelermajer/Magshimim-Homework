#pragma once
#include "Polygon.h"

namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:
		// There's a need only for the top left corner 
		Rectangle(const Point& a, double length, double width, const string& type, const string& name);
		virtual ~Rectangle();
		virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
		virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	};
}