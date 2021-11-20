#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.c"
#include "PostCalculator.c"

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len+1); // 문자열 저장공간 마련 strlen은 문자의 개수만 나오므로 + 1 해줘야 함 
	strcpy(expcpy, exp);
	
	ConvToRPNExp(expcpy);
	ret = EvalRPNExp(expcpy);
	
	free(expcpy);
	return ret;
}
