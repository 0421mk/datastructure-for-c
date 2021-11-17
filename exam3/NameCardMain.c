#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.c"
#include "NameCard.c"

int main(void)
{
	List list;
	NameCard * pcard;
	
	ListInit(&list);
	
	pcard = MakeNameCard("최윤우", "010-4446-5052");
	LInsert(&list, pcard); // LData data는 주소를 받는다. (1중포인터), LData * pdata는 포인터의 주소를 받는다. (2중 포인터)
	
	pcard = MakeNameCard("최윤종", "010-5948-5056");
	LInsert(&list, pcard); // LData data는 주소를 받는다. (1중포인터), LData * pdata는 포인터의 주소를 받는다. (2중 포인터) 
	
	pcard = MakeNameCard("정은정", "010-9116-4547");
	LInsert(&list, pcard); // LData data는 주소를 받는다. (1중포인터), LData * pdata는 포인터의 주소를 받는다. (2중 포인터)

	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "최윤종")) {
			ShowNameCardInfo(pcard);
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "최윤종")) {
				ShowNameCardInfo(pcard);
			}
		}
	}
	
	printf("\n\n");
	
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "최윤종")) {
			ChangePhoneNum(pcard, "010-0000-0000");
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "최윤종")) {
				ChangePhoneNum(pcard, "010-0000-0000");
			}
		}
	}
	
	printf("\n\n");
	
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "최윤종")) {
			ShowNameCardInfo(pcard);
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "최윤종")) {
				ShowNameCardInfo(pcard);
			}
		}
	}
	
	printf("\n\n");
	
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard, "최윤종")) {
			LRemove(&list);
		}
		
		while(LNext(&list, &pcard)) {
			if(!NameCompare(pcard, "최윤종")) {
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
