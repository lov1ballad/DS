#define _CRT_SECURE_NO_WARNINGS 1
#include"BinTree.h"

/////////////////////////////////
//����ʵ��

//void BinTreeInit(BinTree* t)
//{
//	t->root = NULL;
//}

void BinTreeCreate1(BinTree* t)//��ǰ�򴴽�ABCDEFGH
{
	ElemType item;
	scanf("%c", &item);//ABC##DE##F##G#H##
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t);
		(*t)->data = item;
		BinTreeCreate1(&((*t)->leftChild));//����������
		BinTreeCreate1(&((*t)->rightChild));//����������
	}
}

BinTree BinTreeCreate2()
{
	ElemType item;
	scanf("%c", &item);//ABC##DE##F##G#H##
	if (item == '#')
	{
		return NULL;
	}
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t);
		t->leftChild = BinTreeCreate2();
		t->rightChild = BinTreeCreate2();
		return t;
	}
}

BinTree BinTreeCreate3(const char* str,int* i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t);
		t->data = str[*i];
		(*i)++;//�±�ֵ++
		t->leftChild = BinTreeCreate3(str, i);
		(*i)++;
		t->rightChild = BinTreeCreate3(str, i);
		return t;
	}
}

void DestroyNode(BinTreeNode* node)//���ٽڵ�
{
	free(node);
    return;
}

void BinTreeDestroy(BinTree* t)
{
	if (t == NULL)
	{
		return;//�Ƿ�
	}
    if (*t == NULL)
	{
		return;
	}
	 BinTreeDestroy(&((*t)->leftChild));
	 BinTreeDestroy(&((*t)->rightChild));
	 DestroyNode(*t);
	 *t = NULL;
	     return;
	printf("�����������٣�\n");
}

void PreOrder(BinTree t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder(t->leftChild);
		PreOrder(t->rightChild);
	}
}

void InOrder(BinTree t)
{
	if (t != NULL)
	{
		InOrder(t->leftChild);
		printf("%c ", t->data);
		InOrder(t->rightChild);
	}
}

void PostOrder(BinTree t)
{
	if (t != NULL)
	{
		PostOrder(t->leftChild);
		PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}

void PreOrder_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);

		LinkStackPush(&st, t);
	
		while (!LinkStackIsEmpty(&st))
		{
			BinTreeNode* p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
				LinkStackPush(&st, p->rightChild);
			if (p->leftChild != NULL)
				LinkStackPush(&st, p->leftChild);
		}
	}
}

void InOrder_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		BinTreeNode* p;
		while (t || !LinkStackIsEmpty(&st))
		{
			while (t)
			{
				LinkStackPush(&st, t);
				t = t->leftChild;
			}//ֱ������Ϊ��ʱ

			p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);

			t = p->rightChild;
		}
	}
}

void PostOrder_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		BinTreeNode* p, *prev;//prevΪ��ǰ�ڵ��ǰһ���ʽڵ�
		while (t || !LinkStackIsEmpty(&st))
		{
			while (t)
			{
				LinkStackPush(&st, t);
				t = t->leftChild;
			}

			p = LinkStackTop(&st);
			if (p->rightChild == NULL || p->rightChild == prev)
			{
				printf("%c ", p->data);
				LinkStackPop(&st);//Ҫ����
				prev = p;//����
			}
			else
				t = p->rightChild;
		}
	}
}

size_t Size(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1;
}

size_t Height(BinTree t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = Height(t->leftChild);
		int right_h = Height(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}

BinTreeNode* Find(BinTree t, ElemType key)
{
	BinTreeNode* p;
	if (t == NULL || t->data == key)
		return t;
	p = Find(t->leftChild, key);
	if (p != NULL)
		return p;//�����ҵ�
	return Find(t->rightChild, key);
}

BinTreeNode* Parent(BinTree t, BinTreeNode* s)
{
	BinTreeNode* p = NULL;
	if (t == NULL || t == s)
		return NULL;
	if (t->leftChild == s || t->rightChild == s)
		return t;
	p = Parent(t->leftChild, s);
	if (p != NULL)
		return p;
	return Parent(t->rightChild, s);
}

int BinTreeLeafSize(BinTree t)
{
	if (t == NULL)
		return 0;
	if (t->leftChild == NULL && t->rightChild == NULL)
		return 1;
	return (BinTreeLeafSize(t->leftChild) + BinTreeLeafSize(t->rightChild));
}

int BinTreeLevelKSize(BinTree t, int k)
{
	if (t == NULL || k<1)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinTreeLevelKSize(t->leftChild, k - 1) + BinTreeLevelKSize(t->rightChild, k - 1);
}

BinTree Clone(BinTree t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode* new_t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(new_t);
		new_t->data = t->data;
		new_t->leftChild = Clone(t->leftChild);
		new_t->rightChild = Clone(t->rightChild);
		return new_t;
	}
}

int BinTreeComplete(BinTree t)
{
	LinkQueue Q;
	BinTreeNode * cur;
	int i = 0;

	LinkQueueInit(&Q);

	LinkQueueEn(&Q, t);

	while (!LinkQueueIsEmpty(&Q))
	{
		cur = LinkQueuefront(&Q);

		if (cur->rightChild && !cur->leftChild)
		{
			return 0;//����0��Ϊ��ȫ������
		}

		if (i && (cur->rightChild || cur->leftChild))
		{
			return 0;
		}

		if (cur->leftChild)
		{
			LinkQueueEn(&Q, cur->leftChild);
		}

		if (cur->rightChild)
		{
			LinkQueueEn(&Q, cur->rightChild);
		}
		else
		{
			i = 1;
		}

		LinkQueueDe(&Q);
	}
	return 1;
}

bool Equal(BinTree t1, BinTree t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return (t1->data == t2->data)
		&& Equal(t1->leftChild, t2->leftChild)
		&& Equal(t1->rightChild, t2->rightChild);
}

void LevelOrder(BinTree t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t);
		while (!LinkQueueIsEmpty(&Q))
		{
			BinTreeNode* p = LinkQueuefront(&Q);
			LinkQueueDe(&Q);
			printf("%c ", p->data);
			if (p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild);
			if (p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);
		}
	}
}
