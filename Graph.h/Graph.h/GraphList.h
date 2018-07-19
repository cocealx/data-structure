#pragma once
#include<vector>
#include<assert.h>
using namespace std;
template<class W>
struct Node
{
	Node(const size_t _start, const size_t _end, const W&w)
	:weight(w), start(_start), end(_end), next(NULL)
	{

	}
	Node*next;
	size_t start;
	size_t end;
	W weight;
};
template<class V, class W, bool Isdirection = true>
class graphlist
{
public:
	graphlist(const V* &_array, size_t size) :elenet(_array, _array + size)
	{
		arraylist.resize(size);
	}
	void add(const V&v1, const V&v2, const W&weight)
	{
		size_t index1 = GetIndex(v1);
		size_t index2 = GetIndex(v2);
		Node*pcur = arraylist[index1];
		while (pcur)
		{
			if (pcur->end == index2)
				return;
			pcur = pcur->next;
		}
		Node*node = new Node(index1, index2, weight);
		node->next = arraylist[index1];
		arraylist[index1] = node;
		if (Isdirection)
		{
			Node*node = new Node(index2, index1, weight);
			node->next = arraylist[index2];
			arraylist[index2] = node;
		}
	}
	size_t  degree(const V&v)
	{
		size_t index1 = GetIndex(v);
		size_t size = elenet.size();
		size_t count = 0;
		Node*pcur = NULL;
		if (Isdirection)
		{
			for (size_t i = 0; i < size; ++i)
			{
				pcur = arraylist[i];
				while (pcur)
				{
					if (pcur->start == index1 || pcur->end == index1)
					{
						++count;
					}
					pcur = pcur->next;
				}
			}
		}
		else
		{
			pcur = arraylist[index1];
				while (pcur)
				{
					if (pcur->start == index1 || pcur->end == index1)
					{
						++count;
					}
					pcur = pcur->next;
				}
		}
		return count;
	}
private:
	size_t GetIndex(const V&v)
	{
		size_t size = elenet.size();
		for (size_t i = 0; i < size; ++i)
		{
			if (elenet[i] == v)
				return i;
		}
		cout << "v isn't error" << endl;
		assert(0);
		return 0;
	}
	typedef Node<W> Node;
	vector<V>elenet;
	vector<Node*>arraylist;
};