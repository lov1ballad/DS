#include"systil.h"
#define ELEMTYPE int
#define SEQLIST_DEFAULT 10
typedef struct SeqList
{
	ELEMTYPE* base;
	size_t capacity;
	size_t size;
}SeqList;


///////º¯ÊýÉùÃ÷
void SeqListInit(SeqList* pst);
void SeqListPushBack(SeqList* pst, ELEMTYPE x);
void SeqListShow(SeqList* pst);
void SeqListPushFront(SeqList* pst, ELEMTYPE x);
void SeqListPopBack(SeqList* pst);
void SeqListPopFront(SeqList* pst);
size_t SeqListLength(SeqList* pst);
size_t SeqListCapacity(SeqList* pst);
void SeqListClear(SeqList* pst);
void SeqListDestory(SeqList* pst);
int SeqListFindByVal(SeqList* pst, ELEMTYPE key);
void SeqListSort(SeqList* pst);
void SeqListDelByVal(SeqList* pst, ELEMTYPE key);
void SeqListDelByPos(SeqList* pst, ELEMTYPE posi);