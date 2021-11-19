#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, Data data) // 노드를 머리에 추가, tail -> next가 머리를 가리킴 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode; // 원형 연결 리스트 초기화, 자기 자신을 가리킨다. 
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode; // 계속 앞에 삽입되게 코딩함 
	}
	(plist->numOfData)++;
}

void LInsert(List * plist, Data data) // 꼬리에 데이터 추가 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode; // 원형 연결 리스트 초기화, 자기 자신을 가리킨다. 
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode; // 머리에 newNode추가 
		plist->tail = newNode; // 꼬리 주소를 newNode로 변경, 그러면 뒤부터 삽입됨 
	}
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->tail; // before를 꼬리에 놓기 
	plist->cur = plist->tail->next; // cur를 꼬리 다음 데이터에 놓기(머리) 
	
	*pdata = plist->cur->data; // cur의 데이터가 머리이므로 그 값을 데이터에 담는다.
	// 외부에서 사용하는 데이터
	
	return TRUE; 
}

int LNext(List * plist, Data * pdata)
{
	if(plist->tail == NULL)
	{
		return FALSE;
	}
	
	// before와 cur의 위치 재정렬 
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur; // 삭제될 주소
	Data rdata = rpos->data; // 삭제될 데이터
	
	if(rpos == plist->tail) // 다음 데이터가 존재 X, 우리는 다음 데이터로 덮어쓰는 삭제를 하므로 위치 변경해줘야 함 
	{
		if(plist->tail == plist->tail->next) // 데이터가 1개라면 그냥 NULL로 지우자 
		{
			plist->tail = NULL;
		} else {
			plist->tail = plist->before; // 머리에 데이터가 있는 경우 plist->before을 tail로 이동시켜주자
			// cur와 tail이 같으므로, cur은 삭제될 운명 ^^ 
		} 
	}
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	// 이러면 cur과 before의 위치가 같아진다.
	// 하지만 괜찮다. 어차피 Remove를 하려면 LFirst나 LNext를 써야 하므로
	// 그때 before와 cur의 위치가 재정렬된다.
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
