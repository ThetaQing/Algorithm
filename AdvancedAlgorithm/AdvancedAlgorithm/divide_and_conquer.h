#ifndef __DIVIDE_AND_CONQUER_H__
#define __DIVIDE_AND_CONQUER_H__

template <class eleT> eleT SumRecursive(eleT* arr, int start, int end);


// end��ʾ�������һ��Ԫ�ص����������ǳ���
template <class eleT> eleT SumRecursive(eleT* arr, int start, int end)
{
	if (start >= end)
		return arr[start];

	else
	{
		eleT left = SumRecursive(arr, start, (start+end) / 2);
		eleT right = SumRecursive(arr, (start + end) / 2 + 1, end);
		return   left + right;
	}
		

}


#endif // !__DIVIDE_AND_CONQUER_H__
#pragma once
