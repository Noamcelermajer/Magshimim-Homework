#pragma once
#include <iostream>
namespace msl
{
	class OutStream
	{
	protected:
		FILE * _fileObj;
	public:
		OutStream();
		~OutStream();

		OutStream& operator<<(const char *str);
		OutStream& operator<<(int num);
		OutStream& operator<<(void(*pf)());
	};

	void endline();
}
