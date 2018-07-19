#define _CRT_SECURE_NO_WARNINGS 1
#include"Srot.h"
//归并排序
void test_Mer_sort()
{
	int arr[10] = { 1, 3, 5, 7, 2, 4, 6, 8, 0, 9 };
	int arr1[10] = { 0 };
	//mer_sort(arr, 0, 9, arr1);
	Nmer_sort(arr, 10, arr1);

}

//计数排序
void test_count_sort()
{
	int arr[] = { 0, 1, 2, 1, 2, 0, 3, 4, 1, 8, 9, 6, 9, 2, 3, 4, 9, 2, 5, 4, 1 };
	count_sort(arr, sizeof(arr) / sizeof(arr[0]));
}
//基数排序
void test_radix_sort()
{
	int arr[] = { 120, 212, 342, 453, 564, 157, 894, 633, 787, 128, 219, 101, 716, 521, 355 };
	radix_sort(arr, sizeof(arr) / sizeof(arr[0]));
}
//堆排序
void test_heap_sort()
{
	int arr[10] = { 1, 5, 2, 7, 8, 9, 0, 3, 4, 6 };
	hea_sort(arr, 10);
}
//快速排序
void test_qsort()
{
	int arr[10] = { 1, 6, 3, 6, 8, 5, 9, 5, 7, 5 };
	qsort(arr, 0, 10);
}
int main()
{
	//test_Mer_sort();
	//test_count_sort();
	//test_radix_sort();
	test_heap_sort();
	//test_qsort();
	return 0;
}
