
#include "fibonacci.h"
#include <vector>
using namespace std;
/*****************w文件描述**********************
* 文件名：fibonacci.cpp
* 文件功能：实现斐波那契数列
* 主要原理：
	if n =0, fib(n) = 0;
	if n = 1, fib(n) = 1;
	if n > 1, fib(n) = fib(n-1) + fib(n-2).
* 主要实现方法：递归实现、非递归实现
*/

/*****************函数说明****************
* 函数名：FibRecursion(n)
* 函数参数：无符号整型，正整数
* 函数返回值：无符号整型，正整数
* 函数功能：求斐波那契数列的第n个数
* 实现方法：递归实现
* 时间复杂度分析：解二阶齐次差分方程T(N) = T(N-1) + T(N-2)
	O(2^(N/2))<=T(N)<=O(2^N)


*/

unsigned int FibRecursion(unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		
		return FibRecursion(n - 1) + FibRecursion(n - 2);
	}
}

/*****************函数说明****************
* 函数名：FibArray(n)
* 函数参数：无符号整型，正整数
* 函数返回值：无符号整型，正整数
* 函数功能：求斐波那契数列的第n个数
* 实现方法：非递归实现，由于直接用公式存在大量的重复计算，所以将这些中间结果直接存储起来后调用
* 时间复杂度分析：O(n)


*/

unsigned int FibArray(unsigned int n)
{
	vector<unsigned int> temp;
	temp.push_back(0);
	temp.push_back(1);
	for (int i = 2; i < n + 1; ++i)
	{
		temp.push_back(temp[i - 1] + temp[i - 2]);
	}
	return temp[n];
}



/*****************函数说明****************
* 函数名：Fib(n)
* 函数参数：无符号整型，正整数
* 函数返回值：无符号整型，正整数
* 函数功能：求斐波那契数列的第n个数
* 实现方法：非递归实现
* 时间复杂度分析：O(n)


*/

unsigned int Fib(unsigned int n)
{
	unsigned int f1 = 0;
	unsigned int f2 = 1;
	unsigned int result = 0;
	if (n == 0)
		result = f1;
	else if (n == 1)
		result = f2;
	else
	{
		for (int i = 2; i < n + 1; ++i)
		{
			result = f1 + f2;
			f1 = f2;
			f2 = result;
		}

	}
	return result;
}


