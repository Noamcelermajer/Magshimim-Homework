#include "MessagesSender.h"

std::vector<std::string> onlineUser;
std::mutex vectMutex;

std::mutex queueMutex;
std::queue<std::string> messages;

void MessagerMain()
{
	int menuChoose, flag = 1;
	while (flag)
	{
		std::cout << "1. Signin" << std::endl << "2. Signout" << std::endl << "3. Connected Users" << std::endl << "4. exit" << std::endl << "--> ";
		std::cin >> menuChoose;
		system("cls");
		switch (menuChoose)
		{
		case 1:
			if (signin() == 2)
			{
				std::cout << "Already Exist!!!!" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			system("cls");
			break;
		case 2:
			if (signout() == 2)
			{
				std::cout << "User Does Not Exist!!!!" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			system("cls");
			break;
		case 3:
			connectedUser();\
			break;
		case 4:
			flag = 0;
			break;
		}
	}

	
}
int signin()
{
	std::string username;
	std::cout << "Please Enter Your Username : ";
	std::cin >> username;
	
	vectMutex.lock();
	for (auto it = onlineUser.begin(); it != onlineUser.end(); ++it) 
	{
		if (*it == username)
		{
			return 2;
		}
	}
	onlineUser.push_back(username);
	vectMutex.unlock();
	return 0;
}
int signout()
{
	std::string username;
	std::cout << "Please Enter Your Username : ";
	std::cin >> username;
	vectMutex.lock();
	for (auto it = onlineUser.begin(); it != onlineUser.end(); ++it)
	{
		if (*it == username)
		{
			onlineUser.erase(it);
			return 0;
		}
	}
	vectMutex.unlock();
	return 2;
}
void connectedUser()
{
	vectMutex.lock();
	for (auto it = onlineUser.begin(); it != onlineUser.end(); ++it)
	{ 
		std::cout << "Name :" << *it << std::endl;
	}
	vectMutex.unlock();
}
void getFromFiles()
{
	while (true)
	{
		std::string line;
		std::ifstream myfile("data.txt");
		queueMutex.lock();
		while (getline(myfile, line))
		{
			messages.push(line);
		}
		queueMutex.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(60));
	}
}
void  BroadcastMessage()
{
	std::ofstream myfile("output.txt");
	std::string tmp;
	while (true)
	{
		queueMutex.lock();

		while (messages.size())
		{
			tmp = messages.front();
			messages.pop();
			vectMutex.lock();
			for (auto it = onlineUser.begin(); it != onlineUser.end(); ++it)
			{
				myfile << *it << ":" << tmp << std::endl;
			}
			vectMutex.unlock();
		}
		queueMutex.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(60));
	}
	

}