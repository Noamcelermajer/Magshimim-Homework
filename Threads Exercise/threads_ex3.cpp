#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;

std::mutex m;
std::mutex m2;

void F(std::fstream* fileF, std::fstream* fileG) {
	short i = 0;

	m.lock(); // lock the resource: fileF, because need to read from it	
	cout << "F locked m\n" << endl;

	// To make sure a deadlock occures
	//std::this_thread::sleep_for(std::chrono::seconds(1)); 

	m2.lock(); // lock the resource: fileG because need to write it
	cout << "F locked m2" << endl;

	while (i++ < 10) 
	{
		cout << "F is reading from f" << endl;
		cout << "F is writing to g" << endl;

	}

	m2.unlock();
	cout << "F unlocked m2" << endl;

	m.unlock();
	cout << "F unlocked m" << endl;

}

void G(std::fstream* fileF, std::fstream* fileG) {
	short i = 0;

	m2.lock(); // lock the resource: fileG, because need to read from it	
	cout << "G locked m2\n" << endl;

	m.lock(); // lock the resource: fileF because need to write it
	cout << "G locked m" << endl;

	while (i++ < 10)
	{
		cout << "G is reading from g" << endl;
		cout << "G is writing to f" << endl;

	}

	m.unlock();
	cout << "G unlocked m" << endl;

	m2.unlock();
	cout << "G unlocked m2" << endl;
}

void justUpdateF(std::fstream* f)
{
	m.lock();
	cout << "justUpdateF locked m\n" << endl;

	// update f

	m.unlock();
	cout << "justUpdateF unlocked m\n" << endl;

}

void main() {
	std::fstream* f; // shared resource
	std::fstream* g; // shared redsource

	std::thread t0(justUpdateF, f);
	std::thread t1(F, f, g);
	std::thread t2(G, f, g);
	
	t0.join();
	t1.join();
	t2.join();

	system("PAUSE");
}