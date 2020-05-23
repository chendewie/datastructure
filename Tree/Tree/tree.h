#pragma once
#include"common.h"
typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode* root;
}BinTree;
//////����
typedef struct LinkQueueNode
{
	BinTreeNode* data;
	struct LinkQueueNode* link;
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;
void LinkQueueInit(LinkQueue* pq);//���г�ʼ��
void LinkQueueEnQue(LinkQueue* pq, BinTreeNode* x);//���
void LinkQueueDeQue(LinkQueue* pq);//����
void LinkQueuePrint(LinkQueue* pq);//��ӡ
bool LinkQueueEmpty(LinkQueue* pq);//�п�
BinTreeNode* LinkQueueFront(LinkQueue* pq);//ȡ��ͷ

void LinkQueueInit(LinkQueue* pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}
void LinkQueueEnQue(LinkQueue* pq, BinTreeNode* x)
{
	assert(pq != NULL);
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;

	if (pq->front == NULL)
		pq->front = pq->rear = node;
	else
	{
		pq->rear->link = node;
		pq->rear = node;
	}
}
void LinkQueueDeQue(LinkQueue* pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode* p = pq->front;
		pq->front = p->link;
		free(p);
	}
}
void LinkQueuePrint(LinkQueue* pq)
{
	assert(pq != NULL);
	LinkQueueNode* p = pq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
bool LinkQueueEmpty(LinkQueue* pq)
{
	return pq->front == NULL;
}
BinTreeNode* LinkQueueFront(LinkQueue* pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}
//////ջ
typedef struct LinkStackNode
{
	BinTreeNode* data;
	struct LinkStackNode* link; //next
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode* top;
}LinkStack;

void LinkStackInit(LinkStack* pst);//ջ��ʼ��
void LinkStackPush(LinkStack* pst, BinTreeNode* x);//��ջ
void LinkStackPop(LinkStack* pst);//��ջ
BinTreeNode* LinkStackTop(LinkStack* pst);//ȡջ��
bool LinkStackEmpty(LinkStack* pst);//�п�
void LinkStackPrint(LinkStack* pst);//��ӡ
void LinkStackDestroy(LinkStack* pst);//����

void LinkStackInit(LinkStack* pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}
void LinkStackPush(LinkStack* pst, BinTreeNode* x)
{
	assert(pst != NULL);
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = pst->top;
	pst->top = node;
}
void LinkStackPop(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* p = pst->top;
	pst->top = p->link;

	free(p);
}
BinTreeNode* LinkStackTop(LinkStack* pst)
{
	assert(pst != NULL);
	if (pst->top == NULL)
	{
		printf("ջ�ѿգ����ܳ�ջ.\n");
		return;
	}
	return pst->top->data;
}
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
}
void LinkStackDestroy(LinkStack* pst)
{
	assert(pst != NULL);
	while (pst->top != NULL)
	{
		LinkStackNode* p = pst->top;
		pst->top = p->link;
		free(p);
	}
}
bool LinkStackEmpty(LinkStack* pst)
{
	return pst->top == NULL;
}
//////
void BinTreeInit(BinTree* pbt);//��ʼ��
void BinTreeCreate(BinTree* bt);//�����������룩
void BinTreeCreate_1(BinTreeNode** t);
BinTreeNode* BinTreeCreate_2();
void BinTreeCreateByStr(BinTree* bt, const char* str);//�������������ַ�����
BinTreeNode* BinTreeCreateByStr_1(const char* str, int* pindex);

void PreOrder(BinTree* bt);//�ݹ�ǰ��
void PreOrder_1(BinTreeNode* t);
void InOrder(BinTree* bt);//�ݹ�����
void InOrder_1(BinTreeNode* t);
void PostOrder(BinTree* bt);//�ݹ����
void PostOrder_1(BinTreeNode* t);
void LevelOrder(BinTree* bt);//����
void LevelOrder_1(BinTreeNode* t);

