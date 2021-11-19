#include <stdio.h>
#include "DLinkedList.h"
#include "DLinkedList.c"

// ����Ʈ�� ADT�� ������� ���ǵ� main �Լ� 
int main(void) {
	
	// ArrayList�� ���� �� �ʱ�ȭ
	List list; // List��� ����� Ÿ�� �ڷ��� ���� 
	int data;
	ListInit(&list);
	
	// 5���� ������ ���� 
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	// ����� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));
	
	// ù��° ������ ��ȸ
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		// �ι�° ���� ������ �� ��ȸ 
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	printf("\n\n");
	
	// 2, 3�� ����� Ž���Ͽ� ��� ���� 
	if(LFirst(&list, &data)) {
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data)) {
			if(data == 22)
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
