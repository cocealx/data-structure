#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
#if 0
template<class K, class	V>
struct BiTreeNode
{
	BiTreeNode(K key, V value) :_value(value), _key(key), left(NULL), right(NULL){}
	BiTreeNode* left;
	BiTreeNode* right;
	K _key;
	V _value;
};


template<class K,class V>
class  BiSortTree
{
	typedef BiTreeNode<K, V> Node;	
public:

	
	BiSortTree() :_root(NULL)
		{
		}
		BiSortTree(V* array, int size) :_root(NULL)
		{
			int i = 0;
			for (int i = 0; i < size; ++i)
			{
				Insert(array[i], i);
			}
		}

		bool Insert(K key,V value)
		{
			Node* newnode = new Node(key, value);
			if (_root == NULL)
				_root = newnode;
			else
			{
				Node*pparent = NULL;
				Node*pcur = _root;
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
					pparent->left = newnode;
				else
					pparent->right = newnode;
			}
			return true;
		}
		void Delete(K key)
		{
			assert(_root);
			Node* del = _root;
			Node* pparent = NULL;
			stack<Node*>s1;
			while (!s1.empty()||del)
			{
				while (del)
				{
					if (del->_key == key)
						break;
					s1.push(del);
					pparent = del;
					del = del->left;
				}
				if (del)
					break;
				del = s1.top();
				s1.pop();
				del = del->right;
			}
			if (!del)
				return;
			if (!del->left)
			{
				if (del == _root)
				{
					_root = del->right;
				}
				else
				{
					if (pparent->left == del)
					{
						pparent->left = del->right;
					}
					else
					{
						pparent->right = del->right;
					}
				}
			}
			else if (!del->right)
			{
				if (del == _root)
				{
					_root = del->left;
				}
				else
				{
					if (pparent->left == del)
					{
						pparent->left = del->right;
					}
					else
					{
						pparent->right = del->right;
					}
				}
			}
			else
			{
				pparent = del;
				Node*tmp = del;
				del = del->right;
				while (del->left)
				{
					pparent = del;
					del = del->left;
				}
				if (pparent->left == del)
					pparent->left = del->right;
				else
					pparent->right = del->right;
				swap(tmp->_key, del->_key);
				swap(tmp->_value, tmp->_value);
			}
			delete del;
		}
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
		V Find(K key)
		{
			return _Find(key,_root);
		}
		void Rdelete(K key)
		{
			assert(_root);
			//_Rdelete(NULL, _root,key);
			_RRdelete(_root, key);
		}
		//转换为双向链表
		Node* reform_Two_list()
		{
			Node*prev = NULL;
			assert(_root);
			Node*phead = _root;
			while (phead->left)
			{
				phead = phead->left;
			}
		    _reform_Two_list(prev, _root);
			return phead;
		}
private:
	//转换为双向链表
	void _reform_Two_list(Node*&prev, Node*pcur)
	{
		if (pcur == NULL)
			return ;
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
				if (pcur->right)
				{
					del = pcur->right;
					Node*pparent = NULL;
					if (del->left == NULL)
					{
						swap(pcur->_key, del->_key);
						swap(pcur->_value, del->_value);
						pcur = del->right;
					}
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
						swap(pcur->_key, del->_key);
						swap(pcur->_value, del->_value);
					}			
				}
				else
				{
					del = pcur;
					pcur = pcur->left;
				}
				delete del;
			}
			else if (pcur->_key>key)
				_RRdelete(pcur->left, key);
			else
				_RRdelete( pcur->right, key);
		}
	}
	void _Inorder(Node*root)
	{
		if (root)
		{
			_Inorder(root->left);
			cout << root->_key << "->" ;
			_Inorder(root->right);
		}
	}
	V _Find(K key,Node*root)
	{
		if (root)
		{
			if (root->_key == key)
				return root->_value;
			if (root->_key<key)
				_Find(root->left, key);
			else
				_Find(root->right, key);
		}
	}
	Node* _root;  
};
int main()
{
	int arr[10] = { 5, 3, 2, 8, 1, 4, 7, 6, 9, 10 };
	BiSortTree<int, int>bt(arr, 10);
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
 /*   bt.reform_Two_list();
	BiSortTree<int, int>::Iterator it= bt.Begin();
	while (it != bt.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/
}
#endif
