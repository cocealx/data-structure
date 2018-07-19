//#define _CRT_SECURE_NO_WARNINGS 1
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
////找一条路
//
////template<int MAX>
//class Mez
//{
//public:
//	//初始化迷宫
//	Mez(const char* map)
//	{
//		FILE*fp = fopen( map, "r");
//		fscanf(fp, "%d\n%d\n", &_Col, &_Row);
//		maparr = new int*[_Col];
//		for (int i = 0; i < _Col; ++i)
//			maparr[i] = new int[_Row];
//		for (int i = 0; i < _Col; i++)
//		{
//			for (int j = 0; j <_Row; j++)
//			{
//				fscanf(fp, "%d", &maparr[i][j]);
//			}
//		}
//		maparr = new int*[_Col];
//		for (int i = 0; i < _Col; ++i)
//			maparr[i] = new int[_Row];
//		for (int i = 0; i < _Col; i++)
//		{
//			for (int j = 0; j <_Row; j++)
//			{
//				fscanf(fp, "%d", &maparr[i][j]);
//			}
//		}
//	}
//	~Mez()
//	{
//		delete[] maparr;
//	}
//	void display()
//	{
//		for (int i = 0; i < _Col; i++)
//		{
//			for (int j = 0; j < _Row; j++)
//			{
//				printf("%4d", maparr[i][j]);
//			}
//			cout << endl << endl;
//		}
//		cout << endl;
//	}
//	bool  movement(Set&set, stack<Set>& Route)
//	{
//		if (Islegalset(set))
//		{
//			maparr[set._x][set._y] = 2;
//			Route.push(set);
//			if (Route.size()!=1 && Iswill(set))
//			{
//				return true;
//			}
//			//如果他的下一个位置为0则可以走。
//			//朝上走
//			if (maparr[set._x - 1][set._y] == 0)
//			{
//				if(movement(Set(set._x - 1, set._y), Route))
//					return true;
//			}
//			//朝左走
//			if (maparr[set._x][set._y - 1] == 0)
//			{
//				if(movement(Set(set._x, set._y - 1), Route))
//					return true;
//			}
//			//朝右走
//			if (maparr[set._x][set._y + 1] == 0)
//			{
//				if(movement(Set(set._x, set._y + 1), Route))
//					return true;
//			}
//			//朝下走
//			if (Islegalset(Set(set._x + 1, set._y)) && maparr[set._x + 1][set._y] == 0)
//			{
//				if (movement(Set(set._x + 1, set._y), Route))
//					return true;
//			}
//			//如果周围的路都不通，把这个坐标pop出来，交给他的上一级调用者，继续探测周围。
//			Route.pop();
//			//把不通的路标记为3（也可以不标记）
//			maparr[set._x][set._y] = 3;
//		}
//		return false;
//	}
//	bool Islegalset(const Set&set)
//	{
//		if (0 <= set._x&&set._x < _Col && 0 <= set._y&&set._y < _Row)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool Iswill(const Set& set)
//	{
//		if (set._x == 0 || set._y == 0 || set._y == _Row- 1||set._x==_Col-1)
//		{
//			cout << "出口为：" << set._x << " " << set._y << endl;
//			return true;
//		}
//		return false;
//	}
//private:
//	int**interface;
//	int**maparr;
//	int _Col;
//	int _Row;
//};
//
//int main()
//{
//	int arr[11][11] = {
//		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }
//	};
//	FILE*fp = fopen("map2.txt", "w");
//	fprintf(fp, "%d\n%d\n", 11,11);
//	for (int i = 0; i < 11; ++i)
//	{
//		for (int j = 0; j < 11; ++j)
//		{
//			fprintf(fp, "%d ", arr[i][j]);
//		}
//		fprintf(fp, "\n");
//	}
//	fclose(fp);
//	Mez mez("map2.txt");
//	mez.display();
//	//保存走的通路
//	stack<Set>Route;
//	mez.movement(Set(10, 6), Route);
//	mez.display();
//	return 0;
//}
////找多条路版本
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
//template<int MAX>
//class Mez
//{
//public:
//	//初始化迷宫
//	Mez(int arr[][MAX])
//	{
//		maparr = new int[MAX][MAX];
//		for (int i = 0; i < MAX; i++)
//		{
//			for (int j = 0; j < MAX; j++)
//			{
//				maparr[i][j] = arr[i][j];
//			}
//		}
//	}
//	~Mez()
//	{
//		delete[] maparr;
//	}
//	void display()
//	{
//		for (int i = 0; i < MAX; i++)
//		{
//			for (int j = 0; j < MAX; j++)
//			{
//				printf("%4d", maparr[i][j]);
//			}
//			cout << endl << endl;
//		}
//		cout << endl;
//	}
//	void  movement(Set&set, stack<Set>& Route, stack<stack<Set>>&stackRoute)
//	{
//
//		if (Islegalset(set))
//		{
//			maparr[set._x][set._y] = 2;
//			
//			if (maparr[set._x][set._y] == 1)
//			{
//				return;
//			}
//			Route.push(set);
//			if (Iswill(set))
//			{
//				//把所有的通路保存起来
//				stackRoute.push(Route);
//				//如果找到一条通路，在处理完之后把最后一个元素pop掉，把递归返回到他的上一级调用者，继续探测
//				Route.pop();
//				return;
//			}
//			//如果他的下一个位置为0则可以走。
//			//朝上走
//			if (maparr[set._x - 1][set._y] == 0 )
//			{
//				movement(Set(set._x - 1, set._y), Route, stackRoute);
//			}
//			//朝左走
//			if (maparr[set._x][set._y - 1] == 0)
//			{
//				movement(Set(set._x, set._y - 1), Route, stackRoute);
//			}
//			//朝右走
//			if (maparr[set._x][set._y + 1] == 0 )
//			{
//				movement(Set(set._x, set._y + 1), Route, stackRoute);
//			}
//			//朝下走
//			if (maparr[set._x + 1][set._y] == 0 )
//			{
//				movement(Set(set._x + 1, set._y), Route, stackRoute);
//			}
//			//如果所以的路都不通，把这个坐标pop出来，交给他的上一级调用者，继续探测周围。
//			Route.pop();
//		}
//	}
//	bool Islegalset(const Set&set)
//	{
//		if (0 <= set._x&&set._x < MAX && 0 <= set._y&&set._y < MAX)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool Iswill(const Set& set)
//	{
//		if (set._x == 0 || set._y == 0 || set._y == MAX - 1)
//		{
//			cout << "出口为：" << set._x << " " << set._y << endl;
//			return true;
//		}
//		return false;
//	}
//private:
//	int(*maparr)[MAX];
//};
//
//int main()
//{
//	int arr[11][11] = {
//		{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
//		{ 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
//		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
//		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }
//	};
//	Mez<11> mez(arr);
//	mez.display();
//	//保存所有的通路
//	stack<stack<Set>>ArrayRoute;
//	//每次走的通路
//	stack<Set>Route;
//	mez.movement(Set(10, 6), Route,ArrayRoute);
//	mez.display();
//	printf("总共有%d条通路\n", ArrayRoute.size());
//	return 0;
//}

