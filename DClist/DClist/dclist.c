#include"dclist.h"
int main()
{
	DCList mylist;
	DCListInit(&mylist);

	DCListNode* p;
	ElemType item, key;
	int select = 1;
	int pos = 0;
	while (select)
	{
		printf("***********************************************\n");
		printf("* [1] push_back              [2] push_front   *\n");
		printf("* [3] show_list              [0] quit_system  *\n");
		printf("* [4] pop_back               [5] pop_front    *\n");
		printf("* [*6] insert_pos            [7] insert_val   *\n");
		printf("* [*8] delete_pos            [9] delete_val   *\n");
		printf("* [10] find_val              [11] length      *\n");
		printf("* [*12] capacity             [13] sort        *\n");
		printf("* [14] reverse               [15] clear       *\n");
		printf("* [16] remove_all  自己实现                   *\n");
		printf("***********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			//DCListSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值为:> %d\n", p->data);
			break;
		case 11:
			printf("seqlist len = %d\n", DCListLength(&mylist));
			break;
		case 12:
			//printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			DCListSort(&mylist);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			DCListReverse(&mylist);
			break;
		case 15:
			DCListClear(&mylist);
			printf("清除数据表成功......\n");
			break;
		case 16:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;
		}
	}
	DCListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}