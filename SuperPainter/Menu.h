#pragma once
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CImg.h"
#include <vector>
#include <iostream>
#include <sstream>


class Menu
{
public:

	Menu();
	~Menu();
	myShapes::Rectangle* rectangleMaker();
	Triangle* triangleMaker();
	void procedureNewShape();
	void procedureModGet();
	Arrow* arrowMaker();
	Circle* circleMaker();
	vector < Shape*> _shapeVector;
private: 

	cimg_library::CImg<unsigned char>* _board;
	cimg_library::CImgDisplay* _disp;
};

