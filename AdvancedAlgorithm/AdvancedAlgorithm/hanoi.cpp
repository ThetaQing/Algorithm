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
		HanoiRecursion(n - 1, A, C, B);  //步骤1 按ACB数序执行N-1的汉诺塔移动,先把n-1个盘子从A通过C的中转运到B上
		Move(A, C);  //步骤2   中间的一步是把最大的一个盘子由A移到C上去；再把最后一个大盘子运到目标C上
		HanoiRecursion(n - 1, B, A, C);  //步骤3 按BAC数序执行N-1的汉诺塔移动；最后把B上的n-1个盘子通过A中运回C上。
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



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/******************函数说明**************
* 函数名：CreateStack()
* 函数参数：无
* 函数返回值：返回一个指向Stack结构体的指针
* 函数功能：创建一个Stack对象并初始化
*/
Stack* CreateStack()
{
	Stack* S;
	S = new Stack;
	S->Next = NULL;
	return S;
}
/******************函数说明**************
* 函数名：IsEmpty(Stack* S)
* 函数参数：一个Stack型指针
* 函数返回值：bool值，为空返回true
* 函数功能：判断一个栈是否为空
*/
bool IsEmpty(Stack* S)
{
	return (S->Next == NULL);
}
/******************函数说明**************
* 函数名：Push(Stack* S, int n, char A, char B, char C)
* 函数参数：压栈对象，结构体的变量参数实现
* 函数返回值：空
* 函数功能：压栈，将参数赋值给压栈对象的next值
*/
void Push(Stack* S, int n, char A, char B, char C)
{
	Stack* TmpCell; // 定义一个栈
	TmpCell = new Stack;
	TmpCell->n = n;
	TmpCell->src = A;
	TmpCell->mid = B;
	TmpCell->dest = C;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;  // 把这个栈赋值给S->next
}
/******************函数说明**************
* 函数名：Pop(Stack* S, Stack* curPrb)
* 函数参数：出栈对象，返回值
* 函数返回值：返回一个指向Stack的指针，即出栈对象的栈顶元素
* 函数功能：出栈
*/
Stack* Pop(Stack* S, Stack* curPrb)
{
	Stack* FirstCell;
	FirstCell = new Stack;
	FirstCell = S->Next;
	curPrb->n = FirstCell->n; 
	curPrb->src = FirstCell->src;
	curPrb->mid = FirstCell->mid;
	curPrb->dest = FirstCell->dest;
	S->Next = FirstCell->Next;
	delete FirstCell;
	return curPrb;
}
/*****************函数说明****************
* 函数名：Hanoi(n)
* 函数参数：盘子数目，unsigned int类型
* 函数返回值：无，输出移动过程
* 函数功能：实现对n个盘子的汉诺塔转移过程
* 实现方法：堆栈实现
* 实现思路：栈是后进先出，所以顺序恰好和递归相反。
			主要思路和递归是一样的，即先把n-1个盘子通过C柱转移到B柱，
			再把最后一个盘子转移到C柱，最后把B柱上的盘子通过A柱转移到C柱。
			并且每次都是重复两个盘子的操作。
			
			归纳起来就是：
				1、第一次压栈按照ABC分别为起始柱中转柱终点柱的顺序初始化，出栈判断是否一个盘子，否，按照起始柱中转柱终点柱为ABC的顺序转入第二步，否则，转入第六步；
				2、压栈，按照BAC的顺序将n-1个盘子从B转移到C；
				3、压栈，按照ABC的顺序将第n个盘子从A转移到C；
				4、压栈，按照ACB的顺序将n-1个盘子从A转移到B。
				5、出栈，即将第4步压栈的结果出栈，若n != 1，按照当前出栈的起始柱中转柱终点柱的顺序转入第二步，否则，转入第六步；
				6、输出从起始柱向终点柱转移的信息。
			
			可以理解为每一次出栈就是对当前过程的压栈实现，比如出栈结果为ACB，n=2时，三次压栈分别是：
				C->A->B n=1;
				A->C->B n=1;
				A->B->C n=1.
			依次出栈顺序为：
				A->B->C n=1;
				A->C->B n=1;
				C->A->B n=1.
			实际上就是把两个盘子从A柱移动到B柱的实现。
				

* 时间复杂度:
*/
void Hanoi(unsigned int n)
{
	
	Stack* S;
	S = CreateStack();
	Push(S, n, 'A', 'B', 'C');
	while (!IsEmpty(S))
	{
		Stack* curPrb;
		curPrb = new Stack;
		curPrb = Pop(S, curPrb);
		if (curPrb->n == 1)
		printf("%c -> %c\n", curPrb->src, curPrb->dest);
		else
		{
			Push(S, curPrb->n - 1, curPrb->mid, curPrb->src, curPrb->dest);  //堆栈的顺序和递归正好相反
			Push(S, 1, curPrb->src, curPrb->mid, curPrb->dest);
			Push(S, curPrb->n - 1, curPrb->src, curPrb->dest, curPrb->mid);
		}
		delete curPrb;
	}
	delete S;

}