#include "Menu.h"
#include <iostream>
void Menu::procedureNewShape()
{
	system("CLS");
	int shapeChoose = 0;
	std::cout << "Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle." << std::endl;
	std::cin >> shapeChoose;
	switch (shapeChoose)
	{
	case 0:
		_shapeVector.push_back(circleMaker());
		break;
	case 1:
		_shapeVector.push_back(arrowMaker());
		break;
	case 2:
		_shapeVector.push_back(triangleMaker());
		break;
	case 3:
		_shapeVector.push_back(rectangleMaker());
		break;

	}
}
void Menu::procedureModGet()
{
	int i = 0, choose = 0, action = 0, xMovingScale = 0, yMovingScale = 0;
	if (_shapeVector.size() != 0)
	{
		for (i = 0; i < _shapeVector.size(); i++)
		{
			std::cout << "Enter " << i << " for " << _shapeVector[i]->getName() << std::endl;

		}
		std::cin >> choose;
		std::cout << "Enter 0 to move the shape\nEnter 1 to get its details.\nEnter 2 to remove the shape." << std::endl;
		std::cin >> action;
		switch (action)
		{
		case 0:
			std::cout << "Please enter x moving scale: " << std::endl;
			std::cin >> xMovingScale;
			std::cout << "Please enter x moving scale: " << std::endl;
			std::cin >> yMovingScale;

			_shapeVector[choose]->move(Point(xMovingScale, yMovingScale));
			break;
		case 1:
			std::cout << _shapeVector[choose]->getType() << " " << _shapeVector[choose]->getName() << " " << _shapeVector[choose]->getArea() << " " << _shapeVector[choose]->getPerimeter() << std::endl;
			system("pause");
			break;
		}
	}
}
Menu::Menu() 
{
	_board  = new cimg_library::CImg<unsigned char>(700, 700, 1, 3, 1);
	_disp = new cimg_library::CImgDisplay(*_board, "Super Paint");
}
myShapes::Rectangle* Menu::rectangleMaker()
{
	double cornerX = 0, cornerY = 0, width = 0, length = 0;
	string name = "";
	std::cout << "Please enter the X coordinate of the left corner:" << std::endl;
	std::cin >> cornerX;
	std::cout << "Please enter the Y coordinate of the  left corner:" << std::endl;
	std::cin >> cornerY;
	std::cout << "Please enter the width" << std::endl;
	std::cin >> width;
	std::cout << "Please enter the length:" << std::endl;
	std::cin >> length;

	Point leftCorner = Point(cornerX, cornerY);
	myShapes::Rectangle* newRectangle = new myShapes::Rectangle(leftCorner,length,width,"Rectangle", name);
	newRectangle->draw(*_disp, *_board);
	return newRectangle;
}
Menu::~Menu()
{
	_disp->close();
	delete _board;
	delete _disp;
}
Arrow* Menu::arrowMaker()
{
	double firstX = 0, firstY = 0, secondX = 0, secondY = 0;
	string name = "";
	std::cout << "Please enter the X coordinate of the first point:" << std::endl;
	std::cin >> firstX;

	std::cout << "Please enter the Y coordinate of the first point :" << std::endl;
	std::cin >> firstY;

	std::cout << "Please enter the X coordinate of the second point :" << std::endl;
	std::cin >> secondX;

	std::cout << "Please enter the Y coordinate of the second point :" << std::endl;
	std::cin >> secondY;
	Point p1 = Point(firstX, firstY);
	Point p2 = Point(secondX, secondY);
	Arrow* newArrow = new Arrow(p1, p2,"Arrow",name);
	newArrow->draw(*_disp, *_board);
	return newArrow;
}

Triangle* Menu::triangleMaker()
{
	double firstPX = 0, firstPY = 0, SecPX = 0, SecPY = 0, ThirPX = 0, ThirPY = 0;
	string name = "";
	std::cout << "Please enter the X coordinate of the first point : 1" << std::endl;
	std::cin >> firstPX;
	std::cout << "Please enter the Y coordinate of the first point : 1" << std::endl;
	std::cin >> firstPY;

	std::cout << "Please enter the X of coordinate the sec point : 2" << std::endl;
	std::cin >> SecPX;
	std::cout << "Please enter the Y coordinate of the sec point : 2" << std::endl;
	std::cin >> SecPY;

	std::cout << "Please enter the X of coordinate the third point : 3" << std::endl;
	std::cin >> ThirPX;
	std::cout << "Please enter the Y coordinate of the third point : 3" << std::endl;
	std::cin >> ThirPY;

	std::cout << "Please Enter the name of the circle: " << std::endl;
	std::cin >> name;

	Point a = Point(firstPX, firstPY);
	Point b = Point(SecPX, SecPY);
	Point c = Point(ThirPX, ThirPY);
	Triangle* newTriangle = new Triangle(a, b, c, "triangle", name);
	newTriangle->draw(*_disp, *_board);
	return newTriangle;
}

Circle* Menu::circleMaker()
{
	double centerX = 0, centerY = 0, radius = 0;
	string name = "";
	std::cout << "Please enter the X coordinate of the center point :" << std::endl;
	std::cin >> centerX;
	
	std::cout << "Please enter the Y coordinate of the center point :" << std::endl;
	std::cin >> centerY;
	
	std::cout << "Please enter the radius of the circle: " << std::endl;
	std::cin >> radius;

	std::cout << "Please Enter the name of the circle: " << std::endl;
	std::cin >> name;

	Point centerCircle = Point(centerX,centerY);
	Circle* newCircle = new Circle(centerCircle, radius, "circle", name);
	newCircle->draw(*_disp, *_board);
	return newCircle;
}