#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0; // ������ �� 0���� �ʱ�ȭ
	(plist -> curPosition) = -1; // ���� �ּҰ� ���� 
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData >= LIST_LEN) {
		puts("������ �Ұ����մϴ�.");
		return;
	}
	
	plist->arr[plist->numOfData] = data; // ������ ���� �ε����� �ȴ�.
	(plist->numOfData)++; // ������ �ε����� ä��� ���� ��ü ������ ���� 1 �ø���. 
}

int LFirst(List * plist, LData * pdata) // LData �� Point * �̹Ƿ� �����������̴�. 
{
	if(plist->numOfData == 0)
		return FALSE; // �����Ͱ� ������ ������ �����Ͱ� ����. 
		
	(plist->curPosition) = 0; // curPosition ���� �����͸� ����Ű�� ��ǥ 0
	*pdata = plist->arr[0]; // �������� ���� plist->arr[0]���� �ʱ�ȭ 
	
	return TRUE; 
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData) - 1)
		return FALSE; // ���� �������� ��ġ�� ��ü �������� -1 ��, ���� ������ �������̰� ũ�ٸ� �迭 �����÷ο� �߻� 

	(plist->curPosition)++; // ���� �������� ��ġ ���� 
	*pdata = plist->arr[plist->curPosition]; // ���� ����Ű�� ������ ���� Next ������ ���� 
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition; // ���� ��ġ(������ �ε����� ���� �ε��� ������ ���� ���� ���� 
	int num = plist->numOfData; // �������� �ѷ�(���߿� �ٿ��� ��) 
 	
 	int i;
 	LData rdata = plist->arr[rpos]; // ������ �ε��� ���� ����, ���� ���� ���� 
 	
 	for(i = rpos; i < num-1; i++) {
 		plist->arr[i] = plist->arr[i+1];
 		// ������ �ε����� ������ �����ͺ��� ��ü ������ num - 1���� ��ĭ�� �մ���.
		// �ڿ������� ������ �ε����� ������� �������� �ȴ�. 
	 }
	 
	 (plist->numOfData)--;
	 (plist->curPosition)--; // �ڿ������� �ε��� ���� 1�� �ٿ��ش�. (�����ߴµ� ���� �ε����� ����Ű�� �̻��ϹǷ�) 

	return rdata; // ������ �ε��� �� ��� 
}

int LCount(List * plist)
{
	return plist->numOfData;
}
