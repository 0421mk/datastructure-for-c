#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּҰ� ��ȯ
NameCard * MakeNameCard(char * name, char * phone) {
	NameCard * pcard = (NameCard*)malloc(sizeof(NameCard));
	
	strcpy(pcard->name, name);
	strcpy(pcard->phone, phone);
	
	return pcard;
}

// NameCard ����ü ������ ���� ��� 
void ShowNameCardInfo(NameCard * pcard)
{
	printf("name : %s, phone : %s \n", pcard->name, pcard->phone);
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard * pcard, char * name)
{
	return strcmp(pcard->name, name);
}

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy(pcard->phone, phone);
}