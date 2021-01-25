#include"Sysutil.h"

#define QueueElemType int
#define QueueSize 8
typedef struct SeqQueue
{
	QueueElemType* base;
	size_t capacity;
	int front;
	int rear;
}SeqQueue;

///////////////////////////////
//顺序队列函数声明
void SeqQueueInit(SeqQueue* pq, int sz);//初始化
void SeqQueueDestroy(SeqQueue* pq);//销毁
void SeqQueueShow(SeqQueue* pq);//显示
void SeqQueueEn(SeqQueue* pq, QueueElemType x);//入队
void SeqQueueDe(SeqQueue* pq);//出队
QueueElemType SeqQueueBack(SeqQueue* pq);//获取对尾元素
QueueElemType SeqQueuefront(SeqQueue* pq);//获取队头元素
