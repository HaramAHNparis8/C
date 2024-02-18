#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int nombre;
    struct element* suivant;
} element;

element* combine(element* list1, element* list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    element* tête = NULL;
    element* queue = NULL;

    // 두 리스트의 첫 번째 노드 중 작은 값을 head로 설정
    if (list1->nombre < list2->nombre) {
        tête = list1;
        list1 = list1->suivant;
    } else {
        tête = list2;
        list2 = list2->suivant;
    }
    queue = tête;

    
    while (list1 != NULL && list2 != NULL) {
        if (list1->nombre < list2->nombre) {
            queue->suivant = list1;
            list1 = list1->suivant;
        } else {
            queue->suivant = list2;
            list2 = list2->suivant;
        }
        queue = queue->suivant;
    }

    
    if (list1 != NULL) {
        queue->suivant = list1;
    } else {
        queue->suivant = list2;
    }

    return tête;
}

int main() {
    element* list1 = NULL;
    element* list2 = NULL;

    
    list1 = (element*)malloc(sizeof(element));
    list1->nombre = 1;
    list1->suivant = NULL;

    element* temp = (element*)malloc(sizeof(element));
    temp->nombre = 3;
    temp->suivant = NULL;
    list1->suivant = temp;

    temp = (element*)malloc(sizeof(element));
    temp->nombre = 5;
    temp->suivant = NULL;
    list1->suivant->suivant = temp;

    
    list2 = (element*)malloc(sizeof(element));
    list2->nombre = 2;
    list2->suivant = NULL;

    temp = (element*)malloc(sizeof(element));
    temp->nombre = 4;
    temp->suivant = NULL;
    list2->suivant = temp;

    
    element* combinList = combine(list1, list2);

    
    element* actuel = combinList;
    while (actuel != NULL) {
        printf("%d ", actuel->nombre);
        actuel = actuel->suivant;
    }

    return 0;
}

