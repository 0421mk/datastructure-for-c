#include <stdio.h>

// ADT : ����Ž��
// LSearch => Ž�� ������ Ž���� �� ��ȯ, ���н� -1 ��ȯ 
// int �迭 �ڷ������� ���� ���� 

int LSearch(int * ar, int len, int idx) {
	for(int i = 0; i < len; i++) {
		if(ar[i] == idx) {
			return i;
		}
	}
	return -1;
} 

int main(void) {
	
	int ar[] = {2,4,6,8,10};
	
	int result = LSearch(ar, sizeof(ar)/sizeof(int), 7);
	if(result == -1) {
		printf("�������� �ʽ��ϴ�.\n");
	} else {
		printf("Ž�� �Ϸ� �ε��� : %d\n", result);
	}
	
	return 0;
}
