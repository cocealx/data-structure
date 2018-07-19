#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
using  namespace  std;
template<class K, class	V>
struct BiTreeNode
{
	BiTreeNode(K key, V value) :_value(value), _key(key), left(NULL), right(NULL), pParent(NULL){}
	BiTreeNode* left;
	BiTreeNode* right;
	BiTreeNode*pParent;
	K _key;
	V _value;
};
template<class K,class V,class Ref,class Ptr>
class MYIterator
{
	typedef BiTreeNode<K, V>  Node;
	typedef MYIterator<K, V,Ref,Ptr> self;
public:
	MYIterator() :_node(NULL){}
	MYIterator(Node*node,Node*phead) :_node(node),_phead(phead){}
	MYIterator(const self&it)
	{
		_node = it._node;
	}
	self& operator++()
	{
		Increase();
		return *this;
	}
	self operator++(int)
	{
		self temp(*this);
		Increase();
		return temp;
	}
	self& operator--()
	{
		Decrease();
		return *this;
	}
	self operator--(int)
	{
		self temp(*this);
		Decrease();
		return temp;
	}
	bool operator!=(const self&it)
	{
		return _node!= it._node;
	}
	Node operator->()
	{
		return _node;
	}
	K operator*()
	{
		return _node->_key;
	}
private:
	void Increase()
	{
		assert(_node);
		Node*pcur = _node;
		if (pcur->right)
		{
			pcur = pcur->right;
			while (pcur->left)
			{
				pcur = pcur->left;
			}
			_node = pcur;
		}
		else
		{
			Node*pparent = pcur->pParent;
			while (pcur==pparent->right)
			{
				pcur = pparent;
				pparent = pcur->pParent;
			}
		/*	if (pparent != node)*/if (pcur->right!=pparent)
				pcur = pparent;
			_node = pcur;
		}
	}
	void Decrease()
	{
		assert(_node);
		if (_node == _phead)
		{
			_node =  _phead->right;
			return;
		}
		if (_node->left)
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
			Node*pparent = _node->pParent;
			while (pcur == pparent->left)
			{
				pcur = pparent;
				pparent = pcur->pParent;
			}
			pcur = pparent;
			_node = pcur;
		}
	}
	Node*_node;
	Node*_phead;
};


template<class K, class V>
class  BiSortTree
{
	typedef BiTreeNode<K, V> Node;
public:
	typedef MYIterator< K, V, K&, K*> Iterator;
	typedef MYIterator< const K, const V, const K&, const K*> Const_Iterator;
	//迭代器
	Iterator Begin()
	{
		return Iterator(_phead->left,_phead);
	}
	Const_Iterator Begin()const
	{
		return Const_Iterator(_phead->left,_phead);
	}
	Iterator End()
	{
		return Iterator(_phead,_phead);
	}
	Const_Iterator End()const
	{
		return Const_Iterator(_phead,_phead);
	}
	//
	BiSortTree() :_phead(new Node(0, 0))
	{
	}
	BiSortTree(K* array, int size) :_phead(new Node(0,0))
	{
		int i = 0;
		_phead->left = _phead;
		_phead->right = _phead;
		for (int i = 0; i < size; ++i)
		{
			Insert(array[i], i);
		}
	}

	bool Insert(K key, V value)
	{
		Node*newnode = new Node(key,value);
		if (_phead->pParent == NULL)
		{
			_phead->pParent = newnode;
			newnode->pParent = _phead;
		}
		else
		{
			Node*pparent = NULL;
			Node*pcur = _phead->pParent;
			while (pcur)
			{
				pparent = pcur;
				if (pcur->_key == key)
					return false;
				else if (pcur->_key > key)
					pcur = pcur->left;
				else
					pcur = pcur->right;
			}
			if (key < pparent->_key)
			{
				pparent->left = newnode;
				newnode->pParent = pparent;
			}
			else
			{
				pparent->right = newnode;
				newnode->pParent = pparent;
			}
		}
		_phead->left = GetMinNode();
		_phead->right = GetMaxNode();
		return true;
	}

