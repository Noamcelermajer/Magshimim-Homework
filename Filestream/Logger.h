#pragma once
#include "OutStream.h"
#include <stdio.h>
namespace msl
{
	class Logger
	{
		OutStream os;
		bool _startLine;
		void setStartLine();
	public:
		Logger();
		~Logger();
		friend Logger& operator<<(Logger& l, const char *msg);
		friend Logger& operator<<(Logger& l, int num);
		friend Logger& operator<<(Logger& l, void(*pf)());
	};
}

