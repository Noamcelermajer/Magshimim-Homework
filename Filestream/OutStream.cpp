#include "OutStream.h"
#include <stdio.h>
using namespace msl;
	OutStream::OutStream()
	{
	}

	OutStream::~OutStream()
	{
	}

	OutStream& OutStream::operator<<(const char *str)
	{
		printf("%s", str);
		return *this;
	}

	OutStream& OutStream::operator<<(int num)
	{
		printf("%d", num);
		return *this;
	}

	OutStream& OutStream::operator<<(void(*pf)())
	{
		pf();
		return *this;
	}


	void msl::endline()
	{
		printf("\n");
	}


