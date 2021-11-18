#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
	int data;
	struct __node * next;
} Node;

int main(void) {
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;
	
	Node * newNode = NULL;
	int readData;
	
	while(1) {
		printf("자연수 입력 : ");
		scanf("%d", &readData);
		
		if (readData < 1) {
			break;
		}
		
		// 노드 추가
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		if(head == NULL) {
			head = newNode; // 첫번째 데이터 초기화 
		} else {
			tail->next = newNode; // 아래 tail = newNode와 연관
			// 첫번째 실행시 head와 tail은 각각 같은 노드의 주소를 가리킴
			// 여기서 중요한 점은 노드의 주소
			// 그로 인해 다음 노드를 입력받을 때 tail->next = newNode를 한다면
			// 주소값이 동일하므로 head의 next도 newNode로 덮어씌여짐
			// 하지만 head의 Data는 초기화값 그대로 유지
			// 따라서 head의 데이터는 초기화, next는 새로 입력받은 데이터, 그리고 아래
			// tail = newNode로 인해 tail은 새로 입력받은 데이터, next는 NULL을 가리킴 
		}
		
		tail = newNode;
	}
	
	printf("\n\n");
	
	// 입력받은 데이터 출력
	if(head == NULL) {
		printf("저장된 자연수가 존재하지 않습니다.\n");
	} else {
		cur = head; // 처음 데이터 위치 초기화 
		printf("데이터 입력 : %d \n", cur->data); // 처음 데이터 출력 
		
		while(cur->next != NULL) { // cur->next가 NULL일때까지 반복 
			cur = cur->next; // 위치 다음으로 변경
			printf("데이터 입력 : %d \n", cur->data); // 다음 데이터 출력 
			
			// cur에 다음 노드를 삽입했으므로 다음 노드의 다음 노드가 없으면 중단 
		}
	}
	
	printf("\n\n");
	
	// 메모리 해제 과정 
	if(head == NULL) {
		printf("저장된 자연수가 존재하지 않습니다.\n");
	} else {
		Node * delNode = head;
		Node * delNextNode = head->next; // 처음 데이터 위치 초기화
		
		printf("자연수 %d를 삭제합니다. \n", delNode->data);
		free(delNode); // 데이터 삭제
		
		while(delNextNode != NULL) { // delNextNode가 NULL일때까지 반복 
			delNode = delNextNode;
			delNextNode = delNextNode->next; 
			
			printf("자연수 %d를 삭제합니다. \n", delNode->data);
			free(delNode); // 데이터 삭제
			
			// cur에 다음 노드를 삽입했으므로 다음 노드의 다음 노드가 없으면 중단 
		}
	}
	
	return 0;
}
