#include "List.h"

void Test()
{
	List lt;
	ListInit(&lt);
	ListPushBack(&lt, 1);
	ListPushBack(&lt, 2);
	ListPushBack(&lt, 3);
	ListPushBack(&lt, 4); 
	ListPushBack(&lt, 5);
	ListPrint(&lt);
	ListDestory(&lt);

	ListInit(&lt);
	ListPushFront(&lt, 6);
	ListPushFront(&lt, 7);
	ListPushFront(&lt, 8);
	ListPushFront(&lt, 9);
	ListPushFront(&lt, 10);
	ListPrint(&lt);
	ListNode *pos = ListFind(&lt, 8);
	ListInsert(pos, 20);
	ListPrint(&lt);
	ListNode *pos2 = ListFind(&lt, 7);
	ListErase(pos2);
	ListPrint(&lt);
	ListPopBack(&lt);
	ListPopFront(&lt);
	ListPrint(&lt);
	ListDestory(&lt);
}
int main()
{
	Test();
	system("pause");
	return;
}