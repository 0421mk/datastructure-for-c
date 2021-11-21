#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

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
