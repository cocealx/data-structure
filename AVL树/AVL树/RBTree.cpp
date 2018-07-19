#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
using namespace std;
enum Color
{
	red,
	black
};
template<class K, class V>
struct RBTreeNode
{
	typedef RBTreeNode<K, V> Node;
	RBTreeNode(K key, V value)
		:_key(key), _value(value),
		_color(red), left(NULL),
		right(NULL), parent(NULL)
	{

	}
	Node*left;
	Node*right;
	Node*parent;
	K _key;
	V _value;
	Color _color;
};
template<class K, class V,class Ref,class Ptr>
class MyIterator
{
	typedef MyIterator<K, V, Ref, Ptr> self;
	typedef RBTreeNode<K, V> Node;
public:
	MyIterator(Node*node) :_node(node)
	{

	}
	self& operator++()
	{
		increase();
		return *this;
	}
	self operator++(int)
	{
		self temp(*this);
		increase();
		return temp;
	}
	self& operator--()
	{
		decrease();
		return *this;
	}
	self operator--(int)
	{
		self temp(*this);
		decrease();
		return temp;
	}
	Node*operator->()
	{
		return _node;
	}
	K operator*()
	{
		return _node->_key;
	}
	bool operator!=(const self& t1)const
	{
		return _node != t1._node;
	}
	bool operator==(const self& t1)const
	{
		return _node == t1._node;
	}
private:
	void increase()
	{
		if (_node->right)
		{
			_node = _node->right;
			while (_node->left)
			{
				_node = _node->left;
			}
		}
		else
		{
			Node*pcur = _node;
			Node*parent = pcur->parent;
			while (pcur == parent->right)
			{
				pcur = parent;
				parent = pcur->parent;
			}
			if (pcur->right != parent)
				pcur = parent;
			_node = pcur;
		}
	}
	void decrease()
	{
		if (_node == _node->parent->parent&&_node->_color==red)
		{
			_node = _node->right;
		}
		else if (_node->left)
		{
			_node = _node->left;
			while (_node->right)
			{
				_node = _node->right;
			}
		}
		else
		{
			Node*pcur = _node;
			Node*parent = pcur->parent;
			while (parent->left==pcur)
			{
				pcur = parent;
				parent = pcur->parent;
			}
			if (pcur->left != parent)
				pcur = parent;
			_node = parent;
		}
	}
	Node*_node;	
};

template<class K,class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;
	typedef MyIterator<K, V, K&, K*> Iterator;
	typedef MyIterator<K, V, const K&, const K*> Const_Iterator;
	RBTree() :_phead(new Node(K(),V()))
	{
		_phead->left = _phead->right = _phead;
	}
	RBTree(K*array, int size) :_phead(new Node(K(), V()))
	{
		_phead->left = _phead->right = _phead;
		int i = 0;
		for (i = 0; i < size; ++i)
		{
			insert(array[i], i);
		}
	}
	bool insert(K key,V value)
	{
		Node*&root = _phead->parent;
		//如果是空树
		if (!root)
		{
			root = new Node(key, value);
			root->parent = _phead;
		}
		else
		{
			Node*pcur = root;
			Node*parent = NULL;
			//寻找结点的插入位置
			while (pcur)
			{
				parent = pcur;
				if (pcur->_key == key)
					return false;
				else if (pcur->_key < key)
					pcur = pcur->right;
				else
					pcur = pcur->left;
			}
			pcur = new Node(key, value);
			if ( parent->_key>key)
			{
				parent->left = pcur;
			}
			else
			{
				parent->right = pcur;
			}
			pcur->parent = parent;
			//调节红黑树
			while (pcur != root&&parent->_color == red)
			{
				Node*grandfather = parent->parent;
				Node*unclk = NULL;
				//如果在祖父结点的左边
				if (grandfather->left == parent)
				{
					unclk = grandfather->right;
					//情况三
					if (unclk&&unclk->_color == red)
					{
						parent->_color = black;
						unclk->_color = black;
						grandfather->_color = red;
						pcur = grandfather;
						parent = pcur->parent;
					}
					//情况四和五
					else
					{
						//情况五,把情况五转化为情况四
						if (pcur == parent->right)
						{
							TstateLL(parent);
							swap(pcur, parent);
						}
						//情况四
						parent->_color = black;
						grandfather->_color = red;
						TstateRR(grandfather);
						break;
					}
				}
				//如果在祖父节点右半边
				else
				{
					unclk = grandfather->left;
					//情况三
					if (unclk&&unclk->_color == red)
					{
						unclk->_color = black;
						parent->_color = black;
						grandfather->_color = red;
						pcur = grandfather;
						parent = pcur->parent;
					}
					//情况四和五
					else
					{
						//情况五，把情况五转为为情况四
						if (pcur == parent->left)
						{
							TstateRR(parent);
							swap(pcur, parent);
						}
						//情况四
						grandfather->_color = red;
						parent->_color = black;
						TstateLL(grandfather);
						break;
					}
				}
			}		
		}
		//如果根结点是红色的，把根结点颜色设置为黑色
		root->_color = black;
		//调节头节点左右结点的指向
		_phead->left = Getmin();
		_phead->right = Getmax();
		return true;
	}
	bool checkRBTree()
	{
		Node*root = _phead->parent;
		if (root == NULL)
			return true;
		if (root->_color == red)
		{
			cout << "违反了性质2" << endl;
			return false;
		}
		int k = 0;
		while (root)
		{
			if (root->_color == black)
				++k;
			root = root->left;
		}
		if (_check(_phead->parent, 0, k))
			return true;	
		else
			return false;
	}
	/////////////迭代器///////////////////////
	Iterator Begin()
	{
		return _phead->left;
	}
	Iterator End()
	{
		return _phead;
	}
	Const_Iterator Begin()const 
	{
		return _phead->left;
	}
	Const_Iterator End()const
	{
		return _phead ;
	}
