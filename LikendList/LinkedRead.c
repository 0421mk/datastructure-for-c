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
		printf("�ڿ��� �Է� : ");
		scanf("%d", &readData);
		
		if (readData < 1) {
			break;
		}
		
		// ��� �߰�
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		if(head == NULL) {
			head = newNode; // ù��° ������ �ʱ�ȭ 
		} else {
			tail->next = newNode; // �Ʒ� tail = newNode�� ����
			// ù��° ����� head�� tail�� ���� ���� ����� �ּҸ� ����Ŵ
			// ���⼭ �߿��� ���� ����� �ּ�
			// �׷� ���� ���� ��带 �Է¹��� �� tail->next = newNode�� �Ѵٸ�
			// �ּҰ��� �����ϹǷ� head�� next�� newNode�� �������
			// ������ head�� Data�� �ʱ�ȭ�� �״�� ����
			// ���� head�� �����ʹ� �ʱ�ȭ, next�� ���� �Է¹��� ������, �׸��� �Ʒ�
			// tail = newNode�� ���� tail�� ���� �Է¹��� ������, next�� NULL�� ����Ŵ 
		}
		
		tail = newNode;
	}
	
	printf("\n\n");
	
	// �Է¹��� ������ ���
	if(head == NULL) {
		printf("����� �ڿ����� �������� �ʽ��ϴ�.\n");
	} else {
		cur = head; // ó�� ������ ��ġ �ʱ�ȭ 
		printf("������ �Է� : %d \n", cur->data); // ó�� ������ ��� 
		
		while(cur->next != NULL) { // cur->next�� NULL�϶����� �ݺ� 
			cur = cur->next; // ��ġ �������� ����
			printf("������ �Է� : %d \n", cur->data); // ���� ������ ��� 
			
			// cur�� ���� ��带 ���������Ƿ� ���� ����� ���� ��尡 ������ �ߴ� 
		}
	}
	
	printf("\n\n");
	
	// �޸� ���� ���� 
	if(head == NULL) {
		printf("����� �ڿ����� �������� �ʽ��ϴ�.\n");
	} else {
		Node * delNode = head;
		Node * delNextNode = head->next; // ó�� ������ ��ġ �ʱ�ȭ
		
		printf("�ڿ��� %d�� �����մϴ�. \n", delNode->data);
		free(delNode); // ������ ����
		
		while(delNextNode != NULL) { // delNextNode�� NULL�϶����� �ݺ� 
			delNode = delNextNode;
			delNextNode = delNextNode->next; 
			
			printf("�ڿ��� %d�� �����մϴ�. \n", delNode->data);
			free(delNode); // ������ ����
			
			// cur�� ���� ��带 ���������Ƿ� ���� ����� ���� ��尡 ������ �ߴ� 
		}
	}
	
	return 0;
}
