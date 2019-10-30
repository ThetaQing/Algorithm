/*
*******************文件描述**********************************

* 文件名：modular_exponention.cpp
* 实现功能：求一个数的幂对另一个数的模运算，也称为模取幂

* 主要算法：反复平方法

* 算法主要原理：

*/
#include <bitset>
using std::bitset;
int ModularExponention(int a, int b, int n)
{
	int c = 0;
	int d = 1;
	bitset<sizeof(int) * 8>binary_b(b);  // binary_b是b的二进制表示，长度是sizeof(int)*8
	for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		c = 2*c;
		d = (d * d) % n;
		if (binary_b[i] == 1)
		{
			c += 1;
			d = (d * a) % n;
		}
	}
	return d;
}