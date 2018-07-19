#pragma once 
#include<vector>
#include<assert.h>
using namespace std;
template<class V,class W,bool Isdirection=true>
class graph
{
public:
	graph(const V*&_array, size_t size) :elenet(_array, _array + size)
	{
		array.resize(size);
		for (size_t i = 0; i < size; ++i)
		{
			array[i].resize(size);
		}
	}
	void add(const V&v1, const V&v2, const W&weight)
	{
		size_t index1 = GetIndex(v1);
		size_t index2 = GetIndex(v2);
		array[index1][index2] = weight;
		if (Isdirection)
			array[index2][index1] = weight;
	}
	size_t degree(const V&v)
	{
		size_t index1 = GetIndex(v);
		size_t size = elenet.size();
		size_t count = 0;
		for (size_t i = 0; i < size; ++i)
		{
			if (array[index1][i]>0)
				++count;
		}
		if (Isdirection)
		{
			for (size_t i = 0; i < size; ++i)
			{
				if (array[i][index1]>0)
					++count;
			}
		}
		return count;
	}
private:
	size_t GetIndex(const V&v)
	{
		size_t size = elenet.size();
		for (size_t i = 0; i < size; ++i)
		{
			if (elenet[i] == v)
				return i;
		}
		cout << "v isn't error" << endl;
		assert(0);
		return 0;
	}
	vector<V>elenet;
	vector<vector<W>>array;
};