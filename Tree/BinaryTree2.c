#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode * MakeBTreeNode(void) // Ʈ���� ����� �Լ� 
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	
	return nd;
}

BTData GetData(BTreeNode * bt) // Ʈ���� �����͸� Get�ϴ� �Լ�
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data) // Ʈ���� �����͸� Set�ϴ� �Լ�
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) // leftSubTree �ּҰ��� ��ȯ
{
	return bt->left;
}
 
BTreeNode * GetRightSubTree(BTreeNode * bt) // rightSubTree �ּҰ��� ��ȯ
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) // leftSubTree�� �����ϴ� �Լ�
{
	if(main->left != NULL) // leftSubTree�� �����Ѵٸ� 
		free(main->left);
		
	main->left = sub; // ������ �ּ� �� ���� 
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) // rightSubTree�� �����ϴ� �Լ�
{
	if(main->right != NULL) // rightSubTree�� �����Ѵٸ� 
		free(main->right);
		
	main->right = sub; // ������ �ּ� �� ���� 
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	
	PreorderTraverse(bt->left, action);
	action(bt->data);
	PreorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
	action(bt->data);
}
