#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode *_next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode *_front;
	QueueNode *_rear;
}Queue;

void QueueInit(Queue *pq);
void QueueDestory(Queue *pq);

QueueNode* BuyQueueNode(QUDataType x);

void QueuePush(Queue *pq, QUDataType x);
void QueuePop(Queue *pq);
QUDataType QueueFront(Queue *pq);
QUDataType QueueBack(Queue *pq);
bool QueueEmpty(Queue *pq);
int QueueSize(Queue *pq);


void QueueInit(Queue *pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;
}

void QueueDestory(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq->_front;
	while (cur)
	{
		QueueNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}


QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue *pq, QUDataType x)
{
	assert(pq);
	QueueNode *newnode = BuyQueueNode(x);
	if (pq->_rear == NULL)
	{
		pq->_front = pq->_rear = newnode;
	}
	else
	{
		pq->_rear->_next = newnode;
		pq->_rear = newnode;
	}
}
void QueuePop(Queue *pq)
{
	assert(pq && pq->_front != NULL);
	QueueNode *next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
		pq->_rear = NULL;
}
QUDataType QueueFront(Queue *pq)
{
	assert(pq && pq->_front != NULL);;
	return pq->_front->_data;
}
QUDataType QueueBack(Queue *pq)
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}
bool QueueEmpty(Queue *pq)
{
	assert(pq);
	return pq->_front == NULL;
}
int QueueSize(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq->_front;
	size_t size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}



typedef struct {
	Queue _q1;
	Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *st = (MyStack *)malloc(sizeof(MyStack));
	QueueInit(&(st->_q1));
	QueueInit(&(st->_q2));
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&(obj->_q1)))
		QueuePush(&(obj->_q1), x);
	else
		QueuePush(&(obj->_q2), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue *emptyQ = &(obj->_q1);
	Queue *nonemptyQ = &(obj->_q2);
	if (!QueueEmpty(&(obj->_q1)))
	{
		emptyQ = &(obj->_q2);
		nonemptyQ = &(obj->_q1);
	}
	while (QueueSize(nonemptyQ) > 1)
	{
		int front = QueueFront(nonemptyQ);
		QueuePop(nonemptyQ);
		QueuePush(emptyQ, front);
	}
	int front = QueueFront(nonemptyQ);
	QueuePop(nonemptyQ);
	return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&(obj->_q1)))
		return QueueBack(&(obj->_q1));
	else
		return QueueBack(&(obj->_q2));
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->_q1)) && QueueEmpty(&(obj->_q2));
}

void myStackFree(MyStack* obj) {
	QueueDestory(&(obj->_q1));
	QueueDestory(&(obj->_q2));
	free(obj);
}
