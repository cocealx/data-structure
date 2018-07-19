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
	//����÷���
	char _ch;
	//����÷��Ŷ�Ӧ�Ĺ���������
	string Code;
    //�����ظ����ֵĴ���
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
		//��ȡ���ַ�
		char index /*= fgetc(fout)*/;
		//ͳ���ַ����ֵĴ�����
		while (fread(&index, sizeof(char), 1, fout)/*index!=EOF*/)
		{
			
			ch[(unsigned char )index]._ch = index;
			++ch[(unsigned char)index].count;
			/*index = fgetc(fout);*/
		// fread(&index, sizeof(char), 1, fout);	
		}
		//���ɹ���������
		GetCode();
		//ѹ���ļ�
		fseek(fout, 0, SEEK_SET);
		
		//ͳ��Ŀǰ������λ�ĸ�����8λ����д��
		int count = 8;
		//�Ѷ�Ӧ�ı���ת��Ϊ������λ
		//Ҫд����ַ�
		char inch=0;
		/*index = fgetc(fout);*/
		while (fread(&index, sizeof(char), 1, fout)/*index!=EOF*/)
		{
			
			//ͳ���ļ���С
			++fileMax;
			//ÿ���ַ�����ĳ���
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
						cout << "д��ʧ��" << endl;*/
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
		//��¼ÿ���ֽڵ�8��bitλ
		int count = 8;
		//
		while (/*value!=EOF*//*&&*/fileMax)
		{
			//��ý����Ҷ�ӽ����˵����ѹ��һ���ַ�
			if (pcur->_left == NULL&&pcur->_right == NULL)
			{
				//�ļ���С��һ
				--fileMax;
				fwrite(&pcur->_w._ch, sizeof(pcur->_w._ch), 1, fin);
				//fputc(pcur->_w._ch, fin);
				//�Ӹ�������¿�ʼ��
				pcur = root;
			}
			//���һ���ֽ�λ��ѹ�꣬���¶�ȡ��һ���ֽ�
			if (count == 0)
			{
				count = 8;
				fread(&value, sizeof(char), 1, fout);
				//value = getc(fout);
			}
			//�����bitλΪ1��pcur������
			if ((value >> (count - 1)) & 1)
			{
				pcur = pcur->_right;
			}
			else
			{
				pcur = pcur->_left;
			}
			//ÿ�αȽ�һ��bitλ���ܵ�bitλ��1
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
		//���ɹ�������
		HuffmanTree<Weights> HffTree;
		HffTree.CreatTree(ch, 256, Weights());
		//���ɹ���������
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
			//����ý����Ҷ�ӽ�㣬�����ɸ��ַ���Ӧ��Code
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
				//����Code��������Ҷ�ӽ�㵽���ڵ�����Ҫ��������һ��
				reverse(Code.begin(), Code.end());
			}
			pcur = pcur->_right;
		}
	}
	//ÿ�����Ŷ�Ӧ��Ȩֵ
	Weights ch[256];
	//ͳ��Դ�ļ��Ĵ�С
	long long fileMax;
};
