#include "SimpleHeap.h"

void HeapInit(Heap * ph) {
	ph->numOfData = 0;
}
int HIsEmpty(Heap * ph) {
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx/2;
}

int GetLChildIDX(int idx)
{
	return idx*2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData) {
		return 0;
	}
	else if(GetLChildIDX(idx) == ph->numOfData) {
		return GetLChildIDX(idx);		
	}
	else {
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) {
			return GetRChildIDX(idx); // 오른쪽 힙의 우선순위가 더 높다면 우선순위 인덱스 반환 
		} else {
			return GetLChildIDX(idx); // 왼쪽 자식 노드의 인덱스 값 반환 
		}
	}
} 

void HInsert(Heap * ph, HData data, Priority pr) {
	int idx = ph -> numOfData + 1;
	HeapElem nelem = {pr, data};
	
	while(idx != 1) { // 추가되는 노드 idx가 루트라면 삽입할 필요가 없다. 
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr)) { // 맨 뒤에 삽입, 부모보다 우선순위가 높다면? 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // 부모 노드를 자식 노드 주소에 넣음, 부모 레벨을 하나 내림 
			
			idx = GetParentIDX(idx); // 부모의 인덱스 삽입 
		}
		else { // 새 노드의 우선순위가 높다면? 그냥 그 자리에 두자 
			break;
		}
	}
	
	// 이러한 반복 작업이 끝나고 정해진 위치에 데이터 추가
	ph->heapArr[idx] = nelem;
	ph->numOfData += 1; 
}
HData HDelete(Heap * ph) {
	HData retData = (ph->heapArr[1]).data; // 반환을 위한 루트 데이터(삭제 예정) 저장
	HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장 -> 빈 공간을 채워야 함 -> 루트로 이동
	
	int parentIdx = 1; // 루트 노드가 위치해야 할 인덱스 값 저장 
	int childIdx;
		
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) // 처음 parentIdx = 1의 자식중 우선순위가 높은 값이 childIdx로 넘어감 
	{
		if(lastElem.pr <= ph->heapArr[childIdx].pr) {
			break; // 만약 위 조건과 같다면 lastElem은 루트가 자신의 자리가 맞음 
		}
		
		// 아니라면 루트와 childIdx 주소가 서로 바뀌어야 함 
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // 부모 주소에 childIdx 주소값 넣기
		parentIdx = childIdx; // 인덱스 값을 변경, 이렇게 하면 자식 노드의 인덱스부터 다시 while 돌린다. 
	}
	
	// 우선 순위 비교가 끝난 뒤
	ph->heapArr[parentIdx] = lastElem; // 실제 위치에 값을 넣어주기 
	ph->numOfData -= 1;
	return retData; 
}
