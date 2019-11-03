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
		HanoiRecursion(n - 1, A, C, B);  //����1 ��ACB����ִ��N-1�ĺ�ŵ���ƶ�,�Ȱ�n-1�����Ӵ�Aͨ��C����ת�˵�B��
		Move(A, C);  //����2   �м��һ���ǰ�����һ��������A�Ƶ�C��ȥ���ٰ����һ���������˵�Ŀ��C��
		HanoiRecursion(n - 1, B, A, C);  //����3 ��BAC����ִ��N-1�ĺ�ŵ���ƶ�������B�ϵ�n-1������ͨ��A���˻�C�ϡ�
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



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/******************����˵��**************
* ��������CreateStack()
* ������������
* ��������ֵ������һ��ָ��Stack�ṹ���ָ��
* �������ܣ�����һ��Stack���󲢳�ʼ��
*/
Stack* CreateStack()
{
	Stack* S;
	S = new Stack;
	S->Next = NULL;
	return S;
}
/******************����˵��**************
* ��������IsEmpty(Stack* S)
* ����������һ��Stack��ָ��
* ��������ֵ��boolֵ��Ϊ�շ���true
* �������ܣ��ж�һ��ջ�Ƿ�Ϊ��
*/
bool IsEmpty(Stack* S)
{
	return (S->Next == NULL);
}
/******************����˵��**************
* ��������Push(Stack* S, int n, char A, char B, char C)
* ����������ѹջ���󣬽ṹ��ı�������ʵ��
* ��������ֵ����
* �������ܣ�ѹջ����������ֵ��ѹջ�����nextֵ
*/
void Push(Stack* S, int n, char A, char B, char C)
{
	Stack* TmpCell; // ����һ��ջ
	TmpCell = new Stack;
	TmpCell->n = n;
	TmpCell->src = A;
	TmpCell->mid = B;
	TmpCell->dest = C;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;  // �����ջ��ֵ��S->next
}
/******************����˵��**************
* ��������Pop(Stack* S, Stack* curPrb)
* ������������ջ���󣬷���ֵ
* ��������ֵ������һ��ָ��Stack��ָ�룬����ջ�����ջ��Ԫ��
* �������ܣ���ջ
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
/*****************����˵��****************
* ��������Hanoi(n)
* ����������������Ŀ��unsigned int����
* ��������ֵ���ޣ�����ƶ�����
* �������ܣ�ʵ�ֶ�n�����ӵĺ�ŵ��ת�ƹ���
* ʵ�ַ�������ջʵ��
* ʵ��˼·��ջ�Ǻ���ȳ�������˳��ǡ�ú͵ݹ��෴��
			��Ҫ˼·�͵ݹ���һ���ģ����Ȱ�n-1������ͨ��C��ת�Ƶ�B����
			�ٰ����һ������ת�Ƶ�C��������B���ϵ�����ͨ��A��ת�Ƶ�C����
			����ÿ�ζ����ظ��������ӵĲ�����
			
			�����������ǣ�
				1����һ��ѹջ����ABC�ֱ�Ϊ��ʼ����ת���յ�����˳���ʼ������ջ�ж��Ƿ�һ�����ӣ��񣬰�����ʼ����ת���յ���ΪABC��˳��ת��ڶ���������ת���������
				2��ѹջ������BAC��˳��n-1�����Ӵ�Bת�Ƶ�C��
				3��ѹջ������ABC��˳�򽫵�n�����Ӵ�Aת�Ƶ�C��
				4��ѹջ������ACB��˳��n-1�����Ӵ�Aת�Ƶ�B��
				5����ջ��������4��ѹջ�Ľ����ջ����n != 1�����յ�ǰ��ջ����ʼ����ת���յ�����˳��ת��ڶ���������ת���������
				6���������ʼ�����յ���ת�Ƶ���Ϣ��
			
			�������Ϊÿһ�γ�ջ���ǶԵ�ǰ���̵�ѹջʵ�֣������ջ���ΪACB��n=2ʱ������ѹջ�ֱ��ǣ�
				C->A->B n=1;
				A->C->B n=1;
				A->B->C n=1.
			���γ�ջ˳��Ϊ��
				A->B->C n=1;
				A->C->B n=1;
				C->A->B n=1.
			ʵ���Ͼ��ǰ��������Ӵ�A���ƶ���B����ʵ�֡�
				

* ʱ�临�Ӷ�:
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
			Push(S, curPrb->n - 1, curPrb->mid, curPrb->src, curPrb->dest);  //��ջ��˳��͵ݹ������෴
			Push(S, 1, curPrb->src, curPrb->mid, curPrb->dest);
			Push(S, curPrb->n - 1, curPrb->src, curPrb->dest, curPrb->mid);
		}
		delete curPrb;
	}
	delete S;

}