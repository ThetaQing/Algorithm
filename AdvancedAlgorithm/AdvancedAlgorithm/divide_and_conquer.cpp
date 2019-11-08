#include "divide_and_conquer.h"
#include <iostream>
#include <bitset>
using namespace std;

/****************文件说明********************
* 文件名：divide_and_conquer.cpp
* 文件功能：分治法的典型应用
*			快速排序；归并排序；连续加法；整数乘法；矩阵连续乘法；棋盘覆盖等


**/


/************函数说明***********
* 函数名：__int64 IntegerMultiplyDec(int x, int y, int n)
* 函数参数：两个相乘的正整数，最大正整数的位数
* 函数返回值：两个正整数的乘积
* 函数功能：实现大整数相乘
* 函数算法：karatsuba乘法
	现有两个大数，x，y。
	首先将x，y分别拆开成为两部分，可得x1，x0，y1，y0。他们的关系如下：
	x = x1 * 10^m + x0；
	y = y1 * 10^m + y0。其中m为正整数，m < n，且x0，y0 小于 10^m。
	那么 xy = (x1 * 10^m + x0)(y1 * 10^m + y0)
	=z2 * 10^(2*m) + z1 * 10^m + z0，其中：
	z2 = x1 * y1；
	z1 = (x1 + x0) * (y1 + y0) - x1 * y1 - x0 * y0，
	z0 = x0 * y0。

* 注意：考虑到如果m是奇数，那么 m/2 + m/2 != m，所以在实现中要格外注意！！！否则就会出现多一个0~
* 时间复杂度： 每一次计算只有三次乘法，T(n) <= 3 * T(n/2) + cn;
				根据公式法有：O(n^(log3)) = O(n^1.59)
**/



__int64 IntegerMultiplyDec(int x, int y, int n)
{
	int sign_x = 1, sign_y = 1;
	__int64 sum;
	if (x < 0)
	{
		sign_x = -1;
		x = -x;  // 先把负数转为正数
	}
	if (y < 0)
	{
		sign_y = -1;
		y = -y;
	}
	sum = sign_x * sign_y;  // 先算符号位
	
	// 递归结束的条件，满足其一即可，但是一个不能少
	if (x <= 10 || y <= 10 || n <= 1)
		return sum * x * y;	
	// x_high表示x的n/2--n的高位部分，x_low表示1——n/2的低位部分
	int x_high=0, x_low=0, y_high=0, y_low=0;
	int power = pow(10, n / 2);
	x_high = x / power;
	x_low = x % power;
	y_high = y / power;
	y_low = y % power;
	__int64 x_highy_high = IntegerMultiplyDec(x_high, y_high, n / 2);
	__int64 x_lowy_low = IntegerMultiplyDec(x_low, y_low, n / 2);
	__int64 x_highx_lowy_highy_low = IntegerMultiplyDec(x_high - x_low, y_low - y_high, n / 2);
	sum = sum * (x_highy_high * int(pow(10, n/2 + n/2)) + (x_highy_high + x_lowy_low + x_highx_lowy_highy_low) * power + x_lowy_low);  // 这里注意x_highy_high * int(pow(10, n/2 + n/2))，避免n为奇数产生的误差
	return sum;
	
}
