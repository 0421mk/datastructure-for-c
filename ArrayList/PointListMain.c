#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "ArrayList.c"
#include "Point.h"
#include "Point.c"

// ����Ʈ�� ADT�� ������� ���ǵ� main �Լ� 
int main(void) {
	
	// ArrayList�� ���� �� �ʱ�ȭ
	List list; // List��� ����� Ÿ�� �ڷ��� ���� 
	Point comPos;
	Point * ppos; // Point �� ����ü�̴�. pointer �� �ƴ�, ppos�� �ּҸ� �Է¹޴� ������ 
	
	// 4���� ������ ���� 
	ppos = (Point*)malloc(sizeof(Point));
	// Point * ppos = (Point*)mallc(sizeof(Point)); �� ����
	// �� ppos�� Point * ppos�� ����. ��·�� �ּҰ��� �Է¹޴� ������ ���� 
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	// ����� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));
	
	int total = 0;
	
	// ù��° ������ ��ȸ
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos); // list���� ù��° �����͸� ppos �ּҿ� ���� 
		
		// �ι�° ���� ������ �� ��ȸ 
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	} 
	
	// xpos�� 2�� ��� ������ ����
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
	
	// ���� �� ���� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));
	
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	printf("\n\n");
	return 0;
}
