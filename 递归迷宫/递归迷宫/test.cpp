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
////��һ��·
//
////template<int MAX>
//class Mez
//{
//public:
//	//��ʼ���Թ�
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
//			//���������һ��λ��Ϊ0������ߡ�
//			//������
//			if (maparr[set._x - 1][set._y] == 0)
//			{
//				if(movement(Set(set._x - 1, set._y), Route))
//					return true;
//			}
//			//������
//			if (maparr[set._x][set._y - 1] == 0)
//			{
//				if(movement(Set(set._x, set._y - 1), Route))
//					return true;
//			}
//			//������
//			if (maparr[set._x][set._y + 1] == 0)
//			{
//				if(movement(Set(set._x, set._y + 1), Route))
//					return true;
//			}
//			//������
//			if (Islegalset(Set(set._x + 1, set._y)) && maparr[set._x + 1][set._y] == 0)
//			{
//				if (movement(Set(set._x + 1, set._y), Route))
//					return true;
//			}
//			//�����Χ��·����ͨ�����������pop����������������һ�������ߣ�����̽����Χ��
//			Route.pop();
//			//�Ѳ�ͨ��·���Ϊ3��Ҳ���Բ���ǣ�
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
//			cout << "����Ϊ��" << set._x << " " << set._y << endl;
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
//	//�����ߵ�ͨ·
//	stack<Set>Route;
//	mez.movement(Set(10, 6), Route);
//	mez.display();
//	return 0;
//}
////�Ҷ���·�汾
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
//	//��ʼ���Թ�
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
//				//�����е�ͨ·��������
//				stackRoute.push(Route);
//				//����ҵ�һ��ͨ·���ڴ�����֮������һ��Ԫ��pop�����ѵݹ鷵�ص�������һ�������ߣ�����̽��
//				Route.pop();
//				return;
//			}
//			//���������һ��λ��Ϊ0������ߡ�
//			//������
//			if (maparr[set._x - 1][set._y] == 0 )
//			{
//				movement(Set(set._x - 1, set._y), Route, stackRoute);
//			}
//			//������
//			if (maparr[set._x][set._y - 1] == 0)
//			{
//				movement(Set(set._x, set._y - 1), Route, stackRoute);
//			}
//			//������
//			if (maparr[set._x][set._y + 1] == 0 )
//			{
//				movement(Set(set._x, set._y + 1), Route, stackRoute);
//			}
//			//������
//			if (maparr[set._x + 1][set._y] == 0 )
//			{
//				movement(Set(set._x + 1, set._y), Route, stackRoute);
//			}
//			//������Ե�·����ͨ�����������pop����������������һ�������ߣ�����̽����Χ��
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
//			cout << "����Ϊ��" << set._x << " " << set._y << endl;
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
//	//�������е�ͨ·
//	stack<stack<Set>>ArrayRoute;
//	//ÿ���ߵ�ͨ·
//	stack<Set>Route;
//	mez.movement(Set(10, 6), Route,ArrayRoute);
//	mez.display();
//	printf("�ܹ���%d��ͨ·\n", ArrayRoute.size());
//	return 0;
//}

//////����·�汾
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
//	//��ʼ���Թ�
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
//				//����ڽ��б��
//				maparr[set._x][set._y] = 2;
//			}
//			else
//			{
//				//���߹���·���б��
//				//ͨ����һ���Ϸ���ͨ������������ݼ�1���������������ݽ��б�ǣ�
//				//����һ��������ջRoute��ջ��Ԫ�ء�
//				maparr[set._x][set._y] = maparr[Route.top()._x][Route.top()._y]+1;
//			}
//			if (maparr[set._x][set._y] == 1)
//			{
//				return;
//			}
//			Route.push(set);
//			if (Iswill(set))
//			{
//				//�������·�ߵ�ջRoute��Ԫ�رȱ������·�ߵ�ջShortRoute��Ԫ��С�����߱������·�ߵ�ջΪ��
//				//�Ͱ�Route��ֵ��ShortRoute
//				if (Route.size() < ShortRoute.size() || ShortRoute.empty())
//				{
//					ShortRoute = Route;
//				}
//				//����ҵ�һ��ͨ·���ڴ�����֮������һ��Ԫ��pop�����ѵݹ鷵�ص�������һ�������ߣ�����̽��
//				Route.pop();
//				return;
//			}
//		     //���������һ��λ��Ϊ0���ߣ��������ı������С����һ������ı������˵�������ߡ�
//
//			//������
//			if (maparr[set._x - 1][set._y] == 0 || maparr[set._x][set._y] < maparr[set._x - 1][set._y])
//			{
//				movement(Set(set._x - 1, set._y), Route,ShortRoute);
//			}
//			//������
//			if (maparr[set._x][set._y - 1] == 0 || maparr[set._x][set._y] < maparr[set._x][set._y - 1])
//			{
//				movement(Set(set._x, set._y - 1),  Route, ShortRoute);
//			}
//			//������
//			if (maparr[set._x][set._y + 1] == 0 || maparr[set._x][set._y] < maparr[set._x][set._y + 1])
//			{
//				movement(Set(set._x, set._y + 1),  Route, ShortRoute);
//			}
//			//������
//			if (maparr[set._x + 1][set._y] == 0 || maparr[set._x][set._y] < maparr[set._x + 1][set._y])
//			{
//				movement(Set(set._x + 1, set._y),  Route, ShortRoute);
//			}
//			//������Ե�·����ͨ�����������pop����������������һ�������ߣ�����̽����Χ��
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
//				cout << "����Ϊ��" << set._x << " " << set._y << endl;
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
////������̵�·��
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

