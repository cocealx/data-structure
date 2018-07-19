#pragma once
#include<vector>
using namespace std;
//²¢²é¼¯
template <class T>
class UFS
{
public:
	UFS(size_t size) 
	{
		set.resize(size, -1);
	}
	int Find(const T&x)
	{
		if (set[x] < 0)
		{
			return x;
		}
		else
		{
			int index = x;
			while (set[index]>=0)
			{
				index = set[index];
			}
			return index;
		}
	}
	bool Union(const T&x1, const T&x2)
	{
		int root1 = Find(x1);
		int root2 = Find(x2);
		if (root1 != root2)
		{
			set[root1] += set[root2];
			set[root2] = root1;
			return true;
		}
		return false;
	}
	size_t elementcount()
	{
		size_t count = 0;
		vector<T>::iterator t1 = set.begin();
		for (; t1 != set.end(); ++t1)
		{
			if (*t1 < 0)
				++count;
		}
		return count;
	}
private:
	std::vector<T> set;
};