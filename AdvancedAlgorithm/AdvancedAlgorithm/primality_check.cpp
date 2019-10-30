/*
*******************文件描述**********************************

* 文件名：primality_check.cpp
* 实现功能：判断一个数是否是质数（素数）
* 算法主要原理：
	定义：素数是只能被1和自身整除的数
	
* 主要算法：基于同余运算

*/

#include <cmath>
#include <vector>
#include "primality_check.h"
using namespace std;
/**********函数说明**********
* 函数名称：primality(N)
* 函数参数：输入为一个正整数
* 函数输出：输出为COMPOSITE，即合数，或者PRIME，质数
* 算法原理：费马小定理
	如果p是一个质数，对于任意的 1 ≤ a < p
	a^(p-1)和1对p同余。
	如果p是一个合数，且满足对于任意的 1 ≤ a < p
	a^(p-1)和1对p同余。
	则称p是一个基于a的伪素数。
* 算法分析：
	可能出错，341 = 11 * 31， 2^340 和1 对341同余
*/
bool Primality(unsigned __int64 N)  // unsigned __int64的最大值18446744073709551615
{
	double a = 2.0;
	int a_power = pow(a, N - 1);
	if (a_power % N == 1 % N)
		return PRIME;
	else
		return COMPOSITE;
}
/***********函数说明**********
* 函数名称：primality_improve(N)
* 函数参数：输入为一个正整数
* 函数输出：输出为COMPOSITE，即合数，或者PRIME，质数
	费马小定理的其逆命题几乎成立，这个过程出错的概率很小，至少小于1/2.
	为此对算法提出两点改进
		——	Miller-Rabin随机性素数测试法
		第一：它试验了多个随机选取的基值n，而非仅仅一个基值。
		第二：当计算每个模取幂的值时，在最后一组平方里，寻找一个以n为模的1的非平凡平方根。如果发现一个，中值执行并输出结果COMPOSITE（合数）。
		（第二步 具体指 
			a^(p-1)与1对p同余，两边同时开根号，有
			a^((p-1)/2)）与(±1)对p同余，继续开根号，直到
			左边的指数(n-1)/(2^d)是奇数不能再开平方根，或者某一步右边变成了-1为止。
		如果某一步开平方根的时候右端直接从1变成了“不是±1的数”，则p就是合数。)
* 算法分析：如果随机取k个底数做测试的话，准确率可以达到至少1-4^(-k)
* 时间复杂度： O((logn)^3)
* 算法详细分析：https://www.zhihu.com/question/308322307 以及 算法导论Page 565
****************/
bool PrimalityImprove(unsigned __int64 N) // 测试失败
{
	vector <double> test_num = {2.0,3.0,5.0,7.0,11.0,13.0,17.0 };
	for (int i = 0; i < test_num.size()&&test_num[i]<N; ++i)
	{
		
		int temp = N - 1; // 最开始的指数
		do  // 直到指数为奇数才结束
		{
			int temp_pow = pow(test_num[i], temp);
			if (temp_pow % N == 1 % N)
			{
				temp >>= 1;
			}
			else
				return COMPOSITE;
		} while (!(temp % 2));

	}
	return PRIME;
}