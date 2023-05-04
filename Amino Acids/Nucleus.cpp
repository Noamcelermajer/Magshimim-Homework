#include "Nucleus.h"
#include <iostream>
#include <string>
// setters
void Gene::init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand)
{
	_start = start;

	_end = end;

	_on_complementary_dna_strand = on_complementary_dna_strand;

}

unsigned int Gene::get_start() const
{
	return _start;
}


unsigned int Gene::get_end() const
{
	return _end;
}


bool Gene::is_on_complementary_dna_strand() const
{
	return _on_complementary_dna_strand;
}

void Gene::set_start(const int start) 
{
	_start = start;
}

void Gene::set_end(const int end) 
{
	_end = end;
}
void Gene::set_on_complementary_dna_strand(bool value)
{
	_on_complementary_dna_strand = value;
}

void Nucleus::init(const std::string dna_sequence)
{
	check_DNA_strand(dna_sequence);
	_DNA_strand = dna_sequence;
	std::string complementary_dna_strand = "";
	for (unsigned int i = 0; i < dna_sequence.length(); i++)
	{
		if (dna_sequence[i] == 'A')
		{
			complementary_dna_strand += 'T';
		}
		else if (dna_sequence[i] == 'G')
		{
			complementary_dna_strand += 'C';
		}
		else if (dna_sequence[i] == 'C')
		{
			complementary_dna_strand += 'G';
		}
		else if (dna_sequence[i] == 'T')
		{
			complementary_dna_strand += 'A';
		}
		else
		{
			std::cerr << "dna sequence is not valid" << std::endl;
			_exit(1); // exits with error code
		}
	}
}

void Nucleus::check_DNA_strand(std::string _DNA_strand) const //Return true if strand correct else the program print an error message and exit the program
{
	for (unsigned int i = 0; i < _DNA_strand.length(); i++)
	{
		if (_DNA_strand[i] != 'A' && _DNA_strand[i] != 'G' && _DNA_strand[i] != 'C' && _DNA_strand[i] != 'T')
		{
			std::cerr << "Invalid DNA_strand MUST Contains only : \"A,G,C,T\"\n";
			exit(1);
		}
	}
}




std::string Nucleus::get_RNA_transcript(const Gene& gene) const
{
	unsigned int start = gene.get_start();
	unsigned int end = gene.get_end();
	std::string RNA_strand;
	std::string to_check;
	if(gene.is_on_complementary_dna_strand())
	{
		to_check = _complementary_DNA_strand;
	}
	else
	{
		to_check = _DNA_strand;
	}
	for(unsigned int i = start; i <= end; i++)
	{
		if (_DNA_strand[i] == 'T')
		{
			RNA_strand += 'U';
		}
		else
		{
			RNA_strand += _DNA_strand[i];
		}
	}
	return RNA_strand;
}


std::string Nucleus::get_reversed_DNA_strand() const
{
	std::string reversed_DNA_strand = _DNA_strand;
	std::reverse(reversed_DNA_strand.begin(), reversed_DNA_strand.end());
	return reversed_DNA_strand;
}
unsigned int Nucleus::get_num_of_codon_appearances(const std::string& codon) const
{
	int count = 0;
	std::string to_check;
	for (unsigned int i = 0; i <= _DNA_strand.size() - codon.size(); i++)
	{
		to_check += _DNA_strand[i];
		to_check += _DNA_strand[i+1];
		to_check += _DNA_strand[i+2];
		if (to_check== codon)
		{
			count += 1;
		}
		to_check = "";
	}
	return count;
}
