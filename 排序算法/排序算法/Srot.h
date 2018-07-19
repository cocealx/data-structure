#pragma once
#include<iostream>
#include<assert.h>
#include<functional>
using namespace std;
//递归 归并排序
//时间复杂度log2 N
//空间复杂度o(N)
//最好情况和最坏情况时间复杂度都为log2 N
//稳定性 ：稳定
template<class T>
void mez(T*array, int left, int mid ,int right, T*array1)
{
	int l = left;
	int r = mid + 1;
	int i = left;
	while (l <= mid&&r <= right)
	{
		if (array[l] <= array[r])
		{
			array1[i] = array[l++];
		}
		else
		{
			array1[i] = array[r++];
		}
		++i;
	}
	while (l <= mid)
	{
		array1[i++] = array[l++];
	}
	while (r<=right)
	{
		array1[i++] = array[r++];
	}
}
template<class T>
void mer_sort(T*array, int left,int right,T*array1)
{
	T*tempspace = new T[right - left + 1];
	//如果只有一个元素直接归并，不用再分
	if (left == right)
		array1[left] = array[left];
	//如果超过1个元素继续划分
	else
	{
		int mid = (left + right) >> 1;
		//左半部分继续划分
		mer_sort(array, left, mid, tempspace);
		//右半部分继续划分
		mer_sort(array, mid + 1, right, tempspace);	
		//把已经处理好的左右两部分归并在一起
		mez(tempspace, left, mid, right, array1);
	}
}
//非递归 - - 归并排序

template<class T>
void Nmer_sort(T*array, int size, T*array1)
{
	int gap = 1;
	int i = 0;
	while (gap < size)
	{
		for (i = 0; i<size; i += gap * 2)
		{
			int left = i;
			int mid = i + gap-1;
			int right = i + 2 * gap - 1;
			if (mid > size)
				mid = size - 1;
			if (right > size)
				right = size - 1;
			mez(array, left, mid, right, array1);		
		}
		memcpy(array, array1, size*sizeof(T));
		gap *=2;
	}
}
//堆排序
template<class T>
void adjust_down(T*arr, int root, int size)
{
	int right = (root+1) <<1;
	int left = (root <<1) + 1;
	while (left < size)
	{
		
		int max = left;
		if (right < size&&arr[right] > arr[max])
			max = right;
		if (arr[root] < arr[max])
			swap(arr[root], arr[max]);
		else
			break;
		root = max;
		right = root << 2;
		left = (root << 1) + 1;
	}
	    
}
template < class T>
void hea_sort(T*arr,int size)
{
	int i = 0;
	for (i = (size - 1) >> 1; i >= 0; i--)
	{
		adjust_down(arr, i,size);
	}
	for (i = size-1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		adjust_down(arr,0, i);
	}
}
//快速排序
template<class T>
void qsort(T*arr, int left, int right)
{
	int l = left;
	int key = right - 1;
	int r = key;
	if (l <key)
	{
		while (l != r)
		{
			//左边找个比key大的或相等的
			while (l != r&&arr[l] < arr[key])
			{
				++l;
			}
			//右边找个比key小的（两个必须有一个有等号）
			while (l != r&&arr[r] >= arr[key])
			{
				--r;
			}
			swap(arr[l], arr[r]);
		}
		if (l==r)
			swap(arr[l], arr[key]);
		//对左边的进行排序
		qsort(arr, left, l);
		//对右边的进行排序
		qsort(arr, l + 1, right);
	}
}
/////////////非比较类排序///////////////////
//计数排序 
//一般用于数据大量重复，并且比较集中
//时间复杂度log(n)
//空间复杂度log（Max-Min+1)也是log(n)
//稳定性： 稳定
template<class T,class comper>
T find(T*arr, int size,comper com)
{
	T Max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (!com(Max,arr[i]))
			Max = arr[i];
	}
	return Max;
}
template<class T>
void count_sort(T *arr, int size)
{
	greater<T> com1;
	less<T> com2;
	T Max = find(arr,  size,com1 );
	T Min = find(arr,  size, com2 );
	size_t len = Max - Min + 1;
	T*tempspace = new T[len];
	memset(tempspace, 0, sizeof(T)*(Max - Min + 1));
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		//统计每个数出现的次数
		++tempspace[arr[i] - Min];
	}
	int k = 0;
	//还原数据
	for (i = 0; i < (int)len; ++i)
	{
		while (tempspace[i]--)
			arr[k++] = i+ Min;
	}
}
//基数排序
template<class T>
void radix_sort(T*arr, int size)
{
	greater<T> com;
	T Max = find(arr, size, com);
	int agate = 0;
	int gap = 1;
	while (Max)
	{
		++agate;
		Max /= 10;
	}
	T*tempspace = new T[size];
	int state[10] = { 0 };
	int count[10] = { 0 };
	int i = 0;
	while (agate)
	{
		memset(state, 0, 10 * sizeof(int));
		memset(count, 0, 10 * sizeof(int));
		//统计对应位出现的次数
		for ( i = 0; i < size; ++i)
			++count[arr[i] / gap % 10];
		//统计每个数对应的起始地址
		for (i = 1; i < 10; ++i)
		{
			state[i] = count[i-1] + state[i - 1];
		}
		for (i = 0; i < size; ++i)
		{
			tempspace[state[arr[i] / gap % 10]++]=arr[i];
		}
		memcpy(arr, tempspace, size*sizeof(T));
		gap *= 10;
		--agate;
	}
}
