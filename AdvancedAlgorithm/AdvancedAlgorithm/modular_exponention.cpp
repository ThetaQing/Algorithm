/*
*******************�ļ�����**********************************

* �ļ�����modular_exponention.cpp
* ʵ�ֹ��ܣ���һ�������ݶ���һ������ģ���㣬Ҳ��Ϊģȡ��

* ��Ҫ�㷨������ƽ����

* �㷨��Ҫԭ��

*/
#include <bitset>
using std::bitset;
int ModularExponention(int a, int b, int n)
{
	int c = 0;
	int d = 1;
	bitset<sizeof(int) * 8>binary_b(b);  // binary_b��b�Ķ����Ʊ�ʾ��������sizeof(int)*8
	for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		c = 2*c;
		d = (d * d) % n;
		if (binary_b[i] == 1)
		{
			c += 1;
			d = (d * a) % n;
		}
	}
	return d;
}