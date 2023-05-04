#include"Customer.h"
#include<map>
#define ITEM_LIST_LENGHT 10
void case3(map<string, Customer> &abcCustomers);
void printMenu()
{

	cout << "Welcome to MagshiMarket!\n1.      to sign as customer and buy items\n2.      to uptade existing customer's items\n3.      to print the customer who pays the most\n4.      to exit" << endl;
}
void case1(string customer, map<string, Customer> &abcCustomers, Item itemList[ITEM_LIST_LENGHT]);
void case2(string customer, map<string, Customer> &abcCustomers, Item itemList[ITEM_LIST_LENGHT]);
int main()
{
	int cMenu, cOption;
	string customer;
	map<string, Customer> abcCustomers;
	Item itemList[ITEM_LIST_LENGHT] = {
		Item("Milk","00001",5.3),
		Item("Cookies","00002",12.6),
		Item("bread","00003",8.9),
		Item("chocolate","00004",7.0),
		Item("cheese","00005",15.3),
		Item("rice","00006",6.2),
		Item("fish", "00008", 31.65),
		Item("chicken","00007",25.99),
		Item("cucumber","00009",1.21),
		Item("tomato","00010",2.32) };
	while (true)
	{
		printMenu();
		cin >> cMenu;
		switch (cMenu)
		{
		case 1:
			cout << "Please Enter Your Name: ";
			cin >> customer;
			cout << endl;
			if (abcCustomers.count(customer) == 0)
			{
				abcCustomers[customer] = Customer(customer);
				case1(customer, abcCustomers, itemList);
			}
			else
				cout << "Customer already exist try again later....." << endl;
			break;
		case 2:
			cout << "Please Enter Your Name: ";
			cin >> customer;
			cout << endl;
			if (abcCustomers.count(customer) == 0)
			{
				cout << "User Dont exist Please choose option 1" << endl;
			}
			else
				case2(customer, abcCustomers, itemList);
			break;
		case 3:
			case3(abcCustomers);
			break;
		case 4:
			return 0;
		default:
			cout << "Wrong input you got only 4 option :)" << endl;
			break;

		}

	}

}
void case1(string customer, map<string, Customer> &abcCustomers, Item itemList[ITEM_LIST_LENGHT])
{
	int productC, i = 0;
	int cArr[ITEM_LIST_LENGHT];
	set<Item> tmp = abcCustomers[customer].get_items();
	for (i = 0; i < ITEM_LIST_LENGHT; i++)
	{
		cArr[i] = 1;
	}
	i = 0;
	for (auto setIt = tmp.begin(); setIt != tmp.end(); ++setIt)
	{
		cArr[i] = setIt->get_count();
		i++;
	}
	for (int i = 0; i < ITEM_LIST_LENGHT; i++)
	{
		cout << i + 1 << ".      " << itemList[i].get_name() << "      	 price: " << itemList[i].get_unitPrice() << endl;
	}
	while (1)
	{
		cout << "Choose product: ";
		cin >> productC;
		cout << endl;
		if (productC == 0 )
			break;
		if (productC > ITEM_LIST_LENGHT)
		{
			cout << "out of range" << endl;
		}
		else
		{
			productC--;
			if (cArr[productC] > 1)
			{
				itemList[productC].set_count(cArr[productC]);
				abcCustomers[customer].addItem(itemList[productC]);
				cArr[productC]++;
			}
			else
			{
				abcCustomers[customer].addItem(itemList[productC]);
				itemList[productC].set_count(cArr[productC]);
				cArr[productC]++;
			}
		}
	}
	for (i = 0; i < ITEM_LIST_LENGHT; i++)
	{
		itemList[i].set_count(1);
		cArr[i] = NULL;
	}
}
void case2(string customer, map<string, Customer> &abcCustomers, Item itemList[ITEM_LIST_LENGHT])
{
	set<Item> tmp = abcCustomers[customer].get_items();
	Item* tmpList = itemList;
	int optionC, productC, i = 0;;
	int cArr[ITEM_LIST_LENGHT] = {};
	for (auto setIt = tmp.begin(); setIt != tmp.end(); ++setIt)
	{
		if (setIt->get_count() == 0)
			cArr[i] = 1;
		else
		{
			cArr[i] = setIt->get_count();
		}

		i++;
	}
	do
	{
		cout << "1.      Add items\n2.      Remove items\n3.      Back to menu" << endl;
		cout << "Choose an option: ";
		cin >> optionC;
		cout << endl;
		switch (optionC)
		{
		case 1:
			case1(customer, abcCustomers, itemList);
			break;
		case 2:
			while (1)
			{
				i = 0;
				for (auto setIt = tmp.begin(); setIt != tmp.end(); ++setIt)
				{
					cout << setIt->get_name() << " :" << cArr[i] << endl;
					i++;
				}
				cout << "Choose product: ";
				cin >> productC;
				cout << endl;
				if (productC == 0)
					break;
				if (productC > ITEM_LIST_LENGHT)
				{
					cout << "out of range" << endl;
				}
				else
				{
					productC--;
					if (cArr[productC] > 1)
					{
						itemList[productC].set_count(cArr[productC]);
						cArr[productC]--;
					}
					abcCustomers[customer].removeItem(tmpList[productC]);
				}
			}
		}
	} while (optionC != 3);
	for (i = 0; i < ITEM_LIST_LENGHT; i++)
	{
		itemList[i].set_count(1);
	}

}
void case3(map<string, Customer> &abcCustomers)
{
	double l = 0;
	map<string, Customer>::iterator it;
	for (it = abcCustomers.begin(); it != abcCustomers.end(); it++)
	{
		if (l < it->second.totalSum())
			l = it->second.totalSum();
	}
	for (it = abcCustomers.begin(); it != abcCustomers.end(); it++)
	{
		if (l == it->second.totalSum())
		{
			cout << "The customer who paid the most :" << it->second.get_name() << endl;
		}
	}
}
