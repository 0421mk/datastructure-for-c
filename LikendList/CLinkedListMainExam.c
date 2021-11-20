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
			return NULL; // �ش��ϴ� �� ã�� ���� 
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
	
	// ����Ʈ ���� �� �ʱ�ȭ 
	List list;
	ListInit(&list);
	
	// ����Ʈ�� 4���� ������ ����
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1;
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp); // �ּҸ� �ִ´� (�������� ������ ����ü�̹Ƿ�)
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "Jery");
	LInsert(&list, pemp); // �ּҸ� �ִ´� (�������� ������ ����ü�̹Ƿ�)
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "Hary");
	LInsert(&list, pemp); // �ּҸ� �ִ´� (�������� ������ ����ü�̹Ƿ�)
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "Sunny");
	LInsert(&list, pemp); // �ּҸ� �ִ´� (�������� ������ ����ü�̹Ƿ�)
	
	// Terry �ڷ� 15�� �� �����ڴ�?
	pemp = WhosNightDuty(&list, "Terry", 15);
	showEmployeeInfo(pemp);
	
	return 0;
}
