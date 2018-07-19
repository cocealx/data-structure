#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<Windows.h>
//#include<unistd.h>
using namespace std;
int main()
{
	

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);//设置为红色
	printf("这是红色\n");
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);//恢复默认的灰色
	printf("这是灰色\n");
	getchar();
	return 0;
	//const char* label = "|/-\\";
	//char buf[102] = "#";
	//int i = 0;
	//for (i = 1; i <= 100; i++)
	//{
	//	COLOR[5];
	//	printf("[%-100s][%%%d][%c]\n", buf, i, label[i % 4]);
	//	printf("\033c");
	//	fflush(stdout);
	//	buf[i] = '#';
	//	Sleep(100);
	//	//system("cls");
	//	
	/*}*/
	//for (int i = 0; i < 10; ++i)
	//{
	//	/*for (int j = 0; j < 10; ++j)
	//	{
	//		printf("\033[31m%d\033[44m  ", i);
	//	}*/
	//	
	//	printf("\n");
	//}
	return 0;
}
