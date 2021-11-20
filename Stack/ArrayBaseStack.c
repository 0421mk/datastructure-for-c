#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) {
	pstack->topIndex = -1; // -1로 초기화, 값 삽입시 += 1; 
}

int SIsEmpty(Stack * pstack) {
	if(pstack->topIndex == -1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void SPush(Stack * pstack, Data data) {
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) {
	int ridx;
	
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1); // 종료 함수 stdlib.h
	}
	
	ridx = pstack->topIndex;
	pstack->topIndex -= 1;
	
	return pstack->stackArr[ridx];
}

Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}

