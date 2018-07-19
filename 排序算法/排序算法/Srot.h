#pragma once
#include<iostream>
#include<assert.h>
#include<functional>
using namespace std;
//�ݹ� �鲢����
//ʱ�临�Ӷ�log2 N
//�ռ临�Ӷ�o(N)
//������������ʱ�临�Ӷȶ�Ϊlog2 N
//�ȶ��� ���ȶ�
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
	//���ֻ��һ��Ԫ��ֱ�ӹ鲢�������ٷ�
	if (left == right)
		array1[left] = array[left];
	//�������1��Ԫ�ؼ�������
	else
	{
		int mid = (left + right) >> 1;
		//��벿�ּ�������
		mer_sort(array, left, mid, tempspace);
		//�Ұ벿�ּ�������
		mer_sort(array, mid + 1, right, tempspace);	
		//���Ѿ�����õ����������ֹ鲢��һ��
		mez(tempspace, left, mid, right, array1);
	}
}
//�ǵݹ� - - �鲢����

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
//������
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
//��������
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
			//����Ҹ���key��Ļ���ȵ�
			while (l != r&&arr[l] < arr[key])
			{
				++l;
			}
			//�ұ��Ҹ���keyС�ģ�����������һ���еȺţ�
			while (l != r&&arr[r] >= arr[key])
			{
				--r;
			}
			swap(arr[l], arr[r]);
		}
		if (l==r)
			swap(arr[l], arr[key]);
		//����ߵĽ�������
		qsort(arr, left, l);
		//���ұߵĽ�������
		qsort(arr, l + 1, right);
	}
}
/////////////�ǱȽ�������///////////////////
//�������� 
//һ���������ݴ����ظ������ұȽϼ���
//ʱ�临�Ӷ�log(n)
//�ռ临�Ӷ�log��Max-Min+1)Ҳ��log(n)
//�ȶ��ԣ� �ȶ�
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
		//ͳ��ÿ�������ֵĴ���
		++tempspace[arr[i] - Min];
	}
	int k = 0;
	//��ԭ����
	for (i = 0; i < (int)len; ++i)
	{
		while (tempspace[i]--)
			arr[k++] = i+ Min;
	}
}
//��������
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
		//ͳ�ƶ�Ӧλ���ֵĴ���
		for ( i = 0; i < size; ++i)
			++count[arr[i] / gap % 10];
		//ͳ��ÿ������Ӧ����ʼ��ַ
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
