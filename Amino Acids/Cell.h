#pragma once
#include "Mitochodrion.h"


class Cell
{
	Nucleus _nucleus;
	Ribosome _ribosome;
	Mitochondrion _mitochodrion;
	Gene _glocus_receptor_gene;
	unsigned int  _atp_units;
public:
	void init(const std::string dna_sequence, const Gene glucose_receptor_gene);
	bool get_ATP();
};