#pragma once
#include"common.h"
#define HeapDataType int
typedef struct Heap
{
	HeapDataType* base;
	int capacity;//容量
	int size;
}Heap;

void HeapInit(Heap* php, int n);//初始化
void MinHeapInsert(Heap* php, HeapDataType x);//插入
HeapDataType MinHeapRemove(Heap* php);//小堆移除
bool HeapEmpty(Heap* php);//判空
void HeapPrint(Heap* php);//打印
void HeapSort(Heap* php);//排序
void AdjustUp(HeapDataType* base, int start);//向上调整
void AdjustDown(HeapDataType* base, int start, int n);//向下调整

void HeapInit(Heap* php, int n)
{
	assert(php != NULL);
	php->base = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	assert(php->base != NULL);
	php->capacity = n;
	php->size = 0;
}
bool HeapEmpty(Heap* php)
{
	assert(php != NULL);
	return php->size == 0;
}
void MinHeapInsert(Heap* php, HeapDataType x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;
		AdjustUp(php->base, php->size);//从下往上调整为小堆
		php->size++;
	}
}
HeapDataType MinHeapRemove(Heap* php)
{
	assert(php != NULL);
	assert(php->size > 0);
	int heaptop_val = php->base[0];
	php->size--;
	php->base[0] = php->base[php->size];
	AdjustDown(php->base, 0, php->size);
	return heaptop_val;
}
void HeapPrint(Heap* php)
{
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->base[i]);
	}
	printf("\n");
}
void AdjustUp(HeapDataType* base, int start)
{
	int j = start;
	int i = (j - 1) / 2;
	HeapDataType tmp = base[j];
	while(j > 0)
	{
		if (tmp < base[i])
		{
			base[j] = base[i];
			j = i;
			i = (j - 1) / 2;
		}
		else
		{
			break;
		}
	}
	base[j] = tmp;
}
void AdjustDown(HeapDataType* base, int start, int n)
{
	int i = start;//根
	int j = 2 * i + 1;
	while (j<n)
	{
		if (j + 1 < n && base[j] > base[j + 1])
		{
			j++;
		}
		if (base[i] > base[j])
		{
			Swap(&base[i], &base[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(Heap* php, int ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		php->base[i] = ar[i];
	}
	php->size = n;
	int curpos = n / 2 - 1;//最后一个分支
	while (curpos >= 0)
	{
		AdjustDown(php->base, curpos, n);
		curpos--;
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&php->base[0], &php->base[end]);
		AdjustDown(php->base, 0, end);
		end--;
	}
	int k = php->size - 1;
	for (int i = 0; i < n; ++i)
	{
		ar[i] = php->base[k--];
	}
}

/*
void AdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j-1)/2;
	while(j > 0)
	{
		if(base[j] < base[i])
		{
			Swap(&(base[j]), &(base[i]));
			j = i;
			i = (j-1)/2;
		}
		else
			break;
	}
}
*/
//自己建立大堆的实现