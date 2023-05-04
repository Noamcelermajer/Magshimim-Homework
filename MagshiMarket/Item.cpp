#include "Item.h"
Item::Item(string name, string serialNumber, double unitPrice)
{
	_count = 1;
	_name = name;
	_serialNumber = serialNumber;
	_unitPrice = unitPrice;
}
Item::~Item()
{
	_count = 1;
	_name = "";
	_serialNumber = "";
}
string Item::get_name() const
{
	return _name;
}
string Item::get_serialNumber() const
{
	return _serialNumber;
}
int Item::get_count() const 
{
	return _count;
}
double Item::get_unitPrice()const
{
	return _unitPrice;
}

void Item::set_name(string name)
{
	_name = name;
}
void Item::set_serialNumber(string serialNumber)
{
	_serialNumber = serialNumber;
}
void Item::set_count(int count)
{
	_count = count;
}
void Item::set_unitPrice(double unitPrice)
{
	_unitPrice = unitPrice;
}
double Item::totalPrice() const
{
	return _count * _unitPrice;
}
bool Item::operator <(const Item& other) const
{ 
	if (_serialNumber < other._serialNumber)
		return true;
	return false;
}
bool Item::operator >(const Item& other) const
{
	if (_serialNumber > other._serialNumber)
		return true;
	return false;

}
void Item::increase_count()
{
	_count++;
}
void  Item::decrease_count()
{
	_count--;
}
bool Item::operator ==(const Item& other) const
{
	if (_serialNumber == other._serialNumber)
		return true;
	return false;
}