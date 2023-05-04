#define _CRT_SECURE_NO_WARNINGS
#include "OutStream.h"
#include "FileStream.h"
#include "OutStreamEncrypted.h"
#include "Logger.h"
#include <iostream>
#define DOCTOR_AGE 1500
using namespace msl;
int main(int argc, char **argv)
{
	int offset = 0;
	FILE * fileStream = fopen("log.txt", "w");
	FileStream FileStream;
	OutStream std;
	Logger log;
	OutStreamEncrypted stdenc = offset;
	FileStream.setFilePath(fileStream);
	FileStream << "I am the Docto and I'm" << DOCTOR_AGE << " years old";
	std << "using OutStreamEncrypted.h ", stdenc << "i am the Doctor and I'm 1500 years old",std << endline;
	log << "I am the Docto and I'm" << DOCTOR_AGE << " years old"<< endline;
	return 0;
}