private:
	Node*Getmin()
	{
		Node*root = _phead->parent;
		if (root == NULL)
		{
			_phead->left = _phead;
			_phead->right = _phead;
		}
		else
		{
			while (root->left)
			{
				root = root->left;
			}
		}
		return root;
	}
	Node*Getmax()
	{
		Node*root = _phead->parent;
		if (root == NULL)
		{
			_phead->left = _phead;
			_phead->right = _phead;
		}
		else
		{
			while (root->right)
			{
				root = root->right;
			}
		}
		return root;
	}
	bool _check(Node*pcur, int number, int k)
	{
		if (pcur == NULL)
			return true;
		else
		{
			Node*parent = pcur->parent;
			if (pcur->_color == red&&parent->_color == red)
			{
				cout << "违反了性质3" << endl;
				return false;
			}
		}
		if (pcur->_color == black)
			++number;
		if (pcur->left == NULL&&pcur->right == NULL)
		{
			if (k == number)
				return true;
			else
			{
				cout << "违反性质性质四" << endl;
				return false;
			}
		}
		else
			return _check(pcur->left, number, k) && _check(pcur->right, number, k);
	}
	void TstateLL(Node*parent)
	{
		Node*&root = _phead->parent;
		Node*subR = parent->right;
		Node*subRL = subR->left;
		Node*pparent = parent->parent;
		subR->left = parent;
		parent->parent = subR;
		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;
		if (parent == root)
		{
			root = subR;
			subR->parent = _phead;
		}
		else
		{
			if (pparent->left == parent)
				pparent->left = subR;
			else
				pparent->right = subR;
			subR->parent = pparent;
		}
	}
	void TstateRR(Node*parent)
	{
		Node*&root = _phead->parent;
		Node*subL = parent->left;
		Node*subLR = subL->right;
		Node*pparent = parent->parent;
		subL->right = parent;
		parent->parent = subL;
		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;
		if (parent == root)
		{
			root = subL;
			subL->parent = _phead;
		}
		else
		{
			if (pparent->left == parent)
				pparent->left = subL;
			else
				pparent->right = subL;
			subL->parent = pparent;
		}
	}
	Node*_phead;
};
//int main()
//{
//	int a[] = { 10, 7, 8, 15, 5, 6, 11, 13, 12 };
//	RBTree<int, int>bt1(a, sizeof(a)/sizeof(a[0]));
//	if (bt1.checkRBTree())
//		cout << "是红黑树" << endl;
//	////////////////迭代器加加测试////////////////
//	RBTree<int, int>::Iterator t1 = bt1.Begin();
//	while (t1!=bt1.End())
//	{
//		cout << *t1 << " ";
//		++t1;
//	}
//	cout << endl;
//	///////////////////////迭代器减减操作////////////
//	t1 = bt1.End();
//	while (t1!=bt1.Begin())
//	{
//		--t1;
//		cout << *t1 << " ";
//	}
//	cout << endl;
//	//////////////大量随机数测试////////////////
//	RBTree<int, int>bt2;
//	int k = 1000;
//	int left = -1;
//	//////////////插入测试////////
//	while (k--)
//	{
//		bt2.insert(rand() % 500, k);
//		if (!bt2.checkRBTree())
//			getchar();
//	}
//	/////////////迭代器的加加测试////////
//	t1 = bt2.Begin();
//	while (t1 != bt2.End())
//	{
//		assert(left < *t1);
//		left = *t1;
//		/*cout << *t1 << "  ";*/
//		++t1;
//	}
//	cout << endl;
//	///////////////////////迭代器减减操作////////////
//	int right = 1000;
//	t1 = bt2.End();
//	while (t1 != bt2.Begin())
//	{
//		--t1;
//		assert(right > *t1);
//		right = *t1;
//		/*cout << *t1 << "  ";*/
//	}
//	cout << endl;
//  	return 0;
//}