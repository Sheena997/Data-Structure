#include "SList.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode *head = plist->_head;
	SListNode *cur = head->_next;
	while (cur != NULL)
	{
		SListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	node->_next = NULL;
	node->_data = x;
	return node;
}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode *n = BuySListNode(x);
	n->_next = plist->_head;
	plist->_head = n;
}
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	else
	{
		SListNode *next = plist->_head->_next;
		SListNode *cur = plist->_head;
		plist->_head = next;
		free(cur);
		cur = NULL;
	}
	
}
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode *n = BuySListNode(x);
	n->_next = pos->_next;
	pos->_next = n;
} 
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SListNode *cur = pos->_next;
		pos->_next = cur->_next;
		free(cur);
		cur = NULL;
	}
}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode *prev = NULL;
	SListNode *cur = plist->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)
				plist->_head = cur->_next;
			else
				prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while (cur != NULL)
	{
		printf("<=>%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

