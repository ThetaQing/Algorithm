
#include "fibonacci.h"
#include <vector>
using namespace std;
/*****************w�ļ�����**********************
* �ļ�����fibonacci.cpp
* �ļ����ܣ�ʵ��쳲���������
* ��Ҫԭ��
	if n =0, fib(n) = 0;
	if n = 1, fib(n) = 1;
	if n > 1, fib(n) = fib(n-1) + fib(n-2).
* ��Ҫʵ�ַ������ݹ�ʵ�֡��ǵݹ�ʵ��
*/

/*****************����˵��****************
* ��������FibRecursion(n)
* �����������޷������ͣ�������
* ��������ֵ���޷������ͣ�������
* �������ܣ���쳲��������еĵ�n����
* ʵ�ַ������ݹ�ʵ��
* ʱ�临�Ӷȷ������������β�ַ���T(N) = T(N-1) + T(N-2)
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

/*****************����˵��****************
* ��������FibArray(n)
* �����������޷������ͣ�������
* ��������ֵ���޷������ͣ�������
* �������ܣ���쳲��������еĵ�n����
* ʵ�ַ������ǵݹ�ʵ�֣�����ֱ���ù�ʽ���ڴ������ظ����㣬���Խ���Щ�м���ֱ�Ӵ洢���������
* ʱ�临�Ӷȷ�����O(n)


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



/*****************����˵��****************
* ��������Fib(n)
* �����������޷������ͣ�������
* ��������ֵ���޷������ͣ�������
* �������ܣ���쳲��������еĵ�n����
* ʵ�ַ������ǵݹ�ʵ��
* ʱ�临�Ӷȷ�����O(n)


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


