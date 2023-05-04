#pragma once
#include "Nucleus.h"
#include "Protein.h"

class Ribosome
{
public:
	Protein* create_protein(std::string RNA_transcript) const;
};