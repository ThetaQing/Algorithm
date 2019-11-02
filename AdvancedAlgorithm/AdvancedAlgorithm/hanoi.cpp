/***************�ļ�˵��*************************
* �ļ�����hanoi.cpp
* �ļ����ܣ�ʵ�ֺ�ŵ����������
* ����������A��B��C�����ˣ���A�������¶��ϣ��ɴ�С��˳�������64������
*   Ŀ���ǣ���A���ϵĽ���ȫ���Ƶ�C���ϣ����ұ���ԭ�е�˳����á�
* ��������ÿ��ֻ���ƶ�һ�����ӣ��������ƶ��������������϶�ʼ�ձ��ִ������£�С������
			�������������ӿ�������A��B��C��һ���ϡ�
* ʵ��˼·����ֻ����������ʱ���Զ��׼������Խ�����n-1��С���ӿ���һ�����壬����С��Ĵ������γ��������֣��ظ��������ӵĹ���
* ʵ�ַ������ݹ��㷨�ͷǵݹ��㷨
*/
#include <string>
#include <iostream>
#include "hanoi.h"
using namespace std;
void Move(char A, char C);
/*****************����˵��****************
* ��������HanoiRecursion(n��A,B,C)
* ����������nΪ�޷������ͣ�����������ʾA�����ж��ٸ�Բ�̣�A,B,CΪ������
* ��������ֵ����
* �������ܣ�ʵ�ֶ�A����n��Բ���ƶ���C���ϵĲ���
* ʵ�ַ������ݹ�ʵ��
	1.��ACB��˳����ִ����һ�׺�ŵ�����Ʒ�
	2.��A->C�ƶ��������
	3.��BAC��˳����ִ����һ�׺�ŵ�����Ʒ�

* ʱ�临�Ӷ�: O(2^n - 1)
*/

void HanoiRecursion(unsigned int n, char A, char B, char C)
{
	if (n == 1)
		Move(A, C);
	else
	{
		HanoiRecursion(n - 1, A, C, B);  //����1 ��ACB����ִ��N-1�ĺ�ŵ���ƶ�
		Move(A, C);  //����2   �м��һ���ǰ�����һ��������A�Ƶ�C��ȥ��
		HanoiRecursion(n - 1, B, A, C);  //����3 ��BAC����ִ��N-1�ĺ�ŵ���ƶ�
	}	
}

/*****************����˵��****************
* ��������Move(A, C)
* ��������������char���͵�����
* ��������ֵ����
* �������ܣ�ʵ��A->C�����
*/
void Move(char A, char C)
{
	cout << "move:" << A << "->" << C << endl;
}


/*****************����˵��****************
* ��������Hanoi(n)
* ����������
* ��������ֵ��
* �������ܣ�
* ʵ�ַ������ǵݹ�ʵ��
	

* ʱ�临�Ӷ�: 
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
			Push(S, curPrb->n - 1, curPrb->mid, curPrb->src, curPrb->dest);//��ջ��˳��͵ݹ������෴
			Push(S, 1, curPrb->src, curPrb->mid, curPrb->dest);
			Push(S, curPrb->n - 1, curPrb->src, curPrb->dest, curPrb->mid);
		}
		free(curPrb);
	}
	free(S);

}