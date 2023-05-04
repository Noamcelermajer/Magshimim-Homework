#pragma once
#include <string>
class Gene
{
	unsigned int _start;
	unsigned int _end;
	bool _on_complementary_dna_strand;
public:
	void init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand);
	unsigned int get_start() const;
	unsigned int get_end() const;
	bool is_on_complementary_dna_strand() const;
	void set_start(const int start);
	void set_end(const int end);
	void set_on_complementary_dna_strand(bool value);
};

class Nucleus
{
	std::string _DNA_strand;
	std::string _complementary_DNA_strand;
public:
	void init(const std::string dna_sequence);		
	std::string get_RNA_transcript(const Gene& gene) const;
private:
	void check_DNA_strand(std::string _DNA_strand) const;
	std::string get_reversed_DNA_strand() const;
	unsigned int get_num_of_codon_appearances(const std::string& codon) const;
};