#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void F()
{
	short i = 0;

	//	m.lock(); // Starvation!
	while (i++ < 10)
	{
		m.lock();

		std::cout << "F using both locks" << std::endl;

		m.unlock();
	}

	//	m.unlock();  // Starvation!
}

void G()
{
	short i = 0;
	while (i++ < 10)
	{
		m.lock();

		std::cout << "G using both locks" << std::endl;

		m.unlock();
	}
}

void main() {
	std::thread t1(F);
	std::thread t2(G);

	t1.join();
	t2.join();

	system("PAUSE");
}