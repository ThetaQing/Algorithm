#include <iostream>
#include <vector>
#include <algorithm>
#include "dynamic_programming.h"
using namespace std;

/****************�ļ�˵��********************
* �ļ�����dynamic_programming.cpp
* �ļ����ܣ���̬�滮�ĵ���Ӧ��
*			��¥��


**/
/***************����˵��**************
* ��������int climbStairs(int n) 
* ����������0~45��Χ�ڵ������� n
* ��������ֵ����¥�ݵķ�������
* ����������70.������������¥�ݣ���Ҫ n ������ܵ���¥����

			ÿ��������� 1 �� 2 ��̨�ף����ж����ֲ�ͬ�ķ�����������¥���أ�

* �����㷨��
			1���ݹ��㷨����ʱ��
				��n��¥�������ַ������һ���Ǵӵ�n-1��̨��������1��̨�ף���һ���Ǵӵ�n-2��̨��������2��̨�ס�
				����f(n) = f(n - 1) + f(n - 2)
				ʱ�临�Ӷȣ�O(2^n)�����εݹ�Ĵ�СΪ2^n
				�ռ临�Ӷȣ�O(n)��������ȿ��Դﵽn��
			2��쳲�������
				�����ҳ���1��2��Ϊ��һ��͵ڶ����쳲��������ĵ�n������
				ʱ�临�Ӷȣ�O(n)����ѭ����n����Ҫ�����n��쳲�������
				�ռ临�Ӷȣ�O(1)��ʹ�ó����ռ䡣

----------------------------------------------------------------------------------
----------�����ǲο�https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/
			3����̬�滮
				���������Ա��ֽ�ΪһЩ���������ӽṹ�������⣬���������Ž���Դ�������������Ž�����Ч�ع��������ǿ���ʹ�ö�̬�滮�������һ���⡣
				�� i �׿������������ַ����õ���
				�ڵ� (i-1)�׺�������һ�ס�
				�ڵ� (i-2)(�׺������� 2 �ס�
				���Ե���� i �׵ķ����������ǵ��� (i-1)�׺͵� (i-2) �׵ķ�����֮�͡�
				�� dp[i] ��ʾ�ܵ���� i �׵ķ���������
				dp[i]=dp[i-1]+dp[i-2]
				
				������ÿһ���Ľ���洢�������У�ÿ�������ٴε���ʱ��ֱ�Ӵ������з��ؽ��
				ʱ�临�Ӷȣ�O(n)
				�ռ临�Ӷȣ�O(n)

* ��ע��1��2��3�ֱ��Ӧ��������
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
		cur += 1;  // ��һ��̨��
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
		cur += 1;  // ��һ��̨��
		
	}
	total = memo[n];
	delete[] memo;;
	return total;

}
/*****************����˵��*******************
* ��������int rob(vector<int>& nums)
* ����������һ����������
* ��������ֵ���ܴ�ٵ��������
* ����������
	198. ����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

	����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/house-robber
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

* ʵ���㷨����̬�滮
		1���ҵ�˼·��
			�ڵ�i������ʱ��������ѡ��
				һ����͵������ӣ���ô��ʱ������Ϊnums[i]+f(i-2),����nums[i]��ʾ������ӵĽ�f(i-2)��ʾ��i-2�ķ���ʱ���еĽ�
				��һ���ǲ�͵������ӣ���ô��ʱ������Ϊf(i-1)�����ֵ�i-1������ʱ�Ľ�
			�����ܽṫʽ����
				f(i) = max(nums[i]+f(i-2), f(i-1));
			��һ������洢����������
		2���ٷ�˼·��
			����򵥵ؿ�ʼ����f(k)��ʾ��ǰk���������ܴ�ٵ���������nums[i]��ʾ��ǰ��i�����ӵĽ����
			���ȿ� n = 1 ���������Ȼf(1) = nums[1];
			�ٿ� n = 2 �������f(2) = max(nums[1], nums[2]);
			���� n = 3��������ѡ��
				1�� �����������ӣ����������һ��������ӣ�
				2)  �������������ӣ���������������
			��Ȼ��ѡ����������ѡ�����
				f(i) = max(nums[i]+f(i-2), f(i-1));
			����ÿһ��ֻ��Ҫǰ�������ֵ�����������͹��ˡ�
		3���Ա�
			�ٷ�˼·��������������򵥵Ŀ�ʼ������
			
* ������Ϣ��
ִ����ʱ :4 ms, ������ cpp �ύ�л�����70.15%���û�
�ڴ����� :8.6 MB, ������ cpp �ύ�л�����75.47%���û�
**/
int rob(vector<int>& nums) {
	int n = nums.size();  // ���뷿�Ӹ���
	int* price =  new int[ n];
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	int index = 2;
	price[0] = nums[0];
	price[1] = max(nums[1],nums[0]);  // ���ֻ���������ӣ�ѡ������
	while (index < n)
	{
		price[index] = max(nums[index] + price[index - 2], price[index - 1]);  // ѡ��͵�벻͵��i�����ӵĹ�ʽ
		index += 1;
	}
	index = price[n - 1];  // ���һ�����ӵĽ������ܽ��
	delete[] price;
	return index;
}
/*�������
int rob2(vector<int>& nums) {
	int n = nums.size();
	
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	int index = 2;
	int curTotal = nums[1];  // ��i-1������ʱ�ܽ��
	int preTotal = nums[0];  // ��i-2������ʱ�ܽ��
	int maxTotal = max(curTotal, preTotal);  // ��i������ʱ���ܽ��
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
