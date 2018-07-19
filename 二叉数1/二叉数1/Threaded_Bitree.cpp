#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
enum Flag
{
	pointer,
	childNode
};
template<class T>
struct TreeNode
{
	TreeNode(T _data) :data(_data), left(NULL),
	right(NULL), rightflag(childNode), leftflag(childNode)
	{}
	TreeNode<T>*left;
	TreeNode<T>*right;
	T data;
	Flag leftflag;
	Flag rightflag;
};
template<class T>
class BiTree
{
	typedef	TreeNode<T> Node;
public:
	BiTree() :pRoot(NULL)
	{
	}
	BiTree(T*array, size_t size, const T&invalid)
	{
		size_t index = 0;
		Creat(pRoot, array, size, invalid, index);
	}
private:
	void Creat(Node*&root, T*array, size_t size, const T&invalid, size_t &index
		)
	{
		if (index<size&&array[index] != invalid)
		{
			root = new Node(array[index]);
			Creat(root->left, array, size, invalid, ++index);
			Creat(root->right, array, size, invalid, ++index);
		}
	}
public:
	//前序遍历
	void Preorder()
	{
		_Preorder(pRoot);
		cout << endl;
	}
	//前序线索化遍历
	void threaded_play()
	{
		Node*pcur = pRoot;
		while (pcur)
		{
			cout << pcur->data << " ";
			if (pcur->leftflag !=	 pointer)
				pcur = pcur->left;
			else
				pcur = pcur->right;
		}
	}
	void Inorderr()
	{
		_Inorderr(pRoot);
		cout << endl;
	}
private:
	void _Preorder(Node*root)
	{
		if (root)
		{
			cout << root->data << " ";
			_Preorder(root->left);
			_Preorder(root->right);
		}
	}
	void _Inorderr(Node*root)
	{
		if (root)
		{
			_Inorderr(root->left);
			cout << root->data << " ";
			_Inorderr(root->right);
		}
	}
public:
	//前序递归线索化
	void Per_threaded_tree()
	{
		Node*prev = NULL;
		_Per_threaded_tree(pRoot,prev);
	}
	void _Per_threaded_tree(Node*root,Node*&prev)
	{
		if (root)
		{
			if (root->left == NULL)
			{
				root->leftflag = pointer;
				root->left = prev;
			}
			if (prev&&prev->right == NULL)
			{
				prev->rightflag = pointer;
				prev->right = root;
			}
			prev =root;
			if (root->leftflag == childNode)
				_Per_threaded_tree(root->left, prev);
			if (root->rightflag==childNode)
				_Per_threaded_tree(root->right,prev);
		}
	}
	//前序非递归线索化
	void Per_threaded_tree2()
	{
		Node*pcur = pRoot;
		Node*prev = NULL;
		stack<Node*>s1;
		while (!s1.empty() || pcur)
		{
			while (pcur)
			{

				s1.push(pcur);
				if (prev&&prev->right == NULL)
				{
					prev->right = pcur;
					prev->rightflag = pointer;
				}
				prev = pcur;
				if (pcur->left == NULL)
				{
					pcur->left = prev;
					pcur->leftflag = pointer;
				}
				if (pcur->leftflag == childNode)
					pcur = pcur->left;
				else
					pcur = NULL;
			}
			pcur = s1.top();
			if (pcur->rightflag == childNode)
			{
				pcur = pcur->right;
			}
			else
				pcur = NULL;
			s1.pop();
		}
	}

	//中序非递归线索化
	void Inorder_thread2()
	{
		Node*pcur = pRoot;
		Node*prev = NULL;
		stack<Node*>s1;
		while (pcur||!s1.empty())
		{
			while (pcur)
			{
				s1.push(pcur);
				pcur = pcur->left;
			}
			pcur = s1.top();
			if (pcur->left == NULL)
			{
				pcur->leftflag = pointer;
				pcur->left = prev;
			}
			if (prev&&prev->right == NULL)
			{
				prev->rightflag = pointer;
				prev->right = pcur;
			}
			prev = pcur;
			pcur= pcur->right;
			s1.pop();
		}
	}
	//中序递归线索化
	void Inorder_thread()
	{
		Node*prev = NULL;
		_Inorder_thread(pRoot, prev);
		cout << endl;
		
	}
	//中序线索化遍历
	void Inorder_thread_dispaly()
	{
		Node*pcur = pRoot;
		Node*prev = NULL;
		while (pcur)
		{
			while (pcur->leftflag == childNode)
			{
				pcur = pcur->left;
			}
			cout << pcur->data << " ";
			//如果当前结点没有右子树，就遍历该结点，否则遍历该右子树的左子树的结点
			while (pcur->rightflag == pointer)
			{
				pcur = pcur->right;
				cout << pcur->data << " ";	
			} 
			pcur = pcur->right;
		}
		cout << endl;
	}
	//中序递归线索化
	void _Inorder_thread(Node*root, Node*&prev)
	{
		if (root)
		{
			_Inorder_thread(root->left, prev);
			if (root->left == NULL)
			{
				root->leftflag = pointer;
				root->left = prev;
			}	
			if (prev&&prev->right == NULL)
			{
				prev->right = root;
				prev->rightflag = pointer;
			}
			prev = root;
			_Inorder_thread(root->right, prev);
		}
	}
	//后序递归遍历
	void Posorder()
	{
		_Posorder(pRoot);
		cout << endl;
	}
	//后序递归线索化
	void Posorder_thread()
	{
		Node*prev = NULL;
		_Posorder_thread(pRoot, prev);
		
	}
	//后序线索化遍历
	void Posorder_thread_display()
	{
		Node*pcur = pRoot;
		Node*prev = NULL;
		while ()
		{
			while (pcur->leftflag != pointer)
			{
				pcur = pcur->left;
			}

		}
	}
private:
	void _Posorder(Node* root)
	{
		if (root)
		{
			_Posorder(root->left);
			_Posorder(root->right);
			cout << root->data << " ";
		}
	}
	void _Posorder_thread(Node*root,Node*&prev)
	{
		if (root)
		{
			_Posorder_thread(root->left, prev);
			_Posorder_thread(root->right, prev);
			if (root->left == NULL)
			{
				root->leftflag = pointer;
				root->left = prev;
			}
			if (prev&&prev->right == NULL)
			{
				prev->rightflag = pointer;
				prev->right = root;
			}
			prev = root;
		}
	}
	Node* pRoot;
};
#if 0
int main()
{
	char array[] = "ABCD##E##F##GMN###Q##";
	BiTree<char>t1(array, strlen(array), '#');
	//t1.Preorder();
	//t1.Per_threaded_tree();
	//t1.Per_threaded_tree2();
	//t1.threaded_play();
	t1.Inorderr();
	t1.Inorder_thread();
	//t1.Inorder_thread2();
	t1.Inorder_thread_dispaly();
	//t1.Posorder();
	//t1.Posorder_thread();
	return 0;
}
#endif

