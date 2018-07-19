#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"GraphList.h"
#include"Graph.h"
void testgraphlist()
{
	const char *ele= "abcde";
	graphlist<char, int,false>gh1(ele,strlen(ele));
	gh1.add('a', 'b', 20);
	gh1.add('a', 'c', 30);
	gh1.add('a', 'e', 40);
	gh1.add('b', 'c', 50);
	gh1.add('e', 'd', 60);
	gh1.add('b', 'd', 70);
	cout << gh1.degree('a') << endl;
}
void testgraph()
{
	const char *ele = "abcde";
	graph<char, int, true>gh1(ele, strlen(ele));
	gh1.add('a', 'b', 20);
	gh1.add('a', 'c', 30);
	gh1.add('a', 'e', 40);
	gh1.add('b', 'c', 50);
	gh1.add('e', 'd', 60);
	gh1.add('b', 'd', 70);
	cout << gh1.degree('a') << endl;
}
int main()
{
	testgraphlist();
	testgraph();
	return 0;
}

