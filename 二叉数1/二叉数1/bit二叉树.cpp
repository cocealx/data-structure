#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
template<class T>
struct BinTreeNode
{
	BinTreeNode(const T&data = T()) :_left(NULL),
	_right(NULL),
	_data(data)
	{}
	BinTreeNode<T>* _left;
	BinTreeNode<T>*_right;
	T _data;
};
template<class T>
class BinTree
{
	typedef BinTreeNode<T> Node;
	typedef BinTreeNode<T>* PNode;
public:
	BinTree()
		: _pRoot(NULL)
	{}

	BinTree(const T* array, size_t size, const T& invalid)
	{
		size_t index = 0;
		_CreateBinTree(_pRoot, array, size, index, invalid);
	}

	BinTree(const BinTree& bt)
	{
		_pRoot = _CopyBinTree(bt._pRoot);
	}

	BinTree& operator=(const BinTree& bt)
	{
		if (_pRoot != &bt)
		{
			BinTree<T>newtree(bt);
			swap(_pRoot, bt._pRoot);
		}
		return *this;
	}
	~BinTree()
	{
		_DestroyBinTree(_pRoot);
		_pRoot = NULL;
	}
	void NPeroder()
	{
		Node*cur = _pRoot;
		if (_pRoot == NULL)
			return;
		stack<Node*>s1;
		s1.push(cur);
		while (!s1.empty())
		{
			while (cur)
			{
				cout << cur->_data << " ";
				s1.push(cur->_right);
				cur = cur->_left;
			}
			cur = s1.top();
			s1.pop();

		}
	}
	void PreOrder()
	{
		_PreOrder(_pRoot);
		cout << endl;
	}
	void InOrder()
	{
		_InOrder(_pRoot);
		cout << endl;
	}
	void NIndrder()
	{
		if (_pRoot == NULL)
			return;
		Node*cur = _pRoot;
		stack<Node*>s1;
		while (!s1.empty() || cur)
		{
			while (cur)
			{
				s1.push(cur);
				cur = cur->_left;
			}
			cur = s1.top();
			s1.pop();
			cout << cur->_data << " ";
			cur = cur->_right;
		}
		cout << endl;
	}
	void PostOrder()
	{
		_PostOrder(_pRoot);
		cout << endl;
	}
	void NPosOrder()
	{
		if (_pRoot == NULL)
			return;
		Node*cur = _pRoot;
		Node*prev = NULL;
		stack<Node*>s1;
		while (!s1.empty() || cur)
		{
			while (cur&&cur != prev)
			{
				s1.push(cur);
				cur = cur->_left;
			}
			cur = s1.top();
			if (cur->_right == prev || cur->_right == NULL)
			{
				s1.pop();
				cout << cur->_data << " ";
				prev = cur;
				if (s1.empty())
				{
					break;
				}
				cur = s1.top();
				cur = cur->_right;
			}
			else
			{
				cur = cur->_right;
				prev = cur;
			}
		}
		cout << endl;
	}
	void NPosOrder1()
	{
		if (_pRoot == NULL)
			return;
		Node*cur = _pRoot;
		stack<Node*>s1;
		Node*prev = NULL;
		while (!s1.empty() || cur)
		{
			while (cur)
			{
				s1.push(cur);
				cur = cur->_left;
			}
			cur = s1.top();
			if (cur->_right == NULL || cur->_right == prev)
			{
				cout << cur->_data << " ";
				s1.pop();
				prev = cur;
				//cur必须要制空，避免cur重复走上面的while循环
				cur = NULL;
			}
			else
			{
				cur = cur->_right;
			}
		}
	}
	void LevelOrder()
	{
		queue<Node*>Letree;
		if (_pRoot == NULL)
			return;
		Letree.push(_pRoot);
		while (!Letree.empty())
		{
			Node*cur = Letree.front();
			cout << cur->_data << " ";
			Letree.pop();
			if (cur->_left)
				Letree.push(cur->_left);
			if (cur->_right)
				Letree.push(cur->_right);
		}
		cout << endl;
	}
	size_t Size()
	{
		return _Size(_pRoot);
	}
	size_t GetLeefCount()
	{
		return _GetLeefCount(_pRoot);
	}
	// 获取第K层结点的个数 
	size_t GetKLevelCount(size_t K)
	{
		return _GetKLevelCount(_pRoot, K);
	}
	size_t Height()
	{
		return _Height(_pRoot);
	}
	PNode Find(const T& data)
	{
		return _Find(data);
	}
	PNode Parent(PNode pNode)
	{
		if (pNode == _pRoot)
			return NULL;
		return _Parent(pNode);
	}
	//根据序列创建树
	void CreatTree(char * Prestr,char*InOstr,int len)
	{
		if (_pRoot)
			_DestroyBinTree(_pRoot);
		_pRoot = NULL;
		_CreatTree(_pRoot,Prestr,InOstr,len);
	}
	//根据前序和中序非递归创建二叉树
	void Creat_Per_In_Tree(const T*perorder, const T*Inorder)
	{
		stack<Node*>sroot;
		stack<int>sindex;
		//不一定是字符型得，举一个特列
		sindex.push(strlen(perorder));
		//////////////////////////////
		_pRoot = new Node(*perorder);
		int index = 0;
		while (perorder[0] != Inorder[index])
		{
			++index;
		}
		sroot.push(_pRoot);
		sindex.push(index);
		++perorder;
		while (*perorder)
		{
			Node*top_root = sroot.top();
			int top_index = sindex.top();
			int left = -1;
			int index = 0;
			Node*newNode = new Node(perorder[0]);
			while (perorder[0] != Inorder[index])
			{
				++index;
			}
			if (left<top_index&&index < top_index)
			{
				top_root->_left = newNode;
				sroot.push(newNode);
				sindex.push(index);
				++perorder;
			}
			else
			{
				while (1)
				{
					sroot.pop();
					sindex.pop();
					left = top_index;
					top_index = sindex.top();
					if (index < top_index)
					{
						++perorder;
						top_root->_right = newNode;
						sroot.push(newNode);
						sindex.push(index);
						break;
					}
					top_root = sroot.top();
				}
			}
		}
	}
	PNode LeftChild(PNode pNode);
	PNode RightChild(PNode pNode);
private:
	//根据中序和后序创建树
	 void _CreatTree(PNode&root, char*&Prestr, char*InOstr,  int len)
	{
		 if (len==0)
			 return;
		// char*Pre = "ABCDEFGMNQ";
		// char*Inostr = "DCEBFANMGQ";
		 root = new Node(*Prestr);
		 int index = 0;
		 //统计左子树的长度
		 while (InOstr[index] != *Prestr)
		 {				
			 ++index;
		 }
		 //处理前序的下一个结点
		 ++Prestr;

		 _CreatTree(root->_left, Prestr, InOstr, index);
		 //把右子树当成根节点，更新他的中序遍历串，继续构造他的左子树和右子树，
		 _CreatTree(root->_right, Prestr, InOstr+index+1, len-index-1);
	}
	 int find(char *InOstr, char data)
	 {
		 int i = 0;
		 for (; InOstr[i]; ++i)
		 {
			 if (InOstr[i] == data)
				 return i;
		 } 
		 cout << "find()出错" << endl;
	 }
	// 创建树 根+左子树+右子树 
	void _CreateBinTree(PNode& pRoot, const T* array, size_t size, size_t& index, const T& invalid)
	{
		if (index < size&&array[index] != invalid)
		{
			pRoot = new Node(array[index++]);
			_CreateBinTree(pRoot->_left, array, size, index, invalid);
			_CreateBinTree(pRoot->_right, array, size, index, invalid);
		}
		else
		{
			++index;
		}
	}
	//拷贝树
	PNode _CopyBinTree(PNode pRoot)
	{
		if (pRoot == NULL)
			return NULL;
		Node*pnew = new Node(pRoot->_data);
		pnew->_left = _CopyBinTree(pRoot->_left);
		pnew->_right = _CopyBinTree(pRoot->_right);
		return pnew;


	}
	//销毁树
	void _DestroyBinTree(PNode pRoot)
	{
		if (pRoot)
		{
			return;
		}
		if (pRoot->_left == NULL&&pRoot->_right == NULL)
		{
			delete pRoot;
			return;
		}
		_DestroyBinTree(pRoot->_left);
		_DestroyBinTree(pRoot->_right);
		delete pRoot;
	}
	// 递归前序遍历 根--->根的左子树---->根的右子树 
	void _PreOrder(PNode& pRoot)
	{
		if (!pRoot)
			return;
		cout << pRoot->_data << " ";
		_PreOrder(pRoot->_left);
		_PreOrder(pRoot->_right);
	}
	// 递归中序遍历左子树--->根节点--->右子树 
	void _InOrder(PNode pRoot)
	{
		if (!pRoot)
			return;
		_InOrder(pRoot->_left);
		cout << pRoot->_data << " ";
		_InOrder(pRoot->_right);
	}
	// 递归后序遍历左子树--->右子树--->根节点 
	void _PostOrder(PNode root)
	{
		if (!root)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}
	//求树的结点
	size_t _Size(PNode pRoot)
	{
		if (!pRoot)
			return 0;
		if (!pRoot->_left&&!pRoot->_right)
			return 1;
		return 1 + _Size(pRoot->_left) + _Size(pRoot->_right);
	}
	//求树的叶结点
	size_t _GetLeefCount(PNode pRoot)
	{
		if (!pRoot)
			return 0;
		if (!pRoot->_left&&!pRoot->_right)
			return 1;
		return _GetLeefCount(pRoot->_left) + _GetLeefCount(pRoot->_right);
	}
	//求树的高度
	size_t _Height(PNode pRoot)
	{
		if (!pRoot)
			return 0;
		size_t leftHeight = _Height(pRoot->_left);
		size_t rightHeight = _Height(pRoot->_right);
		return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
	}
	//查找一个数据
	PNode _Find(PNode pRoot, const T& data)
	{
		if (!pRoot)
			return NULL;
		if (pRoot->_data == data)
			return pRoot;
		Node*ret = NULL;
		ret = _Find(pRoot->_left, data)
		if (ret)
			return ret;
		ret = _Find(pRoot->_right, data);
		return ret;
	}
	//求第K层的结点
	size_t  _GetKLevelCount(PNode root, size_t k)
	{
		if (root == NULL||k==0)
			return 0;
		if (k == 1 && root)
			return 1;
		return  _GetKLevelCount(root->_left, k - 1) + _GetKLevelCount(root->_right, k - 1);
	}
	//查找一个节点的双亲节点
	PNode _Parent(PNode pRoot, PNode pNode)
	{
		if (!pRoot)
			return NULL;
		if (pRoot->_left == pNode || pRoot->_right == PNode)
			return pRoot;
		Node* ret = _Parent(pRoot->_left);
		if (ret)
			return ret;
		_Parent(pRoot->_right);
		return ret;
	}

private:
	PNode _pRoot;
};
int test()
{
	int i = 1;
	int sum = 0;
	while ( i <= 10)
	{
		if (i % 2 == 0)
			sum += i;
		++i;
	}
	return sum;
}
int main()
{
	BinTree <char>bt1;
	bt1.Creat_Per_In_Tree("ABCDEXFGMNQ", "DCXEBFANMGQ");
	bt1.PreOrder();
	bt1.InOrder();
	bt1.LevelOrder();
	return 0;
}
#if 0
int main()
{
	char array[] = "ABCD##E##F##GMN###Q##";
	BinTree<char>btree(array, strlen(array), '#');
	BinTree<char>bt1(btree);
	bt1.PreOrder();
	btree.PreOrder();
	bt1.NPeroder();
	cout << endl;
	bt1.InOrder();
	cout << endl;
	bt1.PostOrder();
	bt1.NPosOrder();
	bt1.NPosOrder1();
	bt1.LevelOrder();
	char*Pre = "ABCDEFGMNQ";
	char*Inostr = "DCEBFANMGQ";
	bt1.CreatTree(Pre, Inostr, strlen(Pre));
	cout << "树的高度：" << bt1.Height() << endl;
	cout << "树的结点：" << bt1.Size() << endl;
	cout << "树的叶结点：" << bt1.GetLeefCount() << endl;

	cout << "树第K层的结点数：" << bt1.GetKLevelCount(3) << endl;
	cout << test() << endl;
	return 0;
}
#endif
