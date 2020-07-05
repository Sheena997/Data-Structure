#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *_a;
	int _top;
	int _capacity;
}Stack;


void StackInit(Stack *ps);
void StackDestory(Stack *ps);

void StackPush(Stack *ps, STDataType x);
void StackPop(Stack *ps);
STDataType StackTop(Stack *ps);
bool StackEmpty(Stack *ps);
size_t StackSize(Stack *ps);

void StackInit(Stack *ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
void StackDestory(Stack *ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
	free(ps->_a);
	ps = NULL;
}
void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 2 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack *ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}
STDataType StackTop(Stack *ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
bool StackEmpty(Stack *ps)
{
	assert(ps);
	return !(ps->_top);
}
size_t StackSize(Stack *ps)
{
	assert(ps);
	return ps->_top;
}

typedef struct {
	Stack _st;
	Stack _minst;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack *s = (MinStack *)malloc(sizeof(MinStack));
	StackInit(&(s->_st));
	StackInit(&(s->_minst));
	return s;
}

void minStackPush(MinStack* obj, int x) {
	StackPush(&(obj->_st), x);
	if (StackEmpty(&(obj->_minst)) || x <= StackTop(&(obj->_minst)))
	{
		StackPush(&(obj->_minst), x);
	}
}

void minStackPop(MinStack* obj) {
	int top = StackTop(&(obj->_st));
	StackPop(&(obj->_st));
	if (top == StackTop(&(obj->_minst)))
	{
		StackPop(&(obj->_minst));
	}
}

int minStackTop(MinStack* obj) {
	return StackTop(&(obj->_st));
}

int minStackGetMin(MinStack* obj) {
	return StackTop(&(obj->_minst));
}

void minStackFree(MinStack* obj) {
	StackDestory(&(obj->_st));
	StackDestory(&(obj->_minst));
	free(obj);
}



/*
来源：牛客网
链接：https://www.nowcoder.com/questionTerminal/a4d17eb2e9884359839f8ec559043761
*/
#include <iostream>
#include <stack>

using namespace std;

typedef int STDataType;
class MinStack
{
public:
    MinStack()
    {}
    ~MinStack()
    {}
    void MinPush(STDataType x)
    {
        _st.push(x);
        if(_minst.empty() || _minst.top() >= x)
            _minst.push(x);
    }
    void MinPop()
    {
        if(_minst.top() == _st.top())
            _minst.pop();
        _st.pop();
    }
    STDataType GetMin()
    {
        return _minst.top();
    }
    STDataType GetTop()
    {
        return _st.top();
    }
private:
    stack<int> _minst;
    stack<int> _st;
};

int main()
{
    int op = 0, x = 0;
    MinStack ms;
    while(cin >> op)
    {
        switch(op)
        {
            case 0:
                cout << ms.GetMin() << endl;
                break;
            case 1:
                cin >> x;
                ms.MinPush(x);
                break;
            case 2:
                cout << ms.GetTop() << endl;
                ms.MinPop();
                break;
        }
    }
    return 0;
}
