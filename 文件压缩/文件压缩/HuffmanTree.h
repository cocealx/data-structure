#pragma once
#include"Heap.h"
template<class T>
struct TreeNode
{
	
	TreeNode(const T& w) :_w(w), _left(NULL), _right(NULL),_parent(NULL){}
	//左子树
	TreeNode<T>*_left;
	//右子树
	TreeNode<T>*_right;
	//双亲结点
	TreeNode<T>*_parent;
	//权值
	T _w;

};
template<class W>
class HuffmanTree
{
	typedef TreeNode<W> Node;
	//仿函数
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
		//创建一个小堆
		Heap<Node*, WLess>WTree;
		for (size_t i = 0; i < size; ++i)
		{
			if (arr[i] != invalue)
			{
				WTree.Push(new Node(arr[i]));
			}
		}
		//创建哈夫曼树
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
	//获得根节点
	Node* GetRoot()
	{
		return _root;
	}
private:
	Node* _root;
};
