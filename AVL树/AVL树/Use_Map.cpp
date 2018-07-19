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
	m1.insert(make_pair("昹圖", 1));
	m1.insert(make_pair("陲圖", 1));
	m1.insert(make_pair("鰍圖", 1));
	m1.insert(make_pair("躂圖", 1));
	m1.insert(make_pair("眅圖", 1));
	m1.insert(make_pair("慇躇圖", 1));
	m1.insert(make_pair("昹圖", 1));
	m1.insert(make_pair("陲圖", 1));
	m1.insert(make_pair("鰍圖", 1));
	m1.insert(make_pair("躂圖", 1));
	m1.insert(make_pair("眅圖", 1));
	m1.insert(make_pair("慇躇圖", 1));
}
