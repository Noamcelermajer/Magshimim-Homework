#include "HyperList.h"

int main()
{
	std::string test = "test";
	HyperList<int> Ilist;
	HyperList<double> Dlist;
	HyperList<std::string> Slist;
	std::cout << "Test int :" << Ilist.add(89) << std::endl;
	std::cout << "Test Double :" << Dlist.add(43.76) << std::endl;
	std::cout << "Test String :" << Slist.add(test) << std::endl;

	std::cout << "Contains int :" << Ilist.contains(89) << std::endl;
	std::cout << "Contains Double :" << Dlist.contains(43.76) << std::endl;
	std::cout << "Contains String :" << Slist.contains(test) << std::endl;
	getchar();
}