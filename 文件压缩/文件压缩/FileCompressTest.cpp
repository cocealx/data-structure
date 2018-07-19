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
	string s1("gdb调试1）启动gdb：gdb 可执行程序名2）查看代码：\n ll 查看当前文件l 目标文件.c：行号  -- 直接显示目标文件的目标行");
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