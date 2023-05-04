#include "Arrow.h"

Arrow::Arrow(const Point& a, const Point& b, const string& type, const string& name) :
	_p1(a),_p2(b),Shape(name, type)
{
}
Arrow::~Arrow()
{
}
void Arrow::move(const Point& other)
{
	
}
double Arrow::getArea() const
{
	return 0;
}
double Arrow::getPerimeter() const
{
	std::cout << _p1.getX() << std::endl;
	return 10.0;
}
void Arrow::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char RED[] = { 255, 0, 0 };

	board.draw_arrow(_p1.getX(), _p1.getY(),
		_p2.getX(), _p2.getY(), RED, 100.0f).display(disp);
}
void Arrow::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };

	board.draw_arrow(_p1.getX(), _p1.getY(),
		_p2.getX(), _p2.getY(), BLACK, 100.0f).display(disp);
}


