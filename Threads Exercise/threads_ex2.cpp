#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

int shared_resource = 10;
std::mutex mtx;

using std::cout;
using std::endl;

void test_resource()
{
	for (int i = 0; i < 10; i++)
	{
		mtx.lock();//if mtx unlocked: this thread locks it! if mtx locked: this thread waits until unlocked

		/*** critical section start  ***/
		int res = shared_resource;
		cout << "going to sleep at test_reource for 1 second" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (res != shared_resource)
		{
			cout << "ALARM" << endl;
		}
		else
		{
			cout << "SAME" << endl;
		}

		/*** critical section end  ***/
		mtx.unlock();//if mtx locked: this thread unlocks it! if mtx unlocked: this thread waits until it is locked
	}
}

void change_resource()
{
	for (int i = 0; i < 10; i++)
	{
		mtx.lock();//if mtx unlocked: this thread locks it! if mtx locked: this thread waits until unlocked

		/*** critical section start  ***/
		shared_resource++;
		cout << "going to sleep at change_reource for 1 second" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));

		/*** critical section end  ***/
		mtx.unlock();
	}
}


int main()
{
	std::thread t1(test_resource);
	std::thread t2(change_resource);

	t1.join();
	t2.join();
	system("pause");
	return 0;
}