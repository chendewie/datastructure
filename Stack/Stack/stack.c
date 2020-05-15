#include"stack.h"
void main()
{
	LinkStack st;
	LinkStackInit(&st);

	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackPrint(&st);

	LinkStackPop(&st);
	LinkStackPrint(&st);

	LinkStackDestroy(&st);
}
//void main()
//{
//	SeqStack st;
//	SeqStackInit(&st);
//	SeqStackPush(&st, 1);
//	SeqStackPush(&st, 2);
//	SeqStackPush(&st, 3);
//	SeqStackPush(&st, 4);
//	SeqStackPush(&st, 5);
//	SeqStackPush(&st, 6);
//	SeqStackPush(&st, 7);
//	SeqStackPush(&st, 8);
//	SeqStackPush(&st, 9);
//	SeqStackPrint(&st);
//
//	ElemType val = SeqStackTop(&st);
//	SeqStackPop(&st); //6
//	printf("%d ³öÕ».\n", val);
//
//	val = SeqStackTop(&st);
//	SeqStackPop(&st); //5
//	printf("%d ³öÕ».\n", val);
//	SeqStackPrint(&st);
//
//	SeqStackDestroy(&st);
//}