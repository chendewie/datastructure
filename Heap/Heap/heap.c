#include"heap.h"

//void main(void)
//{
//	//int ar[] = { 27,15,19,18,28,34 };
//	//int n = sizeof(ar) / sizeof(ar[0]);
//	Heap minheap;
//	HeapInit(&minheap, 10);
//	MinHeapInsert(&minheap, 9);
//	MinHeapInsert(&minheap, 8);
//	MinHeapInsert(&minheap, 7);
//	HeapPrint(&minheap);
//}
//void main()
//{
//	int ar[] = {27,15,19,18,28,34,65,49,25,37};
//	int n = sizeof(ar) / sizeof(ar[0]); //
//
//	Heap minheap;
//	HeapInit(&minheap, n);
//
//	for(int i=0; i<n; ++i)
//		MinHeapInsert(&minheap, ar[i]);
//	HeapPrint(&minheap);
//
//	while(!HeapEmpty(&minheap))
//	{
//		printf("%d ", MinHeapRemove(&minheap));
//		//HeapPrint(&minheap);
//	}
//	printf("\n");
//}


//void main()
//{
//	int ar[] = { 27,15,19,18,28,34,65,49,25,37 };
//	int n = sizeof(ar) / sizeof(ar[0]); //
//
//	Heap minheap;
//	HeapInit(&minheap, n);
//	HeapSort(&minheap, ar, n);
//	HeapPrint(&minheap);
//}


//void main()
//{
//	int ar[] = {27,15,19,18,28,34,65,49,25,37};
//	int n = sizeof(ar) / sizeof(ar[0]); //
//
//	Heap minheap;
//	HeapInit(&minheap, n);
//
//	for (int i = 0; i < n; ++i)
//	{
//		MinHeapInsert(&minheap, ar[i]);
//	}
//	HeapPrint(&minheap);
//
//	while(!HeapEmpty(&minheap))
//	{
//		printf("%d ", MinHeapRemove(&minheap));
//		//HeapPrint(&minheap);
//	}
//	printf("\n");
//}