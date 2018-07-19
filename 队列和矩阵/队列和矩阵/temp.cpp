#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
template<class T,int n>
class Quenue
{
public:
	Quenue() :_count(0), _back(0), _front(0), _array(new T[n]){}
	void Push(const T &data)
	{
		if (_count == n)
		{
			cout << "¶ÓÁÐÂúÁË" << endl;
			return;
		}
		++_count;
		_array[_back] = data;
		_back = (_back + 1) % n;
	}
	void Pop()
	{
		assert(_count);
		--_count;
		_front = (_front+1)%n;
	}
	size_t Size()
	{
		return _count;
	}
	const T&Top()const 
	{
		return _arrary[_front];
	}
	T&Top()
	{
		return _array[_front];
	}
	T&Back()
	{
		return _array[(_back - 1 + n) % n];
	}
	const T&Back()const 
	{
		return _array[(_back - 1 + n) % n];
	}
	bool Empty()
	{
		return _count == 0;
	}
private:
	T* _array;
	size_t _count;
	size_t _back;
	size_t _front;
};
#if 0
int main()
{
	Quenue<int,6>q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	cout << q1.Size() << endl;
	cout << q1.Top() << endl;
	cout << q1.Back() << endl;
	cout << q1.Empty() << endl;
	q1.Push(5);
	q1.Push(6);
	cout << q1.Size() << endl;
	cout << q1.Top() << endl;
	cout << q1.Back() << endl;
	cout << q1.Empty() << endl;
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	cout << q1.Size() << endl;
	cout << q1.Top() << endl;
	cout << q1.Back() << endl;
	cout << q1.Empty() << endl;
	q1.Push(7);
	q1.Push(8);
	q1.Push(9);
	q1.Push(10);
	cout << q1.Size() << endl;
	cout << q1.Top() << endl;
	cout << q1.Back() << endl;
	cout << q1.Empty() << endl;
	q1.Pop();
	q1.Pop();
	q1.Pop();
	cout << q1.Size() << endl;
	cout << q1.Top() << endl;
	cout << q1.Back() << endl;
	cout << q1.Empty() << endl;
	q1.Pop();
	q1.Pop();
	q1.Pop();
	cout << q1.Size() << endl;
	cout << q1.Empty() << endl;
	return 0;
}
#endif