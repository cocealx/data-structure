#pragma once
#include<iostream>
using namespace std;
template<class T,int max>
struct B_TreeNode
{
	B_TreeNode() : Pparent(NULL)
	{
		memeset(&Pchild, 0, sizeof(B_TreeNode*)*(max + 1));
	}
	T _data[max];
	B_TreeNode*Pparent;
	B_TreeNode*Pchild[max + 1];
	size_t Size;
};
template<class T,int max>
class B_Tree
{
	typedef B_TreeNode<T,max> Node; 
public:
	B_Tree() :root(NULL)
	{

	}
	bool Insert(const T&data)
	{
		if (root == NULL)
		{
			root = new Node;
			_data[root->Size++]=data;

		}
		else
		{
			//查找插入位置

			pair<Node*, int>ret = find(root);
			//判断是否满足几个性质

			//
		}
	}
private:
	pair<Node*, int>find(Node*pcur)
	{

	}
	Node*root;
};

