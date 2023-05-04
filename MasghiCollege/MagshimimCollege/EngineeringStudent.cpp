#include "EngineeringStudent.h"



EngineeringStudent::EngineeringStudent(std::string& firstName, std::string& lastName, double height, int id, std::string& project): Student(firstName,lastName,height,id)
{
	_project = project;
	_courses.push_back(Course("Introduction to Physics", INTRODUCTION_PHYSICS));
	_courses.push_back(Course("Linear Algebra", LINEAR_ALGEBRA));
	_courses.push_back(Course("Calculous", CALCULOUS));
	_courses.push_back(Course("Probability and Statistics", PROB_AND_STATS));
	_courses.push_back(Course("Electronics", ELECTRONICS));
}

std::string EngineeringStudent::projectSubject()
{
	return _project;
}


void EngineeringStudent::print() const
{
	std::cout << "### Engineering Student ###" << std::endl;
	Student::print();
	std::cout << "Project's subject :" << _project.c_str() << std::endl << std::endl;
}