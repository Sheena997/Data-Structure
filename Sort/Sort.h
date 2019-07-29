#pragma once

#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertSort(int *a, int n);
void ShellSort(int *a, int n);
void SelectSort(int *a, int n);
void HeapSort(int *a, int n);
void BubbleSort(int *a, int n);
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSort3(int* a, int left, int right);
void MergeSort(int* a, int left, int right);
void MergeSort2(int* a, int n);
void CountSort(int* a, int n);







void Print(int *a, int n);

void InsertSortTest();
void ShellSortTest();
void SelectSortTest();
void HeapSortTest();
void BubbleSortTest();
void QuickSortTest1();
void QuickSortTest2();
void QuickSortTest3();
void MergeSortTest();
void MergeSortTest2();
void CountSortTest();




typedef struct Heap
{
	int *_a;
	int _size;
	int _capacity;
}Heap;

