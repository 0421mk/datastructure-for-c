#include <stdio.h>
#include "BinaryTree.c"

void InorderTraverse(BTreeNode * bt)
{
	if(bt == NULL) // 트리의 서브트리가 꽉 채워져있든, 공집합 노드가 있든 NULL 이 발견되면 그 트리는 더이상 노드 X 
		return;
		
	InorderTraverse(bt->left);
	printf("%d \n", bt->data); // 순회의 표식 
	InorderTraverse(bt->right);
}

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	
	InorderTraverse(bt1); // 재귀적으로 접근했기 때문에 순서는 무방하나 중위순회를 하고 있다. 
	
	return 0;
}
