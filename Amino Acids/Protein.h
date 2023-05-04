#pragma once
#include "AminoAcid.h"

/** A short class that represents a Node in an amino acid linked list */
class AminoAcidNode
{
public:
	void init(const AminoAcid amino_acid);

	// getters
	AminoAcidNode *get_next() const;
	AminoAcid get_data() const;

	// setters
	void set_next(AminoAcidNode *next);
	void set_data(const AminoAcid new_data);

private:
	AminoAcid _data;
	AminoAcidNode *_next;
};

/** A short class that represents a linked list that holds amino acids */
class Protein
{
public:
	/** initialize an empty list */
	void init();
	void clear();

	// getters
	AminoAcidNode *get_first() const;

	// setters
	void set_first(AminoAcidNode *first);

	/** adds a string to the end of the list
	 * returns true if the string added successfully, false otherwise **/
	void add(const AminoAcid amino_acid_to_add);

private:
	AminoAcidNode* _first;   // first Node in the list
};

/** a protein is a folded chain of amino acids */
typedef Protein Protein;
