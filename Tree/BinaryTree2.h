#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void); // 트리를 만드는 함수 
BTData GetData(BTreeNode * bt); // 트리의 데이터를 Get하는 함수 
void SetData(BTreeNode * bt, BTData data); // 트리의 데이터를 Set하는 함수 

BTreeNode * GetLeftSubTree(BTreeNode * bt); // leftSubTree 주소값을 반환 
BTreeNode * GetRightSubTree(BTreeNode * bt); // rightSubTree 주소값을 반환 

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub); // leftSubTree를 지정하는 함수 
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub); // rightSubTree를 지정하는 함수

typedef void (*VisitFuncPtr)(BTData data); // 함수 포인터 정의

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);

#endif
