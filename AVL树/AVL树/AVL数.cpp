#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(K key, V valaue) 
		:_key(key), _valaue(valaue), 
		right(NULL), left(NULL),
		parent(NULL), bf(0)
	{
	}
	AVLTreeNode<K, V>* left;
	AVLTreeNode<K, V>* right;
	AVLTreeNode<K, V>* parent;
	K _key;
	V _valaue;
	int bf;
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V>  Node;
public:
	AVLTree() :_root(NULL){}
	AVLTree(int *array, int size)
	{
		int i = 0;
		for (i = 0; i < size; ++i)
		{
			insert(array[i], i);
		}
	}
	bool insert(K key,V valaue)
	{
		if (_root == NULL)
		{
			_root = new Node(key, valaue);
		}
		else
		{
			//寻找插入位置
			Node*pcur = _root;
			Node*pparent = NULL;
			while (pcur)
			{
				pparent = pcur;
				if (pcur->_key<key)
				{
					pcur = pcur->right;
				}
				else if (pcur->_key>key)
				{
					pcur = pcur->left;
				}
				else
					return false;
			}
			pcur = new Node(key, valaue);
			//新结点的双亲指向pparent
			pcur->parent = pparent;
			//插入结点
			if (pparent->_key < key)
			{
				pparent->right = pcur;
			/*	pparent->bf++;*/
			}
			else
			{
				pparent->left = pcur;
				/*pparent->bf--;*/
			}
			while (pparent)
			{
				//判断平衡树是否失去平衡调节平衡因子
				if (pparent->left == pcur)
					pparent->bf--;
				else
					pparent->bf++;
				if (pparent->bf == 0)
				{
					break;
				}
				//如果高度增加1或减少1看看他的双亲有没有失去平衡
				else if (pparent->bf == 1 || pparent->bf == -1)
				{
					pcur = pparent;
					pparent = pparent->parent;
					//if (pparent->left == pcur)
					//	pparent->bf--;
					//else
					//	pparent->bf++;
				}
				else
				{
					if (pparent->bf == 2)
					{
						if (pcur->bf == 1)
							TstateLL(pparent);
						else
							TstateRL(pparent);
					}
					else
					{
						if (pcur->bf == -1) 
							TstateRR(pparent);
						else
							TstateLR(pparent);
					}
					break;
				}
			}
		}
		return true;
	}
	//判断AVL数是否平衡
	bool judgeAVLTree()
	{
		return _judgeAVLTree(_root);
	}
	//删除AVL树的一个结点
	void Delete(K key)
	{
		if (_root == NULL)
			return;
		else
		{
			Node*parent = NULL;
			Node*pcur = _root;
			while (pcur)
			{
				
				if (pcur->_key == key)
				{
					//如果右子存在
					if (pcur->right)
					{
						Node*del = pcur->right;
						while (del->left)
						{
							del = del->left;
						}
						swap(del->_key, pcur->_key);
						swap(del->_valaue, pcur->_valaue);
						parent = del->parent;
						if (parent->left == del)
						{
							parent->left = del->right;
							parent->bf++;
						}
						else
						{
							parent->right = del->right;
							parent->bf--;
						}
						if (del->right)
							del->right->parent = parent;
						delete del;
						del = NULL;
					}
					//如果右子树不存在
					else
					{
						//如果改结点是根节点
						if (pcur == _root)
						{
							_root = pcur->left;
							if (_root)
								_root->parent = NULL;
							delete pcur;
							return;
						}
						else
						{
							parent = pcur->parent;
							if (parent->left == pcur)
							{
								parent->bf++;
								parent->left = pcur->left;
							}
							else
							{
								parent->bf--;
								parent->right = pcur->left;
							}
							if (pcur->left)
								pcur->left->parent = parent;
							delete pcur;
							pcur = NULL;
						}
					}
					//调整平衡因子
					while (parent)
					{
						//删除后结点高度没有变，不用继续调节
						if (parent->bf == -1 || parent->bf == 1)
							return;
						//删除节点后高度降低了
						else if (parent->bf == 0)
						{
							pcur = parent;
							parent = pcur->parent;
							if (parent)
							{
								//左子树高度降低了
								if (parent->left == pcur)
									parent->bf++;
								//右子树高度降低了
								else
									parent->bf--;
							}
							else
								return;
						}
						else
						{
							Node*pparent = parent->parent;
							Node*subR = NULL;
							Node*subL = NULL;
							int parentbf = parent->bf;
							int tempbf = 0;
							if (parent->bf == 2)
							{
								subR = parent->right;
								tempbf = parent->right->bf;
								if (parent->right->bf != -1)
									TstateLL(parent);
								else
								{
									TstateLR(parent->right);
									TstateLL(parent);
								}
							}
							else
							{
								subL = parent->left;
								tempbf = parent->left->bf;
								if (parent->left->bf != 1)
									TstateRR(parent);
								else
								{
									TstateRL(parent->left);
									TstateRR(parent);
								}
							}
							if (tempbf == 0)
							{
								if (parentbf == 2)
								{
									parent->bf = 1;
									subR->bf = -1;
								}
								else
								{
									parent->bf = -1;
									subL->bf = 1;
								}
								return;
							}
							else
							{
								parent->bf = 0;
								if (subL)
									subL->bf = 0;
								else
									subR->bf = 0;
								if (pparent)
								{
									if (pparent->left == parent)
										pparent->bf++;
									else
										pparent->bf--;
								}
							}
							parent = pparent;
						}
					}
					break;
				}
				else if (pcur->_key < key)
					pcur = pcur->right;
				else
					pcur = pcur->left;
			}
		}
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	void Perorder()
	{
		_Perorder(_root);
		cout << endl;
	}
private:
	void _Inorder(Node*root)
	{
		if (root)
		{
			_Inorder(root->left);
			cout << root->_key << " ";
			_Inorder(root->right);
		}
	}
	void _Perorder(Node*root)
	{
		if (root)
		{
			cout << root->_key << " ";
			_Perorder(root->left);
			_Perorder(root->right);
		}
	}
	bool  _judgeAVLTree(Node*root)
	{
		if (root == NULL)
			return true;
		else
		{
			int lefthigh = high(root->left);
			int righthigh = high(root->right);
			if (abs(lefthigh - righthigh) > 1)
				return false;
			else
				return _judgeAVLTree(root->left) && _judgeAVLTree(root->right);
		}
	}
	int high(Node*root)
	{
		if (root == NULL)
			return 0;
		else
		{
			int left = high(root->left);
			int right = high(root->right);
			return left > right ? left + 1 : right + 1;
		}
	}
	//左单旋
	void TstateLL(Node*parent)
	{
		Node*subR = parent->right;
		Node*subRL = subR->left;
		Node*pparent = parent->parent;
		subR->left = parent;
		parent->parent = subR;
		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;
		if (parent == _root)
		{
			_root = subR;
			_root->parent = NULL;
		}
		else
		{
			if (pparent->left == parent)
				pparent->left = subR;
			else
				pparent->right = subR;
			subR->parent = pparent;
		}
		
		parent->bf = 0;
		subR->bf = 0;
	}
	//右单旋
	void TstateRR(Node*parent)
	{
		Node*subL = parent->left;
		Node*subLR = subL->right;
		Node*pparent = parent->parent;
		subL->right = parent;
		parent->parent = subL;
		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;
		if (parent == _root)
		{
			_root = subL;
			_root->parent = NULL;
		}
		else
		{
			if (pparent->left == parent)
				pparent->left = subL;
			else
				pparent->right = subL;
			subL->parent = pparent;
		}
		parent->bf = 0;
		subL->bf = 0;
	}
	void TstateRL(Node*parent)
	{
		Node*subR = parent->right;
		Node*subRL = subR->left;
		int bf = subRL->bf;
		TstateRR(subR);
		TstateLL(parent);
		if (bf == 1)
			parent->bf = -1;
		else if (bf==-1)
			subR->bf = 1;
	}
	void TstateLR(Node*parent)
	{
		Node*subL = parent->left;
		Node*subLR = subL->right;
		int bf = subLR->bf;
		TstateLL(subL);
		TstateRR(parent);
		if (bf == 1)
			subL->bf = -1;
		else if (bf==-1)
			parent->bf = 1;
	}
	Node*_root;
};
//int main()
//{
////	srand((size_t)time(NULL));
////	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
////	int array1[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
////	int arr[1000] = { 1, 4, 5, 3, 7, 15, 14, 16, 2, 4, 14, 1, 5, 2, 0, 0, 0, 0};
////	AVLTree<int, int> bt(array,sizeof(array)/sizeof(array[0]));
////	//bt.Perorder();
////	//bt.Inorder();
////	//if (bt.judgeAVLTree())
////	//	cout << "the bt is AVLTree" << endl;
////	//else
////	//	cout << "the bt isn't AVLTree " <<  endl;
////	//bt.Delete(26);
////	//bt.Delete(11);
////	//bt.Perorder();
////	//bt.Inorder();
////	//if (bt.judgeAVLTree())
////	//	cout << "the bt is AVLTree" << endl;
////	//else
////	//	cout << "the bt isn't AVLTree " << endl;
////	//bt.Delete(3);
////	//bt.Delete(9);
////	//bt.Delete(7);
////	//bt.Delete(16);	
////	//bt.Delete(15);
////	//bt.Delete(14);
////	//bt.Delete(18);
////	//bt.Perorder();
////	//bt.Inorder();
////int len = sizeof(array) / sizeof(array[0]);
//	int i = 0;
//	AVLTree<int, int> bt;
//	while (i<11)
//	{
//		bt.insert( rand() % 100,i++);
//		assert(bt.judgeAVLTree());
//	}
//		bt.Perorder();
//		bt.Inorder();
//	//i = 0;
//	//while (i<1000)
//	//{
//	//	int k = rand() % 5000;
//	//	bt.Delete(k);
//	//	assert(bt.judgeAVLTree());
//	//	i++;
//	//}
//	//bt.judgeAVLTree();
//	//AVLTree<int, int> bt1(array1, sizeof(array1) / sizeof(array1[0]));
//	//if (bt1.judgeAVLTree())
//	//	cout << "the bt1 is AVLTree" << endl;
//	//else
//	//	cout << "the bt1 isn't AVLTree " << endl;
// //   i = 0;
//	//int k = 0;
//	//len = sizeof(array1) / sizeof(array1[0]);
//	//while(i<1000)
//	//{
//	//	int k = rand() % len;
//	////	arr[i] = array1[k];
//	//	bt1.Delete(arr[i]);
//	//	if (!bt1.judgeAVLTree())
//	//		getchar()
//
//	//	i++;
//	//}
//	//assert(bt1.judgeAVLTree());
//	//if (bt1.judgeAVLTree())
//	//	cout << "the bt1 is AVLTree" << endl;
//	//else
//	//	cout << "the bt1 isn't AVLTree " << endl;
//	//bt1.judgeAVLTree();
//	//bt1.Perorder();
//	//bt1.Inorder();
//
//	return 0;
//}
//		