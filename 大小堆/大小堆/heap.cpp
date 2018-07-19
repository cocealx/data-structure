#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
int main()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int,Greater<int>>hp1(a, sizeof(a) / sizeof(int),Greater<int>());
	hp1.Push(20);
	hp1.Pop();
	Heap<int, Less<int>>hp2(a, sizeof(a) / sizeof(int), Less<int>());
	return 0;
}
