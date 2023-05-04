#include "Vector.h"
#include <iostream>
#include <string>
Vector::Vector(int n)
{
	if (n < 2)
	{
		n = 2;
	}
	_elements = new int[n];
	_capacity = n;
	_resizeFactor = n;
}
Vector::~Vector()
{
	delete[] _elements;
}
int Vector::size() const
{
	return _size;

}
int Vector::capacity() const
{
	return _capacity;
}
int Vector::resizeFactor() const
{
	return _resizeFactor;
}
void Vector::push_back(const int &val)
{
	if (_size <= _capacity)
	{
		_elements[_size++] = val;
		_size = +1;
	}
	else
	{
		int * newElements = new int[_capacity + _resizeFactor];
	}
	

}
int Vector::pop_back()
{
	if (_size == NULL)
	{
		std::cerr << "error: pop from empty\n";
		return -9999;
	}
	int tmp = _elements[_size];
	_elements[_size] = 0;
	return tmp;
}
void Vector::reserve(int n)
{
	if (_capacity <= n)
	{
		int *tmpElements = new int[_resizeFactor+n];
		for (int i = 0; i < _capacity; i++)
		{
			tmpElements[i] = _elements[i];
		}
		delete[] _elements;
		_elements = new int[_resizeFactor+n];
		for (int i = 0; i < _capacity; i++)
		{
			_elements[i] = tmpElements[i];
		}
	}


}

void Vector::resize(int n)
{
	if (n <= _capacity)
	{
		int *tmpElements = new int[n];
		for (int i = 0; i < n; i++)
		{
			tmpElements[i] = _elements[i];
		}
		delete[] _elements;
		_elements = new int[n];
		for (int i = 0; i < n; i++)
		{
			_elements[i] = tmpElements[i];
		}
	}
}
void Vector::assign(int val)
{
	for (int i = 0; i < _size; i++)
	{
		_elements[i] = val;
	}
}
void Vector::resize(int n, const int& val)
{
	if (n <= _capacity)
	{

		delete[] _elements;
		_elements = new int[n];
		for (int i = 0; i < _size; i++)
		{
			_elements[i] = val;
		}
	}

}

bool Vector::empty() const
{
	return(_size == NULL);
}

Vector& Vector::operator=(const Vector& other)//the program will crashe if the given vector isnt equal in size to other vector 
{

	_capacity = other.capacity();

	delete[] _elements;
	_elements = new int[_capacity];
	_size = other.size();
	for (int i = 0; i < _size; i++)
	{
		_elements[i] = other._elements[i];
	}
	return *this;
}
Vector::Vector(const Vector& other)
{
	*this = other;
}


int& Vector::operator[](int n) const
{
	if (n > _size)
	{
		return _elements[0];
	}
	return _elements[n];
}