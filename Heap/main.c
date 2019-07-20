#include "Heap.h"

void Test1()
{
	int a[] = { 9,5,4,10,8,1,6,7,0,3,2 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(int));
	HeapPrint(&hp);
	HeapPush(&hp, 13);
	HeapPrint(&hp);
	HeapPush(&hp, -9);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HPDataType h = HeapTop(&hp);
	printf("%d\n", h);
	printf("%d\n",HeapSize(&hp));
	HeapDestory(&hp);
}
void Test2()
{
	int a[] = { 9,5,4,10,8,1,6,7,0,3,2 };
	HeapSort(a, sizeof(a)/sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	Test1();
	printf("\n");
	Test2();
	system("pause");
	return 0;
}