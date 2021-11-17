#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.c"
#include "NameCard.c"

int main(void)
{
	List list;
	NameCard * pcard;
	
	ListInit(&list);
	
	pcard = MakeNameCard("������", "010-4446-5052");
	LInsert(&list, pcard); // LData data�� �ּҸ� �޴´�. (1��������), LData * pdata�� �������� �ּҸ� �޴´�. (2�� ������)
	
	pcard = MakeNameCard("������", "010-5948-5056");
	LInsert(&list, pcard); // LData data�� �ּҸ� �޴´�. (1��������), LData * pdata�� �������� �ּҸ� �޴´�. (2�� ������) 
	
	pcard = MakeNameCard("������", "010-9116-4547");
	LInsert(&list, pcard); // LData data�� �ּҸ� �޴´�. (1��������), LData * pdata�� �������� �ּҸ� �޴´�. (2�� ������)

	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "������")) {
			ShowNameCardInfo(pcard);
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "������")) {
				ShowNameCardInfo(pcard);
			}
		}
	}
	
	printf("\n\n");
	
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "������")) {
			ChangePhoneNum(pcard, "010-0000-0000");
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "������")) {
				ChangePhoneNum(pcard, "010-0000-0000");
			}
		}
	}
	
	printf("\n\n");
	
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "������")) {
			ShowNameCardInfo(pcard);
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "������")) {
				ShowNameCardInfo(pcard);
			}
		}
	}
	
	printf("\n\n");
	
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "������")) {
			LRemove(&list);
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "������")) {
				LRemove(&list);
			}
		}
	}
	
	printf("\n\n");
	
	if(LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		
		while(LNext(&list, &pcard)) {
			ShowNameCardInfo(pcard);
		}
	}
	
	printf("\n\n");
}
