#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _HASH_H__
#define _HASH_H__ 
#include<iostream>
using namespace std;
template<class first ,class second>
pair<first,second>& Make_pair(first left, second right)
{
	return pair<first, second>(left, right);
}
enum State
{
	empty,
	exist,
	dlte
};
template<class T>
struct Hash
{
	Hash() :/*_key(0),*/ _data(T()), state(empty)
	{

	}
	//int _key;
	T _data;
	enum State state;
};
template<class T, class TtoK ,unsigned long Max>
class HashTable
{
public:
	HashTable()
	{
		capacity = Getcapacity(Max);
		array = new Hash<T>[capacity];
		size = 0;
	}
	bool Insert(const T &data)
	{
		if (size*10/capacity>7)
			Check();
		int key = TtoK()(data);
		const pair<bool, int>&ret = address(key);
		if (ret.first)
		{
			array[ret.second]._data = data;
		/*	array[ret.second]._key = key;*/
			return true;
		}
		return false;

	}
private:
	void Check()
	{

		int size = capacity;
		capacity = Getcapacity(capacity);
		Hash<T>*pdelete = array;
		array = new Hash<T>[capacity];
		int i = 0;
		for (i = 0; i < size; ++i)
		{
			if (pdelete[i].state == exist)
			{
				ret = address(array[i].key, array[i]._data);
				array[ret.second]._data = data;
			}
		}
	}
	pair<bool,int>& address(int key,const T& data)
	{
		int index = key%capacity;
		if (array[index].state = empty)
			return Make_pair(true,index);
		else
		{
			int i = index;
			while (array[i].state!=empty)
			{
				if (array[i].state == exist&&data == array[i]._data)
					return Make_pair(false, i);
				i = (i + 1) % capacity;
			}
			return Make_pair(true, i);
		}
	}
	Hash<T>*array;
	unsigned long  size;
	unsigned long capacity;
};

#endif
