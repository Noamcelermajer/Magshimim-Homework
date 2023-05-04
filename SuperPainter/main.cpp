#include "Menu.h"

int main()
{
	int  optionChoose = 0, flag = 1;
	Menu* myMenu = new Menu();
	while (flag)
	{

		system("CLS");
		std::cout << "Enter 0 to add a new shape.\nEnter 1 to modify or get information from a current shape.\nEnter 2 to delete all of the shapes.\nEnter 3 to exit." << std::endl;
		std::cin >> optionChoose;
		switch (optionChoose)
		{
			case 0:
				myMenu->procedureNewShape();
				break;
			case 1:
				myMenu->procedureModGet();
				break;

		}

	}system("pause");
}