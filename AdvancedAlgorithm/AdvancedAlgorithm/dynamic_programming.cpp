#include <iostream>
#include <vector>
#include <algorithm>
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
			1、递归算法（超时）
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

* 备注：1、2、3分别对应三个函数
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
/*****************函数说明*******************
* 函数名：int rob(vector<int>& nums)
* 函数参数：一个整型数组
* 函数返回值：能打劫到的最大金额
* 问题描述：
	198. 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

	给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/house-robber
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

* 实现算法：动态规划
		1、我的思路：
			在第i个房子时，有两个选择
				一个是偷这个房子，那么此时的收益为nums[i]+f(i-2),其中nums[i]表示这个房子的金额，f(i-2)表示第i-2的房子时已有的金额；
				另一种是不偷这个房子，那么此时的收益为f(i-1)，保持第i-1个房子时的金额。
			所以总结公式就是
				f(i) = max(nums[i]+f(i-2), f(i-1));
			用一个数组存储并计算结果。
		2、官方思路：
			从最简单地开始，记f(k)表示从前k个房子中能打劫到的最大数额，nums[i]表示当前第i个房子的金额数
			首先看 n = 1 的情况，显然f(1) = nums[1];
			再看 n = 2 的情况，f(2) = max(nums[1], nums[2]);
			对于 n = 3，有两个选择：
				1） 抢第三个房子，将数额与第一个房子相加；
				2)  不抢第三个房子，保持现有最大数额。
			显然，选择数额更大的选项，所以
				f(i) = max(nums[i]+f(i-2), f(i-1));
			由于每一步只需要前两个最大值，两个变量就够了。
		3、对比
			官方思路更简单清晰，从最简单的开始！！！
			
* 测试信息：
执行用时 :4 ms, 在所有 cpp 提交中击败了70.15%的用户
内存消耗 :8.6 MB, 在所有 cpp 提交中击败了75.47%的用户
**/
int rob(vector<int>& nums) {
	int n = nums.size();  // 输入房子个数
	int* price =  new int[ n];
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	int index = 2;
	price[0] = nums[0];
	price[1] = max(nums[1],nums[0]);  // 如果只有两个房子，选择最大的
	while (index < n)
	{
		price[index] = max(nums[index] + price[index - 2], price[index - 1]);  // 选择偷与不偷第i个房子的公式
		index += 1;
	}
	index = price[n - 1];  // 最后一个房子的金额就是总金额
	delete[] price;
	return index;
}
/*输出不对
int rob2(vector<int>& nums) {
	int n = nums.size();
	
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	int index = 2;
	int curTotal = nums[1];  // 第i-1个房子时总金额
	int preTotal = nums[0];  // 第i-2个房子时总金额
	int maxTotal = max(curTotal, preTotal);  // 第i个房子时的总金额
	while (index < n)
	{
		maxTotal = max(curTotal, preTotal + nums[index]);
		preTotal = curTotal;
		curTotal = maxTotal; 		
		index += 1;
	}
	
	return maxTotal;
}
*/
