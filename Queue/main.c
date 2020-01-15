#include "Queue.h"

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("队头元素是：%d\n", q._front->_data);
	printf("队尾元素是：%d\n", q._rear->_data);
	printf("队列大小为：%d\n", QueueSize(&q));
	while (!QueueEmpty(&q))
	{
		printf("%d ", q._front->_data);
		QueuePop(&q);
	}
	printf("\n");
}
int main()
{
	test();

	return 0;
}