/**********************************************************************
ջ��������
������ʵ�ֵ�ջ�ṹ��ȱ����������Ҫ��̬�ķ�����Դ�������������������
����һ��ջ�ṹ�洢��ɾ�������ݣ���ʹ������ʵ����Ч�ʸ���һЩ��Ψһ�Ĳ���
���Ǿ�����Ҫ��ǰ������ռ��С,����ֻ��ʵ����һЩջ��������
**********************************************************************/

#include "stdafx.h"
#include <stdint.h>
#include <stdlib.h>


typedef struct StackRecord
{
	int capcity;
	int topOfStack;
	int *array;
}*Stack;	//ջָ�����



/*
�ͷ�ջ����
*/
void dispose_stack(Stack S)
{
	if (NULL != S)
	{
		free(S->array);
		free(S);
	}
}

/*
�ж�ջ�Ƿ�Ϊ������
*/
int is_empty(Stack S)
{
	return S->topOfStack == -1;
}

/*
����һ����ջ����
*/
void make_empty(Stack S)
{
	S->topOfStack = -1;
}

/*
�ж�ջ��������
*/
int is_full(Stack S)
{
	return S->topOfStack == S->capcity - 1;
}

/*
����ջ����
*/
Stack create_statck(int maxElements)
{
	Stack s;

	//����ջ�ռ�
	s = (Stack)malloc(sizeof(struct StackRecord));
	if (NULL == s)
	{
		printf("Out of space.\n");
		exit(-1);
	}

	//����ջ����ռ�,ջ��ʼ��
	s->array = (int*)malloc(sizeof(int) * maxElements);
	if (NULL == s->array)
	{
		printf("Out of space.\n");
		exit(-1);
	}
	s->capcity = maxElements;
	make_empty(s);

	return s;
}

/*
��ջ����
*/
void push(int x, Stack S)
{
	if (is_full(S))
		printf("Full stack.\n");
	else
		S->array[++S->topOfStack] = x;
}

/*
����ջ������
*/
int top(Stack S)
{
	if (!is_empty(S))
		return S->array[S->topOfStack];
	printf("Empty stack.\n");

	return 0;
}

/*
��ջ����
*/
void pop(Stack S)
{
	if (is_empty(S))
		printf("Empty stack.\n");
	else
		S->topOfStack--;
}

/*
����Ԫ�ز���ջ����
*/
int top_and_pop(Stack S)
{
	if (!is_empty(S))
		return S->array[S->topOfStack--];
	printf("Empty stack.\n");

	return 0;
}
