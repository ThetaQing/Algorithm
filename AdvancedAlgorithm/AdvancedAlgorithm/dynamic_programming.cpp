#include <iostream>
#include "dynamic_programming.h"
using namespace std;

/****************文件说明********************
* 文件名：dynamic_programming.cpp
* 文件功能：动态规划的典型应用
*			爬楼梯


**/
/***************函数说明**************
* 函数名：int climbStairs(int n) 
* 函数参数：0~45范围内的正整数 n
* 函数返回值：爬楼梯的方法总数
* 问题描述：70.假设你正在爬楼梯，需要 n 阶你才能到达楼顶。

			每次你可以爬 1 或 2 个台阶，你有多少种不同的方法可以爬到楼顶呢？

* 函数算法：
			1、递归算法（即暴力法）
				第n级楼梯有两种方法到达，一种是从第n-1级台阶往上爬1个台阶；另一种是从第n-2级台阶往上爬2个台阶。
				所以f(n) = f(n - 1) + f(n - 2)
				时间复杂度：O(2^n)，树形递归的大小为2^n
				空间复杂度：O(n)，数的深度可以达到n。
			2、斐波那契数
				必须找出以1和2作为第一项和第二项的斐波那契数的第n个数。
				时间复杂度：O(n)，单循环到n，需要计算第n个斐波那契数
				空间复杂度：O(1)，使用常量空间。

----------------------------------------------------------------------------------
----------以下是参考https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/
			3、动态规划
				这个问题可以被分解为一些包含最优子结构的子问题，即它的最优解可以从其子问题的最优解来有效地构建，我们可以使用动态规划来解决这一问题。
				第 i 阶可以由以下两种方法得到：
				在第 (i-1)阶后向上爬一阶。
				在第 (i-2)(阶后向上爬 2 阶。
				所以到达第 i 阶的方法总数就是到第 (i-1)阶和第 (i-2) 阶的方法数之和。
				令 dp[i] 表示能到达第 i 阶的方法总数：
				dp[i]=dp[i-1]+dp[i-2]
				
				即：将每一步的结果存储在数组中，每当函数再次调用时，直接从数组中返回结果
				时间复杂度：O(n)
				空间复杂度：O(n)

* 注意：

* 其他资源：
**/
int climbStairs(int n) 
{

	if (n <= 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return climbStairs(n - 1) + climbStairs(n - 2);

}

int climbStairs2(int n)
{	
	if (n <= 1)
		return 1;
	else if (n == 2)
		return 2;

	int path = 0;
	int f1 = 1, f2 = 2;
	int cur = 3;
	while (cur<=n)
	{
		path = f1 + f2;
		cur += 1;  // 下一级台阶
		f1 = f2;
		f2 = path;
	}
	return path;

}

int climbStairs3(int n)
{
	if (n <= 1)
		return 1;
	else if (n == 2)
		return 2;
	int* memo = new int[n+1];
	
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	int total=1;
	int cur = 3;
	while (cur <= n)
	{
		memo[cur] = memo[cur - 1] + memo[cur - 2];
		cur += 1;  // 下一级台阶
		
	}
	total = memo[n];
	delete[] memo;;
	return total;

}
