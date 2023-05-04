#include "threads.h"



int main()
{
	std::cout << std::endl << "First Test" << std::endl;
	std::vector<int> primes1 = callGetPrimes(0, 1000);
	//printVector(primes1);

	std::cout << std::endl << "Second Test" << std::endl;
	std::vector<int> primes2 = callGetPrimes(0, 100000);
	//printVector(primes2);

	std::cout << std::endl << "Third Test" << std::endl;
	std::vector<int> primes3 = callGetPrimes(0, 1000000);
	//printVector(primes3);

	callWritePrimesMultipleThreads(1, 100000, "primes.txt", 10);

	system("pause");
	return 0;
}