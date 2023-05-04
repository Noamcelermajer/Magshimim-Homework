#include "Course.h"

//c'tor
Course::Course(const std::string& name, int id)
{
	_name = name;
	_courseId = id;
	_numCourse++;
}

//setters
void Course::set_name(const std::string name)
{
	_name = name;
}
void Course::set_courseId(int id)
{
	_courseId = id;
}

//getters

std::string Course::get_name() const 
{
	return _name;
}
int Course::get_courseId() const
{
	return _courseId;
}


//class func 
const int Course::totalNumberOfCourse()
{
	return _numCourse;
}
