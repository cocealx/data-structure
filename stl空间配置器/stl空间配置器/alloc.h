#include<iostream>
using namespace std;
enum{_ALIGN=8};//区块的划分边界，如果为4空间利用率不高，分配时还需要一部分负载去管理
enum{_MAX_BYTES=128};//小内存分配的界限
enum{ _NFREELISTS = _MAX_BYTES = 128 / _ALIGN = 8 };//free_list的个数

//inst可能是设计者保留的参数，便于以后扩展
template<int inst>
class _default_alloc_template{
private:
	union obj{
		union obj*free_list_next;//构造结点用于链接链表
		char client_data[1];
	};
private:
	static char*start;
	static char*end;
	static obj*free_list[_NFREELISTS];
};
//初始化类内的静态成员
template<int inst>
_default_alloc_template<inst>::start = NULL;
template<int inst>
_default_alloc_template<inst>::end = NULL; 
template<int inst>

