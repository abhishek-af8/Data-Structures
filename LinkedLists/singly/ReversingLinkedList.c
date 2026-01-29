#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* reverse(struct node* listHead){
    struct node *previousNode, *currentNode, *nextNode;
    previousNode = listHead;
    currentNode = listHead->next;
    nextNode = listHead->next->next;
    while(currentNode!=NULL){
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
        if(nextNode == NULL){break;}
        nextNode = nextNode->next;
    }
    listHead->next = NULL;
    listHead = previousNode;
    return listHead;
}

int main(){
    struct node *head, *tail, *newNode;
    head = (struct node*)malloc(sizeof(struct node));
    head -> data = 5;
    head -> next = NULL;
    tail = head;
    newNode = head;

    for(int i=0; i<9; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode -> data = (i+2)*5;
        newNode -> next = NULL;
        tail -> next = newNode;
        tail = newNode;
    }

    printf("Linked List before reversal : ");
    struct node* printer = head;
    while(printer!=NULL){
        printf("%d ", printer->data);
        printer = printer->next;
    }
    printf("\n");

    struct node* newHead = reverse(head);
    printf("Linked List after reversal : ");
    struct node* printer2 = newHead;
    while(printer2!=NULL){
        printf("%d ", printer2->data);
        printer2 = printer2->next;
    }
    printf("\n");
    
return 0;
}


/*

How I coded this?
So, mere dimaag mein ek chij thi ki reverse karne k liye apne next node ko apne pe point karna hoga
Ya phir 
Agar mai 2nd node se shuru karu, to mujhe harek node ko uske previous node pe point karana padega
But is chakkar mein I don't lose the next node so I use a pointer to point at 
*/