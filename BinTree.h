
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include"LinkQueue.h"//��ʽջ
#include"LinkStack.h"
#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

typedef BinTreeNode* BinTree;
//typedef struct BinTree
//{
//	BinTreeNode* root;
//}BinTree;


///////////////////////////////////////
//����������

//void BinTreeInit(BinTree* t);
//������ʽ��
void BinTreeCreate1(BinTree* t);//�˴�����ʽ��Ҫ���������ǰ�����У���'#'�����
BinTree BinTreeCreate2();//�˴�����ʽ�޲�����Ҫ�ö������ڵ���գ�Ҳ�����������ǰ�����У���'#'�����
BinTree BinTreeCreate3(const char* str, int i);/*�˴�����ʽ����ǰ��test.c���涨�������ǰ�����е��ַ�����
�Ӷ�����Ҫ����ǰ�����У�������Ϊ�ַ�����Ԫ�ص�ַ��i�൱���±�*/
void DestroyNode(BinTreeNode* node);
void BinTreeDestroy(BinTree* t);//���ٶ�����
//�ݹ������
void PreOrder(BinTree t);//ǰ�����
void InOrder(BinTree t);//�������
void PostOrder(BinTree t);//�������
void LevelOrder(BinTree t);//�㼶����
//�ǵݹ������
void PreOrder_Nor(BinTree t);//
void InOrder_Nor(BinTree t);
void PostOrder_Nor(BinTree t);

size_t Size(BinTree t);//�������ڵ����
size_t Height(BinTree t);//�������߶�
BinTreeNode* Find(BinTree t,ElemType key);//����ֵΪkey�Ľڵ�
BinTreeNode* Parent(BinTree t, BinTreeNode* s);//����s�ڵ�ĸ��ڵ�
int BinTreeLeafSize(BinTree t); //������Ҷ�ӽڵ����
int BinTreeLevelKSize(BinTree t, int k);//��������k��ڵ����
BinTree Clone(BinTree t);//��¡������
int BinTreeComplete(BinTree t);// �ж϶������Ƿ�����ȫ������
bool Equal(BinTree t1, BinTree t2);//�Ƚ�����������
