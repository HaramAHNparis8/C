#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    Node* list = NULL;

    // 리스트 생성
    list = (Node*)malloc(sizeof(Node));
    list->data = 1;
    list->next = NULL;

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = 2;
    temp->next = NULL;
    list->next = temp;

    temp = (Node*)malloc(sizeof(Node));
    temp->data = 3;
    temp->next = NULL;
    list->next->next = temp;

    // 리스트 역순으로 출력
    Node* reversedList = reverseList(list);
    while (reversedList != NULL) {
        printf("%d ", reversedList->data);
        reversedList = reversedList->next;
    }

    return 0;
}

