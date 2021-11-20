#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.c"

Employee * WhosNightDuty(List * plist, char * name, int day) {
	
	Employee *ret;
	
	int i, total;
	total = LCount(plist);
	
	LFirst(plist, &ret);
	
	if(strcmp(ret->name, name) != 0) {
		for(i = 0; i < total-1; i++) {
			LNext(plist, &ret);
			
			if(strcmp(ret->name, name) == 0) {
				break;
			}
		}
		
		if(i >= total -1) {
			return NULL; // 해당하는 값 찾지 못함 
		}
	}
	
	for(i = 0; i < day; i++) {
		LNext(plist, &ret);
	}
	
	return ret;
}

void showEmployeeInfo(Employee * emp)
{
	printf("Employee name : %s \n", emp->name);
	printf("Employee number : %d \n", emp->empNum);
}

int main(void)
{
	int i;
	Employee * pemp;
	
	// 리스트 생성 및 초기화 
	List list;
	ListInit(&list);
	
	// 리스트에 4개의 데이터 저장
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1;
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp); // 주소를 넣는다 (여러개의 데이터 구조체이므로)
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "Jery");
	LInsert(&list, pemp); // 주소를 넣는다 (여러개의 데이터 구조체이므로)
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "Hary");
	LInsert(&list, pemp); // 주소를 넣는다 (여러개의 데이터 구조체이므로)
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "Sunny");
	LInsert(&list, pemp); // 주소를 넣는다 (여러개의 데이터 구조체이므로)
	
	// Terry 뒤로 15일 뒤 당직자는?
	pemp = WhosNightDuty(&list, "Terry", 15);
	showEmployeeInfo(pemp);
	
	return 0;
}
