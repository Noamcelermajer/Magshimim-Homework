#pragma once
#include <iostream>
#include "NoCourseException.h"
#define INRODUCTION_COMPUTER_SIENCE 1
#define LINEAR_ALGEBRA 2
#define CALCULOUS 3
#define INTRODUCTION_PHYSICS 4
#define DATA_STRUCTURES 5
#define OPERATING_SYSTEM 6
#define INTRODUCTION_TO_ECONOMY 7
#define ELECTRONICS 8
#define PROB_AND_STATS 9
#define OBJECT_ORIENTED_PROGRAMING 10



class Course
{
	std::string _name;
	static int _numCourse;
	int _courseId;//changed from _courseNum
public:
	//c'tor
	Course(const std::string& name, int id);

	//setters
	void set_name(const std::string name);
	void set_courseId(int id);

	//getters
	int get_courseId() const;
	std::string get_name() const;

	//classe func
	const int totalNumberOfCourse();
};