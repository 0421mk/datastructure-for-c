#include <stdio.h>

void HanoiTowerMove(int num, char from, char serve, char to) {
	
	if (num == 1) {
		printf("원반 1이 %c에서 %c로 이동 \n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, serve);
		printf("원반 %d이 %c에서 %c로 이동 \n", num, from, to);
		HanoiTowerMove(num - 1, serve, from, to);
	}
	
}

int main(void) {
	
	HanoiTowerMove(3, 'A', 'B', 'C');
	
	return 0;
}
