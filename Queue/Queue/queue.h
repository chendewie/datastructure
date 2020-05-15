#pragma once
#include"common.h"
#define SEQ_QUEUE_DEFAULT_SIZE 8
//˳�����
typedef struct SeqQueue
{
	ElemType* base;
	int capacity;
	int front;
	int rear;
}SeqQueue;
void SeqQueueInit(SeqQueue* psq);//��ʼ��
bool SeqQueueIsFull(SeqQueue* psq);//�ж���
bool SeqQueueIsEmpty(SeqQueue* psq);//�жϿ�
void SeqQueueEnque(SeqQueue* psq, ElemType x);//���
void SeqQueueDeque(SeqQueue* psq);//����
ElemType SeqQueueFront(SeqQueue* psq);//ȡ��ͷ
void SeqQueuePrint(SeqQueue* psq);//��ӡ

void SeqQueueInit(SeqQueue* psq)
{
	assert(psq != NULL);
	psq->base = (ElemType*)malloc(sizeof(ElemType) * SEQ_QUEUE_DEFAULT_SIZE);
	assert(psq->base != NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE;
	psq->front = psq->rear = 0;
}//��ʼ��
bool SeqQueueIsFull(SeqQueue* psq)
{
	assert(psq != NULL);
	return psq->rear >= psq->capacity;
}//�ж���
bool SeqQueueIsEmpty(SeqQueue* psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}//�жϿ�
void SeqQueueEnque(SeqQueue* psq, ElemType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		printf("�����������������.\n");
		return;
	}
	psq->base[psq->rear++] = x;
}//���
void SeqQueueDeque(SeqQueue* psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�����Կգ����ܳ���.\n");
		return;
	}
	psq->front++;
}//����
ElemType SeqQueueFront(SeqQueue* psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�����ѿգ�����ȡ��ͷ.\n");
		return;
	}
	return psq->base[psq->front];
}//ȡ��ͷ
void SeqQueuePrint(SeqQueue* psq)
{
	assert(psq != NULL);
	for(int i=psq->front;i<psq->rear;++i)
	{
		printf("%d ", psq->base[i]);
	}
	printf("\n");
}//��ӡ
//ѭ������
#define CIRCLE_QUEUE_DEFAULT_SIZE 8
#define CIRCLE_QUEUE_INC_SIZE 4
typedef struct CircleQueue
{
	ElemType* base;
	int capacity;
	int front;
	int rear;
}CircleQueue;
void CircleQueueInit(CircleQueue* psq);//��ʼ��
bool CircleQueueIsFull(CircleQueue* psq);//�ж���
bool CircleQueueIsEmpty(CircleQueue* psq);//�жϿ�
void CircleQueueEnque(CircleQueue* psq, ElemType x);//���
void CircleQueueDeque(CircleQueue* psq);//����
ElemType CircleQueueFront(CircleQueue* psq);//ȡ��ͷ
void CircleQueuePrint(CircleQueue* psq);//��ӡ

void CircleQueueInit(CircleQueue* psq)
{
	assert(psq != NULL);
	psq->base=(ElemType*)malloc(sizeof(ElemType) * (CIRCLE_QUEUE_DEFAULT_SIZE + 1));
	assert(psq->base!=NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE + 1;
	psq->front = psq->rear = 0;
}//��ʼ��
bool CircleQueueIsFull(CircleQueue* psq)
{
	assert(psq != NULL);
	return ((psq->rear + 1) % psq->capacity) == psq->front;
}//�ж���
bool CircleQueueIsEmpty(CircleQueue* psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}//�жϿ�
void CircleQueueEnque(CircleQueue* psq, ElemType x)
{
	assert(psq!=NULL);
	if (CircleQueueIsFull(psq))
	{
		printf("ѭ�������������������.\n");
			return;
	}
	psq->base[psq->rear] = x;
	psq->rear = (psq->rear + 1) % psq->capacity;
}//���
void CircleQueueDeque(CircleQueue* psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿգ����ܳ���.\n");
		return;
	}
	psq->front = (psq->front + 1) % psq->capacity;
}//����
ElemType CircleQueueFront(CircleQueue* psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿգ�����ȡ��ͷ.\n");
		return;
	}
	return psq->base[psq->front];
}//ȡ��ͷ
void CircleQueuePrint(CircleQueue* psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i != psq->rear;)
	{
		printf("%d ", psq->base[i]);
		i = (i + 1) % psq->capacity;
	}
}//��ӡ
//��ʽ����
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
void LinkQueueInit(LinkQueue* pq);//��ʼ��
void LinkQueueEnQue(LinkQueue* pq, ElemType x);//���
void LinkQueueDeQue(LinkQueue* pq);//����
void LinkQueuePrint(LinkQueue* pq);//��ӡ
bool LinkQueueEmpty(LinkQueue* pq);//�п�
ElemType LinkQueueFront(LinkQueue* pq);//ȡ��ͷ

void LinkQueueInit(LinkQueue* pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}//��ʼ��
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
}//���
void LinkQueueDeQue(LinkQueue* pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode* p = pq->front;
		pq->front = p->link;
		free(p);
	}
}//����
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
}//��ӡ
bool LinkQueueEmpty(LinkQueue* pq)
{
	return pq->front == NULL;
}//�п�
ElemType LinkQueueFront(LinkQueue* pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}//ȡ��ͷ