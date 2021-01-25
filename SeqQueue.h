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
//˳����к�������
void SeqQueueInit(SeqQueue* pq, int sz);//��ʼ��
void SeqQueueDestroy(SeqQueue* pq);//����
void SeqQueueShow(SeqQueue* pq);//��ʾ
void SeqQueueEn(SeqQueue* pq, QueueElemType x);//���
void SeqQueueDe(SeqQueue* pq);//����
QueueElemType SeqQueueBack(SeqQueue* pq);//��ȡ��βԪ��
QueueElemType SeqQueuefront(SeqQueue* pq);//��ȡ��ͷԪ��
