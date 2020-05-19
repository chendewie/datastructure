#include"tree.h"
//void main()
//{
//	const char* VLR = "ABCDEFGH";  //VLR+LVR ==> 
//	const char* LVR = "CBEDFAGH";
//	const char* LRV = "CEFDBHGA";  //LRV+LVR ==>     //VLR + LRV ==> ?
//
//	const char* str = "ABC##DE##F##G#H##";
//	BinTree  bt;
//	BinTreeInit(&bt);
//	BinTreeCreateByStr(&bt, str);
//
//	printf("VLR: ");
//	PreOrder_NoR(&bt);
//	printf("\n");
//
//	BinTreeDestroy(&bt);
//}

//void main()
//{
//	const char* str = "ABC##DE##F##G#H##";
//	const char* str1 = "ABC##DE##F##G#H##";
//	BinTree  bt, bt1;
//	BinTreeInit(&bt);
//	BinTreeInit(&bt1);
//	BinTreeCreateByStr(&bt, str);
//
//	//BinTreeCopy(&bt, &bt1);
//	BinTreeCreateByStr(&bt1, str1);
//
//	bool flag = BinTreeEqual(&bt, &bt1);
//	if (flag)
//		printf("Equal.\n");
//	else
//		printf("Not Equal.\n");
//
//}

//void main()
//{
//	const char* str = "ABC##DE##F##G#H##";
//	BinTree  bt;
//	BinTreeInit(&bt);
//	BinTreeCreateByStr(&bt, str);
//
//	char key = 'X';
//	//BinTreeNode *p = BinTreeFind(&bt, key);
//	BinTreeNode* p = BinTreeParent(&bt, key);
//	if (p == NULL)
//		printf("查找的节点不存在.\n");
//	else
//		//printf("data = %c\n", p->data);
//		printf("parent = %c\n", p->data);
//
//}

//void main()
//{
//	//const char *str = "AB#DF###CE###";
//	//const char* str = "ABC##DE##F##G#H##";
//	BinTree  bt;
//	BinTreeInit(&bt);
//	BinTreeCreate(&bt);
//	//BinTreeCreateByStr(&bt, str);
//
//	printf("VLR: ");
//	PreOrder(&bt);
//	printf("\n");
//
//	printf("LVR: ");
//	InOrder(&bt);
//	printf("\n");
//
//	printf("LRV: ");
//	PostOrder(&bt);
//	printf("\n");
//
//	printf("Level: ");
//	LevelOrder(&bt);
//	printf("\n");
//
//	printf("Size = %d\n", BinTreeCount(&bt));
//	printf("Height = %d\n", BinTreeHeight(&bt));
//}