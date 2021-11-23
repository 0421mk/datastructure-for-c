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

// �� ���� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
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
			return GetRChildIDX(idx); // ������ ���� �켱������ �� ���ٸ� �켱���� �ε��� ��ȯ 
		} else {
			return GetLChildIDX(idx); // ���� �ڽ� ����� �ε��� �� ��ȯ 
		}
	}
} 

void HInsert(Heap * ph, HData data, Priority pr) {
	int idx = ph -> numOfData + 1;
	HeapElem nelem = {pr, data};
	
	while(idx != 1) { // �߰��Ǵ� ��� idx�� ��Ʈ��� ������ �ʿ䰡 ����. 
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr)) { // �� �ڿ� ����, �θ𺸴� �켱������ ���ٸ�? 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // �θ� ��带 �ڽ� ��� �ּҿ� ����, �θ� ������ �ϳ� ���� 
			
			idx = GetParentIDX(idx); // �θ��� �ε��� ���� 
		}
		else { // �� ����� �켱������ ���ٸ�? �׳� �� �ڸ��� ���� 
			break;
		}
	}
	
	// �̷��� �ݺ� �۾��� ������ ������ ��ġ�� ������ �߰�
	ph->heapArr[idx] = nelem;
	ph->numOfData += 1; 
}
HData HDelete(Heap * ph) {
	HData retData = (ph->heapArr[1]).data; // ��ȯ�� ���� ��Ʈ ������(���� ����) ����
	HeapElem lastElem = ph->heapArr[ph->numOfData]; // ���� ������ ��� ���� -> �� ������ ä���� �� -> ��Ʈ�� �̵�
	
	int parentIdx = 1; // ��Ʈ ��尡 ��ġ�ؾ� �� �ε��� �� ���� 
	int childIdx;
		
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) // ó�� parentIdx = 1�� �ڽ��� �켱������ ���� ���� childIdx�� �Ѿ 
	{
		if(lastElem.pr <= ph->heapArr[childIdx].pr) {
			break; // ���� �� ���ǰ� ���ٸ� lastElem�� ��Ʈ�� �ڽ��� �ڸ��� ���� 
		}
		
		// �ƴ϶�� ��Ʈ�� childIdx �ּҰ� ���� �ٲ��� �� 
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // �θ� �ּҿ� childIdx �ּҰ� �ֱ�
		parentIdx = childIdx; // �ε��� ���� ����, �̷��� �ϸ� �ڽ� ����� �ε������� �ٽ� while ������. 
	}
	
	// �켱 ���� �񱳰� ���� ��
	ph->heapArr[parentIdx] = lastElem; // ���� ��ġ�� ���� �־��ֱ� 
	ph->numOfData -= 1;
	return retData; 
}
