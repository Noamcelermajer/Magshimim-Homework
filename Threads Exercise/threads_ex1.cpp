#include <thread>
#include <iostream>
#include <chrono>

int shared_resource = 10;

void test_resource()
{
	for(int i=0;i<10;i++)
	{
		int res = shared_resource;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		if(res != shared_resource)
		{
			std::cout << "ALARM" << std::endl;
		}
		
	}	
}

void change_resource()
{
	for(int i=0;i<10;i++)
	{
		shared_resource++;
		std::this_thread::sleep_for(std::chrono::seconds(1));
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