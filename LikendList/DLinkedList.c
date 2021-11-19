#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // 더미 데이터 초기화, head는 DMY를 가리킴 
	plist->head->next = NULL; // 다음 데이터 NULL로 초기화 
	plist->comp = NULL;
	plist->numOfData = 0; 
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head; // pred는 더미노드를 가리킴, head가 더미노드를 가리키므로 
	newNode->data = data;
	
	while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		// plist->comp(data, pred->next->data) 에서 pred->next->data는 더미 오른쪽 데이터
		// 신규 입력된 데이터 < 더미 오른쪽 데이터이면 pred를 한칸 옆으로 이동
		// 정렬하여 저장하기 위해서 
		pred = pred->next;
	}
	
	newNode->next = pred->next; // 새 노드는 프레드 다음 데이터를 가리킴 
	pred->next = newNode; // 프레드는 새로운 노드를 가리키면서 사이에 새로운 데이터 추가 
	
	(plist->numOfData)++;
}

void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)
	{
		FInsert(plist, data);
	} else {
		SInsert(plist, data);
	}
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->head; // 첫 before 주소 초기화 
	plist->cur = plist->head->next; // 첫 cur 주소 초기화 

	*pdata = plist->cur->data;
	return TRUE; 
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp; // comp라는 함수를 사용할 수 있도록 처리한 것 
}
