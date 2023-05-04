#include "Triangle.h"
Triangle::Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name)
	: Polygon(name,type)
{
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
}
Triangle::~Triangle()
{

}

void Triangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char GREEN[] = { 0, 255, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), GREEN, 100.0f).display(disp);
}

void Triangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), BLACK, 100.0f).display(disp);
}
