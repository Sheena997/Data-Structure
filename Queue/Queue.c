#include "Queue.h"

void QueueInit(Queue* pq)
{
	// ���еĳ�ʼ��
	assert(pq);
	pq->_front = pq->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
	// ���е�����
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
	// ����һ���µĽ��
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_next = NULL;
	node->_data = x;

	return node;
}
void QueuePush(Queue* pq, QUDataType x)
{
	// ���(�Ӷ�ͷ���)
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
	// ���ӣ��Ӷ�β���ӣ�
	assert(pq && pq->_front != NULL);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
		pq->_rear = NULL;
}

QUDataType QueueFront(Queue* pq)
{
	// ȡ��ͷԪ��
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}
QUDataType QueueRear(Queue* pq)
{
	// ȡ��βԪ��
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}

bool QueueEmpty(Queue* pq)
{
	// �ж϶����Ƿ�Ϊ��
	assert(pq);
	return pq->_front == NULL;
}

int QueueSize(Queue* pq)
{
	// ��ȡ���еĴ�С
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