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
* ����������������˵�������nΪ�����������λ��
* ��������ֵ�����������ĳ˻�
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

/************����˵��***********
* ��������void CoverChessBoard(int row_left, int column_left, int row_special, int column_special, int size)
* �����������������Ͻǵ��������꣬�������������꣬���̳ߴ�
* ��������ֵ����
* �������ܣ�ʵ�����̸���
* ����������
��һ��2^k��2^k ��k��0����������ɵ������У�ǡ��һ����������������ͬ���Ƹ÷���Ϊ���ⷽ��
��Ȼ�����ⷽ���������п��ܳ��ֵ�λ����4^k�֣������4^k�ֲ�ͬ�����̣�
���̸������⣨chess cover problem��Ҫ����4�ֲ�ͬ��״��L�͹��Ƹ��Ǹ��������ϳ����ⷽ����������з������κ�2��L�͹��Ʋ����ص����ǡ�
* �����㷨�����η�
			�����̲��ϼ�С��ֱ�����һ��
			1��ȷ���ݹ��������Ϊ��ǰ�ߴ�Ϊ1��
			2���ж������λ��
				��1����������Ͻǣ������ݹ飬�������Ͻǣ�����1/4���̵����½����Ϊ������ٵݹ飻
				��2����������Ͻǣ������ݹ飬��������1/4���̵����½����Ϊ������ٵݹ飻
				��3����������½ǣ������ݹ飬��������1/4���̵����Ͻ�Ϊ������ٵݹ飻
				��4����������½ǣ������ݹ飬��������1/4���̵����Ͻ�Ϊ������ٵݹ顣
			3������������ϱ�ǣ�����һ��ȫ�ֱ�����һ���ֲ���������֤ÿһ�εݹ鷵�غ���һ��ֵ����
**/


int chess[8][8];

int number = 1;
void CoverChessBoard(int row_left, int column_left, int row_special, int column_special, int size)
{
	int tie = number++;

	int row_center = row_left + size / 2, column_center = column_left + size / 2;
	// �ݹ��������
	if (size == 1)
	{
		return;
	}
	// ���ж����ⷽ���λ��
	// ���Ͻ�
	if (row_special < row_center && column_special < column_center)  
	{		
		CoverChessBoard(row_left, column_left, row_special, column_special, size / 2);  // ��ʼ�ݹ�
	}
	else  
	{
		chess[row_center - 1][column_center - 1] = tie;  // �����½�����
		CoverChessBoard(row_left, column_left, row_center-1, column_center - 1, size / 2);  // ��ʼ�ݹ�
		// ���е���һ����
	}
	// ���Ͻ�
	if (row_special < row_center && column_special >= column_center)  
	{
		CoverChessBoard(row_left, (column_left + size)/2, row_special, column_special, size / 2);  // ��ʼ�ݹ�
	}
	else
	{
		chess[row_center-1][column_center] = tie;  // ���½����
		CoverChessBoard(row_left, column_center, row_center-1, column_center, size / 2);
	}
	// ���½�
	if (row_special >= row_center && column_special < column_center)  
	{
		CoverChessBoard((row_left + size)/2, column_left, row_special, column_special, size / 2);  // ��ʼ�ݹ�
	}
	else
	{
		chess[row_center][column_center - 1] = tie;  // ���Ͻ�����
		CoverChessBoard(row_center, column_left, row_center, column_center - 1, size / 2);

	}
	// ���½�
	if (row_special >= row_center && column_special >= column_center)  
	{		
		CoverChessBoard(row_center, column_center, row_special, column_special, size / 2);  // ��ʼ�ݹ�
	}
	else
	{
		chess[row_center][column_center] = tie;  // ���Ͻ�����
		CoverChessBoard(row_center, column_center, row_center, column_center, size / 2);
	}
}
int main()
{
	int row = 2, column = 2;  // ��ʾ���ⷽ�����������

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