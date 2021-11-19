#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Point.c"
#include "DLinkedList.h"
#include "DLinkedList.c"

int WhoIsPrecede(Point * d1, Point * d2)
{
	if(d1->xpos < d2->xpos) {
		return 0;
	} else if(d1->xpos == d2->xpos) {
		if(d1->ypos < d2->ypos) {
			return 0;
		} else {
			return 1;
		}
	} else {
		return 1;
	}
}

// 리스트의 ADT를 기반으로 정의된 main 함수 
int main(void) {
	
	// ArrayList의 생성 및 초기화
	List list; // List라는 사용자 타입 자료형 정의 
	Point comPos;
	Point * ppos; // Point 는 구조체이다. pointer 가 아님, ppos는 주소를 입력받는 포인터
	
	ListInit(&list);
	
	SetSortRule(&list, WhoIsPrecede);
	
	// 4개의 데이터 저장 
	ppos = (Point*)malloc(sizeof(Point));
	// Point * ppos = (Point*)mallc(sizeof(Point)); 와 동일
	// 즉 ppos는 Point * ppos와 같다. 어쨌든 주소값을 입력받는 포인터 변수 
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 3);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 5);
	LInsert(&list, ppos);
	
	// 저장된 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));
	
	int total = 0;
	
	// 첫번째 데이터 조회
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos); // list에서 첫번째 데이터를 ppos 주소에 삽입 
		
		// 두번째 이후 데이터 총 조회 
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	} 
	
	// xpos가 2인 모든 데이터 삭제
	comPos.xpos = 2;
	comPos.ypos = 0;
	if(LFirst(&list, &ppos)) {
		if(PointComp(ppos, &comPos) == 1)
		{
			ppos=LRemove(&list);
			free(ppos);
		}
		
		while(LNext(&list, &ppos)) {
			if(PointComp(ppos, &comPos) == 1)
			{
				ppos=LRemove(&list);
				free(ppos);
			}
		}
	}
	
	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));
	
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	printf("\n\n");
	return 0;
}
