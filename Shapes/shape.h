#ifndef Shape_H
#define Shape_H
#include<string>
#include <iostream>

class Shape
{

public:
	virtual void draw() =0; //DEFINE FOR ALL
	virtual double CalArea();//DEFINE FOR ALL
	static int getCount();
	void setName(std::string);
	std::string getName();
	void setColor(std::string);
	std::string getColor();
	Shape(std::string, std::string);
	//Shape();
	~Shape();
private:
	static int count;
	std::string name;
	std::string color;
	//double area;
	
};

#endif