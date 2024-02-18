#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

//전달받은 데이터를 저장하는 하나의 노드를 생성하는 함수
NODE* createNode(int data)
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->next = NULL;
	temp->data = data;
	return temp;
}

//현재 리스트의 맨 뒤에 노드를 추가해주는 함수
void addNode(NODE **head, int data)
{
	// 전달받은 값을 저장하는 새로운 노드를 생성한다.
	NODE *newNode = createNode(data);
	// 헤드에 아무것도 없을 경우
	// 즉, 현재 노드가 하나도 없을 경우
	if(*head == NULL)
	{
		// 헤드에 생성한 노드를 연결
		*head = newNode;
	}
	else
	{
		NODE *temp = *head;
		// 마지막 노드를 찾는 루프
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		// 마지막 노드일 경우 새로 생성한 노드 연결
		temp->next = newNode;
	}
}

void deletNode(NODE *head){
    NODE *targetNode = head -> next;
    head -> next = targetNode -> next;
    free(targetNode);
    
}

int main(void)
{
	// 리스트의 가장 처음 노드를 가르키는 포인터
	NODE *head = NULL;
	// 맨 뒤에 데이터 '10'을 가진 노드를 추가
	addNode(&head, 10);
	// 맨 뒤에 데이터 '20'을 가진 노드를 추가
	addNode(&head, 20);
	// 맨 뒤에 데이터 '30'을 가진 노드를 추가
	addNode(&head, 30);
    addNode(&head, 40);
    deletNode(head);
//    deletNode(head);
//    deletNode(head);

	
	NODE * curr = head;
	while(curr != NULL){
		printf("%d\n",curr->data);
		curr = curr->next;
	}
	curr = head -> next;
	
	while(curr != NULL){
		free(curr);
		curr = curr->next;
	}
	
	return 0;
}
