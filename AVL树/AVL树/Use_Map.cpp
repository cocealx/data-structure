#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
using namespace std;
template<class K,class V>
//const pair<K, V>&make_pair(K first,V second)
//{
//	return pair<K, V>(first, second);
//}
int main()
{
	map<const char*, int>m1;
	m1.insert(make_pair("����", 1));
	m1.insert(make_pair("����", 1));
	m1.insert(make_pair("�Ϲ�", 1));
	m1.insert(make_pair("ľ��", 1));
	m1.insert(make_pair("���", 1));
	m1.insert(make_pair("���ܹ�", 1));
	m1.insert(make_pair("����", 1));
	m1.insert(make_pair("����", 1));
	m1.insert(make_pair("�Ϲ�", 1));
	m1.insert(make_pair("ľ��", 1));
	m1.insert(make_pair("���", 1));
	m1.insert(make_pair("���ܹ�", 1));
}
