#include "SeqList.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)*8);
	psl->capicity = capacity;
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->size > 0)
		free(psl->array);
	psl->array = NULL;
	psl->capicity = psl->size = 0;
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		int newcapacity = psl->capicity == 0 ? 2 : psl->capicity * 2;
		psl->array = (SLDataType*)realloc(psl->array, newcapacity*(sizeof(SLDataType)));
		psl->capicity = newcapacity;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	psl->size++;
	CheckCapacity(psl);
	for (int i = psl->size - 1; i > 0; --i)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[0] = x;
}
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	for (int i = 1; i < psl->size; i++)
	{
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
			return i;
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(pos >= 0 && pos <= psl->size - 1);
	psl->size++;
	CheckCapacity(psl);
	for (int i = psl->size - 1; i > pos; --i)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(pos >= 0 && pos <= psl->size - 1);
	for (int i = pos; i < psl->size - 1; ++i)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	/*
	int pos = SeqListFind(ps, x);
	if (pos != -1)
		SeqListErase(ps, pos);
	*/
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			for (int j = i; j < psl->size; ++j)
			{
				psl->array[j] = psl->array[j + 1];
			}
			psl->size--;
		}
	}
	
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(pos >= 0 && pos <= psl->size - 1);
	psl->array[pos] = x;
}
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i <= psl->size - 1; ++i)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
// 扩展面试题实现
void Swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	int end = psl->size;
	while (end > 0)
	{
		for (int i = 1; i < end; ++i)
		{
			if (psl->array[i - 1] > psl->array[i])
				Swap(&psl->array[i - 1], &psl->array[i]);
		}
		--end;
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int left = 0;
	int right = psl->size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (psl->array[mid] < x)
			left = mid + 1;
		else if (psl->array[mid] > x)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);
	int k = psl->size;
	for (int i = 0; i < k; i++)
	{
		if (psl->array[i] == x)
		{
			psl->array[i] = psl->array[i + 1];
			--psl->size;
		}
	}
}

void Test1()
{
	SeqList q;
	SeqListInit(&q, 8);
	SeqListPushBack(&q, 1);
	SeqListPushBack(&q, 2);
	SeqListPushBack(&q, 3);
	SeqListPushBack(&q, 4);
	SeqListPrint(&q);
	SeqListPopFront(&q);
	SeqListPopFront(&q);
	SeqListPrint(&q);
	SeqListPushFront(&q, 5);
	SeqListPushFront(&q, 6);
	SeqListPushFront(&q, 7); 
	SeqListPushFront(&q, 8);
	SeqListPrint(&q);
	SeqListPopFront(&q);
	SeqListPopFront(&q);
	SeqListPrint(&q);
	printf("%d\n", SeqListFind(&q, 4));
	printf("%d\n", SeqListFind(&q, 8));
	SeqListInsert(&q, 3, 12);
	SeqListPrint(&q);
	SeqListErase(&q, 2);
	SeqListPrint(&q);
	SeqListRemove(&q, 6);
	SeqListPrint(&q);
	SeqListRemove(&q, 10);
	SeqListPrint(&q);
	SeqListModify(&q, 1, 22);
	SeqListPrint(&q);
	SeqListDestory(&q);
}

void Test2()
{
	SeqList q;
	SeqListInit(&q, 8);
	SeqListPushBack(&q, 1);
	SeqListPushBack(&q, 9);
	SeqListPushBack(&q, 3);
	SeqListPushBack(&q, 0);
	SeqListPrint(&q);
	SeqListBubbleSort(&q);
	SeqListPrint(&q);
	printf("%d\n", SeqListBinaryFind(&q, 4));
	SeqListPushBack(&q, 4);
	SeqListPushBack(&q, 4);
	SeqListPushBack(&q, 4);
	SeqListPushBack(&q, 4);
	SeqListPrint(&q);
	SeqListRemoveAll(&q, 4);
	SeqListPrint(&q);
	SeqListDestory(&q);
}
