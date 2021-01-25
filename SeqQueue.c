#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqQueue.h"


//////////////////////////////////
//˳����к���ʵ��
void SeqQueueInit(SeqQueue* pq, int sz)
{
	assert(pq);
	pq->capacity = sz > QueueSize ? sz : QueueSize;//ȷ����̳���Ϊ8
	pq->base = (QueueElemType*)malloc(sizeof(QueueElemType)*pq->capacity);
	assert(pq->base);
	pq->front = pq->rear = 0;
}

void SeqQueueDestroy(SeqQueue* pq)
{
	assert(pq);
	free(pq->base);
	pq->base = NULL;
	pq->capacity = pq->front = pq->rear = 0;
}

void SeqQueueShow(SeqQueue* pq)
{
	assert(pq);
	for (int i = pq->front; i <= pq->rear-1; i++)
		printf("%d<--", pq->base[i]);
	printf("Nil.\n");
}

void SeqQueueEn(SeqQueue* pq, QueueElemType x)
{
	assert(pq);
	if (pq->rear >= pq->capacity)
	{
		printf("����������\n");
		return;
	}
	pq->base[pq->rear++] = x;
}

void SeqQueueDe(SeqQueue* pq)
{
	assert(pq);
	if (pq->front == pq->rear)
	{
		printf("�����ѿգ�\n");
		return;
	}
	pq->front++;
}

QueueElemType SeqQueueBack(SeqQueue* pq)
{
	assert(pq && (pq->front != pq->rear));
	return pq->base[pq->rear - 1];
}

QueueElemType SeqQueuefront(SeqQueue* pq)
{
	assert(pq && (pq->front != pq->rear));
	return pq->base[pq->front];
}