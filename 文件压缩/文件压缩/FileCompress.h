#pragma once
#include"HuffmanTree.h"
#include<string>
#include<stack>
#include<assert.h>
struct Weights
{
	Weights():_ch(0), count(0){}
	Weights(long long sum) :count(sum){}
	bool operator!=(const Weights& dest)const
	{
		return count != dest.count;
	}
	bool operator<(const Weights& dest)const
	{
		return count < dest.count;
	}
	long long operator+(const Weights& dest)const
	{
		return count + dest.count;
	}
	//保存该符号
	char _ch;
	//保存该符号对应的哈夫曼编码
	string Code;
    //符号重复出现的次数
	long long count;
};
class FileCompress
{
public:
	FileCompress(const char*file) :fileMax(0)
	{
		FILE* fout = fopen(file, "rb");
		FILE* fin = fopen("unhuffman.txt", "wb");
		//FILE* fout = fopen(file, "r");
		//FILE* fin = fopen("unhuffman.txt", "w");
		assert(fout&&fin);
		//读取的字符
		char index /*= fgetc(fout)*/;
		//统计字符出现的次数；
		while (fread(&index, sizeof(char), 1, fout)/*index!=EOF*/)
		{
			
			ch[(unsigned char )index]._ch = index;
			++ch[(unsigned char)index].count;
			/*index = fgetc(fout);*/
		// fread(&index, sizeof(char), 1, fout);	
		}
		//生成哈夫曼编码
		GetCode();
		//压缩文件
		fseek(fout, 0, SEEK_SET);
		
		//统计目前二进制位的个数，8位进行写入
		int count = 8;
		//把对应的编码转换为二进制位
		//要写入的字符
		char inch=0;
		/*index = fgetc(fout);*/
		while (fread(&index, sizeof(char), 1, fout)/*index!=EOF*/)
		{
			
			//统计文件大小
			++fileMax;
			//每个字符编码的长度
			const string&Code = ch[(unsigned char)index].Code;
			size_t size = Code.size();
			int i = 0;
			while (i<size)
			{
				if (Code[i]=='1')
					inch |= (1 << (count-1));
				++i;
				--count;
				if (count == 0)
				{
					fwrite(&inch, sizeof(inch), 1, fin);
					/*if (fputc(inch, fin) == EOF)
						cout << "写入失败" << endl;*/
					count = 8;
					inch = 0;
				}
			}
			/*index = fgetc(fout);*/
		}
		if (count != 8)
		{
			fwrite(&inch, sizeof(inch), 1, fin);
			//fputc(inch, fin);
		}
		fclose(fin);
		fclose(fout);
	}
	void UnFileCompress()
	{
      	FILE* fout = fopen("unhuffman.txt", "rb");
		FILE*fin = fopen("temp.jpg", "wb");
 	//	FILE* fout = fopen("unhuffman.txt", "r");
		//FILE*fin = fopen("jieya.txt", "w");
		//
		HuffmanTree<Weights> HffTree;
		HffTree.CreatTree(ch, 256, Weights());
		TreeNode<Weights> *root = HffTree.GetRoot();
		TreeNode<Weights> *pcur = root;
		char value /*fgetc(fout)*/;
		fread(&value, sizeof(char), 1, fout);
		//记录每个字节的8个bit位
		int count = 8;
		//
		while (/*value!=EOF*//*&&*/fileMax)
		{
			//如该结点是叶子结点则说明解压了一个字符
			if (pcur->_left == NULL&&pcur->_right == NULL)
			{
				//文件大小减一
				--fileMax;
				fwrite(&pcur->_w._ch, sizeof(pcur->_w._ch), 1, fin);
				//fputc(pcur->_w._ch, fin);
				//从根结点重新开始走
				pcur = root;
			}
			//如果一个字节位解压完，重新读取下一个字节
			if (count == 0)
			{
				count = 8;
				fread(&value, sizeof(char), 1, fout);
				//value = getc(fout);
			}
			//如果该bit位为1，pcur往右走
			if ((value >> (count - 1)) & 1)
			{
				pcur = pcur->_right;
			}
			else
			{
				pcur = pcur->_left;
			}
			//每次比较一个bit位后总的bit位减1
			--count;
		}
		fclose(fin);
		fclose(fout);
	}
private:
	typedef TreeNode<Weights>  Node;
	void GetCode()
	{
		//
		//生成哈夫曼树
		HuffmanTree<Weights> HffTree;
		HffTree.CreatTree(ch, 256, Weights());
		//生成哈夫曼编码
		TreeNode<Weights> *root = HffTree.GetRoot();
		TreeNode<Weights> *pcur = root;
		stack<TreeNode<Weights>*>sta;
		while (!sta.empty()||pcur!=NULL)
		{
			while (pcur)
			{
				sta.push(pcur);
				pcur = pcur->_left;
			}
			pcur = sta.top();
			sta.pop();
			//如果该结点是叶子结点，则生成该字符对应的Code
			if (pcur->_left == NULL
				&&pcur->_right == NULL)
			{
				TreeNode<Weights> *child = pcur;
				while (child!=root)
				{
					if (child == child->_parent->_left)
						ch[(unsigned char)(pcur->_w._ch)].Code.push_back('0');
					else
						ch[(unsigned char)(pcur->_w._ch)].Code.push_back('1');
					child = child->_parent;
				}
				string&Code = ch[(unsigned char)(pcur->_w._ch)].Code;
				//由于Code编码是由叶子结点到根节点所有要进行逆置一下
				reverse(Code.begin(), Code.end());
			}
			pcur = pcur->_right;
		}
	}
	//每个符号对应的权值
	Weights ch[256];
	//统计源文件的大小
	long long fileMax;
};
