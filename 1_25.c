#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
//1.循环队列.https://leetcode-cn.com/problems/design-circular-queue/
//typedef struct
//{
//	int *base;
//	int capacity;
//	int front;
//	int rear;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue *pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	pcq->capacity = k;
//	pcq->base = (int*)malloc(sizeof(int)*(pcq->capacity + 1));
//	pcq->front = pcq->rear = 0;
//	return pcq;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	return obj->front == obj->rear;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	return (obj->rear + 1) % (obj->capacity + 1) == obj->front;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//	if (myCircularQueueIsFull(obj))
//		return false;
//	obj->base[obj->rear] = value;
//	obj->rear = (obj->rear + 1) % (obj->capacity + 1);
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return false;
//
//	obj->front = (obj->front + 1) % (obj->capacity + 1);
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->base[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->base[(obj->rear - 1 + obj->capacity + 1) % (obj->capacity + 1)];
//}
//
//
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	free(obj->base);
//	obj = NULL;
//	free(obj);
//}

//2.用栈实现队列.https://leetcode-cn.com/problems/implement-queue-using-stacks/
//#define StackElemType int
//typedef struct LinkStackNode
//{
//	StackElemType data;
//	struct LinkStackNode *next;
//}LinkStackNode;
//typedef struct LinkStack
//{
//	LinkStackNode *head;
//}LinkStack;
//
//void LinkStackInit(LinkStack *pst);
//void LinkStackDestroy(LinkStack *pst);
//void LinkStackPush(LinkStack *pst, StackElemType x);
//void LinkStackPop(LinkStack *pst);
//StackElemType LinkStackTop(LinkStack *pst);
//void LinkStackShow(LinkStack *pst);
//bool LinkStackIsEmpty(LinkStack *pst)
//{
//	return pst->head == NULL;
//}
//
//void LinkStackInit(LinkStack *pst)
//{
//	assert(pst);
//	pst->head = NULL;
//}
//
//void LinkStackPush(LinkStack *pst, StackElemType x)
//{
//	assert(pst);
//	LinkStackNode *s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
//	assert(s != NULL);
//	s->data = x;
//
//	s->next = pst->head;
//	pst->head = s;
//}
//
//void LinkStackPop(LinkStack *pst)
//{
//	assert(pst);
//	if (pst->head != NULL)
//	{
//		LinkStackNode *p = pst->head;
//		pst->head = p->next;
//		free(p);
//	}
//}
//
//StackElemType LinkStackTop(LinkStack *pst)
//{
//	assert(pst && pst->head != NULL);
//	return pst->head->data;
//}
//
//void LinkStackShow(LinkStack *pst)
//{
//	assert(pst);
//	LinkStackNode *p = pst->head;
//	while (p != NULL)
//	{
//		printf("%d\n", p->data);
//		p = p->next;
//	}
//}
//
//void LinkStackDestroy(LinkStack *pst)
//{
//	assert(pst);
//	while (pst->head != NULL)
//	{
//		LinkStackNode *p = pst->head;
//		pst->head = p->next;
//		free(p);
//	}
//}

//3.用队列实现栈.https://leetcode-cn.com/problems/implement-stack-using-queues/





typedef struct
{
	LinkStack st1; //push data
	LinkStack st2; 
} MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue *pq = (MyQueue*)malloc(sizeof(MyQueue));
	LinkStackInit(&(pq->st1));
	LinkStackInit(&(pq->st2));
	return pq;
}

void myQueuePush(MyQueue* obj, int x)
{
	LinkStackPush(&(obj->st1), x);
}

int myQueuePop(MyQueue* obj)
{
	if (LinkStackIsEmpty(&(obj->st2)))
	{
		while (!LinkStackIsEmpty(&(obj->st1)))
		{
			LinkStackPush(&(obj->st2), LinkStackTop(&(obj->st1)));
			LinkStackPop(&(obj->st1));
		}
	}
	int val = LinkStackTop(&(obj->st2));
	LinkStackPop(&(obj->st2));
	return val;
}

int myQueuePeek(MyQueue* obj)
{
	if (LinkStackIsEmpty(&(obj->st2)))
	{
		while (!LinkStackIsEmpty(&(obj->st1)))
		{
			LinkStackPush(&(obj->st2), LinkStackTop(&(obj->st1)));
			LinkStackPop(&(obj->st1));
		}
	}
	int val = LinkStackTop(&(obj->st2));
	return val;
}
bool myQueueEmpty(MyQueue* obj)
{
	return LinkStackIsEmpty(&(obj->st1)) && LinkStackIsEmpty(&(obj->st2));
}

void myQueueFree(MyQueue* obj)
{
	LinkStackDestroy(&(obj->st1));
	LinkStackDestroy(&(obj->st2));
	free(obj);
}

