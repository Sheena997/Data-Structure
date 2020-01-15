#include "Stack.h"

void test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 3);
	StackPush(&s, 2);
	StackPush(&s, 1);
	printf("栈大小为：%d\n", StackSize(&s));
	printf("栈顶元素为：%d\n", StackTop(&s));
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
}
int main()
{
	test();

	return 0;
}