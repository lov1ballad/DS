
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include"LinkQueue.h"//链式栈
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
//函数声明：

//void BinTreeInit(BinTree* t);
//创建方式↓
void BinTreeCreate1(BinTree* t);//此创建方式需要输入二叉树前序序列，用'#'代替空
BinTree BinTreeCreate2();//此创建方式无参数需要用二叉树节点接收，也需输入二叉树前序序列，用'#'代替空
BinTree BinTreeCreate3(const char* str, int i);/*此创建方式需提前在test.c里面定义二叉树前序序列的字符串，
从而不需要输入前序序列，↑参数为字符串首元素地址，i相当于下标*/
void DestroyNode(BinTreeNode* node);
void BinTreeDestroy(BinTree* t);//销毁二叉树
//递归遍历↓
void PreOrder(BinTree t);//前序遍历
void InOrder(BinTree t);//中序遍历
void PostOrder(BinTree t);//后序遍历
void LevelOrder(BinTree t);//层级遍历
//非递归遍历↓
void PreOrder_Nor(BinTree t);//
void InOrder_Nor(BinTree t);
void PostOrder_Nor(BinTree t);

size_t Size(BinTree t);//二叉树节点个数
size_t Height(BinTree t);//二叉树高度
BinTreeNode* Find(BinTree t,ElemType key);//查找值为key的节点
BinTreeNode* Parent(BinTree t, BinTreeNode* s);//查找s节点的父节点
int BinTreeLeafSize(BinTree t); //二叉树叶子节点个数
int BinTreeLevelKSize(BinTree t, int k);//二叉树第k层节点个数
BinTree Clone(BinTree t);//克隆二叉树
int BinTreeComplete(BinTree t);// 判断二叉树是否是完全二叉树
bool Equal(BinTree t1, BinTree t2);//比较两个二叉树
