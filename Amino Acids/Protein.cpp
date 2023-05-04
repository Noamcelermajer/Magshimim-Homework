#include "Protein.h"
#include <iostream>
using std::cout;
using std::endl;

/** initialize an empty list */
void Protein::init()
{
	this->_first = nullptr;
}

// getters
AminoAcidNode* Protein::get_first() const
{
	return this->_first;
}

// setters
void Protein::set_first(AminoAcidNode *first)
{
	this->_first = first;
}

/** adds an amino acid to the end of the list **/
void Protein::add(const AminoAcid amino_acid_to_add)
{
	// create a new node to store the amino acid
	AminoAcidNode *new_node = new AminoAcidNode;
	new_node->init(amino_acid_to_add);

	if (this->_first == nullptr) // list is empty
	{
		this->_first = new_node; // the new node is the first node
	}
	else        // list has at least one element
	{
		AminoAcidNode *curr = this->_first;      // start from first
		while (curr->get_next() != nullptr) // advance to the last element
		{
			curr = curr->get_next();
		}
		curr->set_next(new_node); // add the new node at the end of the list
	}
}

/** clears the list's memory */
void Protein::clear()
{
	AminoAcidNode* temp;
	while (this->_first != nullptr) // as long as the list is not empty
	{
		temp = this->_first;    // temp points to the first element
		this->_first = this->_first->get_next();   // the list now starts from the 2nd element
		delete temp;    // deletes the previous first element
	}
}

/* initialize a new Node object that stores the given data */
void AminoAcidNode::init(const AminoAcid amino_acid)
{
	this->_data = amino_acid;
	this->_next = nullptr;
}

// getters
AminoAcidNode* AminoAcidNode::get_next() const
{
	return this->_next;
}

AminoAcid AminoAcidNode::get_data() const
{
	return this->_data;
}

// setters
void AminoAcidNode::set_next(AminoAcidNode *next)
{
	this->_next = next;
}

void AminoAcidNode::set_data(const AminoAcid amino_acid)
{
	this->_data = amino_acid;
}

