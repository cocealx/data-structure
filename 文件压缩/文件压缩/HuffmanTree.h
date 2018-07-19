#pragma once
#include"Heap.h"
template<class T>
struct TreeNode
{
	
	TreeNode(const T& w) :_w(w), _left(NULL), _right(NULL),_parent(NULL){}
	//������
	TreeNode<T>*_left;
	//������
	TreeNode<T>*_right;
	//˫�׽��
	TreeNode<T>*_parent;
	//Ȩֵ
	T _w;

};
template<class W>
class HuffmanTree
{
	typedef TreeNode<W> Node;
	//�º���
	struct WLess
	{
		bool operator()(const Node* left, const Node* right)
		{
			return left->_w < right->_w;
		}
	};
public:
	HuffmanTree():_root(NULL){}
	void CreatTree(W*arr, size_t size,const W &invalue)
	{
		//����һ��С��
		Heap<Node*, WLess>WTree;
		for (size_t i = 0; i < size; ++i)
		{
			if (arr[i] != invalue)
			{
				WTree.Push(new Node(arr[i]));
			}
		}
		//������������
		while (WTree.Size()>1)
		{
			Node*left = WTree.Top();
			WTree.Pop();
			Node*right = WTree.Top();
			WTree.Pop();
			Node*parent = new Node(W(left->_w + right->_w));
			parent->_left = left;
			left->_parent = parent;
			parent->_right = right;
			right->_parent = parent;
			WTree.Push(parent);
		}
		_root = WTree.Top();
	}
	//��ø��ڵ�
	Node* GetRoot()
	{
		return _root;
	}
private:
	Node* _root;
};
