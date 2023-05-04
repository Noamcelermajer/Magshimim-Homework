#include "Logger.h"
#include "OutStream.h"
#include <iostream>
using namespace msl;
Logger& msl::operator<<(Logger& l, const char *msg)
{
	OutStream std;
	l.setStartLine();
	std << msg << endline;
	return l;
}
void Logger::setStartLine()
{
	static unsigned int count;
	OutStream std;
	std << "LOG N." << count << ".";
	_startLine = false;
	count++;
}
Logger& msl::operator<<(Logger& l, int num)
{
	OutStream std;
	l.setStartLine();
	std << num << endline;
	return l;
}
Logger& msl::operator<<(Logger& l, void(*pf)())
{
	pf();
	l._startLine = true;
	return l;
}
Logger::Logger()
{ 
}
Logger::~Logger()
{

}