//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<stack>
//#include<vector>
//#include<ctime>
//using namespace std;
//struct Set
//{
//	Set(int x, int y) :_x(x), _y(y)
//	{}
//	bool operator!=(const Set set)const 
//	{
//		return _x != set._x&&_y != set._y;
//	}
//	bool operator==(const Set set)const
//	{
//		return _x == set._x&&_y == set._y;
//	}
//	int _x;
//	int _y;
//};
////��һ��·
//
//class Mez
//{
//public:
//	//��ʼ���Թ�
//	Mez(const char* map)
//	{
//		FILE*fp = fopen(map, "r");
//		fscanf(fp, "%d\n%d\n", &_Col, &_Row);
//		maparr.resize( _Col);
//		interface.resize(_Col);
//		for (int i = 0; i < _Col; ++i)
//		{
//			maparr[i].resize(_Row);
//			interface[i] .resize(_Row);
//		}
//		for (int i = 0; i < _Col; i++)
//		{
//			for (int j = 0; j <_Row; j++)
//			{
//				fscanf(fp, "%d", &maparr[i][j]);
//				interface[i][j] = 1;
//			}
//		}
//	}
//	Mez()
//	{};
//	~Mez()
//	{
//		_Col = _Row = 0;
//	}
//	void display()
//	{
//		for (int i = 0; i < _Col; i++)
//		{
//			for (int j = 0; j < _Row; j++)
//			{
//				/*system("color 04");*/
//				printf("%4d", interface[i][j]);
//			}
//			cout << endl;
//		}
//		printf("w W �� s S �� a A �� d D  �� �ո� ��ͣ��Ϸ\n");
//	}
//	long play(Mez&mez, bool IsRec)
//	{
//		clock_t start = 0, finish = 0;
//		int x, y;
//		int flag;
//		mez.display();
//		start = clock();
//		if (IsRec)
//		{
//			Set cur = Recovery();
//			x = cur._x;
//			y = cur._y;
//			while (1)
//			{
//				flag = mez.movement(Set(x, y));
//				if (flag != 0)
//				{
//					break;
//				}
//				printf("����������꣺\n");
//				scanf("%d %d", &x, &y);
//			}
//		}
//		else{
//			while (1)
//			{
//				printf("����������꣺\n");
//				scanf("%d %d", &x, &y);
//				flag = mez.movement(Set(x, y));
//				if (flag != 0)
//				{
//					break;
//				}
//			}
//		}
//		finish = clock();
//		if (flag == 1)
//		{
//			cout << "������Ϸ�����ˣ�" << finish - start << "(s)" << endl;
//			return finish - start;
//		}
//		return 0;
//	}
//	
//	const Set Recovery()
//	{
//		int _x, _y;
//		FILE *fp1 = fopen("interface_document.txt", "r");
//		FILE *fp2 = fopen("maparr_document.txt", "r");
//		fscanf(fp1, "%d%d", &_Col, &_Row);
//		fscanf(fp1, "%d%d", &_x, &_y);
//		maparr.resize(_Col);
//		interface.resize(_Col);
//		for (int i = 0; i < _Col; ++i)
//		{
//			maparr[i].resize(_Row);
//			interface[i].resize(_Row);
//			for (int j = 0; j < _Row; ++j)
//			{
//				fscanf(fp1, "%d", &interface[i][j]);
//				fscanf(fp2, "%d", &maparr[i][j]);
//			}
//		}
//		fclose(fp1);
//		fclose(fp2);
//		return Set(_x, _y);
//	}
//private:
//	int  movement(Set&set)
//	{
//		if (Islegalset(set) && maparr[set._x][set._y] != 0)
//		{
//			cout << "��ڲ��Ϸ�" << endl;
//			return false;
//		}
//		interface[set._x][set._y] = 2;
//		display();
//		Set  Entery = set;
//		char move;
//		while (1)
//		{
//			move = getchar();
//			switch (move)
//			{
//			case'w':
//			case'W':
//			{
//					   Set up = set;
//					   up._x -= 1;
//					   bool flag = Islegalset(up);
//					   if (flag&&maparr[up._x][up._y] == 0)
//					   {
//
//						   interface[set._x][set._y] = 0;
//						   interface[up._x][up._y] = 2;
//						   set._x -= 1;
//					   }
//					   else
//					   {
//						   if (!flag)
//						   {
//							   cout << "�˳��Թ�" << endl;
//							   return 0;
//						   }
//						   interface[up._x][up._y] = 3;
//					   }
//					   system("cls");
//					   display();
//					   break;
//			}
//			case 's':
//			case 'S':
//			{
//						Set down = set;
//						down._x += 1;
//						bool flag = Islegalset(down);
//						if (flag&&maparr[down._x][down._y] == 0)
//						{
//
//							interface[set._x][set._y] = 0;
//							interface[down._x][down._y] = 2;
//							set._x += 1;
//						}
//						else
//						{
//							if (!flag)
//							{
//								cout << "�˳��Թ�" << endl;
//								return 0;
//							}
//							interface[down._x][down._y] = 3;
//						}
//						system("cls");
//						display();
//						break;
//			}
//			case'a':
//			case'A':
//			{
//					   Set left = set;
//					   left._y -= 1;
//					   bool flag = Islegalset(left);
//					   if (flag&& maparr[left._x][left._y] == 0)
//					   {
//
//						   interface[set._x][set._y] = 0;
//						   interface[left._x][left._y] = 2;
//						   set._y -= 1;
//					   }
//					   else
//					   {
//						   if (!flag)
//						   {
//							   cout << "�˳��Թ�" << endl;
//							   return 0;
//
//						   }
//						   interface[left._x][left._y] = 3;
//					   }
//					   system("cls");
//					   display();
//					   break;
//			}
//			case'd':
//			case'D':
//			{
//					   Set right = set;
//					   right._y += 1;
//					   bool flag = Islegalset(right);
//					   if (flag&&maparr[right._x][right._y] == 0)
//					   {
//
//						   interface[set._x][set._y] = 0;
//						   interface[right._x][right._y] = 2;
//						   set._y += 1;
//					   }
//					   else
//					   {
//						   if (!flag)
//						   {
//							   cout << "�˳��Թ�" << endl;
//							   return 0;
//						   }
//						   interface[right._x][right._y] = 3;
//					   }
//					   system("cls");
//					   display();
//					   break;
//			}
//			case ' ':
//			{
//						if (save_game(set))
//							return -1;
//			}
//			default:
//				break;
//			}
//			if (set != Entery && Iswill(set))
//			{
//				cout << "�Ѿ��߳��Թ�" << endl;
//				return 1;
//			}
//		}
//	}
//	bool save_game(const Set set)
//	{
//		char ch;
//		fflush(stdin);
//		printf("�Ƿ��뿪��Ϸ��(yȷ��)");
//		scanf("%c", &ch);
//		fflush(stdin);
//		if (ch == 'y')
//		{
//			printf("�Ƿ񱣴���Ϸ��¼��(yȷ��)");
//			scanf("%c", &ch);
//			if (ch == 'y')
//			{
//				FILE *fp1 = fopen("interface_document.txt", "w");
//				FILE *fp2 = fopen("maparr_document.txt", "w");
//				fprintf(fp1, "%d\n%d\n%d %d\n", _Col, _Row,set._x,set._y);
//				for (int i = 0; i < _Col; ++i)
//				{
//					for (int j = 0; j < _Row; ++j)
//					{
//						fprintf(fp1, "%d ", interface[i][j]);
//						fprintf(fp2, "%d ", maparr[i][j]);
//					}
//					fprintf(fp1, "\n");
//					fprintf(fp2, "\n");
//				}
//				fclose(fp1);
//				fclose(fp2);
//			}
//			return true;
//		}
//		return false;
//	}
//
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
//		if (set._x == 0 || set._y == 0 || set._y == _Row - 1 || set._x == _Col - 1)
//		{
//			return true;
//		}
//		return false;
//	}
//	vector<vector<int>>interface;
//	vector<vector<int>>maparr;
//	int _Col;
//	int _Row;
//};
//void meau()
//{
//	printf("**********************************\n");
//	printf("********      1.����    **********\n");
//	printf("**********************************\n");
//	printf("********      2.�м�    **********\n");	
//	printf("**********************************\n");
//	printf("********      3.����    **********\n");
//	printf("**********************************\n");
//	printf("********   4.�鿴��߼�¼  *******\n");
//	printf("**********************************\n");
//	printf("********   5.�����¼  ***********\n");
//	printf("**********************************\n");
//	printf("*****6.�ָ��ϴ��뿪ʱ��Ϸ����*****\n");
//	printf("**********************************\n");
//	printf("********      0.�˳�    **********\n");
//	printf("**********************************\n");
//}
//
//void test()
//{
//	long time = 0;
//	int input;
//	do
//	{
//		meau();
//		printf("����ѡ��\n");
//		cin >> input;
//		switch (input)
//		{
//		case 0:
//			cout << "��Ϸ�˳�" << endl;
//			break;
//			//��һ��
//		case 1:
//		{
//				  Mez mez("map1.txt");				  
//				  time = mez.play(mez,false);							 
//   			      break;
//		}
//			//�ڶ���
//		case 2:
//		{
//				  Mez mez("map2.txt");
//				  mez.display();
//				  time = mez.play(mez,false);
//				  break;
//		};
//			//������
//		case 3:
//		{
//				  Mez mez("map3.txt");
//				  mez.display();
//				  time = mez.play(mez,false);
//				  break;
//		}
//			//�鿴��߼�¼
//		case 4:
//		{
//				  FILE*fp = fopen("save.txt", "r");
//				  long temp = 0;
//				  if (!feof(fp))
//				  {
//					  fscanf(fp, "%ld", &temp);
//					  printf(" ��߼�¼���ѵ�ʱ��Ϊ��%ld(s)\n", temp);
//				  }
//				  else
//				  {
//					  cout << "Ŀǰû�м�¼" << endl;
//				  }
//				  fclose(fp);
//				  break;
//		}
//			//�����¼
//		case 5:
//		{
//				  FILE*fp = fopen("save.txt", "r");
//				  long temp = 0;
//				  FILE*fp1 = fopen("save.txt", "w");
//				  if (!feof(fp))
//				  {
//					  fscanf(fp, "%ld", &temp);
//					  if (temp > time)
//					  {
//						  fprintf(fp1, "%ld", time);
//					  }
//					  else
//					  {
//						  fprintf(fp1, "%ld", temp);
//					  }
//				  }
//				  else
//				  {
//					  fprintf(fp1, "%ld", time);
//				  }
//				  fclose(fp1);
//				  fclose(fp);
//		}
//			//�ָ��ϴ���Ϸ����
//		case 6:
//		{
//				  Mez mez;
//				  time = mez.play(mez,true);
//				  break;
//		}
//		default :
//			break;
//		}
//	} while (input);
//
//}
//int main()
//{
//	test();
//	return 0;
//}
