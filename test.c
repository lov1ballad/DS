#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


int main()
{
	SeqList mylist;
	SeqListInit(&mylist);
	ELEMTYPE item;
	ELEMTYPE key;
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
		printf("####   18.find_binary                   17.destory       ####\n");
		printf("#############################################################\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要后插的数据(以-1为结束标志):> ");
			while(scanf("%d", &item),item!=-1)
				SeqListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要头插的数据(以-1为结束标志):> ");
			while (scanf("%d", &item), item != -1)
				SeqListPushFront(&mylist, item);
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
			printf("顺序表的长度为:%d", SeqListLength(&mylist));
			break;
		case 7:
			printf("顺序表的容量为:%d", SeqListCapacity(&mylist));
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListDelByVal(&mylist, key);
			break;
		case 11:
			printf("请输入要删除的位置:>");
			scanf("%d", &posi);
			SeqListDelByPos(&mylist, posi);
			break;
		case 12:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			posi = SeqListFindByVal(&mylist, key);
			if (posi == -1)
			{
				printf("未找到%d!\n", key);
			}
			else
			{
				printf("%d的下标是：%d", key, posi);
			}
			break;
		case 13:
			SeqListSort(&mylist);
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			SeqListClear(&mylist);
			break;
		case 17:
			SeqListDestory(&mylist);
			break;
		}
		system("pause");
		system("cls");
	}
	SeqListDestory(&mylist);
	return 0;
}