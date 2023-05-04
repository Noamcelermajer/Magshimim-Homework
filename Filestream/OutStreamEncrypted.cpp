#include "OutStreamEncrypted.h"
#include "OutStream.h"
using namespace msl;
OutStreamEncrypted::OutStreamEncrypted(const int offset)
{
	_offset = offset;
}
OutStreamEncrypted& OutStreamEncrypted::operator<<(char * str)
{
	OutStream std;
	char * str2 = new char[255];
	int i = 0;
	char tmpChar;
	for (i = 0; i <= strlen(str); i++)
	{
		if ((int)str[i] > 32 && (int)str[i] < 126)
		{
			if ((str[i] + _offset) > 126)
			{
				tmpChar = str[i];
				for (int j = 0; j < _offset; j++)
				{
					if (tmpChar > 126)
					{
						tmpChar = 32;
					}
					tmpChar = tmpChar + 1;

				}
				str2[i] = tmpChar;
			}
			else
			{
				str2[i] = str[i] + _offset;

			}
		}
		else
		{
			str2[i] = str[i];
		}
	}
	std << str2;
	return *this;
}