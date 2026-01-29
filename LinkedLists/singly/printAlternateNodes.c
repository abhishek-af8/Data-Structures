#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void printAlternate(node* head){
    if(head==NULL){
        return;
    }
    node* traversePtr = head;
    while(traversePtr!=NULL){
        printf("%d ", traversePtr->data);

        if(traversePtr->next!=NULL && traversePtr->next->next!=NULL){
            traversePtr=traversePtr->next->next;
        }
        else{
            return;
        }
    }
}

void printList(struct node* pHead){
    while(pHead!=NULL){
        printf("%d ", pHead->data);
        pHead=pHead->next;
    }
    printf("\n");
}

int main(){
    node* head, *tailNode, *newNode; int index;
    head = NULL;
    int sizeOfList;
    printf("Enter the number of nodes : ");
    scanf("%d", &sizeOfList);
    for(int i=0; i<sizeOfList; i++){
        if(head==NULL){
            head = (node*)malloc(sizeof(node));
            head->data = (i+1)*7;
            head->next = NULL;
            tailNode = head;
        }
        else{
            newNode = (node*)malloc(sizeof(node));
            newNode->data = (i+1)*7;
            newNode->next = NULL;
            tailNode->next = newNode;
            tailNode = newNode;
        }
    }
    printf("Original List : ");
    if(head==NULL){
        printf("No nodes added\n");
    }
    else{
        printList(head);
    }

    printf("Alterante elements of the list : ");
    printAlternate(head);
    printf("\n");
}