#include "EnconomyStudent.h"



EnconomyStudent::EnconomyStudent(std::string& firstName, std::string& lastName, double height, int id, std::string& internship) : Student(firstName, lastName, height,id)
{
	_internship = internship;
	_courses.push_back(Course("Introduction to Economy", INTRODUCTION_TO_ECONOMY));
	_courses.push_back(Course("Linear Algebra", LINEAR_ALGEBRA));
	_courses.push_back(Course("Calculous", CALCULOUS));
	_courses.push_back(Course("Probability and Statistics", PROB_AND_STATS));
}
std::string EnconomyStudent::internship()
{
	return _internship;
}

void EnconomyStudent::print() const
{
	std::cout << "### Economy ###" << std::endl;
	Student::print();
	std::cout << "Doing internship in: " << _internship.c_str() << std::endl;
}