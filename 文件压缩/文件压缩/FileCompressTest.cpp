#define _CRT_SECURE_NO_WARNINGS 1
#include"FileCompress.h"
#include"Heap.h"
#include"HuffmanTree.h"
void Test()
{
	HuffmanTree<int> hftree;
	FileCompress fc("1949.jpg");
	fc.UnFileCompress();
}
void testgutcfwrite()
{
	FILE*fin = fopen("test.txt", "w");
	FILE*fout = fopen("test123.txt", "w");
	char a = -1;
	string s1("gdb����1������gdb��gdb ��ִ�г�����2���鿴���룺\n ll �鿴��ǰ�ļ�l Ŀ���ļ�.c���к�  -- ֱ����ʾĿ���ļ���Ŀ����");
//	fwrite(&s1[0], sizeof(char), s1.size(), fin);
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		fputc(*it, fin);
		++it;
	}
	fputc(a, fin);
	fputc(a, fin);
	fputc(a, fin);
	fputc(a, fin);
	 it = s1.begin();
	while (it != s1.end())
	{
		fputc(*it, fin);
		++it;
	}
	//fwrite(&a, sizeof(char), 1, fin);
	//fwrite(&s1[0], sizeof(char), s1.size(), fin);
	fclose(fin);
	FILE*fin1 = fopen("test.txt", "rb");
	char ch;
	//ch = getc(fout);
	
	while (fread(&ch, sizeof(char), 1, fin1))
	{
		fputc(ch, fout);
		
		//ch = getc(fout);
	}
	return;
}
int main()
{
	Test();
	//testgutcfwrite();
	return 0;
}