#ifndef __HANOI_H__
#define __HANOI_H__
// 递归实现
void Move(char A, char C);
void HanoiRecursion(unsigned int n, char A, char B, char C);
//非递归实现
void Hanoi(unsigned int n);

typedef struct Problem {
	int n;
	char src, mid, dest;
	struct Problem* Next;
}Stack;
bool IsEmpty(Stack* S);
void Push(Stack* S, int n, char A, char B, char C);
Stack* Pop(Stack* S, Stack* curPrb);

Stack* CreateStack();

#endif // !__HANOI_H__
#pragma once
