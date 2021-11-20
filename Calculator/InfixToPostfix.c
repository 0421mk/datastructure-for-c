#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "ListBaseStack.c"

int GetOpPrec(char op) {
	switch(op)
	{
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);
	
	if(op1Prec > op2Prec) {
		return 1;
	} else if(op1Prec < op2Prec) {
		return -1;
	} else {
		return 0;
	}
}

void ConvToRPNExp(char exp[]) {
	Stack stack; // 쟁반 
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1);
	
	int i, idx = 0;
	char tok, popOp;
	
	// 모든 문자 0으로 초기화, 자연스럽게 문자열의 끝 지정(/0) 
	memset(convExp, 0, sizeof(char)*expLen+1);
	StackInit(&stack);
	
	for(i=0; i < expLen; i++) {
		tok = exp[i];
		if(isdigit(tok)) {
			convExp[idx++] = tok; // 값을 넣고 idx 1 추가
		} else {
			switch(tok)
			{
				case '(':
					SPush(&stack, tok); // 쟁반에 올림
					break;
				case ')':
					while(1)
					{
						popOp = SPop(&stack);
						if(popOp == '(')
							break;
						convExp[idx++] = popOp; // 그려보면 이해됨 
					 }
					 break;
				case '+': case '-':
				case '*': case '/':
					// 쟁반에 있는 값이 있다면, 그리고 우선순위가 쟁반에 있는게 더 높다면? 날린다. 
					while(!SIsEmpty(&stack)&&WhoPrecOp(SPeek(&stack), tok) >= 0)
						convExp[idx++] = SPop(&stack); // 날리면서 값 반환
					SPush(&stack, tok); // 새롭게 쟁반에 올림, 이미 값이 있다면 우선순위가 더 높아서 추가로 올림
					break;
			}	
		}
	}
	
	while(!SIsEmpty(&stack)) {
		convExp[idx++] = SPop(&stack); // 스택에 남은 연산자를 convExp 배열에 추가 
	}
	
	strcpy(exp, convExp);
	free(convExp);
}
