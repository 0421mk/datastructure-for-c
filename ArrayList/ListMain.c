#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c"

// ����Ʈ�� ADT�� ������� ���ǵ� main �Լ� 
int main(void) {
	
	// ArrayList�� ���� �� �ʱ�ȭ
	List list; // List��� ����� Ÿ�� �ڷ��� ���� 
	int data;
	ListInit(&list);
	
	// 5���� ������ ���� 
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsert(&list, 9);
	
	// ����� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));
	
	int total = 0;
	
	// ù��° ������ ��ȸ
	if(LFirst(&list, &data)) {
		total += data;
		
		// �ι�° ���� ������ �� ��ȸ 
		while(LNext(&list, &data)) {
			total += data;
		}
	} 
	
	printf("���� �������� �� : %d \n", total);
	printf("\n\n");
	
	// 2, 3�� ����� Ž���Ͽ� ��� ���� 
	if(LFirst(&list, &data)) {
		if(data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
		
		while(LNext(&list, &data)) {
			if(data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}
	
	// ���� �� ���� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	printf("\n\n");
	return 0;
}
