#pragma once
#include "Course.h"
#include <vector>
class Student
{
	std::string _firstName;
	std::string _lastName;
	int _id;
	double _height;
	static int _tallest;
	static double _maxHeight;
protected:
	std::vector<int> _grades;
	std::vector<Course> _courses;

public:
	//c'tor
	Student(std::string& firstName, std::string& lastName, double height, int id);

	//setters
	void set_firstname(std::string& firstName);
	void set_lastName(std::string& lastName);
	void set_height(double height);
	void set_grades(std::vector<int> grades);
	void set_courses(std::vector<Course> courses);
	void setGrade(std::string& courseName, int newGrade);
	//getters

	std::string get_firstName();
	std::string get_lastName();
	double get_height();
	std::vector<int> get_grades();
	std::vector<Course> get_courses();

	//class func
	virtual void print() const;
	double getAverage() const;
	int tallestStudent() const;

	//operators
	const bool operator==(Student& other);
	const bool operator<(Student& other);
	const int operator[](std::string& courseName);

};

