#include <stdio.h>
#include "InfixToPostfix.c"

int main(void)
{
	char exp1[] = "(1+2*3)/4";
	
	ConvToRPNExp(exp1);
	
	printf("%s", exp1);
}
