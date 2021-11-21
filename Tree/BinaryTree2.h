#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void); // Ʈ���� ����� �Լ� 
BTData GetData(BTreeNode * bt); // Ʈ���� �����͸� Get�ϴ� �Լ� 
void SetData(BTreeNode * bt, BTData data); // Ʈ���� �����͸� Set�ϴ� �Լ� 

BTreeNode * GetLeftSubTree(BTreeNode * bt); // leftSubTree �ּҰ��� ��ȯ 
BTreeNode * GetRightSubTree(BTreeNode * bt); // rightSubTree �ּҰ��� ��ȯ 

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub); // leftSubTree�� �����ϴ� �Լ� 
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub); // rightSubTree�� �����ϴ� �Լ�

typedef void (*VisitFuncPtr)(BTData data); // �Լ� ������ ����

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);

#endif
