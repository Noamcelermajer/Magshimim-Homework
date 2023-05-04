#include "FileStream.h"
#include <iostream>
using namespace msl;
FileStream& FileStream::operator<<(const char *str)
{
	fprintf(_fileObj,"%s", str);
	return *this;
}

FileStream& FileStream::operator<<(int num)
{
	fprintf(_fileObj,"%d", num);
	return *this;
}

void FileStream::setFilePath(FILE * fileStream)
{
	_fileObj = fileStream;
}
FileStream& FileStream::operator<<(void(*pf)())
{
	pf();
	return *this;
}
FILE* FileStream::getFileObj()
{
	return _fileObj;
}

void fEndline()
{

}