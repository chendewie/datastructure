#include"queue.h"
void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEnQue(&Q, 1);
	LinkQueueEnQue(&Q, 2);
	LinkQueueEnQue(&Q, 3);
	LinkQueueEnQue(&Q, 4);

	LinkQueueDeQue(&Q);
	LinkQueuePrint(&Q);
}

//void main()
//{
//	CircleQueue Q;
//	CircleQueueInit(&Q);
//
//	CircleQueueEnque(&Q, 1);
//	CircleQueueEnque(&Q, 2);
//	CircleQueueEnque(&Q, 3);
//	CircleQueueEnque(&Q, 4);
//	CircleQueueEnque(&Q, 5);
//	CircleQueueEnque(&Q, 6);
//	CircleQueueEnque(&Q, 7);
//	CircleQueueEnque(&Q, 8);
//
//	CircleQueueDeque(&Q);
//
//	CircleQueueEnque(&Q, 9);
//	CircleQueuePrint(&Q);
//
//	printf("对头 = %d\n", CircleQueueFront(&Q));
//}

//void main()
//{
//	SeqQueue Q;
//	SeqQueueInit(&Q);
//
//	SeqQueueEnque(&Q, 1);
//	SeqQueueEnque(&Q, 2);
//	SeqQueueEnque(&Q, 3);
//	SeqQueueEnque(&Q, 4);
//	SeqQueueEnque(&Q, 5);
//	SeqQueueEnque(&Q, 6);
//	SeqQueueEnque(&Q, 7);
//	SeqQueueEnque(&Q, 8);
//	SeqQueueEnque(&Q, 9);
//	SeqQueuePrint(&Q);
//
//	printf("对头 = %d\n", SeqQueueFront(&Q));
//
//	SeqQueueDeque(&Q);
//	SeqQueuePrint(&Q);
//
//	SeqQueueDeque(&Q);
//	SeqQueuePrint(&Q);
//
//	printf("对头 = %d\n", SeqQueueFront(&Q));
//
//}