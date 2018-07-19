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
	b1.insert("��ʱ����\n");
	b1.insert("����õ���\n");
	b1.insert("���ڵ���\n");
	b1.insert("����õ���\n");
	b1.insert("��õ�������������һ���ഺ\n");
	if (b1.Isexist("��õ�����\n"))
		printf("�����ǵ�\n");
	else
		printf("������\n");

	if (b1.Isexist("��õ�������������һ���ഺ\n"))
		printf("�����ǵ�\n");
	else
		printf("������\n");
}
int main()
{
	//test();
	bloomfiltertest();
	return 0;
}
