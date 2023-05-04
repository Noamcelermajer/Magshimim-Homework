#include "Student.h"
#include "CSStudent.h"
#include "EnconomyStudent.h"
#include "EngineeringStudent.h"
#include <iostream>
int Student::_tallest;
double Student::_maxHeight;
int Course::_numCourse;
void printall(std::vector<Student*>& students);
int main()
{
	std::string firstName = "noam", lastName = "Celermajer", project = "IronMan", internship = "IBM", course = "check exception";
	std::vector<Student*>students;
	students.push_back(new CSStudent(firstName, lastName, 1.78, 2, true));
	firstName = "Yoav",lastName = "Matityaouh";
	students.push_back(new CSStudent(firstName, lastName, 1.78, 2, false));
	firstName = "Nadav",lastName = "Weiss";
	students.push_back(new EngineeringStudent(firstName, lastName, 1.78, 2, project));
	firstName = "Cino",lastName = "Funi";
	students.push_back(new EnconomyStudent(firstName, lastName, 1.78, 2, internship));\
	try
	{
		for (auto &i : students) {
			i->setGrade(course, 100);//change course to check
		}
	}
	catch (std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}
	printall(students);
	getchar();
}

void printall(std::vector<Student*>& students)
{
	for (auto &i : students) {
		i->print();
	}
}