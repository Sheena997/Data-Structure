#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);// ջ�ĳ�ʼ��
void StackDestory(Stack* ps);// ջ������

void StackPush(Stack* ps, STDataType x);// ���ݵ�ѹջ
void StackPop(Stack* ps);// ��ջ

STDataType StackTop(Stack* ps);// ��ȡջ��Ԫ��

bool StackEmpty(Stack* ps);// �ж�ջ�Ƿ�Ϊ��

size_t StackSize(Stack* ps);// ��ȡջ�Ĵ�С