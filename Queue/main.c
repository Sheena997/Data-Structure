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
	printf("��ͷԪ���ǣ�%d\n", q._front->_data);
	printf("��βԪ���ǣ�%d\n", q._rear->_data);
	printf("���д�СΪ��%d\n", QueueSize(&q));
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