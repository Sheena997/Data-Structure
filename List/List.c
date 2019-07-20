#include "List.h"

void ListInit(List *plt)
{
	assert(plt);
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	plt->_head = head;
}


ListNode* ListFind(List *plt, LTDataType x)
{
	assert(plt);
	ListNode *head = plt->_head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
ListNode* BuyListNode(LTDataType x)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;
	return node;
}
void ListInsert(ListNode *pos, LTDataType x)
{
	ListNode *prev = pos->_prev;
	ListNode *newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;

	pos->_prev = newnode;
	newnode->_next = pos;

}
void ListErase(ListNode *pos)
{
	ListNode *prev = pos->_prev;
	ListNode *next = pos->_next;

	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

void ListPushBack(List *plt, LTDataType x)
{
	/*
	assert(plt);
	ListNode *newnode = BuyListNode(x);
	ListNode *head = plt->_head;
	ListNode *tail = head->_prev;

	head->_prev = newnode;
	newnode->_next = head;

	tail->_next = newnode;
	newnode->_prev = tail;
	*/
	assert(plt);
	ListInsert(plt->_head, x);
}
void ListPushFront(List *plt, LTDataType x)
{
	/*
	assert(plt);
	ListNode *head = plt->_head;
	ListNode *newnode = BuyListNode(x);
	ListNode *first = head->_next;

	head->_next = newnode;
	newnode->_prev = head;

	first->_prev = newnode;
	newnode->_next = first;
    */
	assert(plt);
	ListInsert(plt->_head->_next, x);
}

void ListPopBack(List *plt)
{
	/*
	assert(plt);
	ListNode *head = plt->_head;
	assert(head->_next != head);

	ListNode *tail = head->_prev;
	ListNode *prev = tail->_prev;
	
	free(tail);
	prev->_next = head;
	head->_prev = prev;
	*/
	assert(plt);
	ListNode *head = plt->_head;
	assert(head->_next != head);
	ListErase(head->_prev);
}
void ListPopFront(List *plt)
{
	/*
	assert(plt);
	ListNode *head = plt->_head;
	assert(head->_next != head);
	ListNode *first = head->_next;
	ListNode *second =first->_next;

	free(first);
	head->_next = second;
	second->_prev = head;
	*/
	assert(plt);
	ListNode *head = plt->_head;
	assert(head->_next != head);
	ListErase(head->_next);
}

void ListPrint(List *plt)
{
	assert(plt);
	ListNode *head = plt->_head;
	ListNode *cur = head->_next;
	printf("head");
	while (cur != head)
	{
		printf("<=>%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

	
	

void ListDestory(List *plt)
{
	assert(plt);
	ListNode *head = plt->_head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		ListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	plt->_head = NULL;
}