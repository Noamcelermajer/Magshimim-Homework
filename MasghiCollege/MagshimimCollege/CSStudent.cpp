#include "CSStudent.h"



CSStudent::CSStudent(std::string& firstName, std::string& lastName, double height, int id, bool laptop) : Student(firstName,lastName,height,id)
{
	_laptop = laptop;
	_courses.push_back(Course("Introduction to Computer Science", INRODUCTION_COMPUTER_SIENCE));
	_courses.push_back(Course("Linear Algebra", LINEAR_ALGEBRA));
	_courses.push_back(Course("Calculous", CALCULOUS));
	_courses.push_back(Course("Probability and Statistics", PROB_AND_STATS));
	_courses.push_back(Course("Object Oriented Programming", OBJECT_ORIENTED_PROGRAMING));
	_courses.push_back(Course("Data Structures", DATA_STRUCTURES));
	_courses.push_back(Course("Operating System", OPERATING_SYSTEM));
}
//getters
bool CSStudent::hasLaptop()
{
	return _laptop;
}

//func
void CSStudent::print() const
{
	std::cout << "### Computer Science Student ###" << std::endl;
	Student::print();
	if (_laptop)
	{
		std::cout << "has a laptop";
	}
	std::cout << std::endl << std::endl;
}