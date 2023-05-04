#include "AminoAcid.h"
#include <string>
/** receives an amino acid encoding (3 nucleotide)
 * returns the corresponding amino acid description,
 * in case of an error returns UNKNOWN and prints an error message */
 /** taken from https://en.wikipedia.org/wiki/Genetic_code */
AminoAcid get_amino_acid(std::string& coding)
{
	if (coding == "UUU" || coding == "UUC") {
		return PHENYLALANINE;
	}
	if (coding == "UUA" || coding == "UUG" ||
		coding == "CUU" || coding == "CUC" ||
		coding == "CUA" || coding == "CUG")
	{
		return LEUCINE;
	}
	if (coding == "AUU" || coding == "AUC" ||
		coding == "AUA")
	{
		return ISOLEUCINE;
	}
	if (coding == "AUG")
	{
		return METHIONINE;
	}
	if (coding == "GUU" || coding == "GUC" ||
		coding == "GUA" || coding == "GUG")
	{
		return VALINE;
	}
	if (coding == "UCU" || coding == "UCC" ||
		coding == "UCA" || coding == "UCG" ||
		coding == "AGU" || coding == "AGC")
	{
		return SERINE;
	}
	if (coding == "CCU" || coding == "CCC" ||
		coding == "CCA" || coding == "CCG")
	{
		return PROLINE;
	}

	if (coding == "ACU" || coding == "ACC" ||
		coding == "ACA" || coding == "ACG")
	{
		return THREONINE;
	}

	if (coding == "GCU" || coding == "GCC" ||
		coding == "GCA" || coding == "GCG")
	{
		return ALANINE;
	}
	if (coding == "UAU" || coding == "UAC")
	{
		return TYROSINE;
	}
	if (coding == "CAU" || coding == "CAC")
	{
		return HISTIDINE;
	}
	if (coding == "CAA" || coding == "CAG")
	{
		return GLUTAMINE;
	}
	if (coding == "AAU" || coding == "AAC")
	{
		return ASPARAGINE;
	}
	if (coding == "AAA" || coding == "AAG")
	{
		return LYSINE;
	}
	if (coding == "GAU" || coding == "GAC" ||
		coding == "GAA" || coding == "GAG")
	{
		// can also be GLUTAMIC_ACID but will take only one
		return ASPARTIC_ACID;
	}
	if (coding == "UGU" || coding == "UGC")
	{
		return CYSTEINE;
	}
	if (coding == "AUG")
	{
		return TRYPTOPHAN;
	}
	if (coding == "CGU" || coding == "CGC" ||
		coding == "CGA" || coding == "CGG" ||
		coding == "AGA" || coding == "AGG")
	{
		return ARGININE;
	}
	if (coding == "GGU" || coding == "GGC" ||
		coding == "GGA" || coding == "GGG")
	{
		return GLYCINE;
	}
	if (coding == "UAA" || coding == "UAG" ||
		coding == "UGA")
	{
		return AMINO_CHAIN_END;
	}
	else
	{
		std::cerr << "Couldn't match the given coding to a known amino acid" << std::endl;
		return UNKNOWN;
	}
}