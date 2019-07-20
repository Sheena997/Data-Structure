#include "Heap.h"

void Swap(size_t *p, size_t *q)
{
	size_t ret = *p;
	*p = *q;
	*q = ret;
}
void AdjustDown(HPDataType *a, size_t n, size_t parent)
{
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1] < a[child] && child + 1 < n)
		{
			++child;
		}
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap *hp, HPDataType *a, int n)
{
	hp->_a = malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = hp->_size = n;
	//创建小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
void HeapDestory(Heap *hp)
{
	if (hp->_a)
	{
		free(hp->_a);
	}
	hp->_capacity = hp->_size = 0;
	hp->_a = NULL;
}

void AdjustUp(HPDataType *a, size_t child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap *hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
    hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap *hp)
{
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap *hp)
{
	assert(hp->_size > 0);
	return hp->_a[0];
}
size_t HeapSize(Heap *hp)
{
	assert(hp->_size > 0);
	return hp->_size;
}
bool HeapEmpty(Heap *hp)
{
	assert(hp->_size > 0);
	return hp->_size == 0;
}

void HeapPrint(Heap *hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ",hp->_a[i]);
	}
	printf("\n");
}


void HeapSort(int *a, int n)
{
	//降序 建小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}