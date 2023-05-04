#include "Mitochodrion.h"

void Mitochondrion::init()
{
	_glocuse_level = 0;
	_has_glucose_receptor = false;
}

void Mitochondrion::insert_glucose_receptor(const Protein & protein)
{
	for (int i = 0; i < 7; i++)
	{
		if (!(protein.get_first()->get_data() == ALANINE))
			_has_glucose_receptor = false;
		else if (!(protein.get_first()->get_next()->get_data() == LEUCINE))
			_has_glucose_receptor = false;
		else if (!(protein.get_first()->get_next()->get_next()->get_data() == GLYCINE))
			_has_glucose_receptor = false;
		else if (!(protein.get_first()->get_next()->get_next()->get_next()->get_data() == HISTIDINE))
			_has_glucose_receptor = false;
		else if (!(protein.get_first()->get_next()->get_next()->get_next()->get_next()->get_data() == LEUCINE))
			_has_glucose_receptor = false;
		else if (!(protein.get_first()->get_next()->get_next()->get_next()->get_next()->get_next()->get_data() == PHENYLALANINE))
			_has_glucose_receptor = false;
		else if (!(protein.get_first()->get_next()->get_next()->get_next()->get_next()->get_next()->get_next()->get_data() == AMINO_CHAIN_END))
			_has_glucose_receptor = false;
		else
			_has_glucose_receptor = true;

	}
}
void Mitochondrion::set_glucose(const unsigned int glocuse_units)
{
	_glocuse_level = glocuse_units;
}
bool Mitochondrion::produceATP()const
{
	return(_glocuse_level >= 50 && _has_glucose_receptor == true);
}
