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

static SListNode* _Buynode(ElemType x);//申请结点
void SListInit(SList* plist);//初始化
void SListPushBack(SList* plist, ElemType x);//尾插
void SListPushFront(SList* plist, ElemType x);//头插
void SListPopBack(SList* plist);//尾删
void SListPopFront(SList* plist);//头删
void SListDestroy(SList* plist);//销毁
 
void SListInsertByVal(SList* plist, ElemType x);//值插入

SListNode* SListFind(SList* plist, ElemType key);//查找
void SListDeleteByVal(SList* plist, ElemType key);//值删除

void SListClear(SList* plist);//清除
size_t SListLength(SList* plist);//长度

void SListReverse(SList* plist);//反转
void SListSort(SList* plist);//排序

void SListShow(SList* plist);//展示

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

	if (plist->head == NULL)//head为空?
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
		printf("要删除的节点不存在.\n");
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

	if (prev == NULL) //x<head,需要进行头部插入
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
	plist->head->next = NULL; //断开链表
	t = plist->head;

	while (p != NULL)
	{
		q = p->next;
		//把p节点摘除进行按值插入，升序
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