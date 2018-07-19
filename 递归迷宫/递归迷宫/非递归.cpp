////#define _CRT_SECURE_NO_WARNINGS 1
////
////找一条路
//#include<iostream>
//#include<stack>
//using namespace std;
//struct Set
//{
//	Set(int x, int y) :_x(x), _y(y)
//	{}
//	int _x;
//	int _y;
//};
//template<int max>
//class mez
//{
//public:
//	//初始化迷宫
//	mez(int arr[][max])
//	{
//		maparr = new int[max][max];
//		for (int i = 0; i < max; i++)
//		{
//			for (int j = 0; j < max; j++)
//			{
//				maparr[i][j] = arr[i][j];
//			}
//		}
//	}
//	~mez()
//	{
//		delete[] maparr;
//	}
//	void display()
//	{
//		for (int i = 0; i < max; i++)
//		{
//			for (int j = 0; j < max; j++)
//			{
//				printf("%4d", maparr[i][j]);
//			}
//			cout << endl << endl;
//		}
//		cout << endl;
//	}
//	bool  movement(Set&set, stack<Set>&route)
//	{
//	   do
//		{
//
//				if (iswill(set))
//				{
//					maparr[set._x][set._y] = 2;
//					return true;
//				}
//				if (islegalset(set) && maparr[set._x][set._y] == 0)
//				{
//					maparr[set._x][set._y] = 2;
//					//如果他的下一个位置为0则可以走。
//					//朝上走
//				if (islegalset(Set(set._x - 1, set._y)) && maparr[set._x - 1][set._y] == 0)
//					{
//						route.push(set);
//						set = Set(set._x - 1, set._y);
//						continue;
//					}
//					//朝左走
//				  if (islegalset(Set(set._x, set._y - 1)) && maparr[set._x][set._y - 1] == 0)
//					{
//					  route.push(set);
//						set = Set(set._x, set._y - 1);
//						continue;
//					}
//					//朝右走
//					 if (islegalset(Set(set._x, set._y + 1)) && maparr[set._x][set._y + 1] == 0)
//					{
//						 route.push(set);
//						set = Set(set._x, set._y + 1);
//						continue;
//					}
//					//朝下走
//					 if (islegalset(Set(set._x + 1, set._y)) && maparr[set._x + 1][set._y] == 0)
//					{
//						 route.push(set);
//						set = Set(set._x + 1, set._y);
//						continue;
//					}
//					 //把不通的路标记为3（也可以不标记）
//					 maparr[set._x][set._y] = 3;
//				}
//				//如果周围的路都不通，把上一个坐标pop出来，继续探测周围。
//				set = route.top();
//				route.pop();
//				maparr[set._x][set._y] = 0;
//	   } while (!route.empty());
//		return false;
//	}
//	bool islegalset(const Set&set)
//	{
//		if (0 <= set._x&&set._x < max && 0 <= set._y&&set._y < max)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool iswill(const Set& set)
//	{
//		if (set._x == 0 || set._y == 0 || set._y == max - 1)
//		{
//			cout << "出口为：" << set._x << " " << set._y << endl;
//			return true;
//		}
//		return false;
//	}
//private:
//	int(*maparr)[max];
//};
//
//int main()
//{
//	int arr[11][11] = {
//		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }
//	};
//	mez<11> mez(arr);
//	mez.display();
//	//保存走的通路
//	stack<Set>route;
//	mez.movement(Set(10, 6), route);
//	mez.display();
//	return 0;
//}

