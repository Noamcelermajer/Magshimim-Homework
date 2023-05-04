#include <iostream>
#include "shape.h"
#include "circle.h"
#include "quadrilateral.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "Pentagon.h"
#include "Hexagone.h"
#include <string>
#include "shapeException.h"
#include "InputException.h"
int main()
{
	std::string nam, col, test; double rad = 0,length = 0, ang = 0, ang2 = 180; int height = 0, width = 0 ;
	Circle circ(col, nam, rad);
	quadrilateral quad(nam, col, width, height);
	rectangle rec(nam, col, width, height);
	parallelogram para(nam, col, width, height, ang, ang2);
	Shape *ptrcirc = &circ;
	Shape *ptrquad = &quad;
	Shape *ptrrec = &rec;
	Shape *ptrpara = &para;


	
	std::cout << "Enter information for your objects" << std::endl;
	const char circle = 'c', quadrilateral = 'q', rectangle = 'r', parallelogram = 'p'; char shapetype;
	char x = 'y';
	while (x != 'x') {
		std::cout << "which shape would you like to work with?.. \nc=circle, q = quadrilateral, r = rectangle, p = parallelogram" << std::endl;
		std::cin >> test;
		if (test.length() > 2)
		{
			std::cout << "Warning - Don't try to build more than one shape at once" << std::endl;
		}
		shapetype = test[0];
try		
		{

			switch (shapetype) {
			case 'p':
				std::cout << "enter color, name,  length" << std::endl;
				std::cin >> col >> nam >> length;
				if (std::cin.fail())
				{
					throw InputException();
				}
				circ.setColor(col);
				circ.setName(nam);
				circ.setRad(rad);
				ptrcirc->draw();
				break;
			case 'h':
				std::cout << "enter color, name,  length" << std::endl;
				std::cin >> col >> nam >> length;
				if (std::cin.fail())
				{
					throw InputException();
				}
				circ.setColor(col);
				circ.setName(nam);
				circ.setRad(rad);
				ptrcirc->draw();
				break;
			case 'c':
				std::cout << "enter color, name,  rad for circle" << std::endl;
				std::cin >> col >> nam >> rad;
				if (std::cin.fail())
				{
					throw InputException();
				}
				circ.setColor(col);
				circ.setName(nam);
				circ.setRad(rad);
				ptrcirc->draw();
				break;
			case 'q':
				std::cout << "enter name, color, height, width" << std::endl;
				std::cin >> nam >> col >> height >> width;
				if (std::cin.fail())
				{
					throw InputException();
				}
				quad.setName(nam);
				quad.setColor(col);
				quad.setHeight(height);
				quad.setWidth(width);
				ptrquad->draw();
				break;
			case 'r':
				std::cout << "enter name, color, height, width" << std::endl;
				std::cin >> nam >> col >> height >> width;
				if (std::cin.fail())
				{
					throw InputException();
				}
				rec.setName(nam);
				rec.setColor(col);
				rec.setHeight(height);
				rec.setWidth(width);
				ptrrec->draw();
				break;
			case 'p':
				std::cout << "enter name, color, height, width, 2 angles" << std::endl;
				std::cin >> nam >> col >> height >> width >> ang >> ang2;
				if (ang < 0 || ang > 180 || ang2 < 0 || ang2 > 180)
				{
					throw shapeException();
				}
				if (std::cin.fail())
				{
					throw InputException();
				}
				para.setName(nam);
				para.setColor(col);
				para.setHeight(height);
				para.setWidth(width);
				para.setAngle(ang, ang2);
				ptrpara->draw();

			default:
				std::cout << "you have entered an invalid letter, please re-enter" << std::endl;
				break;
			}
			std::cout << "would you like to add more object press any key if not press x" << std::endl;
			std::cin.get() >> x;
		}
		catch (InputException &e)
		{
			std::cout << e.what();
			std::cin.clear();
			std::cin.ignore();
		}
		catch (std::exception &e)//return by value and get as reference (Dont work with Thing u dont know :P)
		{			
			printf(e.what());
		}
		catch (...)
		{
			printf("caught a bad exception. continuing as usual\n");
		}
	}



		system("pause");
		return 0;
	
}