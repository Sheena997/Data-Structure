#include "sort.h"
#include "Stack.h"

//直接插入排序
void InsertSort(int *a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
		    int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int *m, int *n)
{
	int t = *m;
	*m = *n;
	*n = t;
}

//直接选择排序
void SelectSort(int *a, int n)
{
	int min_index = 0;
	int max_index = 0;
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		min_index = max_index = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[min_index] > a[i])
				min_index = i;
			if (a[max_index] < a[i])
				max_index = i;
		}
		Swap(&a[min_index], &a[begin]);
	    if (max_index == begin)
			max_index = min_index;
	    Swap(&a[max_index], &a[end]);
		++begin;
		--end;
	}
	
}

//堆排序
void AdjustDown(int *a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
		{
			++child;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *a, int n)
{
	//升序建大堆   降序建小堆
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

//冒泡排序
void BubbleSort(int *a, int n)
{
	int end = n;
	while (end > 0)
	{
		for (int i = 1; i < n; ++i)
		{
			if (a[i - 1] > a[i])
				Swap(&a[i - 1], &a[i]);
		}
		--end;
	}
}


//快速排序
//左右指针法
int PartSort1(int* a, int left, int right)
{
	/*加上三数取中法来优化
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	*/
	int key = a[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
			++left;
		while (left < right && a[right] >= key)
			--right;
		if (left < right)
		{
			Swap(&a[left], &a[right]);
			++left;
			--right;
		}
	}
	Swap(&a[left], &a[key_index]);
	return left;
}
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;
	int index = PartSort1(a, left, right);
	QuickSort1(a, left, index - 1);
	QuickSort1(a, index + 1, right);
}

//快速排序 
//挖坑法
int PartSort2(int* a, int left, int right)
{
	/*加上三数取中法来优化
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	*/
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
			++left;
		a[right] = a[left];
		while (left < right && a[right] >= key)
			--right;
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;
	/*优化代码用小区间优化法*/
	//if(right - left + 1 > 10)
  //{
	int index = PartSort2(a, left, right);
	QuickSort1(a, left, index - 1);
	QuickSort1(a, index + 1, right);
 // }
 /* else 
   {
      InsertSort(a + left, right - left + 1 );
	}*/
}

//快速排序
//前后指针法
int PartSort3(int *a, int left, int right)
{
	/*加上三数取中法来优化
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	*/
	
	int cur = left;
	int prev = left - 1;
	int key = a[right];
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	++prev;
	Swap(&a[right], &a[prev]);
	return prev;
}
//非递归的快速排序  用栈
void QuickSort3(int *a, int left, int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s,left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);
		int index = PartSort3(a, begin, end);
		if (begin < index - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, index - 1);
		}
		if (index + 1 < end)
		{
			StackPush(&s, index + 1);
			StackPush(&s, end);
		}
			
	}
	StackDestory(&s);
}



/*快速排序避免有序时时间复杂度为O(n^2)时采取的方法：
  1. 随机选key法 
  2. 三数取中法
  3. 小区间优化法（小区间时不用递归用直接插入法）*/
 
//三数取中法
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}



//归并排序
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1];
			++begin1;
		}
		else
		{
			tmp[i++] = a[begin2];
			++begin2;
		}
	}
	while (begin1 <= end1)//若begin1 - end1这段不为空
	{
		tmp[i++] = a[begin1];
		++begin1;
	}
	while (begin2 <= end2)//若begin2 - end2这段不为空
	{
		tmp[i++] = a[begin2];
		++begin2;
	}
	memcpy(a + left, tmp + left, sizeof(int)*(i - left));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}


void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}



void InsertSortTest()
{
	int s[] = { 2,1,3,5,7,6,8,9,10,4 };
	InsertSort(s, sizeof(s) / sizeof(int));
	Print(s, sizeof(s) / sizeof(int));
}
void ShellSortTest()
{
	int s[] = { 9,8,7,6,5,4,3,2,1 };
	ShellSort(s, sizeof(s) / sizeof(int));
	Print(s, sizeof(s) / sizeof(int));
}
void SelectSortTest()
{
	int s[] = { 9,8,7,6,5,4,3,2,1 };
	SelectSort(s, sizeof(s) / sizeof(int));
	Print(s, sizeof(s) / sizeof(int));
}
void HeapSortTest()
{
	int s[] = { 2,1,3,5,7,6,8,9,10,4 };
	HeapSort(s, sizeof(s) / sizeof(int));
	Print(s, sizeof(s) / sizeof(int));
}
void BubbleSortTest()
{
	int s[] = { 2,1,3,5,7,6,8,9,10,4 };
	BubbleSort(s, sizeof(s) / sizeof(int));
	Print(s, sizeof(s) / sizeof(int));
}
void QuickSortTest1()
{
	int s[] = { 2,1,3,5,7,6,8,9,10,4 };
	QuickSort1(&s, 0, sizeof(s) / sizeof(int) - 1);
	Print(s, sizeof(s) / sizeof(int));
}
void QuickSortTest2()
{
	int s[] = { 9,8,7,6,5,4,3,2,1 };
	QuickSort2(&s, 0, sizeof(s) / sizeof(int) - 1);
	Print(s, sizeof(s) / sizeof(int));
}
void QuickSortTest3()
{
	int s[] = { 2,1,3,5,7,6,8,9,10,4 };
	QuickSort3(&s, 0, sizeof(s) / sizeof(int) - 1);
	Print(s, sizeof(s) / sizeof(int));
}
void MergeSortTest()
{
	int s[] = { 9,8,7,6,5,4,3,2,1 };
	MergeSort(&s, sizeof(s) / sizeof(int));
	Print(s, sizeof(s) / sizeof(int));
}