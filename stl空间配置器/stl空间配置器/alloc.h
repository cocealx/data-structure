#include<iostream>
using namespace std;
enum{_ALIGN=8};//����Ļ��ֱ߽磬���Ϊ4�ռ������ʲ��ߣ�����ʱ����Ҫһ���ָ���ȥ����
enum{_MAX_BYTES=128};//С�ڴ����Ľ���
enum{ _NFREELISTS = _MAX_BYTES = 128 / _ALIGN = 8 };//free_list�ĸ���

//inst����������߱����Ĳ����������Ժ���չ
template<int inst>
class _default_alloc_template{
private:
	union obj{
		union obj*free_list_next;//������������������
		char client_data[1];
	};
private:
	static char*start;
	static char*end;
	static obj*free_list[_NFREELISTS];
};
//��ʼ�����ڵľ�̬��Ա
template<int inst>
_default_alloc_template<inst>::start = NULL;
template<int inst>
_default_alloc_template<inst>::end = NULL; 
template<int inst>

