#include <string.h>
#include <ctype.h>

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;
	
	StackInit(&stack);
	// "5*3/4"
	// "53" "/"
	for(i = 0; i < expLen; i++) {
		tok = exp[i];
		
		if(isdigit(tok))
		{
			SPush(&stack, tok - '0');
		}
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			
			switch(tok)
			{
				case '+':
					SPush(&stack, op1+op2);
					break;
				case '-':
					SPush(&stack, op1-op2);
					break;
				case '*':
					SPush(&stack, op1*op2);
					break;
				case '/':
					SPush(&stack, op1/op2);
					break;
			}
		}
	}
	
	return SPop(&stack); // 마지막 한개 남은 스택의 값은? 결과값이다. 
}