////找多条路
//#include<iostream>
//#include<stack>
//using namespace std;
//struct Set
//{
//	Set(int x, int y) :_x(x), _y(y)
//	{}
//	int _x;
//	int _y;
//};
//template<int max>
//class mez
//{
//public:
//	//初始化迷宫
//	mez(int arr[][max])
//	{
//		maparr = new int[max][max];
//		for (int i = 0; i < max; i++)
//		{
//			for (int j = 0; j < max; j++)
//			{
//				maparr[i][j] = arr[i][j];
//			}
//		}
//	}
//	~mez()
//	{
//		delete[] maparr;
//	}
//	void display()
//	{
//		for (int i = 0; i < max; i++)
//		{
//			for (int j = 0; j < max; j++)
//			{
//				printf("%4d", maparr[i][j]);
//			}
//			cout << endl << endl;
//		}
//		cout << endl;
//	}
//	void  movement(Set&set, stack<Set>&route)
//	{
//		do
//		{
//
//			if (iswill(set))
//			{
//				route.pop();
//			}
//			if (maparr[set._x][set._y] == 0)
//			{
//				maparr[set._x][set._y] = 2;
//				//如果他的下一个位置为0则可以走。
//				//朝上走
//				if ( maparr[set._x - 1][set._y] == 0)
//				{
//					route.push(set);
//					set = Set(set._x - 1, set._y);
//					continue;
//				}
//				//朝左走
//				if ( maparr[set._x][set._y - 1] == 0)
//				{
//					route.push(set);
//					set = Set(set._x, set._y - 1);
//					continue;
//				}
//				//朝右走
//				if ( maparr[set._x][set._y + 1] == 0)
//				{
//					route.push(set);
//					set = Set(set._x, set._y + 1);
//					continue;
//				}
//				//朝下走
//				if ( maparr[set._x + 1][set._y] == 0)
//				{
//					route.push(set);
//					set = Set(set._x + 1, set._y);
//					continue;
//				}
//				//把不通的路标记为3（也可以不标记）
//			}
//			//如果周围的路都不通，把上一个坐标pop出来，继续探测周围。
//			set = route.top();
//			route.pop();
//			maparr[set._x][set._y] = 0;
//		} while (!route.empty());
//	}
//	bool islegalset(const Set&set)
//	{
//		if (0 <= set._x&&set._x < max && 0 <= set._y&&set._y < max)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool iswill(const Set& set)
//	{
//		if (set._x == 0 || set._y == 0 || set._y == max - 1)
//		{
//			cout << "出口为：" << set._x << " " << set._y << endl;
//			return true;
//		}
//		return false;
//	}
//private:
//	int(*maparr)[max];
//};
//
//int main()
//{
//	int arr[11][11] = {
//		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }
//	};
//	mez<11> mez(arr);
//	mez.display();
//	//保存走的通路
//	stack<Set>route;
//	mez.movement(Set(10, 6), route);
//	mez.display();
//	return 0;
//}

//带回路非递归版本。
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct Set
{
	Set(int x, int y) :_x(x), _y(y){}
	bool operator==(const Set set)const
	{
		return _x == set._x&&_y == set._y;
	}
	bool operator!=(const Set set)const
	{
		return !(*this == set);
	}
	int _x;
	int _y;
};
class mez
{
public:
	//初始化迷宫
	mez(int*arr, int row, int col) :_row(row), _col(col)
	{
		_map.resize(row);
		for (int i = 0; i < row; ++i)
		{
			_map[i].resize(col);
			for (int j = 0; j < col; ++j)
			{
				_map[i][j] = arr[i*col + j];
			}
		}
	}
	~mez()
	{
		_col = 0;
		_row = 0;
	}
	void display()
	{
		for (int i = 0; i < _row; ++i)
		{
			for (int j = 0; j < _col; ++j)
			{
				printf("%-3d", _map[i][j]);
			}
			cout << endl;
		}
	}
	void  movement(Set&Entery, stack<Set>&route)
	{
		stack<Set>s;
		if (_map[Entery._x][Entery._y] ==1 )
		{
			cout << "入口不合法" << endl;
			return;
		}
		_map[Entery._x][Entery._y] = 2;
		s.push(Entery);
		while (!s.empty())
		{
			Set cur = s.top();
			if (iswill(cur) && cur != Entery)
			{
				if (route.empty() || route.size() > s.size())
				{
					route = s;
				}
				s.pop();
				continue;
			}
			Set up(cur._x-1, cur._y);
			if (isleag(up) && ispass(cur, up))
			{
				_map[up._x][up._y] = _map[cur._x][cur._y] + 1;
				s.push(up);
				continue;
			}
			Set left(cur._x, cur._y - 1);
			if (isleag(left) && ispass(cur, left))
			{
				_map[left._x][left._y] = _map[cur._x][cur._y] + 1;
				s.push(left);
				continue;
			}
			Set right(cur._x, cur._y + 1);
			if (isleag(right)&&ispass(cur, right))
			{
				_map[right._x][right._y] = _map[cur._x][cur._y] + 1;
				s.push(right);
				continue;
			}
			Set down(cur._x + 1, cur._y);
			if (isleag(down)&&ispass(cur, down))
			{
				_map[down._x][down._y] = _map[cur._x][cur._y] + 1;
				s.push(down);
				continue;
			}
			s.pop();

		} 
	}

private:
	bool ispass(const Set &cur, const Set&next)
	{
		if (_map[next._x][next._y] == 0 ||
			_map[cur._x][cur._y] < _map[next._x][next._y] && _map[cur._x][cur._y] +1!=_map[next._x][next._y])
			return true;
		return false;
	}
	bool iswill(const Set& set)
	{
		if (set._x == 0 || set._y == 0 || set._x == _row - 1 || set._y == _col - 1)
			return true;
		return false;
	}
	bool isleag(const Set &set)
	{
		if (0 <= set._x&&set._x < _row && 0 <= set._y&&set._y < _col)
			return true;
		return false;
	}
	//二维数组地图
	vector<vector<int>> _map;
	//行
	int _row;
	//列
	int _col;
};
int main()
{
		int arr[11][11] = {
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1 },
			{ 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1 },
			{ 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }
		};
		mez m1((int*)arr, 11, 11);
		m1.display();
		stack<Set>path;
		m1.movement(Set(10, 6),path);
		cout << endl;
		m1.display();
		return 0;
}