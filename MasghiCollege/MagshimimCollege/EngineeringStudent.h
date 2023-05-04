#pragma once
#include "Student.h"
class EngineeringStudent :
	public Student
{
	std::string _project;
public:
	EngineeringStudent(std::string& firstName, std::string& lastName, double height, int id, std::string& project);
	virtual void print() const;
	std::string projectSubject();
};

