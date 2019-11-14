#include "divide_and_conquer.h"
#include <iostream>
#include <bitset>
#include "sort.h"
using namespace std;

/****************文件说明********************
* 文件名：divide_and_conquer.cpp
* 文件功能：分治法的典型应用
*			快速排序；归并排序；连续加法；整数乘法；矩阵连续乘法；棋盘覆盖；找到第k个最小值等


**/


/************函数说明***********
* 函数名：__int64 IntegerMultiplyDec(int x, int y, int n)
* 函数参数：两个相乘的整数，n为最大正整数的位数
* 函数返回值：两个整数的乘积
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

/************函数说明***********
* 函数名：void CoverChessBoard(int row_left, int column_left, int row_special, int column_special, int size)
* 函数参数：棋盘左上角的行列坐标，特殊格的行列坐标，棋盘尺寸
* 函数返回值：空
* 函数功能：实现棋盘覆盖
* 问题描述：
在一个2^k×2^k （k≥0）个方格组成的棋盘中，恰有一个方格与其他方格不同，称该方格为特殊方格。
显然，特殊方格在棋盘中可能出现的位置有4^k种，因而有4^k种不同的棋盘，
棋盘覆盖问题（chess cover problem）要求用4种不同形状的L型骨牌覆盖给定棋盘上除特殊方格以外的所有方格，且任何2个L型骨牌不得重叠覆盖。
* 函数算法：分治法
			将棋盘不断减小，直到最后一个
			1、确定递归结束条件为当前尺寸为1；
			2、判断特殊格位置
				（1）如果在左上角，继续递归，不在左上角，将该1/4棋盘的右下角填充为特殊格再递归；
				（2）如果在右上角，继续递归，否则填充该1/4棋盘的左下角填充为特殊格再递归；
				（3）如果在左下角，继续递归，否则填充该1/4棋盘的右上角为特殊格再递归；
				（4）如果在右下角，继续递归，否则填充该1/4棋盘的左上角为特殊格再递归。
			3、给特殊格填上标记，用了一个全局变量和一个局部变量，保证每一次递归返回后上一次值不变
* 时间复杂度：if k > 0:
				T(k) = 4T(k-1) + O(1)  
			else
				T(k) = O(1);
			所以：T(n) = O(4^k)
**/


int chess[8][8];

int number = 1;
void CoverChessBoard(int row_left, int column_left, int row_special, int column_special, int size)
{
	int tie = number++;

	int row_center = row_left + size / 2, column_center = column_left + size / 2;
	// 递归结束条件
	if (size == 1)
	{
		return;
	}
	// 先判断特殊方块的位置
	// 左上角
	if (row_special < row_center && column_special < column_center)  
	{		
		CoverChessBoard(row_left, column_left, row_special, column_special, size / 2);  // 开始递归
	}
	else  
	{
		chess[row_center - 1][column_center - 1] = tie;  // 给右下角填上
		CoverChessBoard(row_left, column_left, row_center-1, column_center - 1, size / 2);  // 开始递归
		// 进行到这一步了
	}
	// 右上角
	if (row_special < row_center && column_special >= column_center)  
	{
		CoverChessBoard(row_left, (column_left + size)/2, row_special, column_special, size / 2);  // 开始递归
	}
	else
	{
		chess[row_center-1][column_center] = tie;  // 左下角填充
		CoverChessBoard(row_left, column_center, row_center-1, column_center, size / 2);
	}
	// 左下角
	if (row_special >= row_center && column_special < column_center)  
	{
		CoverChessBoard((row_left + size)/2, column_left, row_special, column_special, size / 2);  // 开始递归
	}
	else
	{
		chess[row_center][column_center - 1] = tie;  // 右上角填上
		CoverChessBoard(row_center, column_left, row_center, column_center - 1, size / 2);

	}
	// 右下角
	if (row_special >= row_center && column_special >= column_center)  
	{		
		CoverChessBoard(row_center, column_center, row_special, column_special, size / 2);  // 开始递归
	}
	else
	{
		chess[row_center][column_center] = tie;  // 左上角填上
		CoverChessBoard(row_center, column_center, row_center, column_center, size / 2);
	}
}
/**********函数说明************
* 函数名：main（）
* 函数参数：无
* 函数返回值：0
* 函数功能：测试棋盘覆盖函数
* 使用说明：仅当测试棋盘覆盖时取消注释，测试完成后重新注释

int main()
{
	int row = 2, column = 2;  // 表示特殊方格的行列坐标

	chess[row][column] = 0;
	CoverChessBoard(0, 0, row, column, 8);
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << chess[i][j] <<"\t";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}
**/

/**************函数说明**********************
* 函数名：int FindKthElement(int* arr, int start, int end, int k)
* 函数参数：arr：一个数组；start：数组查找范围内起始元素的索引；
			end：数组查找范围内结束元素的索引；k：数组查找范围之内的第k个最小值
* 函数返回值：输入数组有效查找范围之内的第k个最小值
* 函数功能：查找输入数组有效查找范围之内的第k个最小值并返回
* 函数算法：利用快排的思想
			1、如果分区关键元素正好是第k个元素，返回该元素；
			2、如果分区关键元素比第k个元素大，即第k个元素在关键元素的左边，对左边递归查找；
			3、否则在后边递归查找。
* 注意：1、输入参数k的范围；
		2、索引与排序的序号区别；
		3、如果start不为0，要排除掉前start个元素的影响（语句：if (index -  start == k - 1) ），否则会掉入死循环。
* 时间复杂度：O(nlogn) 最差情况下O(n^2)

**/

int FindKthElement(int* arr, int start, int end, int k)
{
	static int len = end - start + 1; // 计算长度，保障k有效
	try 
	{
		if (start == end)
			return arr[start];
		if (!k || k > len)  // k必须在数组有效范围内
			throw "The parameter k must be a positive integer in range of ";
		// 分区
		int index = Partition(arr, start, end);  // Partition返回的是在整个数组中的该元素的索引
		
		if (index -  start == k - 1)  // 第k个数的索引是k-1，如果不是从0开始查找的，要减去start再与k-1比较
			return arr[index];
		else if (index > k - 1)
		{
			FindKthElement(arr, start, index - 1, k);  // 对分区的左边进行查找
		}
		else
		{
			FindKthElement(arr, index + 1, end, k);  // 对分区的右边进行查找
		}
	}
	catch (const char *e)
	{
		cerr << e << "[ 1, " << end - start + 1 << "]." << endl;
	}
	catch (...)
	{
		cerr << "Function FindKthElement Error!!!" <<endl;
	}
	

}

