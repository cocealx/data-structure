#pragma once
class  BKDRHash1
{
public:
	size_t operator()(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..  
			// 有人说将乘法分解为位运算及加减法可以提高效率，如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;  
			// 但其实在Intel平台上，CPU内部对二者的处理效率都是差不多的，  
			// 我分别进行了100亿次的上述两种运算，发现二者时间差距基本为0（如果是Debug版，分解成位运算后的耗时还要高1/3）；  
			// 在ARM这类RISC系统上没有测试过，由于ARM内部使用Booth's Algorithm来模拟32位整数乘法运算，它的效率与乘数有关：  
			// 当乘数8-31位都为1或0时，需要1个时钟周期  
			// 当乘数16-31位都为1或0时，需要2个时钟周期  
			// 当乘数24-31位都为1或0时，需要3个时钟周期  
			// 否则，需要4个时钟周期  
			// 因此，虽然我没有实际测试，但是我依然认为二者效率上差别不大          
		}
		return hash;
	}
};
class  BKDRHash2
{
public:
	size_t operator()(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}
		return hash;
	}
};
class  BKDRHash3
{
public:
	size_t operator()(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}
		return hash;
	}
};
class  BKDRHash4
{
public:
	size_t operator()(const char *str)
	{
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; ch = (size_t)*str++; i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};
class  BKDRHash5
{
public:
	size_t operator()(const char *str)
	{
		if (!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
			return 0;
		register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
			hash ^= ((hash << 5) + ch + (hash >> 2));
		}
		return hash;
	}
};