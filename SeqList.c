#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

bool IsFull(SeqList* pst)
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}

void SeqListInit(SeqList* pst)
{
	pst->base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)*SEQLIST_DEFAULT);
	assert(pst->base);
	memset(pst->base, 0, sizeof(ELEMTYPE)*SEQLIST_DEFAULT);
	pst->capacity = SEQLIST_DEFAULT;
	pst->size = 0;
}

void SeqListPushBack(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("顺序表满了，%d 不能插入!\n", x);
		return;
	}
	pst->base[pst->size++] = x;
	printf("插入数据 %d 成功！\n", x);
}

void SeqListShow(SeqList* pst)
{
	assert(pst);
	for (int i = 0; i < pst->size; i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("顺序表满了，%d 不能插入!\n", x);
		return;
	}
	for (int i = pst->size; i > 0; i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[0] = x;
	pst->size++;
	printf("插入数据 %d 成功！\n", x);
}

void SeqListPopBack(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，无法删除！\n");
		return;
	}
	pst->size--;
	printf("尾部删除成功！\n");
}

void SeqListPopFront(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，无法删除！\n");
		return;
	}
	for (int i = 0; i < pst->size-1; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
	printf("头部删除成功！\n");
}

size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}

size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}

void SeqListClear(SeqList* pst)
{
	pst->size = 0;
	printf("顺序表已格式化!\n");
}

void SeqListDestory(SeqList* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = 0;
	pst->size = 0;
	printf("顺序表已摧毁！\n");
}

int SeqListFindByVal(SeqList* pst, ELEMTYPE key)
{
	assert(pst);
	for (int i = 0; i < pst->size; i++)
	{
		if (key == pst->base[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListSort(SeqList* pst)
{
	for (int i = 0; i < pst->size - 1; i++)
	{
		for (int j = 0; j < pst->size - i - 1; j++)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				ELEMTYPE tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

void SeqListDelByVal(SeqList* pst, ELEMTYPE key)
{
	int index = SeqListFindByVal(pst, key);
	if (index == -1)
	{
		printf("删除的数据不存在！\n");
		return;
	}
	for (int i = index; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListDelByPos(SeqList* pst, ELEMTYPE posi)
{
	assert(pst && (posi>=0&&posi<pst->size));
	for (int i = posi; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}