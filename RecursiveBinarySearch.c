#include <stdio.h>

// ADT : ���� Ž�� (���ĵ� ������ ����) 
// BSearch => Ž�� ������ Ž�� �� ��ȯ, ���� Ƚ�� ��ȯ
// Ž�� ���н� Ž���� ū�� ������ �Ǵ� -> �Ǵ� �� Ž�� ���� ��� 
// int �迭 �ڷ������� ���� ����

int BSearchRecur(int * ar, int first, int last, int target) {
	
	if (first > last) {
		printf("BSearchRecur ����\n");
		return -1;
	}

	int mid = (first+last)/2;
	
	if(ar[mid] == target) {
		return mid;
	} else {
		if(ar[mid] < target) {
			BSearchRecur(ar, mid + 1, last, target);
		} else {
			BSearchRecur(ar, first, mid - 1, target);
		}
	}
	
}

int main(void) {
	
	int ar[] = {2, 4, 6, 8, 10};
	
	int result = BSearchRecur(ar, 0, sizeof(ar)/sizeof(int)-1, 10);
	
	if(result == -1) {
		printf("�������� �ʽ��ϴ�.\n");
	} else {
		printf("Ž�� �Ϸ� �ε��� : %d\n", result);
	}
	
	return 0;
}
