#ifndef _Heap_H__
#define _Heap_H__
#include<iostream>
#include<vector>
#include<assert.h>
using namespace  std;
template<class T>
struct Greater
{
	bool operator()(const T&left, const T&right)
	{
		return left > right;
	}
};
template<class T>
struct Less
{
	bool operator()(const T&left, const T&right)
	{
		return left < right;
	}
};
template <class T, class Comper = Less<T> >
class Heap
{
public:
	Heap(int *arr, int size, const Comper&comper = Less<T>()) :_comper(comper)
	{
		for (int i = 0; i < size; ++i)
		{
			_array.push_back(arr[i]);
		}
		for (int index = (size - 1) >> 1; index >= 0; --index)
		{
			adjustdown(index);
		}
	}
	void Push(const T&data)
	{
		_array.push_back(data);
		adjustup((_array.size() - 2) >> 1);
	}
	void Pop()
	{
		assert(_array.size());
		swap(_array[0], _array[_array.size() - 1]);
		_array.pop_back();
		adjustdown(0);
	}
	T&Top()
	{
		assert(_array.size());
		return _array[0];
	}
private:
	void adjustdown(int root)
	{
		size_t leftchild = (root << 1) + 1;
		size_t rightchild = (root + 1) << 1;
		size_t index;
		size_t _size = _array.size();
		while (leftchild<_size)
		{
			if (rightchild <_size&&_comper(_array[rightchild], _array[leftchild]))
			{
				index = rightchild;
			}
			else
			{
				index = leftchild;
			}
			if (_comper(_array[index], _array[root]))
			{
				swap(_array[root], _array[index]);
			}
			else
			{
				break;
			}
			root = index;
			leftchild = (root << 1) + 1;
			rightchild = (root + 1) << 1;
		}
	}
	void adjustup(int root)
	{
		int leftchild = (root << 1) + 1;
		int rightchild = (root + 1) << 1;
		int _size = _array.size();
		int index = 0;
		while (leftchild>0)
		{
			if (rightchild<_size&&_comper(_array[rightchild], _array[leftchild]))
			{
				index = rightchild;
			}
			else
			{
				index = leftchild;
			}

			if (_comper(_array[index], _array[root]))
			{
				swap(_array[root], _array[index]);
			}
			else
			{
				break;
			}
			root = (root - 1) >> 1;
			leftchild = (root << 1) + 1;
			rightchild = (root + 1) << 1;
		}
	}
	vector<T>_array;
	Comper _comper;
};
#endif