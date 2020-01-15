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

void StackInit(Stack* ps);// 栈的初始化
void StackDestory(Stack* ps);// 栈的销毁

void StackPush(Stack* ps, STDataType x);// 数据的压栈
void StackPop(Stack* ps);// 出栈

STDataType StackTop(Stack* ps);// 获取栈顶元素

bool StackEmpty(Stack* ps);// 判断栈是否为空

size_t StackSize(Stack* ps);// 获取栈的大小