#include "Student.h"
//c'tor
Student::Student(std::string& firstName, std::string& lastName, double height, int id)
{
	int i = 0;
	_firstName = firstName;
	_lastName = lastName;
	_height = height;
	_id = id;
	if (_height > _maxHeight)
	{
		_maxHeight = _height;
		_tallest = id;
	}
	while (i++ != 11)
	{
		_grades.push_back(-1);
	}
}

//setters
void Student::set_firstname(std::string& firstName)
{
	_firstName = firstName;
}
void Student::set_lastName(std::string& lastName)
{
	_lastName = lastName;
}
void Student::set_height(double height)
{
	_height = height;
}
void Student::set_grades(std::vector<int> grades)
{
	_grades = grades;
}
void Student::set_courses(std::vector<Course> courses)
{
	_courses = courses;
}

//getters

std::string Student::get_firstName()
{
	return _firstName;
}
std::string Student::get_lastName()
{
	return _lastName;
}
double Student::get_height()
{
	return _height;
}
std::vector<int> Student::get_grades()
{
	return _grades;
}
std::vector<Course> Student::get_courses()
{
	return _courses;
}

double Student::getAverage() const
{
	double sum = 0;

	for (std::vector<int>::const_iterator it = _grades.begin(); it != _grades.end(); ++it)
		sum += *it;

	return sum / _grades.size();
}

int Student::tallestStudent() const 
{
	return _tallest;
}


void Student::setGrade(std::string& courseName, int newGrade)
{
	int index = 0;
	for (auto it = _courses.begin(); it != _courses.end(); ++it)
	{
		if (it->get_name() == courseName)
		{
			_grades[it->get_courseId()] = newGrade;
			return;
		}
	}
	throw NoCourseException();
}
//operators
const bool Student::operator==(Student& other)
{
	return(other.get_firstName() == _firstName && other.get_lastName() == _lastName && other.get_height() == _height);
}


void Student::print() const 
{
	std::cout << "Student id " << _id << std::endl << _firstName.c_str() << " " << _lastName.c_str() << std::endl << "Height :" << _height << std::endl << "Grades: " << std::endl;
	for (std::vector<Course>::const_iterator cIt = _courses.begin(); cIt != _courses.end(); ++cIt)
	{
			std::cout << cIt->get_name().c_str() << _grades[cIt->get_courseId()] << std::endl;
	}
}
const bool Student::operator<(Student& other)
{
	return (_height < other.get_height());
}

const int Student::operator[](std::string& courseName)
{
	int courseIndex = 0;
	for (auto it = _courses.begin(); it != _courses.end(); it++)
	{
		if (it->get_name() == courseName)
		{
			courseIndex = it->get_courseId();
			return _grades[courseIndex];
		}
	}
	throw NoCourseException();

}



//
