#include <stdio.h>
// 1 1 2 3 5 8 13
// Fibo(n) = Fibo(n-1) + Fibo(n-2);
// n == 2 => Fibo(1) + Fibo(0); 1 + 0 으로 해석 가능 
// n == 1 => Fibo(0) + Fibo(-1); 0 + 0 으로 해석 가능 

int Fibo(int num)
{
	printf("func call param %d \n", num);
	
	if(num == 1)
		return 0;
	else if(num == 2)
		return 1;
	else
		return Fibo(num-1) + Fibo(num-2);
}

int main(void)
{
	int i;
	for (i = 1; i < 10; i++) {
		printf("%d ", Fibo(i));
	}
	
	return 0;
}
