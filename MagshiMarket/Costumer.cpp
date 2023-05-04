#include "Customer.h"
#include <iostream>
Customer::Customer(string name)
{
	
	_name = name;
}
Customer::Customer()
{
	_name = "";
}
double Customer::totalSum() const
{
	double totalSum = 0;
	for (auto setIt = _items.begin(); setIt != _items.end(); ++setIt)
	{
		totalSum += setIt->totalPrice();
	}
	return totalSum;
}
void Customer::addItem(Item other)
{
	set<Item>::iterator tmp = _items.find(other);
	if(tmp == _items.end())
		_items.insert(other);
	else
	{
		_items.erase(_items.find(other));
		_items.insert(other);
	}

}
void Customer::removeItem(Item toDelete)
{
	_items.erase(_items.find(toDelete));
	if (toDelete.get_count() > 1)
		_items.insert(toDelete);

}

string Customer::get_name()
{
	return _name;
}
set<Item> Customer::get_items()
{
	return _items;
}

void Customer::set_name(string name)
{
	_name = name;
}
void Customer::set_items(set<Item> items)
{
	_items = items;
}