/*
*******************文件描述**********************************

* 文件名：GREATEST_COMMON_DIVISION.cpp
* 实现功能：求解两个正整数m，n的最大公约数
* 算法主要原理：两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。
* 主要算法：欧几里得算法、连续整数检测算法、公共质因数相乘法

*/

/*
**********函数说明*************
* 函数名称：GcdEuclid(int m, int n)
* 函数参数：m、n为输入两个正整数
* 函数返回值：返回m和n的最大公约数

* 算法思想：欧几里得算法：
	第一步：如果n=0，返回m的值作为结果，结束；否则进入第二步
	第二步：用n去除m，将余数赋值给r；
	第三步：将n的值赋值给m，将r的值赋值给n，返回第一步。
* 算法实现：
	递归实现：GcdEuclidRecursion(m,n)
	非递归实现：GcdEuclid(m,n)
* 时间复杂度：
	因为每经过一遍第二步，即每调用一次gcd函数，其中必有一个数减少一半以上（因为余数不可能大于被除数）
	所以时间复杂度为	O(lgn)
*/

#include <algorithm>
#include "greatest_common_division.h"
#include "primality_check.h"
#include <vector>
using namespace std;

// 递归实现
int GcdEuclidRecursion(int m, int n)
{
	return (!n ? m : GcdEuclidRecursion(n, m % n));  // 判断n是否为0，不为0，则递归调用，辗转相除
}
// 非递归实现
int GcdEuclid(int m, int n)
{
	int r;
	while (n)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

/*
**********函数说明*************
* 函数名称：GcdContinuousIntegerTest(int m, int n)
* 函数参数：m、n为输入两个正整数
* 函数返回值：返回m和n的最大公约数

* 算法思想：连续整数检验法
	第一步：将min{m,n}的值赋给t
	第二步：m除以t，如果余数为0，则进入第三步；否则，进入第四步；
	第三步：n除以t，如果余数为0，则返回t值作为结果；否则，进入第四步；
	第四步：把t的值减1，返回第二步。
* 算法实现：
	
	非递归实现：gcd_continuous_integer_test(m,n)
* 时间复杂度：
	考虑最坏的情况是公约数为1，循环做了t-1次，最好的情况是只做一次
	所以时间复杂度为	O(n) = n/2
*/

int GcdContinuousIntegerTest(int m, int n)
{
	int temp = std::min(m, n);
	while (m % temp || n % temp)  // 第一个操作数将完全计算，只有当第一个操作数的计算结果为0时才计算第二个操作数。满足算法要求
	{
		temp -= 1;
	}
	return temp;
}

/*
**********函数说明*************
* 函数名称：GcdCommonPrimeFactors(int m, int n)
* 函数参数：m、n为输入两个正整数
* 函数返回值：返回m和n的最大公约数

* 算法思想：公共质因数相除法
	第一步：找到m的所有质因数；
	第二步：找到n的所有质因数；
	第三步：从第一步到第二步中求得的质因数分解式找出所有的公因数；
	第四步：将第三步中找的质因数相乘，其结果作为给定数字的最大公因数。

* 算法实现：

	非递归实现：GcdCommonPrimeFactors(m,n)
* 时间复杂度：
	O(n*(logn)^3)
	
*/
int GcdCommonPrimeFactors(int m, int n)
{
	int result = 1;

	std::vector<int> prime_m, prime_n;

	// 对m进行质因数分解
	// 如果m是质数，m = 1 * m
	if (MilleRabin(m))
		prime_m.push_back(m);
	else
	{
		for (int temp = m, prime = 2; temp > 1; )
		{
			if (temp % prime)  // 如果prime不是temp的因式，prime + 1
				prime += 1;

			else if (MilleRabin(prime))
			{
				temp = temp / prime;  // 如果prime是temp的因式，更新temp
				prime_m.push_back(prime);  // 如果prime是质数，添加进质因数列表
			}
			else
				prime += 1;  // 如果是因数但又不是质数，更新prime
		}
	}

	// 对n进行质因数分解
	// 如果n是质数，n = 1 * n
	if (MilleRabin(n))
		prime_n.push_back(n);
	else
	{
		for (int temp = n, prime = 2; temp > 1; )
		{
			if (temp % prime)  // 如果prime不是temp的因式，prime + 1
				prime += 1;

			else if (MilleRabin(prime))
			{
				temp = temp / prime;  // 如果prime是temp的因式，更新temp
				prime_n.push_back(prime);  // 如果prime是质数，添加进质因数列表
			}
			else
				prime += 1;  // 如果是因数但又不是质数，更新prime
		}
	}

	while (!prime_m.empty() && !prime_n.empty())
	{
		if (prime_m[0] == prime_n[0])
		{
			result = result * prime_m[0];// 如果相等，相乘
			prime_m.erase(prime_m.begin());  // 清楚
			prime_n.erase(prime_n.begin());
		}
		else if (prime_m[0] < prime_n[0])  // 移除小的那个因数
		{
			prime_m.erase(prime_m.begin());  
		}
		else
			prime_n.erase(prime_n.begin());
	}
	

	
	
	return result;
}



