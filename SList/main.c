#include "SList.h"

void TestSList()
{
	SList lt;
	SListInit(&lt);
	SListPushFront(&lt, 1);
	SListPushFront(&lt, 2);
	SListPushFront(&lt, 3);
	SListPushFront(&lt, 4);
	SListPushFront(&lt, 5);
	SListPushFront(&lt, 6);
	SListPushFront(&lt, 7);
	SListPrint(&lt);
	SListPopFront(&lt);
	SListPrint(&lt);
	SListNode *pos1 = SListFind(&lt, 6);
	SListInsertAfter(pos1, 12);
	SListPrint(&lt);
	SListNode *pos2 = SListFind(&lt, 5);
	SListEraseAfter(pos2);
	SListPrint(&lt);
	SListRemove(&lt, 2);
	SListPrint(&lt);
	SListDestory(&lt);
}
int main()
{
	TestSList();
	system("pause");
	return 0;
}