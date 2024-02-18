#include<stdio.h>
#include<stdlib.h>

struct node {

	struct node *next;
	int data;
};


int main(void){

	struct node *head = malloc(sizeof(struct node));
	struct node *node1 = malloc(sizeof(struct node));
	head -> next = node1;
	
	node1 -> data = 10;

	struct node * node2 = malloc(sizeof(struct node));
	node1 -> next = node2;
	node2 -> data = 20;

	struct node * node3 = malloc(sizeof(struct node));
	node2 -> next = node3;
	node3 -> data = 30;

	node3 -> next = NULL;

	struct node *curr = head -> next;
	while (curr != NULL){
		printf("%d\n", curr -> data);
		curr = curr -> next;
	}

	free(node3);
	free(node2);
	free(node1);
	free(head);

	return 0;
}
