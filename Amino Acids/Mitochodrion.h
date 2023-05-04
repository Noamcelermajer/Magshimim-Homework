#pragma once
#include "Ribosome.h"
class Mitochondrion
{
	unsigned int _glocuse_level;
	bool _has_glucose_receptor;
public:
	void init();
	void insert_glucose_receptor(const Protein & protein);
	void set_glucose(const unsigned int glocuse_units);
	bool produceATP() const;
};