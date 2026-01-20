#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int sizeOf(struct node* pseudoHead){
    int count = 0;
    while(pseudoHead != NULL){
        count++;
        pseudoHead = pseudoHead->next;
    }
    return count;
}

struct node* insertNode(struct node* pHead, unsigned int index, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    int size = sizeOf(pHead);

    struct node *currentNode;

    if(index == 0){
        if(pHead == NULL){
            pHead = newNode;
        }
        else{
            newNode->next = pHead;
            pHead = newNode;
        }
    }

    else if(index>0 && index<size){
        currentNode = pHead;
        for(int i=0; i<(index-1); i++){
            currentNode=currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    
    else if(index>=size){
        if(pHead == NULL){
            pHead = newNode;
        }
        else{
            currentNode = pHead;
            for(int i=0; i<(size-1); i++){
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    return pHead;
}

void printList(struct node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct node*head, *newnode, *tail;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 7;
    head -> next = NULL;
    tail = head;
    newnode = head;

    unsigned int n;
    printf("Enter the number of nodes (a positive integer please) : ");
    scanf("%u", &n);

    for(int i = 0; i<(n-1); i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = (i+2)*7;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    printf("List before insertion : ");
    printList(head);
    
    unsigned int index;
    printf("Enter the index (a positive integer please) : ");
    scanf("%u", &index);

    int data;
    printf("Enter the data (an integer please): ");
    scanf("%d", &data);

    printf("List after insertion : ");
    head = insertNode(head, index, data);
    printList(head);

}