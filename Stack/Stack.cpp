#include "Stack.h"

void StackInit(Stack* ps)
{
	// 栈的初始化
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
void StackDestory(Stack* ps)
{
	// 栈的销毁
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
	free(ps->_a);
	ps = NULL;
}

void StackPush(Stack* ps, STDataType x)
{
	// 数据的压栈
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = (ps->_capacity == 0) ? 2 : (ps->_capacity * 2);
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	++ps->_top;
}
void StackPop(Stack* ps)
{
	// 出栈
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)
{
	// 获取栈顶元素
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

bool StackEmpty(Stack* ps)
{
	// 判断栈是否为空
	assert(ps);
	return ps->_top == 0;
}

size_t StackSize(Stack* ps)
{
	// 获取栈的大小
	assert(ps);
	return ps->_top;
}