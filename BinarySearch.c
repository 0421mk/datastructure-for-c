#include <stdio.h>

// ADT : ���� Ž�� (���ĵ� ������ ����) 
// BSearch => Ž�� ������ Ž�� �� ��ȯ, ���� Ƚ�� ��ȯ
// Ž�� ���н� Ž���� ū�� ������ �Ǵ� -> �Ǵ� �� Ž�� ���� ��� 
// int �迭 �ڷ������� ���� ����

int BSearch(int * ar, int len, int target) {
	
	int first = 0;
	int last = len - 1;
	int mid;
	
	while(first<=last) {
		mid = (first+last)/2;
		
		printf("mid : %d\n", mid);
		
		if(target == ar[mid]) {
			return mid;
		}	
		else if(target > ar[mid]) {
			first = mid + 1;
		} else if(target < ar[mid]) {
			last = mid - 1;
		}
	}
	
	return -1;
} 

int main(void) {
	
	int ar[] = {2,4,6,8,10};
	
	int result = BSearch(ar, sizeof(ar)/sizeof(int), 6);
	printf("%d", result);
	
	if(result == -1) {
		printf("�������� �ʽ��ϴ�.\n");
	} else {
		printf("Ž�� �Ϸ� �ε��� : %d\n", result);
	}
	
	return 0;
}