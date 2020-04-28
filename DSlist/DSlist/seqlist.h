#pragma once
#include"common.h"

#define SEQLIST_DEFAULT_SIZE 10

typedef struct SeqList
{
	ElemType* base;
	size_t capacity;//����
	size_t size;//ʵ�ʴ�С
}SeqList;

static bool _Inc(SeqList* pst); //���ӳɹ����� true, ʧ�ܷ���false

void SeqListInit(SeqList* pst);//��ʼ��
bool IsFull(SeqList* pst);//�ж���
bool IsEmpty(SeqList* pst);//�жϿ�
void SeqListPushBack(SeqList* pst, ElemType x);//β��
void SeqListPushFront(SeqList* pst, ElemType x);//ͷ��
void SeqListPopBack(SeqList* pst);//β��ɾ
void SeqListPopFront(SeqList* pst);//ͷ��ɾ

void SeqListInsertByPos(SeqList* pst, int pos, ElemType x);//λ�ò���
void SeqListInsertByVal(SeqList* pst, ElemType x);//ֵ����
void SeqListDeleteByPos(SeqList* pst, int pos);//λ��ɾ��
void SeqListDeleteByVal(SeqList* pst, ElemType key);//ֵ����
void SeqListRemoveAll(SeqList* pst, ElemType key);//ɾ��ȫ����
void SeqListSort(SeqList* pst);//����
int SeqListFind(SeqList* pst, ElemType key);//����
void SeqListReverse(SeqList* pst);//��ת


size_t SeqListLength(SeqList* pst);//����
size_t SeqListCapacity(SeqList* pst);//����
void SeqListClear(SeqList* pst);//��
void SeqListShow(SeqList* pst);//��ʾ
void SeqListDestroy(SeqList* pst);//���٣�

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
		printf("˳���ռ�����,���ܲ�������%d,�����ݣ�\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}
void SeqListPushFront(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ�����,���ܲ�������%d,�����ݣ�\n", x);
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
		printf("˳����ѿ�,����β��ɾ��Ԫ��.\n");
		return;
	}
	pst->size--;
}
void SeqListPopFront(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳����ѿ�,����tͷ��ɾ��Ԫ��.\n");
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
		printf("Ҫ�������ݵ�λ�÷Ƿ���%d���ܲ���.\n", x);
		return;
	}
	if (IsFull(pst))
	{
		printf("˳���ռ�����,���ܰ�λ�ò�������%d,�����ݣ�\n", x);
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
		printf("˳����ѿ�,���ܰ�λ��ɾ��Ԫ��.\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("Ҫɾ�����ݵ�λ�÷Ƿ������ܰ�λ��ɾ������.\n");
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
		printf("˳����ѿ�,���ܰ�ֵɾ��Ԫ��.\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
	{
		printf("Ҫɾ�������ݲ�����,����ɾ��.\n");
		return;
	}
	SeqListDeleteByPos(pst, pos);
}

void SeqListInsertByVal(SeqList* pst, ElemType x)
{
	//�Ӻ���ǰ�Ƚ�
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���ռ�����,���ܰ�ֵ�������� %d\n", x);
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

void SeqListSort(SeqList* pst)//ð������
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