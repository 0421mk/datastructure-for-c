#include <stdio.h>

void HanoiTowerMove(int num, char from, char serve, char to) {
	
	if (num == 1) {
		printf("���� 1�� %c���� %c�� �̵� \n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, serve);
		printf("���� %d�� %c���� %c�� �̵� \n", num, from, to);
		HanoiTowerMove(num - 1, serve, from, to);
	}
	
}

int main(void) {
	
	HanoiTowerMove(3, 'A', 'B', 'C');
	
	return 0;
}
