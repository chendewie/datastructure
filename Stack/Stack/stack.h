#pragma once
#include"common.h"
//˳��ջ
#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE     3
typedef struct SeqStack
{
	ElemType* base;
	size_t capacity;
	int top;
}SeqStack;

void SeqStackInit(SeqStack* pst);//��ʼ��
bool SeqStackIsFull(SeqStack* pst);//�ж���
bool SeqStackIsEmpty(SeqStack* pst);//�жϿ�
void SeqStackPush(SeqStack* pst, ElemType x);//��ջ
void SeqStackPop(SeqStack* pst);//��ջ
ElemType SeqStackTop(SeqStack* pst); //ȡջ��Ԫ��
void SeqStackPrint(SeqStack* pst);//��ӡ���
void SeqStackDestroy(SeqStack* pst);//����

void SeqStackInit(SeqStack* pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base!=NULL);
	pst->capacity = SEQ_STACK_DEFAULT_SIZE;
	pst->top = 0;
}
bool SeqStackIsFull(SeqStack* pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}
bool SeqStackIsEmpty(SeqStack* pst)
{
	assert(pst!=NULL);
	return pst->top == 0;
}
void SeqStackPush(SeqStack* pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst))
	{
		printf("ջ����������ջ.\n");
		return;
	}
	pst->base[pst->top++] = x;
}
void SeqStackPop(SeqStack* pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿգ����ܳ�ջ.\n");
		return;
	}
	pst->top--;
}
ElemType SeqStackTop(SeqStack* pst)
{
	assert(pst!=NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿգ�����ȡջ��.\n");
		return;
	}
	return pst->base[pst->top - 1];
}
void SeqStackPrint(SeqStack* pst)
{
	assert(pst != NULL);
	for (int i=pst->top-1;i>=0;--i)
	{
		printf("%d\n", pst->base[i]);
	}
	printf("\n");
}
void SeqStackDestroy(SeqStack* pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}
//��ջ
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode* link;//next
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode* top;
}LinkStack;
void LinkStackInit(LinkStack* pst);//��ʼ��
void LinkStackPush(LinkStack* pst, ElemType x);//��ջ
void LinkStackPop(LinkStack* pst);//��ջ
ElemType LinkStackTop(LinkStack* pst);//ȡջ��
void LinkStackPrint(LinkStack* pst);//��ӡ
void LinkStackDestroy(LinkStack* pst);//����

void LinkStackInit(LinkStack* pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}//��ʼ��
void LinkStackPush(LinkStack* pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;
	node->link = pst->top;
	pst->top = node;
}//��ջ
void LinkStackPop(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* p = pst->top;
	pst->top = p->link;
	free(p);
}//��ջ
ElemType LinkStackTop(LinkStack* pst)
{
	assert(pst != NULL);
	if (pst->top==NULL)
	{
		printf("ջ�գ����ܳ�ջ.\n");
		return;
	}
	return pst->top->data;
}//ȡջ��
void LinkStackPrint(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* p = pst->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}//��ӡ
void LinkStackDestroy(LinkStack* pst)
{
	assert(pst != NULL);
	while (pst->top!=NULL)
	{
		LinkStackNode* p = pst->top;
		pst->top = p->link;
		free(p);
	}
}//����