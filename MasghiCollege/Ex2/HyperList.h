#pragma once
#include <algorithm>
#include <iostream>
#include <list>

template<typename T> class HyperList
{
	
	std::list<T> _list;
public:
	bool add(const T& item);
	bool contains(const T& item) const;
};

template<typename T>
bool HyperList<T>::add(const T& item)
{
	size_t o = _list.size();
	_list.push_back(item);
	return (o != _list.size());
}
template<typename T>
bool HyperList<T>::contains(const T& item) const
{
	bool found = (std::find(_list.begin(), _list.end(), item) != _list.end());
	return found;
}