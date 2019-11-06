#ifndef __HANOI_H__
#define __HANOI_H__
// 递归实现
void Move(char A, char C);
void HanoiRecursion(unsigned int n, char A, char B, char C);
//非递归实现
void Hanoi(unsigned int n);

struct Stack {
	int n;
	char src, mid, dest;
	struct Stack* Next;
};
bool IsEmpty(Stack* S);
void Push(Stack* S, int n, char A, char B, char C);
Stack* Pop(Stack* S, Stack* curPrb);

Stack* CreateStack();

#endif // !__HANOI_H__
#pragma once
