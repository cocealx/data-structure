#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<class T,int NUMBER = 20>
class Stack
{
public:
	Stack() :_capacity(NUMBER), _size(0)
	{
		memset(_arr, 0, NUMBER*sizeof(T));
	}
	Stack(T arr[],int size)
	{
		for (_size= 0;_size < size; _size++)
		{
			_arr[_szie] = arr[_size];
		}
	}
	bool Pushback(const T&data)
	{
		if (_size < _capacity)
		{
			_arr[_szie++] = data;
			return true;
		}
		return false;
	}
	bool Popback()
	{
		if (_size != 0)
		{
			--_size;
			return true;
		}
		return false;
	}
	bool Empty()
	{
		return _size == 0;
	}
	const T&Top()
	{
		assert(_size != 0);
		return _arr[_size - 1];
	}
private:
	int _size;
	int _capacity;
	T _arr[NUMBER];
};
