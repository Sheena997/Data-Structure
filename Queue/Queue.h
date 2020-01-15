#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

// 队列的结构
typedef int QUDataType;

// 队列结点的结构（链表）
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;// 队头
	QueueNode* _rear;// 队尾
}Queue;

void QueueInit(Queue* pq);// 队列的初始化
void QueueDestory(Queue* pq);// 队列的销毁

QueueNode* BuyQueueNode(QUDataType x);// 创建一个新的结点
void QueuePush(Queue* pq, QUDataType x);// 入队(从队头入队)
void QueuePop(Queue* pq);// 出队（从队尾出队）

QUDataType QueueFront(Queue* pq);// 取队头元素
QUDataType QueueRear(Queue* pq);// 取队尾元素

bool QueueEmpty(Queue* pq);// 判断队列是否为空

int QueueSize(Queue* pq);// 获取队列的大小