#include <stdio.h>
#include "DLinkedList.h"
#include "DLinkedList.c"

// 리스트의 ADT를 기반으로 정의된 main 함수 
int main(void) {
	
	// ArrayList의 생성 및 초기화
	List list; // List라는 사용자 타입 자료형 정의 
	int data;
	ListInit(&list);
	
	// 5개의 데이터 저장 
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	// 저장된 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));
	
	// 첫번째 데이터 조회
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		// 두번째 이후 데이터 총 조회 
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	printf("\n\n");
	
	// 2, 3의 배수를 탐색하여 모두 삭제 
	if(LFirst(&list, &data)) {
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data)) {
			if(data == 22)
				LRemove(&list);
		}
	}
	
	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	printf("\n\n");
	return 0;
}
