#pragma once
#include"common.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode* head;
}SList;

static SListNode* _Buynode(ElemType x);//������
void SListInit(SList* plist);//��ʼ��
void SListPushBack(SList* plist, ElemType x);//β��
void SListPushFront(SList* plist, ElemType x);//ͷ��
void SListPopBack(SList* plist);//βɾ
void SListPopFront(SList* plist);//ͷɾ
void SListDestroy(SList* plist);//����
 
void SListInsertByVal(SList* plist, ElemType x);//ֵ����

SListNode* SListFind(SList* plist, ElemType key);//����
void SListDeleteByVal(SList* plist, ElemType key);//ֵɾ��

void SListClear(SList* plist);//���
size_t SListLength(SList* plist);//����

void SListReverse(SList* plist);//��ת
void SListSort(SList* plist);//����

void SListShow(SList* plist);//չʾ

static SListNode* _Buynode(ElemType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)
{
	plist->head = NULL;
}

void SListPushBack(SList* plist,ElemType x)
{
	assert(plist != NULL);
	SListNode* s = _Buynode(x);

	if (plist->head == NULL)//headΪ��?
	{
		plist->head = s;
		return;
	}
	SListNode* p = plist->head;
	while (p->next!=NULL)
	{
		p = p->next;
	}
	p->next = s;
}

void SListPushFront(SList* plist,ElemType x)
{
	assert(plist != NULL);
	SListNode* s = _Buynode(x);
	s->next = plist->head;
	plist->head = s;
}

void SListPopBack(SList* plist)
{
	assert(plist!=0);
	SListNode* p=NULL;
	SListNode* prev=NULL;

	if (plist->head==NULL)
	{
		return;
	}
	p = plist->head;
	if (p->next==NULL)
	{
		plist->head = NULL;
	}
	else
	{
		while (p->next!=NULL)
		{
			prev = p;
			p = p->next;
		}
		prev->next = NULL;
	}
	free(p);
}

void SListPopFront(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	if (plist->head == NULL)
	{
		return;
	}
	plist->head = p->next;
	free(p);
}

SListNode* SListFind(SList* plist, ElemType key)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	while (p!=NULL && p->data!=key)
	{
		p = p->next;
	}
	return p;
}

void SListDeleteByVal(SList* plist, ElemType key)
{
	assert(plist != NULL);
	SListNode* prev = NULL;
	SListNode* p = SListFind(plist, key);
	if (p == NULL)
	{
		printf("Ҫɾ���Ľڵ㲻����.\n");
		return;
	}
	if (p == plist->head)
	{
		plist->head = p->next;
	}
	else
	{
		prev = plist->head;
		while (prev->next != p)
		{
			prev = prev->next;
		}

		prev->next = p->next;
	}
	free(p);
}

size_t SListLength(SList* plist)
{
	assert(plist != NULL);
	size_t len = 0;
	SListNode* p = plist->head;

	while (p!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void SListShow(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void SListClear(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;

	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList* plist)
{
	SListClear(plist);
	plist->head = NULL;
}

void SListReverse(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head->next;
	SListNode* q;
	if (p->next == NULL)
	{
		return;
	}

	plist->head->next = NULL;
	while (p!=NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}

void SListInsertByVal(SList* plist, ElemType x)
{
	assert(plist != NULL);
	SListNode* prev = NULL;
	SListNode* p = plist->head;

	SListNode* s = _Buynode(x);

	while (p != NULL && x > p->data)
	{
		prev = p;
		p = p->next;
	}

	if (prev == NULL) //x<head,��Ҫ����ͷ������
	{
		s->next = p;
		plist->head = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}

void SListSort(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head->next;
	SListNode* q, * t, * prev = NULL;
	plist->head->next = NULL; //�Ͽ�����
	t = plist->head;

	while (p != NULL)
	{
		q = p->next;
		//��p�ڵ�ժ�����а�ֵ���룬����
		while (t != NULL && p->data >= t->data)
		{
			prev = t;
			t = t->next;
		}

		if (prev == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		else if (t == NULL)
		{
			p->next = t;
			prev->next = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		p = q;
		t = plist->head;
	}
}