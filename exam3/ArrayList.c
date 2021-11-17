#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0; // 데이터 수 0으로 초기화
	(plist -> curPosition) = -1; // 현재 주소값 없음 
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData >= LIST_LEN) {
		puts("저장이 불가능합니다.");
		return;
	}
	
	plist->arr[plist->numOfData] = data; // 데이터 수가 인덱스가 된다.
	(plist->numOfData)++; // 데이터 인덱스를 채우고 다음 전체 데이터 값을 1 올린다. 
}

int LFirst(List * plist, LData * pdata) // LData 는 Point * 이므로 이중포인터이다. 
{
	if(plist->numOfData == 0)
		return FALSE; // 데이터가 없으면 참조할 데이터가 없다. 
		
	(plist->curPosition) = 0; // curPosition 현재 데이터를 가르키는 지표 0
	*pdata = plist->arr[0]; // 데이터의 값을 plist->arr[0]으로 초기화 
	
	return TRUE; 
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData) - 1)
		return FALSE; // 현재 데이터의 위치가 전체 데이터의 -1 즉, 서로 같으면 마지막이고 크다면 배열 오버플로우 발생 

	(plist->curPosition)++; // 현재 포지션의 위치 증가 
	*pdata = plist->arr[plist->curPosition]; // 현재 가르키는 데이터 값도 Next 값으로 수정 
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition; // 현재 위치(삭제할 인덱스를 다음 인덱스 값으로 덮어 씌울 예정 
	int num = plist->numOfData; // 데이터의 총량(나중에 줄여줄 것) 
 	
 	int i;
 	LData rdata = plist->arr[rpos]; // 삭제할 인덱스 값을 저장, 덮어 씌울 예정 
 	
 	for(i = rpos; i < num-1; i++) {
 		plist->arr[i] = plist->arr[i+1];
 		// 삭제할 인덱스의 오른쪽 데이터부터 전체 데이터 num - 1까지 한칸씩 앞당긴다.
		// 자연스럽게 삭제할 인덱스가 덮어씌어져 없어지게 된다. 
	 }
	 
	 (plist->numOfData)--;
	 (plist->curPosition)--; // 자연스럽게 인덱스 값을 1씩 줄여준다. (삭제했는데 다음 인덱스를 가리키면 이상하므로) 

	return rdata; // 삭제된 인덱스 값 출력 
}

int LCount(List * plist)
{
	return plist->numOfData;
}
