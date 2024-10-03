#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node{
    int value;
    struct node* next;
} node;


node *createNode(int value){
    node *ptr = (node*)malloc(sizeof(node));

    ptr->value = value;
    ptr->next = NULL;

    return ptr;
}


int size(node **array){
    int count = 0;
    node *p = *array;
    while(p != NULL){
        count++;
        p = p->next; 
    }
    return count;
}


void push_back(node **array, int value){
    node *temp = createNode(value);

    if (*array == NULL)
    {
        *array = temp;
    } else {
        node *p = *array;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}


void push_front(node **array, int value){
    node *temp = createNode(value);
    if (*array == NULL)
    {
        *array = temp;
    } else {
        temp->next = *array;
        *array = temp;
    }
    
}


void insert(node **array, int value, int pos){
    int sizeArr = size(array);

    if (pos < 1 || pos > sizeArr + 1){
        printf("Eror: Position is invalid!");
        return;
    }

    if (pos == 1){
        push_front(array, value);
    }

    if (pos == sizeArr + 1){
        push_back(array, value);
    }

    node *p = *array;
    int currentPos = 1;
    while(p != NULL && currentPos < pos - 1){
        p = p->next;
        currentPos++;
    }
    if(p != NULL){
        node *temp = createNode(value);
        temp->next = p->next;
        p->next = temp;
    }
}


void pop_back(node **array){
    if (*array == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    
    node *p = *array;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = NULL;
}

void pop_front(node **array){
    if (*array == NULL) {
        printf("Error: List is empty.\n");
        return;
    }

    node *p = *array;
    p = p->next;
    *array = p;
}

void erase(node **array, int pos, int num){
    int sizeArr = size(array);

    if(*array == NULL){
        printf("Error: List is empty!\n");
        return;
    }

    if (pos < 1 || pos > sizeArr){
        printf("Eror: Position is invalid!\n");
        return;
    }

    if (pos == 1) {
        node *current = *array;
        for (int i = 0; i < num && current != NULL; i++) {
            current = current->next;
        }
        *array = current;
        return;
    }

    node *p = *array;
    int currentPos = 1;
    while(p != NULL && currentPos < pos - 1){
        p = p->next;
        currentPos++;
    }
    if (p == NULL || p->next == NULL) {
        printf("Error: Position is out of range!\n");
        return;
    }
    node *current = p->next;
    for (int i = 0; i < num && current != NULL; i++) {
        current = current->next;
    }
    p->next = current;
}


int front(node *array){
    node *p = array;
    return p->value;
}


int back(node *array){
    node *p = array;
    while(p->next != NULL){
        p = p->next;
    }
    return p->value;
}


int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}


bool empty(node **array){
    return *array == NULL;
}


void printList(node *array){
    node *p = array;
    while(p != NULL){
        printf("%d\n", p->value);
        p = p->next;
    }
}


void clear(node *array){
    node *temp = array;
    node *nextNode;
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}
























