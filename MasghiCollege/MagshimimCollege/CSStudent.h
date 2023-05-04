#pragma once
#include "Student.h"
class CSStudent :
	public Student
{
	bool _laptop;
public:
	//c'tor
	CSStudent(std::string& firstName, std::string& lastName, double height, int id, bool laptop);
	//getters
	bool hasLaptop();

	//func
	virtual void print() const;
};

