#include "Nucleus.h"
#include "Ribosome.h"
#include "Protein.h"
#include <iostream>
#include <string>

Protein* Ribosome::create_protein(std::string RNA_transcript)const
{
	std::string protein_maker;

	Protein* head = new Protein;
	head->init();

	for ( int i = 0; i < RNA_transcript.length(); i+=3)
	{
		protein_maker = RNA_transcript.substr(i, 3);
		if (get_amino_acid(protein_maker)==AminoAcid::UNKNOWN)
		{
			head->clear();
			delete head;
			return nullptr;
		}
		else
		{
			head->add(get_amino_acid(protein_maker));
		}
	}
	
	return head;
}
