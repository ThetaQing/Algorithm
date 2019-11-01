/*
*******************�ļ�����**********************************

* �ļ�����GREATEST_COMMON_DIVISION.cpp
* ʵ�ֹ��ܣ��������������m��n�����Լ��
* �㷨��Ҫԭ���������������Լ���������н�С���Ǹ���������������������Լ����
* ��Ҫ�㷨��ŷ������㷨��������������㷨��������������˷�

*/

/*
**********����˵��*************
* �������ƣ�GcdEuclid(int m, int n)
* ����������m��nΪ��������������
* ��������ֵ������m��n�����Լ��

* �㷨˼�룺ŷ������㷨��
	��һ�������n=0������m��ֵ��Ϊ������������������ڶ���
	�ڶ�������nȥ��m����������ֵ��r��
	����������n��ֵ��ֵ��m����r��ֵ��ֵ��n�����ص�һ����
* �㷨ʵ�֣�
	�ݹ�ʵ�֣�GcdEuclidRecursion(m,n)
	�ǵݹ�ʵ�֣�GcdEuclid(m,n)
* ʱ�临�Ӷȣ�
	��Ϊÿ����һ��ڶ�������ÿ����һ��gcd���������б���һ��������һ�����ϣ���Ϊ���������ܴ��ڱ�������
	����ʱ�临�Ӷ�Ϊ	O(lgn)
*/

#include <algorithm>
#include "greatest_common_division.h"
#include "primality_check.h"
#include <vector>
using namespace std;

// �ݹ�ʵ��
int GcdEuclidRecursion(int m, int n)
{
	return (!n ? m : GcdEuclidRecursion(n, m % n));  // �ж�n�Ƿ�Ϊ0����Ϊ0����ݹ���ã�շת���
}
// �ǵݹ�ʵ��
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
**********����˵��*************
* �������ƣ�GcdContinuousIntegerTest(int m, int n)
* ����������m��nΪ��������������
* ��������ֵ������m��n�����Լ��

* �㷨˼�룺�����������鷨
	��һ������min{m,n}��ֵ����t
	�ڶ�����m����t���������Ϊ0�����������������򣬽�����Ĳ���
	��������n����t���������Ϊ0���򷵻�tֵ��Ϊ��������򣬽�����Ĳ���
	���Ĳ�����t��ֵ��1�����صڶ�����
* �㷨ʵ�֣�
	
	�ǵݹ�ʵ�֣�gcd_continuous_integer_test(m,n)
* ʱ�临�Ӷȣ�
	�����������ǹ�Լ��Ϊ1��ѭ������t-1�Σ���õ������ֻ��һ��
	����ʱ�临�Ӷ�Ϊ	O(n) = n/2
*/

int GcdContinuousIntegerTest(int m, int n)
{
	int temp = std::min(m, n);
	while (m % temp || n % temp)  // ��һ������������ȫ���㣬ֻ�е���һ���������ļ�����Ϊ0ʱ�ż���ڶ����������������㷨Ҫ��
	{
		temp -= 1;
	}
	return temp;
}

/*
**********����˵��*************
* �������ƣ�GcdCommonPrimeFactors(int m, int n)
* ����������m��nΪ��������������
* ��������ֵ������m��n�����Լ��

* �㷨˼�룺���������������
	��һ�����ҵ�m��������������
	�ڶ������ҵ�n��������������
	���������ӵ�һ�����ڶ�������õ��������ֽ�ʽ�ҳ����еĹ�������
	���Ĳ��������������ҵ���������ˣ�������Ϊ�������ֵ����������

* �㷨ʵ�֣�

	�ǵݹ�ʵ�֣�GcdCommonPrimeFactors(m,n)
* ʱ�临�Ӷȣ�
	O(n*(logn)^3)
	
*/
int GcdCommonPrimeFactors(int m, int n)
{
	int result = 1;

	std::vector<int> prime_m, prime_n;

	// ��m�����������ֽ�
	// ���m��������m = 1 * m
	if (MilleRabin(m))
		prime_m.push_back(m);
	else
	{
		for (int temp = m, prime = 2; temp > 1; )
		{
			if (temp % prime)  // ���prime����temp����ʽ��prime + 1
				prime += 1;

			else if (MilleRabin(prime))
			{
				temp = temp / prime;  // ���prime��temp����ʽ������temp
				prime_m.push_back(prime);  // ���prime����������ӽ��������б�
			}
			else
				prime += 1;  // ������������ֲ�������������prime
		}
	}

	// ��n�����������ֽ�
	// ���n��������n = 1 * n
	if (MilleRabin(n))
		prime_n.push_back(n);
	else
	{
		for (int temp = n, prime = 2; temp > 1; )
		{
			if (temp % prime)  // ���prime����temp����ʽ��prime + 1
				prime += 1;

			else if (MilleRabin(prime))
			{
				temp = temp / prime;  // ���prime��temp����ʽ������temp
				prime_n.push_back(prime);  // ���prime����������ӽ��������б�
			}
			else
				prime += 1;  // ������������ֲ�������������prime
		}
	}

	while (!prime_m.empty() && !prime_n.empty())
	{
		if (prime_m[0] == prime_n[0])
		{
			result = result * prime_m[0];// �����ȣ����
			prime_m.erase(prime_m.begin());  // ���
			prime_n.erase(prime_n.begin());
		}
		else if (prime_m[0] < prime_n[0])  // �Ƴ�С���Ǹ�����
		{
			prime_m.erase(prime_m.begin());  
		}
		else
			prime_n.erase(prime_n.begin());
	}
	

	
	
	return result;
}



