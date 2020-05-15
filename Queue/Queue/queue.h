#pragma once
#include"common.h"
#define SEQ_QUEUE_DEFAULT_SIZE 8
//顺序队列
typedef struct SeqQueue
{
	ElemType* base;
	int capacity;
	int front;
	int rear;
}SeqQueue;
void SeqQueueInit(SeqQueue* psq);//初始化
bool SeqQueueIsFull(SeqQueue* psq);//判断满
bool SeqQueueIsEmpty(SeqQueue* psq);//判断空
void SeqQueueEnque(SeqQueue* psq, ElemType x);//入队
void SeqQueueDeque(SeqQueue* psq);//出队
ElemType SeqQueueFront(SeqQueue* psq);//取对头
void SeqQueuePrint(SeqQueue* psq);//打印

void SeqQueueInit(SeqQueue* psq)
{
	assert(psq != NULL);
	psq->base = (ElemType*)malloc(sizeof(ElemType) * SEQ_QUEUE_DEFAULT_SIZE);
	assert(psq->base != NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE;
	psq->front = psq->rear = 0;
}//初始化
bool SeqQueueIsFull(SeqQueue* psq)
{
	assert(psq != NULL);
	return psq->rear >= psq->capacity;
}//判断满
bool SeqQueueIsEmpty(SeqQueue* psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}//判断空
void SeqQueueEnque(SeqQueue* psq, ElemType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		printf("队列已满，不能入队.\n");
		return;
	}
	psq->base[psq->rear++] = x;
}//入队
void SeqQueueDeque(SeqQueue* psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("队列以空，不能出队.\n");
		return;
	}
	psq->front++;
}//出队
ElemType SeqQueueFront(SeqQueue* psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("队列已空，不能取对头.\n");
		return;
	}
	return psq->base[psq->front];
}//取对头
void SeqQueuePrint(SeqQueue* psq)
{
	assert(psq != NULL);
	for(int i=psq->front;i<psq->rear;++i)
	{
		printf("%d ", psq->base[i]);
	}
	printf("\n");
}//打印
//循环队列
#define CIRCLE_QUEUE_DEFAULT_SIZE 8
#define CIRCLE_QUEUE_INC_SIZE 4
typedef struct CircleQueue
{
	ElemType* base;
	int capacity;
	int front;
	int rear;
}CircleQueue;
void CircleQueueInit(CircleQueue* psq);//初始化
bool CircleQueueIsFull(CircleQueue* psq);//判断满
bool CircleQueueIsEmpty(CircleQueue* psq);//判断空
void CircleQueueEnque(CircleQueue* psq, ElemType x);//入队
void CircleQueueDeque(CircleQueue* psq);//出队
ElemType CircleQueueFront(CircleQueue* psq);//取对头
void CircleQueuePrint(CircleQueue* psq);//打印

void CircleQueueInit(CircleQueue* psq)
{
	assert(psq != NULL);
	psq->base=(ElemType*)malloc(sizeof(ElemType) * (CIRCLE_QUEUE_DEFAULT_SIZE + 1));
	assert(psq->base!=NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE + 1;
	psq->front = psq->rear = 0;
}//初始化
bool CircleQueueIsFull(CircleQueue* psq)
{
	assert(psq != NULL);
	return ((psq->rear + 1) % psq->capacity) == psq->front;
}//判断满
bool CircleQueueIsEmpty(CircleQueue* psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}//判断空
void CircleQueueEnque(CircleQueue* psq, ElemType x)
{
	assert(psq!=NULL);
	if (CircleQueueIsFull(psq))
	{
		printf("循环队列已满，不能入队.\n");
			return;
	}
	psq->base[psq->rear] = x;
	psq->rear = (psq->rear + 1) % psq->capacity;
}//入队
void CircleQueueDeque(CircleQueue* psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("循环队列已空，不能出队.\n");
		return;
	}
	psq->front = (psq->front + 1) % psq->capacity;
}//出队
ElemType CircleQueueFront(CircleQueue* psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("循环队列已空，不能取队头.\n");
		return;
	}
	return psq->base[psq->front];
}//取对头
void CircleQueuePrint(CircleQueue* psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i != psq->rear;)
	{
		printf("%d ", psq->base[i]);
		i = (i + 1) % psq->capacity;
	}
}//打印
//链式队列
typedef struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode* link;
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;
void LinkQueueInit(LinkQueue* pq);//初始化
void LinkQueueEnQue(LinkQueue* pq, ElemType x);//入队
void LinkQueueDeQue(LinkQueue* pq);//出队
void LinkQueuePrint(LinkQueue* pq);//打印
bool LinkQueueEmpty(LinkQueue* pq);//判空
ElemType LinkQueueFront(LinkQueue* pq);//取对头

void LinkQueueInit(LinkQueue* pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}//初始化
void LinkQueueEnQue(LinkQueue* pq, ElemType x)
{
	assert(pq != NULL);
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;
	if (pq->front == NULL)
	{
		pq->front = pq->rear = node;
	}
	else
	{
		pq->rear->link = node;
		pq->rear=node;
	}
}//入队
void LinkQueueDeQue(LinkQueue* pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode* p = pq->front;
		pq->front = p->link;
		free(p);
	}
}//出队
void LinkQueuePrint(LinkQueue* pq)
{
	assert(pq != NULL);
	LinkQueueNode* p = pq->front;
	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}//打印
bool LinkQueueEmpty(LinkQueue* pq)
{
	return pq->front == NULL;
}//判空
ElemType LinkQueueFront(LinkQueue* pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}//取对头