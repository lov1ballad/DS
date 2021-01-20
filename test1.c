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
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
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
			printf("��Ϊ:>%d\n", SListLength(&mylist));
			break;
		case 7:
			//printf("�������Ϊ:>%d\n", SeqListCapacity(&mylist));
			break;
		case 8:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &posi);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		case 11:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &posi);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = SeqListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d����.\n", key);
			break;
		case 13:
			//SeqListSort(&mylist);
			break;
		case 14:
			SListReverse(&mylist);
			break;
		case 15:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;
		case 16:
			SListClear(&mylist);
			break;
		case 18:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			//pos = SeqListFindByBinary(&mylist, key);
			if (posi == -1)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d���±�Ϊ%d��λ��.\n", key, posi);
			break;
		}
		system("pause");
		system("cls");
	}
	SListDestroy(&mylist);
	return 0;
}