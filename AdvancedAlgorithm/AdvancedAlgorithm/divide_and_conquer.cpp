#include "divide_and_conquer.h"
#include <iostream>
#include <bitset>
using namespace std;

/****************�ļ�˵��********************
* �ļ�����divide_and_conquer.cpp
* �ļ����ܣ����η��ĵ���Ӧ��
*			�������򣻹鲢���������ӷ��������˷������������˷������̸��ǵ�


**/


/************����˵��***********
* ��������__int64 IntegerMultiplyDec(int x, int y, int n)
* ����������������˵��������������������λ��
* ��������ֵ�������������ĳ˻�
* �������ܣ�ʵ�ִ��������
* �����㷨��karatsuba�˷�
	��������������x��y��
	���Ƚ�x��y�ֱ�𿪳�Ϊ�����֣��ɵ�x1��x0��y1��y0�����ǵĹ�ϵ���£�
	x = x1 * 10^m + x0��
	y = y1 * 10^m + y0������mΪ��������m < n����x0��y0 С�� 10^m��
	��ô xy = (x1 * 10^m + x0)(y1 * 10^m + y0)
	=z2 * 10^(2*m) + z1 * 10^m + z0�����У�
	z2 = x1 * y1��
	z1 = (x1 + x0) * (y1 + y0) - x1 * y1 - x0 * y0��
	z0 = x0 * y0��

* ע�⣺���ǵ����m����������ô m/2 + m/2 != m��������ʵ����Ҫ����ע�⣡��������ͻ���ֶ�һ��0~
* ʱ�临�Ӷȣ� ÿһ�μ���ֻ�����γ˷���T(n) <= 3 * T(n/2) + cn;
				���ݹ�ʽ���У�O(n^(log3)) = O(n^1.59)
**/



__int64 IntegerMultiplyDec(int x, int y, int n)
{
	int sign_x = 1, sign_y = 1;
	__int64 sum;
	if (x < 0)
	{
		sign_x = -1;
		x = -x;  // �ȰѸ���תΪ����
	}
	if (y < 0)
	{
		sign_y = -1;
		y = -y;
	}
	sum = sign_x * sign_y;  // �������λ
	
	// �ݹ������������������һ���ɣ�����һ��������
	if (x <= 10 || y <= 10 || n <= 1)
		return sum * x * y;	
	// x_high��ʾx��n/2--n�ĸ�λ���֣�x_low��ʾ1����n/2�ĵ�λ����
	int x_high=0, x_low=0, y_high=0, y_low=0;
	int power = pow(10, n / 2);
	x_high = x / power;
	x_low = x % power;
	y_high = y / power;
	y_low = y % power;
	__int64 x_highy_high = IntegerMultiplyDec(x_high, y_high, n / 2);
	__int64 x_lowy_low = IntegerMultiplyDec(x_low, y_low, n / 2);
	__int64 x_highx_lowy_highy_low = IntegerMultiplyDec(x_high - x_low, y_low - y_high, n / 2);
	sum = sum * (x_highy_high * int(pow(10, n/2 + n/2)) + (x_highy_high + x_lowy_low + x_highx_lowy_highy_low) * power + x_lowy_low);  // ����ע��x_highy_high * int(pow(10, n/2 + n/2))������nΪ�������������
	return sum;
	
}