void PreOrder_NoR(BinTree* bt);//�ǵݹ�ǰ
void PreOrder_1_NoR(BinTreeNode* t);
void InOrder_NoR(BinTree* bt);//�ǵݹ���
void InOrder_1_NoR(BinTreeNode* t);
void PostOrder_NoR(BinTree* bt);//�ǵݹ��
void PostOrder_1_NoR(BinTreeNode* t);

int BinTreeCount(BinTree* bt);//�ڵ���
int BinTreeCount_1(BinTreeNode* t);
int BinTreeHeight(BinTree* bt);//����
int BinTreeHeight_1(BinTreeNode* t);

BinTreeNode* BinTreeFind(BinTree* bt, ElemType key);//��ѯ���
BinTreeNode* BinTreeFind_1(BinTreeNode* t, ElemType key);
BinTreeNode* BinTreeParent(BinTree* bt, ElemType key);//��ѯ���ڵ�
BinTreeNode* BinTreeParent_1(BinTreeNode* t, ElemType key);

void BinTreeCopy(BinTree* bt1, BinTree* bt2);  //������������bt2 = bt1;
BinTreeNode* BinTreeCopy_1(BinTreeNode* t);

bool BinTreeEqual(BinTree* bt1, BinTree* bt2);//�ж϶�����
bool BinTreeEqual_1(BinTreeNode* t1, BinTreeNode* t2);

