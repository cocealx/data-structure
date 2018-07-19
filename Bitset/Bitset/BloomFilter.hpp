#ifndef _BLOOMFILTER_H__
#define _BLOOMFILTER_H__
#include"bitset.hpp"
template<class K, 
class KEYTOINT1 = BKDRHash1, 
class KEYTOINT2 = BKDRHash2,
class KEYTOINT3 = BKDRHash3,
class KEYTOINT4 = BKDRHash4,
class KEYTOINT5 = BKDRHash5>
class bloomfilter
{
public:
	bloomfilter(size_t max) :set(max*10)
	{

	}
	bool insert(const K &key)
	{
		int max = set.Size();
		int index1 = KEYTOINT1()(key) % max;
		int index2 = KEYTOINT2()(key) % max;
		int index3 = KEYTOINT3()(key) % max;
		int index4 = KEYTOINT4()(key) % max;
		int index5 = KEYTOINT5()(key) % max;
		printf("%d  %d  %d  %d  %d\n", index1, index2, index3, index4, index5);
		set.Set(index1);
		set.Set(index2);
		set.Set(index3);
		set.Set(index4);
		set.Set(index5);
		return true;
	}
	bool Isexist(const K &key)
	{
		int max = set.Size();
		int index1 = KEYTOINT1()(key) % max;
		int index2 = KEYTOINT2()(key) % max;
		int index3 = KEYTOINT3()(key) % max;
		int index4 = KEYTOINT4()(key) % max;
		int index5 = KEYTOINT5()(key) % max;
		printf("%d  %d  %d  %d  %d\n", index1, index2, index3, index4, index5);
		if (!set.Test(index1))
			return false;
		if (!set.Test(index2))
			return false;
		if (!set.Test(index3))
			return false;
		if (!set.Test(index4))
			return false;
		if (!set.Test(index5))
			return false;
		return true;  
	}
private:
	BitSte set;
};
#endif