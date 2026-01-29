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

void freeNodes(struct node* head){
    struct node *currentNode, *previousNode;
    currentNode = head; previousNode = head;
    while(currentNode!=NULL){
        currentNode = currentNode->next;
        free(previousNode);
        previousNode = currentNode;
    }
    //you can do it with just one pointer as well. Use head instead of currentNode. Head rakhne ka koi point hai nahi, cuz at the end the list will not exist. So, BOOM. INJOY.
}

int main(){
    struct node* head, *tailNode, *newNode; int index;
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
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = (i+1)*7;
            newNode->next = NULL;
            tailNode->next = newNode;
            tailNode = newNode;
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
        if(head==NULL){
            break;
        }
        printf("Enter the index which you want to delete : ");
        scanf("%d", &index);
        head = deleteNode(head, index);
        printf("List after deletion : ");
        printList(head);
        printf("Enter flag : ");
        scanf("%d", &flag);
    }

    freeNodes(head);
    head=NULL; 
}