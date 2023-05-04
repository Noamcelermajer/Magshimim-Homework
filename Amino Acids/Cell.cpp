#include "Cell.h"
#include <iostream>
#include <string>
void Cell::init(const std::string dna_sequence, const Gene glucose_receptor_gene)
{
	
	_nucleus.init(dna_sequence);
	_mitochodrion.init();
	_atp_units = 0;
	_glocus_receptor_gene = glucose_receptor_gene;


}
bool Cell::get_ATP()
{
	Protein* protein = _ribosome.create_protein(_nucleus.get_RNA_transcript(_glocus_receptor_gene));
	if (protein == nullptr)
	{
		std::cerr << "Failed to create protein\n";
		exit(1);
	}
	_mitochodrion.insert_glucose_receptor(*protein);
	_mitochodrion.set_glucose(50);
	if (!(_mitochodrion.produceATP()))
	{
		_atp_units = 100;
		return true;
	}

	return false;
}