	void Inorder()
	{
		assert(_phead);
		_Inorder(_phead->pParent);
		cout << endl;
	}
	V Find(K key)
	{
		return _Find(key, _root);
	}
	void Rdelete(K key)
	{
		assert(_phead);
		//_Rdelete(NULL, _root,key);
		_RRdelete(_phead->pParent, key);
	}
	//转换为双向链表
	Node* reform_Two_list()
	{
		Node*prev = NULL;
		Node*phead = _phead->pParent;
		if (phead)
		{
			while (phead->left)
			{
				phead = phead->left;
			}
			_reform_Two_list(prev, _phead->pParent);
		}
		return phead;
	}
private:

	Node*GetMinNode()
	{
		Node*pcur = _phead->pParent;
		if (pcur == NULL)
			return _phead;
		while (pcur->left)
		{
			pcur = pcur->left;
		}
		return pcur;
	}
	Node*GetMaxNode()
	{
		Node*pcur = _phead->pParent;
		if (pcur == NULL)
			return _phead;
		while (pcur->right)
		{
			pcur = pcur->right;
		}
		return pcur;
	}
	//转换为双向链表
	void _reform_Two_list(Node*&prev, Node*pcur)
	{
		if (pcur == NULL)
			return;
		_reform_Two_list(prev, pcur->left);
		Node*right = pcur->right;
		pcur->left = prev;
		if (prev)
			prev->right = pcur;
		prev = pcur;
		_reform_Two_list(prev, right);
	}
	//递归删除某个结点
	void _Rdelete(Node*pparent, Node*pcur, K key)
	{
		if (pcur == NULL)
			return;
		if (pcur->_key == key)
		{
			if (pcur->right)
			{
				pparent = pcur;
				Node*tmp = pcur;
				pcur = pcur->right;
				while (pcur->left)
				{
					pparent = pcur;
					pcur = pcur->left;
				}
				swap(tmp->_key, pcur->_key);
				swap(tmp->_value, pcur->_value);
				if (pparent->left == pcur)
				{
					pparent->left = pcur->right;
				}
				else
				{
					pparent->right = pcur->right;
				}
			}
			else
			{
				if (pparent == NULL)
					_root = pcur->left;
				else
				{
					if (pparent->left == pcur)
					{
						pparent->left = pcur->left;
					}
					else
					{
						pparent->right = pcur->left;
					}
				}

			}
			delete pcur;
		}
		else
		{
			if (pcur->_key<key)
				_Rdelete(pcur, pcur->left, key);
			else
				_Rdelete(pcur, pcur->right, key);

		}
	}
	void _RRdelete(Node*&pcur, K key)
	{
		Node*del = NULL;
		if (pcur == NULL)
			return;
		else
		{
			if (pcur->_key == key)
			{
				//判断有没有右子树
				if (pcur->right)
				{
					//保存当前结点的右子树
					del = pcur->right;
					Node*pparent = pcur;
					//如果当前结点的右子树没有左子树，就删除该节点
					if (del->left == NULL)
					{
						swap(pcur->_key, del->_key);
						swap(pcur->_value, del->_value);
						pcur->right = del->right;
						if (del->right)
							del->right->pParent = pcur;
					}
					//否则找最左边的
					else
					{
						while (del->left)
						{
							pparent = del;
							del = del->left;
						}
						if (pparent->left == del)
						{
							pparent->left = del->right;
						}
						else
						{
							pparent->right = del->right;
						}
						if (del->right)
							del->right->pParent = pparent;
						swap(pcur->_key, del->_key);
						swap(pcur->_value, del->_value);
					}
				}
				//如果他没有右子树
				else
				{
					del = pcur;
					if (pcur->left)
						pcur->left->pParent = pcur->pParent;
					pcur = pcur->left;
				}
				delete del;
				_phead->left = GetMinNode();
				_phead->right = GetMaxNode();
			}
			else if (pcur->_key>key)
				_RRdelete(pcur->left, key);
			else
				_RRdelete(pcur->right, key);
		}
	}
	void _Inorder(Node*root)
	{
		if (root)
		{
			_Inorder(root->left);
			cout << root->_key << "->";
			_Inorder(root->right);
		}
	}
	bool _Find(K key, Node*root)
	{
		if (root)
		{
			if (root->_key == key)
				return true;
			if (root->_key<key)
				_Find(root->left, key);
			else
				_Find(root->right, key);
		}
		return false;
	}
	Node*_phead;
};
int main()
{
	int arr[10] = { 5, 3, 2, 8, 1, 4, 7, 6, 9, 10 };
	srand((size_t)time(NULL));
	BiSortTree<int, int>bt(arr, 10);
	/*
	//bt.Inorder();
	//bt.Insert(11,11);
	//bt.Inorder();
	//bt.Delete(11);
	//bt.Inorder();	
	//bt.Delete(5);
	//bt.Inorder();
	//bt.Delete(1);
	//bt.Inorder();
	//bt.Delete(6);
	//bt.Inorder();
	bt.Inorder();
	bt.Insert(11, 11);
	bt.Inorder();
	bt.Rdelete(11);
	bt.Inorder();
	bt.Rdelete(5);
	bt.Inorder();
	bt.Rdelete(1);
	bt.Inorder();
	bt.Rdelete(6);
	bt.Inorder();
	bt.Rdelete(1);
	bt.Rdelete(2);
	bt.Rdelete(3);
	bt.Rdelete(4);
	bt.Rdelete(8);
	bt.Rdelete(9);
	bt.Rdelete(10);
	bt.Inorder();
	*/

/*	BiTreeNode<int ,int>*head = bt.reform_Two_list();
	while (head)
	{
		cout << head->_key << "->";
		head = head->right;
	}
	*/
	//bt.Rdelete(5);
	//bt.Rdelete(6);
	//bt.Rdelete(7);
	//bt.Rdelete(8);
	//bt.Rdelete(9);
	//bt.Rdelete(10);
	//bt.Rdelete(11);
	///////////////////迭代器减减测试///////////////////
	//BiSortTree<int, int>::Iterator  it = bt.Begin();
	//int k = 1000;
	//while (k--)
	//{
	//	bt.Insert(rand() % 500,k);
	//}
	//k = 1000;
	//int j=500;
	//while (k--)
	//{

	//	it = bt.End();
	//	while (it != bt.Begin())
	//	{
	//		--it;
	//		if (j < *it)
	//			getchar();
	//		j = *it;
	//	}
	//	bt.Rdelete(rand() % 500);
	//}

	////////////迭代器加加测试///////////////
	//BiSortTree<int, int>bt2;
	//BiSortTree<int, int>::Iterator  it1 = bt2.Begin();
	//k = 1000;
	//while (k--)
	//{
	//	bt2.Insert(rand() % 500, k);
	//}
	//k = 1000;
	//j = -1;
	//while (k--)
	//{
	//	it1 = bt2.Begin();
	//	while (it1 != bt2.End())
	//	{
	//		if (j > *it)
	//			getchar();
	//		++it;
	//	}
	//	bt.Rdelete(rand() % 500);
	//}
	//cout << endl;
	//////////////大量随机数测试////////////////
	BiSortTree<int, int>bt2;
	int k = 1000;
	int left = -1;
	//////////////插入测试////////
	while (k--)
	{
		bt2.Insert(rand() % 500, k);
	}
	/////////////迭代器的加加测试////////
	BiSortTree<int,int>::Iterator t1 = bt2.Begin();
	k = 501;
	while (k--)
	{
		int de = rand() % 500;
		/*cout << "删除" <<de<< endl;*/
		bt2.Rdelete(de);
		t1 = bt2.Begin();
		left = -1;
		while (t1 != bt2.End())
		{
			if (left > *t1)
				getchar();
			left = *t1;
			//cout << *t1 << "  ";
			++t1;
		}
	}
	///////////////////////迭代器减减操作////////////
	k = 1000;
	while (k--)
	{
		bt2.Insert(rand() % 500, k);
	}
	k = 501;
	while (k--)
	{
		int right = 501;
		t1 = bt2.End();
		while (t1 != bt2.Begin())
		{
			--t1;
			if (right < *t1)
				getchar();
			right = *t1;
			//cout << *t1 << "  ";
		}
		bt2.Rdelete(rand() % 500);
	}
	return 0;
}