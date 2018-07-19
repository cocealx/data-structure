#define _CRT_SECURE_NO_WARNINGS 1
#include"UFS.h"

#include<iostream>
void testUFS()
{
	UFS<int> s1(6);
	s1.Union(1, 2);
	s1.Union(2,3);
	s1.Union(4,5);
	cout << s1.elementcount()-1 << endl;
}
int main()
{

	testUFS();
	return 0;
}