#include "Stack.h"

void StackInit(Stack* ps)
{
	// ջ�ĳ�ʼ��
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
void StackDestory(Stack* ps)
{
	// ջ������
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
	free(ps->_a);
	ps = NULL;
}

void StackPush(Stack* ps, STDataType x)
{
	// ���ݵ�ѹջ
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
	// ��ջ
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)
{
	// ��ȡջ��Ԫ��
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

bool StackEmpty(Stack* ps)
{
	// �ж�ջ�Ƿ�Ϊ��
	assert(ps);
	return ps->_top == 0;
}

size_t StackSize(Stack* ps)
{
	// ��ȡջ�Ĵ�С
	assert(ps);
	return ps->_top;
}