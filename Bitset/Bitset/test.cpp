#define _CRT_SECURE_NO_WARNINGS 1
#include"bitset.hpp"
#include"KEYTOINT.h"
#include"BloomFilter.hpp"
using namespace std;


void test()
{
	BitSte bit(56);
	cout << "bit number" << bit.Count() << endl;
	if (bit.Test(23))
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
	bit.Set(23);
	bit.Set(0);
	cout << bit.Count() << endl;
	if (bit.Test(23))
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
	bit.ReSet(0);
	cout << bit.Count() << endl;
}
void bloomfiltertest()
{
	bloomfilter<char*> b1(10);
	b1.insert("那时的你\n");
	b1.insert("是最好的你\n");
	b1.insert("现在的我\n");
	b1.insert("是最好的我\n");
	b1.insert("最好的我们整整隔了一个青春\n");
	if (b1.Isexist("最好的我们\n"))
		printf("或许是的\n");
	else
		printf("并不是\n");

	if (b1.Isexist("最好的我们整整隔了一个青春\n"))
		printf("或许是的\n");
	else
		printf("并不是\n");
}
int main()
{
	//test();
	bloomfiltertest();
	return 0;
}
