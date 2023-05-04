#include "Cell.h"
#include "Nucleus.h"

#include <string>
#include <random>
#include <windows.h> // WinApi header

////////////////////////////////////////////////////
//					Ex2 Tests					  //
////////////////////////////////////////////////////

/*
NOTE:
You don't have to understand the code,
but you could really benefit from it.

You can use this tester to verify that the
exercise is implemented correctly.

run the tester, it shouldn't print "FAIL",
if it does, try to figure out what is the problem*/


#define RED 4
#define GREEN 2
#define YELLOW 6
#define LIGHT_YELLOW 14
#define LIGHT_BLUE 9
#define WHITE 15

// changes the color of the text on the console screen, 
// feel free to use it in your exercises :)
void set_console_color(unsigned int color)
{
	// colors are 0=black 1=blue 2=green and so on to 15=white
	// colorattribute = foreground + background * 16
	// to get red text on yellow use 4 + 14*16 = 228
	// light red on yellow would be 12 + 14*16 = 236
	// a Dev-C++ tested console application by vegaseat 07nov2004

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

#define NUM_OF_NUCLEUTIDES_IN_PROTEIN 21
#define DNA_SIZE 30		// Must be bigger than NUM_OF_NUCLEUTIDES_IN_PROTEIN

// the desired protein structure 
// ALANINE -> LEUCINE -> GLYCINE -> HISTIDINE -> LEUCINE -> PHENYLALANINE -> AMINO_CHAIN_END
AminoAcid glucose_receptor_amino_acid_chain[] = { ALANINE, LEUCINE, GLYCINE, HISTIDINE, LEUCINE, PHENYLALANINE, AMINO_CHAIN_END };


// the possible coduns for each amino acid that is being tested
// *Note that the coduns are written in their DNA form, not in their RNA form which is different than real life
std::string ALANINE_POSSIBLE_CODUNS[] = { "GCT", "GCC", "GCA", "GCG" };
std::string LEUCINE_POSSIBLE_CODUNS[] = { "TTA", "TTG", "CTT", "CTC", "CTA", "CTG" };
std::string GLYCINE_POSSIBLE_CODUNS[] = { "GGT", "GGC", "GGA", "GGG" };
std::string HISTIDINE_POSSIBLE_CODUNS[] = { "CAT", "CAC" };
std::string PHENYLALANINE_POSSIBLE_CODUNS[] = { "TTT", "TTC" };
std::string AMINOCHAIN_END_POSSIBLE_CODUNS[] = { "TAA", "TAG", "TGA" };

// gets a random number between a range of numbers
int get_random_int(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	auto random_integer = uni(rng);
	return random_integer;
}

// creates a random sequence of neucleotides that translated into the desired protein
std::string generate_random_target_protein()
{
	std::string sequence = "";
	return ALANINE_POSSIBLE_CODUNS[get_random_int(0, 3)]
		+ LEUCINE_POSSIBLE_CODUNS[get_random_int(0, 5)]
		+ GLYCINE_POSSIBLE_CODUNS[get_random_int(0, 3)]
		+ HISTIDINE_POSSIBLE_CODUNS[get_random_int(0, 1)]
		+ LEUCINE_POSSIBLE_CODUNS[get_random_int(0, 5)]
		+ PHENYLALANINE_POSSIBLE_CODUNS[get_random_int(0, 1)]
		+ AMINOCHAIN_END_POSSIBLE_CODUNS[get_random_int(0, 2)];
}

// wraps the variables needed for the test
struct DNA_test
{
	Gene gene;
	std::string dna_sequence;
};

std::string complementary_dna(std::string dna_sequence)
{
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
	return complementary_dna_strand;
}

// returns a random nucleutide sequence in the given size
std::string get_random_dna_sequence(unsigned int size)
{
	// scrambles a random dna sequence
	std::string dna_sequence = "";
	for (unsigned int i = 0; i < size; i++)
	{
		int choice = get_random_int(0, 3);
		switch (choice)
		{
		case 0:
			dna_sequence += 'A';
			break;
		case 1:
			dna_sequence += 'C';
			break;
		case 2:
			dna_sequence += 'G';
			break;
		case 3:
			dna_sequence += 'T';
			break;
		}
	}
	return dna_sequence;
}

DNA_test generate_random_test()
{
	// gets a valid protein
	std::string protein = generate_random_target_protein();

	std::cout << "original ";
	set_console_color(LIGHT_YELLOW);
	std::cout << protein << std::endl;
	set_console_color(WHITE);

	// randomly decides if the protein is represented in it's complementary form
	bool is_on_complementary = bool(get_random_int(0, 1));
	if (is_on_complementary)
	{
		protein = complementary_dna(protein);
	}

	// adds random sequences from the left and from the right of the protein (could be empty)
	int left_sequence_size = get_random_int(0, DNA_SIZE - NUM_OF_NUCLEUTIDES_IN_PROTEIN);
	std::string dna_sequence = get_random_dna_sequence(left_sequence_size) +
		protein +
		get_random_dna_sequence(DNA_SIZE - NUM_OF_NUCLEUTIDES_IN_PROTEIN - left_sequence_size);

	// the protein starts at the end of the left sequence
	int start = left_sequence_size;

	// builds a Gene object that suits the protein
	Gene gene;
	gene.init(start, start + NUM_OF_NUCLEUTIDES_IN_PROTEIN - 1, is_on_complementary);

	// wraps both dna sequence and gene in a struct called test
	struct DNA_test random_test;
	random_test.dna_sequence = dna_sequence;
	random_test.gene = gene;

	return random_test;
}

void print_test_vars(DNA_test test)
{
	set_console_color(2 * 15);
	std::cout << "**************** Test information ****************" << std::endl;

	set_console_color(WHITE);
	std::cout << "DNA sequence: ";
	set_console_color(LIGHT_BLUE);
	std::cout << test.dna_sequence.substr(0, test.gene.get_start());
	set_console_color(YELLOW);
	std::cout << test.dna_sequence.substr(test.gene.get_start(), test.gene.get_end() + 1);
	set_console_color(LIGHT_BLUE);
	std::cout << test.dna_sequence.substr(test.gene.get_end(), std::string::npos) << std::endl;

	set_console_color(WHITE);
	std::cout << "Gene: ";
	set_console_color(LIGHT_BLUE);
	std::cout << "start: ";
	set_console_color(YELLOW);
	std::cout << test.gene.get_start();
	set_console_color(LIGHT_BLUE);
	std::cout << "  end: ";
	set_console_color(YELLOW);
	std::cout << test.gene.get_end();
	set_console_color(LIGHT_BLUE);
	std::cout << " the gene is on ";
	set_console_color(YELLOW);
	std::cout << (test.gene.is_on_complementary_dna_strand() ? "complementary" : "regular");
	set_console_color(LIGHT_BLUE);
	std::cout << " DNA strand" << std::endl;
	set_console_color(WHITE);
}

void print_test_result(bool result)
{
	set_console_color(WHITE);
	std::cout << "Test ";
	if (result)
	{
		set_console_color(GREEN);
		std::cout << "PASSED! :)";
	}
	else
	{
		set_console_color(RED);
		std::cout << "FAILED! :(";
	}
	set_console_color(WHITE);
	std::cout << "\n" << std::endl;
}

int main()
{
	DNA_test t = generate_random_test();
	print_test_vars(t);

	Cell cell;
	cell.init(t.dna_sequence, t.gene);
	bool result = cell.get_ATP();
	print_test_result(result);


	system("pause");
	return 0;
}