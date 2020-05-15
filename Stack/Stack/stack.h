#pragma once
#include"common.h"
//顺序栈
#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE     3
typedef struct SeqStack
{
	ElemType* base;
	size_t capacity;
	int top;
}SeqStack;

void SeqStackInit(SeqStack* pst);//初始化
bool SeqStackIsFull(SeqStack* pst);//判断满
bool SeqStackIsEmpty(SeqStack* pst);//判断空
void SeqStackPush(SeqStack* pst, ElemType x);//入栈
void SeqStackPop(SeqStack* pst);//出栈
ElemType SeqStackTop(SeqStack* pst); //取栈顶元素
void SeqStackPrint(SeqStack* pst);//打印输出
void SeqStackDestroy(SeqStack* pst);//销毁

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
		printf("栈满，不能入栈.\n");
		return;
	}
	pst->base[pst->top++] = x;
}
void SeqStackPop(SeqStack* pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}
ElemType SeqStackTop(SeqStack* pst)
{
	assert(pst!=NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能取栈顶.\n");
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
//链栈
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode* link;//next
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode* top;
}LinkStack;
void LinkStackInit(LinkStack* pst);//初始化
void LinkStackPush(LinkStack* pst, ElemType x);//入栈
void LinkStackPop(LinkStack* pst);//出栈
ElemType LinkStackTop(LinkStack* pst);//取栈顶
void LinkStackPrint(LinkStack* pst);//打印
void LinkStackDestroy(LinkStack* pst);//销毁

void LinkStackInit(LinkStack* pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}//初始化
void LinkStackPush(LinkStack* pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;
	node->link = pst->top;
	pst->top = node;
}//入栈
void LinkStackPop(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* p = pst->top;
	pst->top = p->link;
	free(p);
}//出栈
ElemType LinkStackTop(LinkStack* pst)
{
	assert(pst != NULL);
	if (pst->top==NULL)
	{
		printf("栈空，不能出栈.\n");
		return;
	}
	return pst->top->data;
}//取栈顶
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
}//打印
void LinkStackDestroy(LinkStack* pst)
{
	assert(pst != NULL);
	while (pst->top!=NULL)
	{
		LinkStackNode* p = pst->top;
		pst->top = p->link;
		free(p);
	}
}//销毁