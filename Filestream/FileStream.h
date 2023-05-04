#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "OutStream.h"
#include <string>
#include <iostream>
namespace msl
{
	class FileStream :
				public OutStream
			{
			public:
				FileStream& FileStream::operator<<(void(*pf)());
				void setFilePath(FILE * fileStream);
				FileStream& operator<<(int num);
				FileStream& operator<<(const char *str);
				FILE *getFileObj();
			};


}
		