#define _CRT_SECURE_NO_WARNINGS 1
#include"SListWithoutHead.h"
int main()
{
	SList mylist;
	SListInit(&mylist);
	ELEMTYPE item;
	ELEMTYPE key;
	SListNode *p;
	int posi = 0;
	int select = 1;
	while (select)
	{
		printf("#############################################################\n");
		printf("####    1.push_back                      2.push_front    ####\n");
		printf("####    3.show_list                      0.exit system   ####\n");
		printf("####    4.pop_back                       5.pop_front     ####\n");
		printf("####    6.length                         7.capacity      ####\n");
		printf("####    8.insert_val                     9.insert_pos    ####\n");
		printf("####   10.delete_val                    11.detele_pos    ####\n");
		printf("####   12.find                          13.sort          ####\n");
		printf("####   14.reverse                       15.remove_all    ####\n");
		printf("####   16.clear                         17.destory       ####\n");
		printf("####   18.find_binary                                    ####\n");
		printf("#############################################################\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushFront(&mylist, item);
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("表长为:>%d\n", SListLength(&mylist));
			break;
		case 7:
			//printf("表的容量为:>%d\n", SeqListCapacity(&mylist));
			break;
		case 8:
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("请输入要插入的位置:>");
			scanf("%d", &posi);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		case 11:
			printf("请输入要删除的位置:>");
			scanf("%d", &posi);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SeqListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d存在.\n", key);
			break;
		case 13:
			//SeqListSort(&mylist);
			break;
		case 14:
			SListReverse(&mylist);
			break;
		case 15:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;
		case 16:
			SListClear(&mylist);
			break;
		case 18:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			//pos = SeqListFindByBinary(&mylist, key);
			if (posi == -1)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d在下标为%d的位置.\n", key, posi);
			break;
		}
		system("pause");
		system("cls");
	}
	SListDestroy(&mylist);
	return 0;
}