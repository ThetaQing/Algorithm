#ifndef __DIVIDE_AND_CONQUER_H__
#define __DIVIDE_AND_CONQUER_H__

template <class eleT> eleT SumRecursive(eleT* arr, int start, int end);


// end表示数组最后一个元素的索引，不是长度
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

__int64 IntegerMultiplyDec(int x, int y, int n);

#endif // !__DIVIDE_AND_CONQUER_H__
#pragma once
