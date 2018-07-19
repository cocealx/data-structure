#ifndef _COMM_H__
#define _COMM_H__
#include<string>
const int _PrimeSize = 28;
static const unsigned long _PrimeList[_PrimeSize] = {
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

static unsigned long Getcapacity(unsigned long Max)
{
	int i = 0;
	for (i = 0; i < _PrimeSize; ++i)
	{
		if (_PrimeList[i] >= Max)
			return _PrimeList[i];
	}
	return _PrimeList[i - 1];
}
static size_t BKDRHash(const char * str) {

	unsigned int seed = 131; // 31 131 1313 13 131 1313 13  

	unsigned int hash = 0;

	while(*str)
	{

		hash = hash * seed + (*str++);
	}

	return(hash & 0x7FFFFFFF);
}

template<class T>
class TtoK
{
	int operator()(const T& data)
	{
		return data;
	}
};
template<>
class TtoK<std::string>
{
	int operator()(const std::string& data)
	{
		return BKDRHash(data.c_str());
	} 
};
#endif