void BinTreeDestroy(BinTree* bt);//�ݻٶ�����
void BinTreeDestroy_1(BinTreeNode* t);
//����������������������������������������
void BinTreeInit(BinTree* pbt)
{
	pbt->root = NULL;
}
void BinTreeCreate(BinTree* bt)
{
	//BinTreeCreate_1(&bt->root);
	bt->root=BinTreeCreate_2();
}
void BinTreeCreate_1(BinTreeNode** t)
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data == item;
		BinTreeCreate_1(&(*t)->leftChild);
		BinTreeCreate_1(&(*t)->rightChild);
	}
}
BinTreeNode* BinTreeCreate_2()
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
	{
		return NULL;
	}
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = BinTreeCreate_2();
		t->rightChild=BinTreeCreate_2();
		return t;
	}
}
void BinTreeCreateByStr(BinTree* bt, const char* str)
{
	int index = 0;
	bt->root = BinTreeCreateByStr_1(str, &index);
}
BinTreeNode* BinTreeCreateByStr_1(const char* str, int* pindex)
{
	if (str[*pindex] == '#' || str[*pindex] == '\0')
	{
		return 0;
	}
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		t->leftChild = BinTreeCreateByStr_1(str, pindex);
		(*pindex)++;
		t->rightChild = BinTreeCreateByStr_1(str, pindex);
		return t;
	}
}
void PreOrder(BinTree* bt)
{
	PreOrder_1(bt->root);
}
void PreOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}
}
void InOrder(BinTree* bt)
{
	InOrder_1(bt->root);
}
void InOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		InOrder_1(t->leftChild);
		printf("%c ", t->data);
		InOrder_1(t->rightChild);
	}
}
void PostOrder(BinTree* bt)
{
	PostOrder_1(bt->root);
}
void PostOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		printf("%c ", t->data);
	}
}
void LevelOrder(BinTree* bt)
{
	LevelOrder_1(bt->root);
}
void LevelOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);
		LinkQueueEnQue(&Q, t);
		while (!LinkQueueEmpty(&Q))
		{
			BinTreeNode* p = LinkQueueFront(&Q);
			LinkQueueDeQue(&Q);
			printf("%c ", p->data);
			if (p->leftChild != NULL)
				LinkQueueEnQue(&Q, p->leftChild);
			if (p->rightChild != NULL)
				LinkQueueEnQue(&Q, p->rightChild);
		}
	}
}int BinTreeCount(BinTree* bt)
{
	return BinTreeCount_1(bt->root);
}
int BinTreeCount_1(BinTreeNode* t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return BinTreeCount_1(t->leftChild) + BinTreeCount_1(t->rightChild) + 1;
	}
}
int BinTreeHeight(BinTree* bt)
{
	return BinTreeHeight_1(bt->root);
}
int BinTreeHeight_1(BinTreeNode* t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		int left_h = BinTreeHeight_1(t->leftChild);
		int right_h = BinTreeHeight_1(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}
BinTreeNode* BinTreeFind(BinTree* bt, ElemType key)
{
	return BinTreeFind_1(bt->root, key);
}
BinTreeNode* BinTreeFind_1(BinTreeNode* t, ElemType key)
{
	BinTreeNode* p;
	if (t == NULL || t->data == key)
	{
		return t;
	}
	p = BinTreeFind_1(t->leftChild, key);
	if (p != NULL)
	{
		return p;
	}
	return BinTreeFind_1(t->rightChild, key);
}
BinTreeNode* BinTreeParent(BinTree* bt, ElemType key)
{
	return BinTreeParent_1(bt->root, key);
}
BinTreeNode* BinTreeParent_1(BinTreeNode* t, ElemType key)
{
	BinTreeNode* p;
	if (t == NULL || t->data == key)
	{
		return NULL;
	}
	if ((t->leftChild != NULL && t->leftChild->data == key)
		|| (t->rightChild != NULL && t->rightChild->data == key))
	{
		return t;
	}
	p = BinTreeParent_1(t->leftChild, key);
	if (p != NULL)
	{
		return p;
	}
	return BinTreeParent_1(t->rightChild, key);
}
void BinTreeCopy(BinTree* bt1, BinTree* bt2)
{
	bt2->root = BinTreeCopy_1(bt1->root);
}
BinTreeNode* BinTreeCopy_1(BinTreeNode* t)
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		BinTreeNode* tmp = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(tmp != NULL);
		tmp->data = t->data;
		tmp->leftChild = BinTreeCopy_1(t->leftChild);
		tmp->rightChild = BinTreeCopy_1(t->rightChild);
		return tmp;
	}
}
bool BinTreeEqual(BinTree* bt1, BinTree* bt2)
{
	return BinTreeEqual_1(bt1->root, bt2->root);
}
bool BinTreeEqual_1(BinTreeNode* t1, BinTreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
	{
		return true;
	}
	if (t2 == NULL && t2 == NULL)
	{
		return false;
	}
	if (t1->data == t2->data && \
		BinTreeEqual_1(t1->leftChild, t2->leftChild) && \
		BinTreeEqual_1(t1->rightChild, t2->rightChild))
	{
		return true;
	}
	return false;
}
void BinTreeDestroy(BinTree* bt)
{
	BinTreeDestroy_1(bt->root);
}
void BinTreeDestroy_1(BinTreeNode* t)
{
	if (t == NULL)
	{
		return;
	}
	BinTreeDestroy_1(t->leftChild);
	BinTreeDestroy_1(t->rightChild);
	free(t);
}
//////�ǵݹ�!!!
void PreOrder_NoR(BinTree* bt)
{
	PreOrder_1_NoR(bt->root);
}
void PreOrder_1_NoR(BinTreeNode* t)
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		LinkStackPush(&st, t);
		while (!LinkStackEmpty(&st))
		{
			BinTreeNode* top = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", top->data);
			if (top->rightChild != NULL)
				LinkStackPush(&st, top->rightChild);
			if (top->leftChild != NULL)
				LinkStackPush(&st, top->leftChild);
		}
	}
}
/*
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->_data);

		if (cur->_right && !cur->_left)
		{
			return 0;
		}

		if (tag && (cur->_right || cur->_left))
		{
			return 0;
		}

		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}

		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		else
		{
			tag = 1;
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
	return 1;
}
*/