#pragma once
#include"Item.h"
#include<set>

class Customer
{
public:
	Customer(string);
	Customer();
	double totalSum() const;//returns the total sum for payment
	void addItem(Item);//add item to the set
	void removeItem(Item);//remove item from the set

	string get_name();
	set<Item> get_items();

	void set_name(string name);
	void set_items(set<Item> items);
private:
	string _name;
	set<Item> _items;


};
