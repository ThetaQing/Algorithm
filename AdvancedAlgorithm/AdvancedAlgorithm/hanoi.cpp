/***************文件说明*************************
* 文件名：hanoi.cpp
* 文件功能：实现汉诺塔问题的求解
* 问题描述：A、B、C三个杆，在A杆上自下而上，由大到小按顺序放置了64个金盘
*   目标是：把A杆上的金盘全部移到C杆上，并且保持原有的顺序叠好。
* 操作规则：每次只能移动一个盘子，并且在移动过程中三根杆上都始终保持大盘在下，小盘在下
			操作过程中盘子可以置于A、B、C任一杆上。
* 实现思路：当只有两个盘子时，显而易见。所以将上面n-1个小盘子看做一个整体，与最小面的大盘子形成两个部分，重复两个盘子的过程
* 实现方法：递归算法和非递归算法
*/
#include <string>
#include <iostream>
#include "hanoi.h"
using namespace std;
void Move(char A, char C);
/*****************函数说明****************
* 函数名：HanoiRecursion(n，A,B,C)
* 函数参数：n为无符号整型，正整数，表示A杆上有多少个圆盘，A,B,C为三个杆
* 函数返回值：无
* 函数功能：实现对A杆上n个圆盘移动到C杆上的步骤
* 实现方法：递归实现
	1.在ACB的顺序下执行了一阶汉诺塔的移法
	2.从A->C移动了最大盘
	3.在BAC的顺序下执行了一阶汉诺塔的移法

* 时间复杂度: O(2^n - 1)
*/

void HanoiRecursion(unsigned int n, char A, char B, char C)
{
	if (n == 1)
		Move(A, C);
	else
	{
		HanoiRecursion(n - 1, A, C, B);  //步骤1 按ACB数序执行N-1的汉诺塔移动
		Move(A, C);  //步骤2   中间的一步是把最大的一个盘子由A移到C上去；
		HanoiRecursion(n - 1, B, A, C);  //步骤3 按BAC数序执行N-1的汉诺塔移动
	}	
}

/*****************函数说明****************
* 函数名：Move(A, C)
* 函数参数：两个char类型的输入
* 函数返回值：空
* 函数功能：实现A->C的输出
*/
void Move(char A, char C)
{
	cout << "move:" << A << "->" << C << endl;
}


/*****************函数说明****************
* 函数名：Hanoi(n)
* 函数参数：
* 函数返回值：
* 函数功能：
* 实现方法：非递归实现
	

* 时间复杂度: 
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


Stack* CreateStack()
{
	Stack* S;
	S = (Stack*)malloc(sizeof(struct Problem));
	S->Next = NULL;
	return S;
}

bool IsEmpty(Stack* S)
{
	return (S->Next == NULL);
}

void Push(Stack* S, int n, char A, char B, char C)
{
	Stack* TmpCell;
	TmpCell = (Stack*)malloc(sizeof(struct Problem));
	TmpCell->n = n;
	TmpCell->src = A;
	TmpCell->mid = B;
	TmpCell->dest = C;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

Stack* Pop(Stack* S, Stack* curPrb)
{
	Stack* FirstCell;
	FirstCell = (Stack*)malloc(sizeof(struct Problem));
	FirstCell = S->Next;
	curPrb->n = FirstCell->n; curPrb->src = FirstCell->src; curPrb->mid = FirstCell->mid; curPrb->dest = FirstCell->dest;
	S->Next = FirstCell->Next;
	free(FirstCell);
	return curPrb;
}

void Hanoi(unsigned int n)
{
	
	Stack* S;
	S = CreateStack();
	Push(S, n, 'A', 'B', 'C');
	while (!IsEmpty(S))
	{
		Stack* curPrb;
		curPrb = (Stack*)malloc(sizeof(struct Problem));
		curPrb = Pop(S, curPrb);
		if (curPrb->n == 1)printf("%c -> %c\n", curPrb->src, curPrb->dest);
		else
		{
			Push(S, curPrb->n - 1, curPrb->mid, curPrb->src, curPrb->dest);//堆栈的顺序和递归正好相反
			Push(S, 1, curPrb->src, curPrb->mid, curPrb->dest);
			Push(S, curPrb->n - 1, curPrb->src, curPrb->dest, curPrb->mid);
		}
		free(curPrb);
	}
	free(S);

}