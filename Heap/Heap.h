#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType *_a;
	int _size;
	int _capacity;
}Heap;

void AdjustDown(HPDataType *a, size_t n, size_t parent);
void HeapInit(Heap *hp, HPDataType *a, int n);
void HeapDestory(Heap *hp);

void HeapPush(Heap *hp, HPDataType x);
void AdjustUp(HPDataType *a, size_t child);
void HeapPop(Heap *hp);

HPDataType HeapTop(Heap *hp);
size_t HeapSize(Heap *hp);
bool HeapEmpty(Heap *hp);

void HeapPrint(Heap *hp);

void HeapSort(int *a, int n);