//////带回路版本
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
//template<int MAX>
//class Mez
//{
//public:
//	//初始化迷宫
//	Mez(int arr[][MAX])
//	{
//		maparr = new int[MAX][MAX];
//		for (int i = 0; i < MAX; i++)
//		{
//			for (int j = 0; j < MAX; j++)
//			{
//				maparr[i][j] = arr[i][j];
//			}
//		}
//	}
//	~Mez()
//	{
//		delete[] maparr;
//	}
//	void display()
//	{
//		for (int i = 0; i < MAX; i++)
//		{
//			for (int j = 0; j < MAX; j++)
//			{
//				printf("%4d", maparr[i][j]);
//			}
//			cout << endl<<endl;
//		}
//		cout << endl;
//	}
//	void  movement(Set&set,stack<Set>& Route,stack<Set>&ShortRoute)
//	{
//		
//		if (Islegalset(set))
//		{
//			
//			if (Route.empty())
//			{
//				//对入口进行标记
//				maparr[set._x][set._y] = 2;
//			}
//			else
//			{
//				//对走过的路进行标记
//				//通过上一个合法能通过的坐标的内容加1来对这个坐标的内容进行标记，
//				//而上一个坐标是栈Route的栈顶元素。
//				maparr[set._x][set._y] = maparr[Route.top()._x][Route.top()._y]+1;
//			}
//			if (maparr[set._x][set._y] == 1)
//			{
//				return;
//			}
//			Route.push(set);
//			if (Iswill(set))
//			{
//				//如果保存路线的栈Route的元素比保存最短路线的栈ShortRoute的元素小，或者保存最短路线的栈为空
//				//就把Route赋值给ShortRoute
//				if (Route.size() < ShortRoute.size() || ShortRoute.empty())
//				{
//					ShortRoute = Route;
//				}
//				//如果找到一条通路，在处理完之后把最后一个元素pop掉，把递归返回到他的上一级调用者，继续探测
//				Route.pop();
//				return;
//			}
//		     //如果他的下一个位置为0或者，这个坐标的标记内容小于下一个坐标的标记内容说明可以走。
//
//			//朝上走
//			if (maparr[set._x - 1][set._y] == 0 || maparr[set._x][set._y] < maparr[set._x - 1][set._y])
//			{
//				movement(Set(set._x - 1, set._y), Route,ShortRoute);
//			}
//			//朝左走
//			if (maparr[set._x][set._y - 1] == 0 || maparr[set._x][set._y] < maparr[set._x][set._y - 1])
//			{
//				movement(Set(set._x, set._y - 1),  Route, ShortRoute);
//			}
//			//朝右走
//			if (maparr[set._x][set._y + 1] == 0 || maparr[set._x][set._y] < maparr[set._x][set._y + 1])
//			{
//				movement(Set(set._x, set._y + 1),  Route, ShortRoute);
//			}
//			//朝下走
//			if (maparr[set._x + 1][set._y] == 0 || maparr[set._x][set._y] < maparr[set._x + 1][set._y])
//			{
//				movement(Set(set._x + 1, set._y),  Route, ShortRoute);
//			}
//			//如果所以的路都不通，把这个坐标pop出来，交给他的上一级调用者，继续探测周围。
//			Route.pop();
//		}
//	}
//	bool Islegalset(const Set&set)
//	{
//		if (0 <= set._x&&set._x < MAX && 0 <= set._y&&set._y < MAX)
//		{
//			return true;
//		}		
//		return false;
//	}
//	bool Iswill(const Set& set)
//	{
//			if (set._x == 0 || set._y == 0 || set._y == MAX - 1)
//			{
//				cout << "出口为：" << set._x << " " << set._y << endl;
//				return true;
//			}	
//		return false;
//	}
//private:
//	int(*maparr)[MAX];
//};
//
//int main()
//{
//	int arr[11][11] = {
//		{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,1 },
//		{ 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 ,1},
//		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 ,1},
//		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 ,1},
//		{ 1, 0, 1, 1, 1, 0, 0, 0, 1, 1 ,1},
//		{ 1, 0, 0, 0, 1, 0, 1, 1, 1, 1 ,1},
//		{ 1, 1, 1, 0, 1, 0, 1, 1, 1, 1 ,1},
//		{ 1, 0, 0, 0, 1, 0, 1, 1, 1, 1 ,1},
//		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 1 ,1},
//		{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 ,1},
//		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 ,1}
//	};
//	Mez<11> mez(arr);
//	mez.display();
//	stack<Set>Route;
////保存最短的路径
//	stack<Set>ShrotRoute;
//	mez.movement(Set(10, 6),Route,ShrotRoute);
//	mez.display();
//	cout << ShrotRoute.size() << endl;
//	return 0;
//}
//




//bool operator==(const Set&set)const
//{
//	return _x == set._x&&_y == set._y;
//}
//bool operator!=(const Set&set)const
//{
//	return !(_x == set._x&&_y == set._y);
//}

