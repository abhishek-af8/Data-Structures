#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
};

struct node*createCircularList(int size, int multipleOf){
    struct node*head = NULL, *newNode, *previous;
    for(int i = 0; i<size; i++){
        if(head==NULL){
            head = (struct node*)malloc(sizeof(struct node));
            head->data=(i+1)*multipleOf;
            head->next = head;      //pahle ye maine head->next = NULL kar ka chhoda hua tha, but then I realised what 
                                    //is my list has just one node. Seg Fault ho jaayega phir to in case of head->next->next->next->data mein. 
            previous = head;
        }
        else{
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = (i+1)*multipleOf;
            newNode->next = head;
            previous->next = newNode;
            previous = newNode;
        }
    }
    return head;
}

int lengthOfCLL(struct node* head){
    if(head==NULL) return 0;
    int count = 0;
    struct node* curr = head;
    do{
        count ++;
        curr = curr->next;
    }while(curr!=head);
    return count;
}

void freeNodes(struct node* head){
    if(head==NULL){return;}
    struct node *currentNode, *previousNode;
    currentNode = head->next; previousNode = head->next;

    if(head->next!=head){
        do{
            currentNode = currentNode->next;
            free(previousNode);
            previousNode = currentNode;
        }while(currentNode!=head);
    }
    free(head);
    head = NULL;
    currentNode = NULL;
    previousNode = NULL;
}

void printlist(struct node* head){
    struct node* printer = head;
    if(head==NULL){return;}
    do{
        printf("%d ", printer->data);
        printer=printer->next;
    }while(printer!=head);
    printf("\n");
}

int main(){
    int size, multipleOf;

    int flag = 1;
    while(flag){
        printf("Enter the size of LL : ");
        scanf("%d", &size);
        printf("Enter the multiple number : ");
        scanf("%d", &multipleOf);
        struct node* head = createCircularList(size, multipleOf);
        printlist(head);
        printf("The length of the LL is : %d\n", lengthOfCLL(head));

        printf("Enter the flag (0 to stop):");
        scanf("%d", &flag);

        freeNodes(head);
        head=NULL;
    }    
return 0;
}