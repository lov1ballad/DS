#ifndef _SLISTWITHOUTHEAD_H_
#define _SLISTWITHOUTHEAD_H_
#include"sysetil.h"
#define ELEMTYPE int

typedef struct SListNode
{
	ELEMTYPE data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode* head;
}SList;

void SListInit(SList* plist);//链表初始化

void SListPushBack(SList* plist, ELEMTYPE item);//尾部插入节点

void SListPushFront(SList *plist, ELEMTYPE x);
void SListPopBack(SList *plist);
void SListPopFront(SList *plist);
void SListShow(SList *plist);

int SListLength(SList *plist);
SListNode* SeqListFind(SList *plist, ELEMTYPE key);
void SListClear(SList *plist);
void SListDestroy(SList *plist);

void SListDeleteByVal(SList *plist, ELEMTYPE key);
void SListInsertByVal(SList *plist, ELEMTYPE x);
void SListReverse(SList *plist);





#endif