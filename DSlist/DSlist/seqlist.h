#pragma once
#include"common.h"

#define SEQLIST_DEFAULT_SIZE 10

typedef struct SeqList
{
	ElemType* base;
	size_t capacity;//容量
	size_t size;//实际大小
}SeqList;

static bool _Inc(SeqList* pst); //增加成功返回 true, 失败返回false

void SeqListInit(SeqList* pst);//初始化
bool IsFull(SeqList* pst);//判断满
bool IsEmpty(SeqList* pst);//判断空
void SeqListPushBack(SeqList* pst, ElemType x);//尾插
void SeqListPushFront(SeqList* pst, ElemType x);//头插
void SeqListPopBack(SeqList* pst);//尾部删
void SeqListPopFront(SeqList* pst);//头部删

void SeqListInsertByPos(SeqList* pst, int pos, ElemType x);//位置插入
void SeqListInsertByVal(SeqList* pst, ElemType x);//值插入
void SeqListDeleteByPos(SeqList* pst, int pos);//位置删除
void SeqListDeleteByVal(SeqList* pst, ElemType key);//值插入
void SeqListRemoveAll(SeqList* pst, ElemType key);//删除全部？
void SeqListSort(SeqList* pst);//排序
int SeqListFind(SeqList* pst, ElemType key);//查找
void SeqListReverse(SeqList* pst);//反转


size_t SeqListLength(SeqList* pst);//长度
size_t SeqListCapacity(SeqList* pst);//容量
void SeqListClear(SeqList* pst);//？
void SeqListShow(SeqList* pst);//显示
void SeqListDestroy(SeqList* pst);//销毁？

static bool _Inc(SeqList* pst)
{
	ElemType* new_base = (ElemType*)realloc(pst->base, sizeof(ElemType) * pst->capacity * 2);
	if (new_base== NULL)
	{
		return false;
	}
	pst->base = new_base;
	pst->capacity *= 2;
	return true;
}

void SeqListInit(SeqList* pst)
{
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

bool IsFull(SeqList* pst)
{
	assert(pst != NULL); 
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	assert(pst != NULL); 
	return pst->size == 0;
}

void SeqListPushBack(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满,不能插入数据%d,请扩容！\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}
void SeqListPushFront(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满,不能插入数据%d,请扩容！\n", x);
		return;
	}
	for (size_t pos=pst->size;pos>0;--pos)
	{
		pst->base[pos] = pst->base[pos - 1];
	}
	pst->base[0] = x;
	pst->size++;
}

void SeqListPopBack(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空,不能尾部删除元素.\n");
		return;
	}
	pst->size--;
}
void SeqListPopFront(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空,不能t头部删除元素.\n");
		return;
	}
	for (int i=0;i< pst->size;i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListInsertByPos(SeqList* pst, int pos, ElemType x)
{
	assert(pst != NULL);
	if (pos<0 || pos> pst->size)
	{
		printf("要插入数据的位置非法，%d不能插入.\n", x);
		return;
	}
	if (IsFull(pst))
	{
		printf("顺序表空间已满,不能按位置插入数据%d,请扩容！\n", x);
		return;
	}
	for (int i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}
void SeqListDeleteByPos(SeqList* pst, int pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空,不能按位置删除元素.\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("要删除数据的位置非法，不能按位置删除数据.\n");
		return;
	}
	for (int i = pos; i < pst->size; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListDeleteByVal(SeqList* pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空,不能按值删除元素.\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
	{
		printf("要删除的数据不存在,不能删除.\n");
		return;
	}
	SeqListDeleteByPos(pst, pos);
}

void SeqListInsertByVal(SeqList* pst, ElemType x)
{
	//从后往前比较
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表空间已满,不能按值插入数据 %d\n", x);
		return;
	}

	int end = pst->size;
	while (end > 0 && x < pst->base[end - 1])
	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = x;
	pst->size++;
}

void SeqListSort(SeqList* pst)//冒泡排序
{
	assert(pst != NULL);
	if (pst->size <= 1)
		return;
	for (int i = 0; i < pst->size - 1; ++i)
	{
		for (int j = 0; j < pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

int SeqListFind(SeqList* pst,ElemType key)
{
	assert(pst != 0);
	for (int i = 0; i < pst->size; i++)
	{
		if (key == pst->base[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListReverse(SeqList* pst)
{
	assert(pst != NULL);
	if (pst->size < 2)
	{
		return;
	}
	int left = 0;
	int right = pst->size - 1;
	while (left < right)
	{
		Swap(&pst->base[left], &pst->base[right]);
		left++;
		right--;
	}
}

size_t SeqListLength(SeqList* pst)
{
	assert(pst != NULL);
	return pst->size;
}

size_t SeqListCapacity(SeqList* pst)
{
	assert(pst != NULL);
	return pst->capacity;
}

void SeqListClear(SeqList* pst)
{
	assert(pst != NULL);
	pst->size = 0;
}

void SeqListShow(SeqList* pst)
{
	assert(pst != NULL);
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListDestroy(SeqList* pst)
{
	assert(pst != NULL);
	if (pst->base)
	{
		free(pst->base);
	}
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}