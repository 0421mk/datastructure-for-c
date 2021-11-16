#include <stdio.h>

// ADT : 순차탐색
// LSearch => 탐색 성공시 탐색한 값 반환, 실패시 -1 반환 
// int 배열 자료형으로 예시 수행 

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
		printf("존재하지 않습니다.\n");
	} else {
		printf("탐색 완료 인덱스 : %d\n", result);
	}
	
	return 0;
}
