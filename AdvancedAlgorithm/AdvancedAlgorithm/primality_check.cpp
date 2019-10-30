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

#include "modular_exponention.h"
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
* Tips: 注意，求模取幂时，不要用pow函数，double类型进行操作时可能会判断出错
*/
bool Primality(unsigned __int64 N)  // unsigned __int64的最大值18446744073709551615
{	
	if (ModularExponention(2, N-1, N)== 1 % N)
		return PRIME;
	return COMPOSITE;
}

/***********函数说明**********
* 函数名称：Witness(a,n)
* 函数参数：a为检验算子，n为待检验数
* 函数输出：输出为bool值，当且仅当a为合数n的证据时（即用a来证明n为合数的可能的），返回TRUE
* 函数功能：用检验算子a来检验n是否为素数
* 算法分析：判断合数的关键在于
				a^(n-1) mod n != 1 mod n
			令n-1 = 2^t * u,其中，t≥1且u是奇数，即n-1的二进制表示是奇数u的二进制表示后面跟上恰好t个0.因此
				a^(n-1) mod n == [a^(u)]^(2^t) mod n
			所以通过先计算a^(u) mod n，再对结果连续平方t次来计算a^(n-1) mod n.
* 算法原理：仅当n是合数时，才可能存在以n为模的1的非平凡平方根。
* 算法详细分析：https://blog.csdn.net/maxichu/article/details/45458569以及 算法导论Page 567
****************/

bool Witness(__int64 a, __int64 n)
{
	__int64 tem = n - 1;
	int j = 0;
	// 把n-1拆分为2^t * u，u为奇数
	while (!(tem % 2))
	{
		tem >>= 1;  // 右移一位，表示除以2
		++j;  
	}

	__int64 x = ModularExponention(a, tem, n);  // 得到a^u mod n
	for (int i = 0; i < j; ++i)
	{
		tem = x;
		x = (x * x) % n;  
		if (x == 1 && tem != 1 && tem != n - 1)  // 这个部分的第三个条件还是没太懂.第一个和第二个条件表示1和1和一个非平凡平方根(tem)同余,是合数，提前结束循环
		{
			return true;  // 当且仅当a为合数n的证据时，返回TRUE
		}
	}
	if (x != 1)  // 即a^(n-1) mod n ！= 1 mod n，不满足费马小定理，不是素数，是合数。
		return true;
	return false;  // 如果是质数，返回false，表示a不能证明n是合数

}

/***********函数说明**********
* 函数名称：MillerRabin(N)
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
		如果某一步开平方根的时候右端直接从1变成了“不是±1的数”，则p就是合数。
		注意：非平凡平方根：若果一个数x满足方程

			x^2 mod n == 1 mode n

		但x不等于以n为模的1的两个“平凡”平方根：1或者-1，则称x是一个以n为模的1的非平凡平方根。
		如，6是以35为模的1 的非平凡平方根。)
* 算法分析：如果随机取k个底数做测试的话，准确率可以达到至少1-4^(-k)
* 时间复杂度： O((logn)^3)
* 算法详细分析：https://www.zhihu.com/question/308322307 以及 算法导论Page 565
****************/
bool MillerRabin(unsigned __int64 N) // 测试失败
{
	vector <int> test_num = { 2,3,5,7,11,13,17 };  // 算法导论中采用的是随机数，这里采用大部分判断质数的函数isPrime中的检验数
	for (int i = 0; i < test_num.size() && test_num[i] < N; ++i)
	{
		if (Witness(test_num[i], N))
			return COMPOSITE;	

	}
	return PRIME;
}
