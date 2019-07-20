#pragma once
#define _SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode *_prev;
	struct ListNode *_next;
	LTDataType _data;
}ListNode;
typedef struct List
{
	ListNode *_head;
}List;

void ListInit(List *plt);
void ListDestory(List *plt);

ListNode* ListFind(List *plt, LTDataType x);

void ListInsert(ListNode *pos, LTDataType x);
void ListErase(ListNode *pos);

void ListPushBack(List *plt, LTDataType x);
void ListPushFront(List *plt, LTDataType x);

void ListPopBack(List *plt);
void ListPopFront(List *plt);

void ListPrint(List *plt);



