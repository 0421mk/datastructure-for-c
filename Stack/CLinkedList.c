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

void LInsertFront(List * plist, Data data) // ��带 �Ӹ��� �߰�, tail -> next�� �Ӹ��� ����Ŵ 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode; // ���� ���� ����Ʈ �ʱ�ȭ, �ڱ� �ڽ��� ����Ų��. 
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode; // ��� �տ� ���Եǰ� �ڵ��� 
	}
	(plist->numOfData)++;
}

void LInsert(List * plist, Data data) // ������ ������ �߰� 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode; // ���� ���� ����Ʈ �ʱ�ȭ, �ڱ� �ڽ��� ����Ų��. 
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode; // �Ӹ��� newNode�߰� 
		plist->tail = newNode; // ���� �ּҸ� newNode�� ����, �׷��� �ں��� ���Ե� 
	}
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->tail; // before�� ������ ���� 
	plist->cur = plist->tail->next; // cur�� ���� ���� �����Ϳ� ����(�Ӹ�) 
	
	*pdata = plist->cur->data; // cur�� �����Ͱ� �Ӹ��̹Ƿ� �� ���� �����Ϳ� ��´�.
	// �ܺο��� ����ϴ� ������
	
	return TRUE; 
}

int LNext(List * plist, Data * pdata)
{
	if(plist->tail == NULL)
	{
		return FALSE;
	}
	
	// before�� cur�� ��ġ ������ 
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur; // ������ �ּ�
	Data rdata = rpos->data; // ������ ������
	
	if(rpos == plist->tail) // ���� �����Ͱ� ���� X, �츮�� ���� �����ͷ� ����� ������ �ϹǷ� ��ġ ��������� �� 
	{
		if(plist->tail == plist->tail->next) // �����Ͱ� 1����� �׳� NULL�� ������ 
		{
			plist->tail = NULL;
		} else {
			plist->tail = plist->before; // �Ӹ��� �����Ͱ� �ִ� ��� plist->before�� tail�� �̵���������
			// cur�� tail�� �����Ƿ�, cur�� ������ ��� ^^ 
		} 
	}
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	// �̷��� cur�� before�� ��ġ�� ��������.
	// ������ ������. ������ Remove�� �Ϸ��� LFirst�� LNext�� ��� �ϹǷ�
	// �׶� before�� cur�� ��ġ�� �����ĵȴ�.
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
