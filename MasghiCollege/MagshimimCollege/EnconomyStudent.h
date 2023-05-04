#pragma once
#include "Student.h"

class EnconomyStudent :
	public Student
{
	std::string _internship;
public:
	EnconomyStudent(std::string& firstName, std::string& lastName, double height, int id, std::string& internship);
	std::string internship();
	virtual void print() const;
};
