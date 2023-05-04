#pragma once
#include "OutStream.h"
namespace msl {
	class OutStreamEncrypted :
			public OutStream
		{

		public:
			int _offset;
			OutStreamEncrypted(const int offset);
			OutStreamEncrypted& operator<<(char * str);
		};
}
	