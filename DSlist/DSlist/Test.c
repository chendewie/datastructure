#include"seqlist.h"

int main()
{
	SeqList mylist;
	SeqListInit(&mylist);
	ElemType item;
	ElemType key;
	int pos = 0;
	int select = 1;
	bool tmp;

	while (select)//[0] quit_system
	{
		printf("************************************************\n");
		printf("* [0]  quit_system            [1]  push_back   *\n");
		printf("* [2]  push_front             [3]  show_list   *\n");
		printf("* [4]  pop_back               [5]  pop_front   *\n");
		printf("* [6]  insert_pos             [7]  insert_val  *\n");
		printf("* [8]  delete_pos             [9]  delete_val  *\n");
		printf("* [10] find_val               [11] length      *\n");
		printf("* [12] capacity               [13] sort        *\n");
		printf("* [14] reverse                [15] clear       *\n");
		//printf("* [16] remove_all  自己实现                   *\n");
		printf("* [16] myrealloc                               *\n");
		printf("************************************************\n");
		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			SeqListSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值的位置为:> %d\n", pos);
			break;
		case 11:
			printf("seqlist len = %d\n", SeqListLength(&mylist));
			break;
		case 12:
			printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			SeqListClear(&mylist);
			printf("清除数据表成功......\n");
			break;
		case 16:
			tmp=_Inc(&mylist);
			if (tmp == true)
			{
				printf("扩容成功！\n");
			}
			else
			{
				printf("扩容失败！\n");
			}
			//printf("请输入要删除的值:>");
			//scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;
		default:
			printf("请重新输入！\n");
			break;
		}
	}

	SeqListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}