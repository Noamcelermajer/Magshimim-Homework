#include "threads.h"
std::mutex fileMutex;
std::ofstream myfile;
void I_Love_Threads()
{
	std::cout << "I Love Threads" << std::endl;
}
void call_I_Love_Threads()
{
	std::thread callFuncThread(I_Love_Threads);
	callFuncThread.join();
}

void printVector(std::vector<int> primes)
{
	for (auto i = primes.begin(); i != primes.end(); ++i)
		std::cout << *i << std::endl;
}

void getPrimes(int begin, int end, std::vector<int>& primes)
{
	int flag = 0;
	for (int i = begin; i <= end; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				flag = 1;
				break;
			}

		}
		if (flag == 0 && i != 1)
		{
			primes.push_back(i);
			flag = 0;
		}
		flag = 0;
	}
}


std::vector<int> callGetPrimes(int begin, int end)
{
	std::vector<int> primes;
	auto before = std::chrono::system_clock::now();
	std::thread  funcThread(getPrimes, begin, end, ref(primes));
	funcThread.join();
	auto after = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = after - before;
	time_t end_time = std::chrono::system_clock::to_time_t(after);
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	return primes;
}

void writePrimesToFile(int begin, int end, std::ofstream& file)
{
	int flag = 0;

	for (int i = begin; i <= end; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				flag = 1;
				break;
			}

		}
		if (flag == 0 && i != 1)
		{
			fileMutex.lock();
			file << i << "\n";
			flag = 0;
			fileMutex.unlock();
		}
		flag = 0;
	}
}
void callWritePrimesMultipleThreads(int begin, int end, std::string filePath, int N)
{
	myfile.open(filePath);
	int offset = end / N;
	int send(end);
	for (int i = 0; i < N - 1; i++)
	{
		end += offset;
		std::thread callfunc(writePrimesToFile, begin, end, ref(myfile));
		callfunc.detach();
		begin += offset;
	}
	end += offset;
	std::thread callfunc(writePrimesToFile, begin, end, ref(myfile));
	callfunc.join();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	myfile.close();
}
