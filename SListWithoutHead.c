#define _CRT_SECURE_NO_WARNINGS 1
#include"SListWithoutHead.h"

SListNode* _Buynode()
{
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}

void SListInit(SList *plist)
{
	plist->head = NULL;
}

void SListPushBack(SList *plist, ELEMTYPE x)
{
	assert(plist);
	SListNode *s = _Buynode();
	s->data = x;

	//查找链表的尾部
	SListNode *p = plist->head;

	//插入的节点是第一个节点
	if (p == NULL)
		plist->head = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
}

void SListPushFront(SList *plist, ELEMTYPE x)
{
	assert(plist);//合法检查
	SListNode* s = _Buynode(); //创建新节点，存储数据
	s->data = x;

	s->next = plist->head;
	plist->head = s;
}

void SListPopBack(SList *plist)
{
	assert(plist);
	SListNode *p = plist->head;

	if (p != NULL) //不能为空
	{
		if (p->next == NULL) // 只有一个节点
			plist->head = NULL;
		else
		{
			SListNode *pre = NULL;
			while (p->next != NULL)
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
		}
		free(p);
	}
}

void SListPopFront(SList *plist)
{
	assert(plist);
	SListNode *p = plist->head;
	if (p != NULL)
	{
		plist->head = p->next;
		free(p);
	}
}

void SListShow(SList *plist)
{
	SListNode *p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

int SListLength(SList *plist)
{
	assert(plist);
	int len = 0;
	SListNode *p = plist->head;

	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

SListNode* SeqListFind(SList *plist, ELEMTYPE key)
{
	//找到返回节点的地址
	//找不到返回NULL
	assert(plist);
	SListNode *p = plist->head;

	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

void SListClear(SList *plist)
{
	assert(plist);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;  //头删
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList *plist)
{
	SListClear(plist);
}

void SListDeleteByVal(SList *plist, ELEMTYPE key)
{
	assert(plist);
	//查找节点
	SListNode *p = plist->head;
	SListNode *pre = NULL;
	while (p != NULL && p->data != key)
	{
		pre = p;
		p = p->next;
	}

	if (p != NULL)  //找到删除的节点
	{
		if (pre == NULL) //删除的节点为第一个节点
			plist->head = p->next;
		else
			pre->next = p->next;

		free(p);
	}
}

void SListInsertByVal(SList *plist, ELEMTYPE x)
{
	assert(plist);
	SListNode *s = _Buynode();
	s->data = x;

	if (plist->head == NULL)
		plist->head = s;
	else
	{
		SListNode *p = plist->head;
		SListNode *pre = NULL;
		while (p != NULL && x>p->data)
		{
			pre = p;
			p = p->next;
		}

		if (pre == NULL) //说明在链表的头部插入
		{
			s->next = p;  //s->next = plist->head
			plist->head = s;
		}
		else
		{
			s->next = pre->next;
			pre->next = s;
		}
	}
}

void SListReverse(SList *plist)
{
	assert(plist);
	SListNode *p, *q;
	if (plist->head == NULL)
		return;

	if (plist->head->next == NULL) //不需要转置
		return;

	//1 切割链表
	p = plist->head->next;
	plist->head->next = NULL;

	//2 将剩余的链表节点进行一一头插
	q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}