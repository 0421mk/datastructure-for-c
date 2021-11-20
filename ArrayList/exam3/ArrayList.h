#ifndef __ARRAY_LIST_H__ // __ARRAPY_LIST_H__ � ���ڷ� ��ü�ص� �������, �� #define�� ���� �ٲ���� �� 
#define __ARRAY_LIST_H__ // �̷��� �ϸ� �����Ϸ��� �����Ͻ� ArrayList.h ������ �߰��Ǿ��ִ��� Ȯ�� �� �߰��Ǿ����� �ʴٸ� ��ó���ϰ� �߰��Ǿ� �ִٸ� #endif�� �ǳʶپ� ���ʿ��� �����Ϸ� �˻縦 ���� 
#include "NameCard.h"

#define TRUE 1 // �� 
#define FALSE 0 // ���� 

#define LIST_LEN 100 // ��ü ������ ũ�� 
typedef NameCard * LData; // int�� ������ ������ ���� ���� 

typedef struct __ArrayList
{
	// int ������ �� arr �迭 ����, ũ��� LIST_LEN 
	LData arr[LIST_LEN];
	int numOfData; // ����� �������� �� 
	int curPosition; // ������ ���� ��ġ(LData�� ��ġ) 
} ArrayList;

typedef ArrayList List; // ArrayList�� (�迭���)List�� �θ���. 
// ���� ��ũ�� ����Ʈ���� typedef LikendList List�� ��� 

void ListInit(List * plist); // ������ �ʱ�ȭ 
void LInsert(List * plist, LData data); // ������ ����

int LFirst(List * plist, LData * pdata); // ù ������ ���� 
int LNext(List * plist, LData * pdata); // �ι�° ���� ������ ����

LData LRemove(List * plist); // ���� ������ ����
int LCount(List * plist); // ����� ������ �� ��ȯ

#endif 
