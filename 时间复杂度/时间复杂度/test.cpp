//#define _crt_secure_no_warnings 1
//#include<iostream>
//using namespace std;
//void sort(int* arr, int size, int n)
//{
//	if (size == n)
//	{
//		for (int i = 0; i < size; ++i)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//	else
//	{
//		for (int j = n; j < size; ++j)
//		{
//			swap(arr[n], arr[j]);
//			sort(arr, size, n+1);
//			swap(arr[n], arr[j]);
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	sort(arr, 5, 3);
//	return 0;
//}
//#include<iostream>
//#include<stack>
//#include<assert.h>
//using namespace std;
//bool isoperator(const char ch)
//{
//	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'||ch =='('||ch ==')')
//		return true;
//	return false;
//}
////Õ»ÄÚ²Ù×÷·û
//int isp(char ch)
//{
//	switch (ch)
//	{
//	case '#':
//			return 0;
//	case '(':
//		return 1;
//	case '*':
//	case '/':
//	case '%':
//		return 5;
//	case '+':
//	case '-':
//		return 3;
//	case ')':
//		return 6;
//	default:
//		assert(0);
//		cout << "ÔËËã·û²»ºÏ·¨" << endl; 
//	}
//	return 0;
//}
////Õ»Íâ²Ù×÷·û
//int icp(char ch)
//{
//	switch (ch)
//	{
//	case '#':
//		return 0;
//	case '(':
//		return 6;
//	case '*':
//	case '/':
//	case '%':
//		return 4;
//	case '+':
//	case '-':
//		return 2;
//	case ')':
//		return 1;
//	default:
//		assert(0);
//		cout << "ÔËËã·û²»ºÏ·¨" << endl;
//	}
//	return 0;
//}
//void postfixnotation(char*expre)
//{
//	//stack<char>data;
//	string str;
//	char ch;
//	stack<char>op;
//	op.push('#');
//	int i = 0;
//    while (expre[i])
//	{
//		if (!isoperator(expre[i]))
//		{
//			str.push_back( expre[i]);
//			cout << expre[i];
//		}
//		else
//		{
//			str.push_back(' ');
//			cout << ' ';
//			ch = op.top();
//			if (icp(expre[i]) > isp(ch))
//				op.push(expre[i]);
//			else if (icp(expre[i]) < isp(ch))
//			{
//				str.push_back(ch);
//				op.pop();
//				cout << ch;
//				continue;
//			}
//			else
//			{
//				if (op.top() == '(')
//				{
//					op.pop();
//				}
//			}
//		}
//		++i;
//	}
//	while (op.top() != '#')
//	{
//		ch = op.top();
//		str.push_back(ch);
//		cout << ch;
//		op.pop();
//	}
//	cout << endl;
//	str.push_back(0);
//	//return sum(str);
//}
//int main()
//{
//	char expre[] = "12*(3+4)-6+8/2";
//	postfixnotation(expre);
//	return 0;
//}
////À¨ºÅÊÇ·ñÆ¥Åä
//#include<iostream>
//#include<stack>
//using namespace std;
////ÅÐ¶ÏÊÇ·ñÊÇÀ¨ºÅ
//bool Isbrackets(const char ch)
//{
//	if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
//		return true;
//	return false;
//}
////ÅÐ¶Ï×Ö·û´®ÀïÃæµÄ»¨À¨ºÅÊÇ·ñÆ¥Åä
//void Ismatch(const char* src)
//{
//	stack<char>sta;
//	int i = 0;
//	while (src[i])
//	{
//		if (Isbrackets(src[i]))
//		{
//			if (src[i] == '(' || src[i] == '{' || src[i] == '[')
//				sta.push(src[i]);
//			else
//			{
//				if (sta.empty())
//				{
//					cout << "ÓÒÀ¨ºÅ¶àÓà×óÀ¨ºÅ" << endl;
//					return;
//				}
//				else
//				{
//					char ch = sta.top();
//					if (ch == '{'&&src[i] == '}' || ch == '('&&src[i] == ')' || ch == '['&&src[i] == ']')
//					{
//						sta.pop();
//					}
//					else
//					{
//						cout << "À¨ºÅÀàÐÍ²»Æ¥Åä" << endl;
//						return;
//					}
//				}
//			}
//		}
//		++i;
//	}
//	if (!sta.empty())
//	{
//		cout << "×óÀ¨ºÅ¶àÓàÓÒÀ¨ºÅ" << endl;
//		return;
//	}
//	cout << "À¨ºÅÆ¥ÅäÕýÈ·" << endl;
//}
//int main()
//{
//	char*src1 = "(())abc{[(])}";
//	char*src2 = "(()))abc{[]}";
//	char*src3 = "(()()abc{[]}";
//	char*src4= "(())abc{[]()}";
//	Ismatch(src1);
//	Ismatch(src2);
//	Ismatch(src3);
//	Ismatch(src4);
//	return 0;
//}
////µÝ¹é°æ±¾¶þ·Ö²éÕÒ·¨
//#include<iostream>
//using namespace std;
//template<class T>
//int binary_search(T*arr, int left, int right, T _data)
//{
//	if (left > right)
//		return -1;
//	int mid = left + (right - 1 - left) /2 ;
//	if (arr[mid] == _data)
//		return mid;
//	else if (arr[mid] > _data)
//		binary_search(arr, left, mid - 1,_data);
//	else
//		binary_search(arr, mid + 1, right,_data);
//}
//int main()
//{
//	int arr[] = { 1, 3, 4, 6, 7, 8, 9 };
//	cout << binary_search(arr, 0, sizeof(arr) / sizeof(arr[0]), 7) << endl;
//	return 0;
//}
//¶¯Ì¬Ë³ÐòÕ»µÄÊµÏÖ
//#include<iostream>|
//using namespace std;
//struct NBuilt_intypes
//{
//	static bool Gettypes()
//	{
//		return false;
//	}
//};
//struct Built_intypes
//{
//	static bool Gettypes()
//	{
//		return true;
//	}
//};
//template<class T>
//class Is_Built_intypes
//{
//public:
//	typedef Built_intypes GetTypes;
//};
//template<>
//class Is_Built_intypes<int>
//{
//public:
//	typedef Built_intypes GetTypes;
//
//};
//template<>
//class Is_Built_intypes<double>
//{
//public:
//	typedef Built_intypes GetTypes;
//
//};
//template<>
//class Is_Built_intypes<char>
//{
//public:
//	typedef Built_intypes GetTypes;
//
//};
//
//template<class T>
//class Stack
//{
//public:
//	Stack() :_array(NULL), _capacity(0), _size(0)
//	{};
//	void Push(const T& data)
//	{
//		CheckCapacity();
//		_array[_size] = data;
//		++_size;
//	}
//	void Pop()
//	{
//		if (_size > 0)
//			--_size;
//	}
//	T& Top()
//	{
//		return _array[_size - 1];
//	}
//	T& Top()const
//	{
//		return _array[_size - 1];
//	}
//	size_t Size()const
//	{
//		return _size ;
//	}
//	bool Empty()const
//	{
//		return _size == 0;
//	}
//private:
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			T*Newp = new T[_capacity * 2 + 3];
//			_capacity = _capacity * 2 + 3;
//			if (_array != NULL)
//			{
//				if (Is_Built_intypes<T>::GetTypes::Gettypes())
//				{
//					memcpy(Newp, _array, _size*sizeof(T));
//				}
//				else
//				{
//					for (size_t i = 0; i < _size; ++i)
//					{
//						Newp[i] = _array[i];
//					}
//				}
//				delete[] _array;
//			}
//			_array = Newp;
//		}
//		
//	}
//
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//int main()
//{
//	Stack<int>s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	s1.Pop();
//	s1.Pop();
//	s1.Pop();
//	s1.Pop();
//	Stack<string>s2;
//	s2.Push("11111");
//	s2.Push("12123121212");
//	s2.Push("1212234783458762346");
//	s2.Push("1209354890325097");
//	s2.Pop();
//	s2.Pop();
//	s2.Pop();
//	s2.Pop();
//	s2.Pop();
//	return 0;
//}
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{

	void *ptr = malloc(4);
	*ptr = 4;
	++ptr;
	int *p = (int*)malloc(4);
	*p = 4;
	return 0;
}