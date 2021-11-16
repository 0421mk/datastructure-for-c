#include <stdio.h>

// ADT : 이진 탐색 (정렬된 데이터 가정) 
// BSearch => 탐색 성공시 탐색 값 반환, 연산 횟수 반환
// 탐색 실패시 탐색값 큰지 작은지 판단 -> 판단 후 탐색 범위 축소 
// int 배열 자료형으로 예시 수행

int BSearch(int * ar, int len, int target) {
	
	int first = 0;
	int last = len - 1;
	int mid;
	
	while(first<=last) {
		mid = (first+last)/2;
		
		if(ar[mid] == target) {
			return mid;
		} else {
			if(ar[mid] < target) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}
	}
	
	return -1;
	
}

int main(void) {
	
	int ar[] = {2,4,6,8,10};
	
	int result = BSearch(ar, sizeof(ar)/sizeof(int), 2);
	
	if(result == -1) {
		printf("존재하지 않습니다.\n");
	} else {
		printf("탐색 완료 인덱스 : %d\n", result);
	}
	
	return 0;
}
