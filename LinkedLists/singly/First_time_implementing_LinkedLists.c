/* First linked list implementation.
Focus: pointer reasoning, manual insertion/deletion, memory ownership, not generic APIs.
Written while learning C fundamentals and Data Structures */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head, *last, *newNode;

void insertNode(){
    struct node* insertedNode;
    insertedNode = (struct node*)malloc(sizeof(struct node));
    insertedNode -> data = 12;
    insertedNode -> next = head -> next -> next;
    head -> next -> next = insertedNode;
}

void deleteNode(){
    struct node* freePointer = head -> next -> next;
    head->next->next = head -> next -> next -> next;
    free(freePointer);          //no Memory leak
    freePointer=NULL;           //no Dangling Pointer
}

int main(){
    head = (struct node*)malloc(sizeof(struct node));
    head -> data = 5;
    head -> next = NULL;
    last = head;
    newNode = head;

    for(int i=0; i<9; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode -> data = (i+2)*5;
        newNode -> next = NULL;
        last -> next = newNode;
        last = newNode;
    }

    last = NULL;

    struct node*printer = head;
    printf("List before insertion : ");
    do{
        printf("%d ", printer->data);
        printer = printer->next;
    }
    while(printer != NULL);     //initially I wrote printer->next != NULL;
                                //usse hua kya ki at the last node printer->next == NULL, so usey visit karne se pahle hi the loop got terminated each time. So, BOOM, The classic "Off-By-One" error.

    // for(int i=0; i<10; i++){
    //     printf("%d ", printer->data);
    //     printer = printer->next;
    // }

    printf("\n");  
    
    insertNode();

    printf("List after insertion : ");
    struct node*printer2 = head;
    do{
        printf("%d ", printer2->data);
        printer2 = printer2->next;
    }
    while(printer2 != NULL);

    printf("\n");

    deleteNode();

    printf("List after deletion : ");
    struct node*printer3 = head;
    do{
        printf("%d ", printer3->data);
        printer3 = printer3->next;
    }
    while(printer3 != NULL);

    printf("\n");

return 0;
}

/*
So, this was my first official implementation of Linked-List and it is by heart, by understanding the first-principles.


I kept the head node outside the loop because I didn't know how to stop it from initialising again and again at every iteration of loop, later I knew about if(head==NULL) condition. But then found that my approach is techniaclly much better because it doesn't require the CPU to check the if() condition in each iteration. That reduces computational overhead a bit.


Insertion mein ek hi formula tha for me, NAYA NODE BANAO, AGAR Nth INDEX PE RAKHNA HAI TO (N-1)th K NEXT MEIN ISKA ADDRESS HONA CHAHIYE, BUT BEFORE THAT PRESERVE THE ADDRESS OF PICHHLE Nth NODE. SO, ISKE NEXT MEIN PICHHLE KA ADDRESS DAALO AND THEN (N-1)th K NEXT KO ISPE POINT KARA DO. Easy !!


Deletion mein bhi I had an initial formula, Nth NODE DELETE KARNA HAI? SO (N-1)th NODE K NEXT MEIN (N+1)th NODE KA ADDRESS CHIPKAO, AUTOMATICALLY LIST SE Nth NODE GAYAB HO JAAYEGA. But this led to memory leakage. Woh Nth node still Heap mein exist kar raha hai and you cannot access it in anyway. No pointer points to it. 

SO I NOW CREATED A SEPARETE POINTER WHICH JUST POINTS TO THE Nth NODE WHICH NEEDS TO BE DELETED. AFTER i DID THis "(N-1)th NODE K NEXT MEIN (N+1)th NODE KA ADDRESS CHIPKAO" I KNEW KI MERA INITIAL Nth NODE LIST SE TO CHALA GAYA HAI, BUT IT'S STILL THERE IN HEAP AND A POINTER POINTS TO IT. SO I FREED THAT NODE USING free(POINTER); AND THEN SET THE POINTER TO NULL AS WELL. Now in our code, there was no Memory Leak, no Dangling Pointer.
*/