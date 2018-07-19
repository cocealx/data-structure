#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;
template<class T>
struct TreeNode
{
	TreeNode() :_data(0), left(NULL), right(NULL)
	{

	}
	TreeNode(const char & data) :_data(data), left(NULL), right(NULL)
	{

	}
	T _data;
	TreeNode<T>*left;
	TreeNode<T>*right;
};
template<class T>
class Tree
{
public:
	typedef  TreeNode<T>* pTreeNode;
	typedef  TreeNode<T> TreeNode;
	Tree()
	{
		*_root = NULL;
	}
	Tree(pTreeNode* root=NULL)
	{
		CreatTree(&_root);
	}
	//前序遍历
	void Preorder()
	{
		_Preorder(_root);
		cout << endl;
	}
	//非递归前序
	void  Non_Perorder()
	{
		stack<TreeNode*>s1;
		TreeNode*root = _root;
		while (!s1.empty() || root != NULL)
		{
			while (root)
			{
				cout << root->_data << " ";
				s1.push(root);
				root = root->left;
			}
			root = s1.top();
			s1.pop();
			root = root->right;
		}
	}

	//中序
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	//非递归中序
	void Non_Inorder()
	{
		stack<TreeNode*>s1;
		TreeNode*root = _root;
		while (!s1.empty() || root != NULL)
		{
			while (root)
			{
				s1.push(root);
				root = root->left;
			}
			root = s1.top();
			cout << root->_data << " ";
			s1.pop();
			root = root->right;
		}
	}
	//后序遍历
	void Postorder()
	{
		_Postorder(_root);
		cout << endl;
	}
	//非递归后序遍历
	void Non_Postorder()
	{
		TreeNode*root = _root;
		TreeNode*father = NULL;
		stack<TreeNode*>s1;
		while (!s1.empty() || root != NULL)
		{
			while (root)
			{
				s1.push(root);
				root = root->left;
			}
			root = s1.top();
			if (root->right == NULL || root->right == father)
			{
				cout << root->_data << " ";
				father = root;
				root = NULL;
				s1.pop();
			}
			else
			{
				root = root->right;
			}
		}
	}
	//求树的结点
	size_t TreeLeaf()
	{
		return  _TreeLeaf(_root);
	}
	//求叶结点
	size_t LeafNode()
	{
		return _LeafNode(_root);
	}
	//求第K层的结点个数
	size_t KNode(size_t k)
	{
		return _KNode(_root, k);
	}
	//求树的深度
	size_t Depth()
	{
		return _Depth(_root);
	}
	//层序化
	void _sequence()
	{
		sequence(_root);
	}

private:
	void CreatTree(pTreeNode*root)
	{
		char ch;
		ch = getchar();
		if (ch == '.')
		{
			return;
			*root = NULL;
		}
		else
		{
			*root = new TreeNode(ch);
			CreatTree(&((*root)->left));
			CreatTree(&((*root)->right));
		}
	}
	void _Preorder(pTreeNode root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_Preorder(root->left);
		_Preorder(root->right);
	}
	void _Inorder(pTreeNode treenode)
	{
		if (treenode == NULL)
			return;
		_Inorder(treenode->left);
		cout << treenode->_data << " ";
		_Inorder(treenode->right);
	}
	void _Postorder(pTreeNode root)
	{
		if (root == NULL)
			return;
		_Postorder(root->left);
		_Postorder(root->right);
		cout << root->_data << "  ";
	}
	size_t _TreeLeaf(TreeNode*root)
	{
		if (root == NULL)
			return 0;
		return 1 + _TreeLeaf(root->left) + _TreeLeaf(root->right);
	}
	size_t _LeafNode(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		if (root->left == NULL&&root->right == NULL)
			return 1;
		return _LeafNode(root->left) + _LeafNode(root->right);
	}
	size_t _KNode(TreeNode*root, size_t k)
	{
		if (k == 0 || root == NULL)
			return 0;
		if (k == 1)
			return 1;
		else
		{
			return  _KNode(root->left, k - 1) + _KNode(root->right, k - 1);
		}
	}
	size_t _Depth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		size_t Sumleft = 1 + _Depth(root->left);
		size_t Sumright = 1 + _Depth(root->right);
		return  Sumleft > Sumright ? Sumleft : Sumright;
	}
	//层序化
	void sequence(TreeNode* root)
	{
		assert(root);
		queue<TreeNode*>que;
		que.push(root);
		TreeNode*cur = NULL;
		while (!que.empty())
		{
			cur = que.front();
			cout << cur->_data << " ";
			que.pop();
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
	}
	TreeNode* _root;
};
void meau()
{

}
//int main()
//{
//	//TreeNode<char>*_root = NULL;
//	Tree<char>tree(0);
//	tree.Preorder();
//	tree.Non_Perorder();
//	cout << endl;
//	tree.Inorder();
//	//cout << endl;
//	tree.Non_Inorder();
//	cout << endl;
//	tree.Postorder();
//	cout << endl;
//	tree.Non_Postorder();
//	cout << endl;
//	/*cout << tree.TreeLeaf() << endl;
//	cout << tree.LeafNode() << endl;
//	cout << tree.KNode(2) << endl;
//	cout << tree.Depth() << endl;*/
//	cout << endl;
//	tree._sequence();
//	return 0;
//}