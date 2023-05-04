#include "NoCourseException.h"



const char * NoCourseException::what() const throw ()
{
	return "Error: the course is not part of the student's syllabus";

}