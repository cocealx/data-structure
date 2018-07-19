#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//元素出栈合法性检查。
#include<iostream>
#include<stack>
using namespace std;
bool IsCheckLegl(const char*PushStr, const char * PopStr)
{
	stack<char> s1;
	while (*PushStr)
	{
		if (*PushStr == *PopStr)
		{
			++PopStr;
		}
		else
		{
			s1.push(*PushStr);	
		}
		++PushStr;
	}
	while (*PopStr)
	{
		if (*PopStr++ == s1.top())
		{
			s1.pop();
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	char *PushStr = "12345";
	char*PopStr = "45213";
	cout << IsCheckLegl(PushStr, PopStr);
	return 0;
}
#endif

#if 0
//对角矩阵的压缩存储
#include<iostream>
#include<vector>
using namespace std;
template <class T>
class Matrix
{
public:
	Matrix(T* array, int Max) :_col(Max)
	{
		int count = 0;
		////了解resize和resever的去别
		_array.reserve(_col*(_col + 1) >> 1);
		//_array.resize(Max*(Max + 1) >> 1);
		for (size_t i = 0; i < _col; ++i)
		{
			for (size_t j = 0; j <= i; ++j)
			{
				_array.push_back(array[i*_col + j]);
			}
		}	
	}
	T&Get(int col, int row)
	{
		if (row>col)
		{
			row = row^col;
			col = row^col;
			row = row^col;
		}
		return _array[(col*(col + 1) >> 1) + row];
	}
	void display()
	{
		for (size_t i = 0; i < _col; ++i)
		{
			for (size_t j = 0; j < _col; ++j)
			{
				cout << Get(i,j) << " ";
			}
			cout << endl;
		}
	}
	

private:
	size_t _col;
	vector<T> _array;
};
int main()
{
	int a[5][5] = {
		{ 0, 1, 2, 3, 4 },
		{ 1, 0, 1, 2, 3 },
		{ 2, 1, 0, 1, 2 },
		{ 3, 2, 1, 0, 1 },
		{ 4, 3, 2, 1, 0 } };
	Matrix<int> arr((int*)a, 5);
	cout << arr.Get(3, 4) << endl;
	cout << arr.Get(2, 2) << endl;
	cout << arr.Get(3, 2) << endl;
	arr.display();
	return 0;
}
#endif

#if 1
//稀疏矩阵的存储
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
template<class T>
struct Trituple
{
	Trituple()
	:_row(0),
	_col(0),
	_data(0)
	{}
	Trituple(size_t row, size_t col, const T & data)
	:_row(row),
	_col(col),
	_data(data)
	{

	}
	size_t _row;
	size_t _col;
	T _data;
};
template<class T>
class SparseMatrix
{
public:
	SparseMatrix()
		:_row(0),
		_col(0),
		_invalid(0)
	{}
	SparseMatrix(T *arr, size_t row, size_t col, const T&invalid)
		:_row(row),
		_col(col),
		_invalid(invalid)
	{
		for (size_t i = 0; i < _row; ++i)
		{
			for (size_t j = 0; j < _col; ++j)
			{
				if (arr[i*_col + j] != _invalid)
				{
					_array.push_back(Trituple<T>(i, j, arr[i*_col + j]));
				}
			}
		}
	}
	T&Get(size_t row, size_t col)
	{
		size_t count = _array.size();
		for (size_t i = 0; i < count; ++i)
		{
			if (_array[i]._row == row&&_array[i]._col == col)
				return _array[i]._data;
		}
		return _invalid;
	}
	friend ostream& operator<<(ostream& _cout, const SparseMatrix<T>& _arr)
	{
		size_t index = 0;
		size_t count = _arr._array.size();
		for (size_t i = 0; i < _arr._row; ++i)
		{
			for (size_t j = 0; j < _arr._col; ++j)
			{
				if (index<count&&_arr._array[index]._row == i&&_arr._array[index]._col == j)
					_cout << _arr._array[index++]._data << " ";
				else
					_cout << _arr._invalid << " ";
			}
			_cout << endl;
		}
		return _cout;
	}
	SparseMatrix Transpose()
	{
		SparseMatrix<T>s2;
		s2._invalid = _invalid;
		s2._row = _col;
		s2._col = _row;
		//size_t index = 0;
		//如果容量小于参数的大小，会扩容，然后进行初始化，也就是改变了,vector的_size的大小
		//s2._array.resize(_array.size());
		//如果容量小于参数的大小，会扩容，不会对新开辟的空间进行初始化，_size的大小不变，
		//改变的是_capacity的大小
		s2._array.reserve(_array.size());
		vector<Trituple<T>>::iterator it;
		for (size_t i = 0; i < _col; ++i)
		{
			for (it = _array.begin(); it != _array.end(); ++it)
			{
				if (i == (*it)._col)
				{
					s2._array.push_back(Trituple<T>((*it)._col, (*it)._row, (*it)._data));
				}
			}
		}
		return s2;
	}
	SparseMatrix NonTranspose()
	{
		SparseMatrix<T>s2;
		s2._invalid = _invalid;
		s2._row = _col;
		s2._col = _row;
		s2._array.resize(_array.size());
		//每列的个数
		size_t *count = new size_t[_col];
		memset(count, 0, _col*sizeof(size_t));
		vector<Trituple<T>>::iterator it = _array.begin();
		//统计每列有多少个有效元素
		for (; it != _array.end(); ++it)
		{
			++count[(*it)._col];
		}
		Trituple<T>**_Pstart = new Trituple<T>*[_col];
		_Pstart[0] = &s2._array[0];
		for (size_t i = 1; i < _col; ++i)
		{
			_Pstart[i] = _Pstart[i - 1] + count[i - 1];
		}
		for (it = _array.begin(); it != _array.end(); ++it)
		{
			(*_Pstart[(*it)._col])._row = (*it)._col;
			(*_Pstart[(*it)._col])._col = (*it)._row;
			(*_Pstart[(*it)._col])._data =(*it)._data;
			++_Pstart[(*it)._col];
		}
		return s2;
	}
	SparseMatrix Matrix_addition(const SparseMatrix<T>&matr1)
	{
		assert(_col == matr1._col&&_row == matr1._row);
		SparseMatrix<T>s2;
		s2._invalid = _invalid;
		s2._row = _row;
		s2._col = _col;
		vector<Trituple<T>>::iterator it1 = _array.begin();
		vector<Trituple<T>>::const_iterator it2 = matr1._array.begin();
		while( it1 != _array.end() && it2 != matr1._array.end())
		{
			if ((*it1)._row == (*it2)._row&&(*it1)._col == (*it2)._col)
			{
			    T data = (*it1)._data + (*it2)._data;
				if (data!=_invalid )
					s2._array.push_back(Trituple<T>((*it1)._row, (*it1)._col, data));
				++it1;
				++it2;
			}
			else if ((*it1)._row < (*it2)._row)
			{
				
				s2._array.push_back(Trituple<T>((*it1)._row, (*it1)._col, (*it1)._data));
				++it1;
			}
			else if ((*it1)._row == (*it2)._row)
			{
				if ((*it1)._col < (*it2)._col)
				{
					s2._array.push_back(Trituple<T>((*it1)._row, (*it1)._col, (*it1)._data));
					++it1;
				}
				else
				{
					s2._array.push_back(Trituple<T>((*it2)._row, (*it2)._col, (*it2)._data));
					++it2;
				}
			}
			else
			{
				s2._array.push_back(Trituple<T>((*it2)._row, (*it2)._col, (*it2)._data));
				++it2;
			}
		}
		if (it1 != _array.end())
		{
			s2._array.push_back(Trituple<T>((*it1)._row, (*it1)._col, (*it1)._data));
			++it1;
			return s2;
		}
		if (it2 != matr1._array.end())
		{
			s2._array.push_back(Trituple<T>((*it2)._row, (*it2)._col, (*it2)._data));
			++it2;
			return s2;
		}
		return s2;
	}
private:
	vector<Trituple<T>> _array;
	T _invalid;
	size_t _row;
	size_t _col;
};
int main()
{
	int array[6][5] = {
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 7, 0, 0, 0, 0 } };
	int array1[6][5] = {
		{ -1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 2, 0, 0, 0 },
		{ 1, 0, -3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 9, 0, 0 } };
	SparseMatrix<int>_array((int*)array, 6, 5, 0);
	cout << _array.Get(0, 4) << endl;
	cout << _array << endl;
	SparseMatrix<int>s2=_array.Transpose();
	cout << s2 << endl;
	SparseMatrix<int>s3 = _array.NonTranspose();
	cout << s3 << endl;
	SparseMatrix<int>s4 = _array.Matrix_addition(SparseMatrix<int>((int*)array1, 6, 5, 0));
	cout << s4 << endl;
	return 0;
}
#endif

#if 0
//实现一个栈，要求push pop  返回最小值的操作都为0(1)
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T,int Max=10>
class  Stack
{
public:
	Stack()
	{}
	void Push(const T& _data)
	{
		if (mindata.empty()||mindata.top()>_data)
		{
			mindata.push(_data);
		}
		data.push(_data);
	}
	void Pop()
	{
		assert(!data.empty());
		if (mindata.top() == data.top())
		    mindata.pop();
		data.pop();
	}
	T&GetMindata()
	{
		assert(!mindata.empty());
		return mindata.top();
	}
	T&Top()
	{
		return data.top();
	}
	bool Empty()
	{
		return data.empty();
	}
	size_t size()
	{
		return data.size();
	}
private:
	stack<T> data;
	stack<T>mindata;
};
int main()
{
	Stack<int>s1;
	s1.Push(10);
	cout << " 最小值"<<s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Push(1);
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Push(9);
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Push(2);
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Push(0);
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Push(3);
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Push(5);
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Push(6);
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Pop();
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Pop();
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Pop();
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Pop();
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Pop();
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Pop();
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	s1.Pop();
	cout << " 最小值" << s1.GetMindata() << endl;
	cout << "栈顶元素为:" << s1.Top() << endl;
	return 0;
}
#endif
#if 0
//两个栈实现一个队列
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
class Quene
{
public:
	Quene()
	{}
	void Puhs_back(const T&data)
	{
		while (!qu.empty())
		{
			st.push(qu.top());
			qu.pop();
		}
		st.push(data);
	}
	void Pop_front()
	{
			while (!st.empty())
			{
				qu.push(st.top());
				st.pop();
			}
		assert(!qu.empty());
		qu.pop();
	}
    T& Front()
	{
		while (!st.empty())
		{
			qu.push(st.top());
			st.pop();
		}
		return qu.top();
	}
	T&Back()
	{
		while (!qu.empty())
		{
			st.push(qu.top());
			qu.pop();
		}
		return st.top();
	}
	bool Empty()
	{
		return qu.empty() && st.empty();
	}
	size_t Size()
	{
		return qu.size() + st.size();
	}
private:
	stack<T>st;
	stack<T>qu;
};
int main()
{
	Quene<int> qu1;
	qu1.Puhs_back(0);
	cout <<"队头"<< qu1.Front() << endl;
	cout << "队尾" << qu1.Back() << endl;
	qu1.Puhs_back(1);
	cout << "队头" << qu1.Front() << endl;
	cout << "队尾" << qu1.Back() << endl;
	qu1.Puhs_back(2);
	cout << "队头" << qu1.Front() << endl;
	cout << "队尾" << qu1.Back() << endl;
	qu1.Puhs_back(3);
	cout << "队头" << qu1.Front() << endl;
	cout << "队尾" << qu1.Back() << endl;
	cout << "大小" << qu1.Size() << endl;
	cout << "是否为空" << qu1.Empty() << endl;
	qu1.Pop_front();
	cout << "队头" << qu1.Front() << endl;
	cout << "队尾" << qu1.Back() << endl;
	qu1.Pop_front();
	cout << "队头" << qu1.Front() << endl;
	cout << "队尾" << qu1.Back() << endl;
	qu1.Pop_front();
	cout << "队头" << qu1.Front() << endl;
	cout << "队尾" << qu1.Back() << endl;
	cout << "大小" << qu1.Size() << endl;
	qu1.Pop_front();
	cout << "大小" << qu1.Size() << endl;
	cout << "是否为空" << qu1.Empty() << endl;

	//cout << "队头" << qu1.Front() << endl;
	//cout << "队尾" << qu1.Back() << endl;
	return 0;
}
#endif
//两个队列实现一个栈
#if 0
#include<iostream>
#include<queue>
#include<assert.h>
using  namespace std;
template<class T>
class Stack
{
public:
	Stack()
	{}
	void Push(const T data)
	{
		if (!qu1.empty())
		{
			qu1.push(data);
		}
		else
		{
			qu2.push(data);
		}
	}
	void Pop()
	{
		assert(!qu1.empty() || !qu2.empty());
		if (!qu1.empty())
		{
			while (qu1.size()>1)
			{
				qu2.push(qu1.front());
				qu1.pop();
			}
			qu1.pop();
		}
		else
		{
			while (qu2.size()>1)
			{
				qu1.push(qu2.front());
				qu2.pop();
			}
			qu2.pop();
		}
	}
	T&Top()
	{
		assert(!qu1.empty() || !qu2.empty());
		if (!qu1.empty())
		{
			return qu1.back();
		}
		else
		{
			return qu2.back();
		}
	}
	size_t Size()
	{
		if (!qu1.empty())
		{
			return qu1.size();
		}
		else
		{
			return qu2.size();
		}
	}
	bool Empty()
	{
		return qu1.empty() && qu2.empty();
	}
private:
	queue<T> qu1;
	queue<T>qu2;
};
int main()
{
	Stack<int>s1;
	s1.Push(1);
	cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	s1.Push(2);
	cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	s1.Push(3);
	cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	s1.Push(4);
	cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	cout << "栈是否为空" << s1.Empty() << endl;
	s1.Pop();
	cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	s1.Pop();
	cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	s1.Pop();
	cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	s1.Pop();
	//cout << "栈顶元素为：" << s1.Top() << endl;
	cout << "栈大小为：" << s1.Size() << endl;
	cout << "栈是否为空" << s1.Empty() << endl;
	return 0;
}
#endif



//一个数组实现两个栈
#if 0
#include<iostream>
#include<assert.h>
using namespace std;

template<class T,int Max>
class ShareStack
{
public:
	ShareStack():size1(0), size2(Max - 1)
	{}
	void Push(const T&data, int select = 1)
	{
		if (select == 1)
		{
			if (size1 == size2)
			{
				cout << "栈满" << endl;
				return;
			}
			_array[size1++] = data;
		}
		else
		{
			if (size1 == size2)
			{
				cout << "栈满" << endl;
				return;
			}
			_array[size2--] = data;
		}
	}
	void Pop(int select = 1)
	{
		if (select == 1)
		{
			if (size1 == 0)
			{
				assert(0);
				cout << "空栈" << endl;
				
			}
			size1--;
		}
		else
		{
			if (Max-1 == size2)
			{
				assert(0);
				cout << "空栈" << endl;
				
			}
			size2++;
		}
	}
	T& Top(int select = 1)
	{
		if (select == 1)
		{
			if (size1 == 0)
			{
				assert(0);
				cout << "空栈" << endl;
				
			}
			return _array[size1 - 1];
		}
		else
		{
			if (size2 == Max-1)
			{
				assert(0);
				cout << "空栈" << endl;
				
			}
			return _array[size2 + 1];
		}
	}
	size_t Size(int select = 1)
	{
		if (select == 1)
			return size1;
		else
			return Max-size2-1;
	}
	bool Empty(int secelt = 1)
	{
		if (secelt == 1)
			return size1 == 0;
		else
			return size2 == Max-1;
	}

private:
	template<class T>
	struct Stack
	{

		size_t size;
	};
	T _array[Max];
	//Stack<T>
	size_t size1;
	size_t size2;
};
int main()
{
	ShareStack<int,10>sh1;
	sh1.Push(1);
	cout << "栈顶元素："<<sh1.Top() << endl;
	cout << "栈的大小：" << sh1.Size() << endl;
	sh1.Push(2);
	cout << "栈顶元素：" << sh1.Top() << endl;
	cout << "栈的大小：" << sh1.Size() << endl;
	sh1.Push(3);
	cout << "栈顶元素：" << sh1.Top() << endl;
	cout << "栈的大小：" << sh1.Size() << endl;
	cout << "栈是否为空:" << sh1.Empty() << endl;
	sh1.Pop();
	cout << "栈顶元素：" << sh1.Top() << endl;
	cout << "栈的大小：" << sh1.Size() << endl;
	sh1.Pop();
	cout << "栈顶元素：" << sh1.Top() << endl;
	cout << "栈的大小：" << sh1.Size() << endl;
	sh1.Pop();
	cout << "栈的大小：" << sh1.Size() << endl;
	cout << "栈是否为空:" << sh1.Empty() << endl;
	sh1.Push(1,2);
	cout << "栈顶元素：" << sh1.Top(2) << endl;
	cout << "栈的大小：" << sh1.Size(2) << endl;
	sh1.Push(2, 2);
	cout << "栈顶元素：" << sh1.Top(2) << endl;
	cout << "栈的大小：" << sh1.Size(2) << endl;
	sh1.Push(3,2);
	cout << "栈顶元素：" << sh1.Top(2) << endl;
	cout << "栈的大小：" << sh1.Size(2) << endl;
	cout << "栈是否为空:" << sh1.Empty(2) << endl;
	sh1.Pop(2);
	cout << "栈顶元素：" << sh1.Top(2) << endl;
	cout << "栈的大小：" << sh1.Size(2) << endl;
	sh1.Pop(2);
	cout << "栈顶元素：" << sh1.Top(2) << endl;
	cout << "栈的大小：" << sh1.Size(2) << endl;
	sh1.Pop(2);
	cout << "栈的大小：" << sh1.Size(2) << endl;
	cout << "栈是否为空:" << sh1.Empty(2) << endl;
	
	sh1.Push(1);
	sh1.Push(1);
	sh1.Push(1);
	sh1.Push(1);
	sh1.Push(1);
	sh1.Push(2, 2);
	sh1.Push(2, 2);
	sh1.Push(2, 2);
	sh1.Push(2, 2);
	sh1.Push(2, 2);
	sh1.Push(2, 2);
	return 0;
}
#endif