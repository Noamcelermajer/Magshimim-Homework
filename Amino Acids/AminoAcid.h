#pragma once
#include <string>
#include <iostream>

enum AminoAcid
{
	/** visit http://www.cryst.bbk.ac.uk/education/AminoAcid/the_twenty.html
	 * to learn about the amino acids purpose */
	ALANINE,
	ARGININE,
	ASPARAGINE,
	ASPARTIC_ACID,
	CYSTEINE,
	GLUTAMINE,
	GLUTAMIC_ACID,
	GLYCINE,
	HISTIDINE,
	ISOLEUCINE,
	LEUCINE,
	LYSINE,
	METHIONINE,
	PHENYLALANINE,
	PROLINE,
	SERINE,
	THREONINE,
	TRYPTOPHAN,
	TYROSINE,
	VALINE,
	AMINO_CHAIN_END,
	UNKNOWN
};

/** receives an amino acid encoding (3 nucleotide)
 * returns the corresponding amino acid description,
 * in case of an error returns UNKNOWN and prints an error message */
 /** taken from https://en.wikipedia.org/wiki/Genetic_code */
AminoAcid get_amino_acid(std::string& coding);