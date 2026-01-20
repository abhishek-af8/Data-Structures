#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int sizeOf(struct node*pseudoHead){
    int count = 0;
    while(pseudoHead!=NULL){
        count++;
        pseudoHead = pseudoHead->next;
    }
    return count;
}

struct node* deleteNode(struct node* pHead, int index){
    int size = sizeOf(pHead);

    if(index == 0){
        if(pHead==NULL){
            printf("List already empty.");
        }
        else{
            struct node* tempHead = pHead;
            pHead = pHead->next;
            free(tempHead);
            tempHead = NULL;
        }
    }
    else if(index>0 && index<size){
            struct node* previousNode, *deleteNode;
            previousNode=pHead;
            for(int i = 0; i<(index-1); i++){
                previousNode = previousNode->next;
            }
            deleteNode = previousNode->next;
            previousNode->next = deleteNode->next;
            free(deleteNode);
            deleteNode=NULL;
    }
    else{
        printf("Index Out of Bound.\n");
    }
    return pHead;
}

void printList(struct node* pHead){
    while(pHead!=NULL){
        printf("%d ", pHead->data);
        pHead=pHead->next;
    }
    printf("\n");
}

int main(){
    struct node* head, *tailNode, *n; int index;
    head = NULL;
    int sizeOfList;
    printf("Enter the number of nodes : ");
    scanf("%d", &sizeOfList);
    for(int i=0; i<sizeOfList; i++){
        if(head==NULL){
            head = (struct node*)malloc(sizeof(struct node));
            head->data = (i+1)*7;
            head->next = NULL;
            tailNode = head;
        }
        else{
            n = (struct node*)malloc(sizeof(struct node));
            n->data = (i+1)*7;
            n->next = NULL;
            tailNode->next = n;
            tailNode = n;
        }
    }
    printf("List before deletion : ");
    if(head==NULL){
        printf("No nodes added\n");
    }
    else{
        printList(head);
    }

    int flag = 1;
    while(flag>0){
        printf("Enter the index which you want to delete : ");
        scanf("%d", &index);
        head = deleteNode(head, index);
        printf("List after deletion : ");
        printList(head);
        printf("Enter flag : ");
        scanf("%d", &flag);
    }
}