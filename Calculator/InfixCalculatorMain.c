#include <stdio.h>
#include "InfixCalculator.c"

int main(void)
{
	char exp1[] = "1+2*3";
	
	printf("%s = %d \n", exp1, EvalInfixExp(exp1));
	
	return 0;
}
