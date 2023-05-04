#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Item
{
public:
	Item(string, string, double);
	~Item();

	double totalPrice() const; //returns _count*_unitPrice
	bool operator <(const Item& other) const; //compares the _serialNumber of those items.
	bool operator >(const Item& other) const; //compares the _serialNumber of those items.
	bool operator ==(const Item& other) const; //compares the _serialNumber of those items.
	string get_name()const;
	string get_serialNumber()const;
	int get_count()const;
	double get_unitPrice()const;

	void set_name(string name);
	void set_serialNumber(string serialNumber);
	void set_count(int count);
	void set_unitPrice(double unitPrice);

	void increase_count();
	void decrease_count();
private:
	string _name;
	string _serialNumber; //consists of 5 numbers
	int _count; //default is 1, can never be less than 1!
	double _unitPrice; //always bigger than 0!
};