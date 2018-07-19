#ifndef _BITSET_H__
#define _BITSET_H__
#include<vector>
#include<iostream>
class BitSte
{
public:
	BitSte(int bitcount = 12) 
	:_bitcount(bitcount)
	{
		size_t count = (bitcount >> 5) + 1;
		array.resize(count);
	}
	bool Set(size_t which)
	{
		if (which < _bitcount)
		{
			size_t index = which >> 5;
			size_t bit = which % 32;
			array[index] |= (1 << bit);
			return true;
		}
		std::cout << "which is invalid_argument " << std::endl;
		return false;
	}
	bool ReSet(size_t which)
	{
		if (which < _bitcount)
		{
			size_t index = which >> 5;
			size_t bit = which % 32;
			array[index] &=(~(1 << bit));
			return true;
		}
		std::cout << "which is invalid_argument " << std::endl;
		return false;
	}
	bool Test(size_t which)
	{
		if (which < _bitcount)
		{
			size_t index = which >> 5;
			size_t bit = which % 32;
			return array[index] & (1 << bit);
		}
		std::cout << "which is invalid_argument " << std::endl;
		return false;
	}
	size_t Size()
	{
		return _bitcount;
	}
	size_t Count()
	{
		const char*list = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";
		size_t size = array.size();
		size_t i = 0;
		size_t count = 0;
		for (; i < size; ++i)
		{
			int value = array[i];
			while (value)
			{
				count += list[value & 0xf];
				value >>= 4;
			}
		}
		return count;
	}
private:
	std::vector<int> array;
	size_t _bitcount;
};
#endif