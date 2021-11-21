#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode * MakeBTreeNode(void) // 트리를 만드는 함수 
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	
	return nd;
}

BTData GetData(BTreeNode * bt) // 트리의 데이터를 Get하는 함수
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data) // 트리의 데이터를 Set하는 함수
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) // leftSubTree 주소값을 반환
{
	return bt->left;
}
 
BTreeNode * GetRightSubTree(BTreeNode * bt) // rightSubTree 주소값을 반환
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) // leftSubTree를 지정하는 함수
{
	if(main->left != NULL) // leftSubTree가 존재한다면 
		free(main->left);
		
	main->left = sub; // 지정할 주소 값 세팅 
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) // rightSubTree를 지정하는 함수
{
	if(main->right != NULL) // rightSubTree가 존재한다면 
		free(main->right);
		
	main->right = sub; // 지정할 주소 값 세팅 
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
