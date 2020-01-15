#include "Queue.h"

void QueueInit(Queue* pq)
{
	// 队列的初始化
	assert(pq);
	pq->_front = pq->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
	// 队列的销毁
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	// 创建一个新的结点
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_next = NULL;
	node->_data = x;

	return node;
}
void QueuePush(Queue* pq, QUDataType x)
{
	// 入队(从队头入队)
	assert(pq);
	QueueNode* node = BuyQueueNode(x);
	if (pq->_rear == NULL)
	{
		pq->_front = pq->_rear = node;
	}
	else
	{
		pq->_rear->_next = node;
		pq->_rear = node;
	}
}
void QueuePop(Queue* pq)
{
	// 出队（从队尾出队）
	assert(pq && pq->_front != NULL);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
		pq->_rear = NULL;
}

QUDataType QueueFront(Queue* pq)
{
	// 取队头元素
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}
QUDataType QueueRear(Queue* pq)
{
	// 取队尾元素
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}

bool QueueEmpty(Queue* pq)
{
	// 判断队列是否为空
	assert(pq);
	return pq->_front == NULL;
}

int QueueSize(Queue* pq)
{
	// 获取队列的大小
	assert(pq);
	QueueNode* cur = pq->_front;
	size_t size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}