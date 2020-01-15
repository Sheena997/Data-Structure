#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

// ���еĽṹ
typedef int QUDataType;

// ���н��Ľṹ������
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;// ��ͷ
	QueueNode* _rear;// ��β
}Queue;

void QueueInit(Queue* pq);// ���еĳ�ʼ��
void QueueDestory(Queue* pq);// ���е�����

QueueNode* BuyQueueNode(QUDataType x);// ����һ���µĽ��
void QueuePush(Queue* pq, QUDataType x);// ���(�Ӷ�ͷ���)
void QueuePop(Queue* pq);// ���ӣ��Ӷ�β���ӣ�

QUDataType QueueFront(Queue* pq);// ȡ��ͷԪ��
QUDataType QueueRear(Queue* pq);// ȡ��βԪ��

bool QueueEmpty(Queue* pq);// �ж϶����Ƿ�Ϊ��

int QueueSize(Queue* pq);// ��ȡ���еĴ�С