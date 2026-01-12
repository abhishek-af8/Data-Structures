#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    // printf("Welcome to learn Linked Lists");
    // printf("\nYou will become an excellent programmer\n");

    struct node a, b, c;

    a.data = 21;
    a.next = &b;

    b.data = 22;
    b.next = &c;

    c.data = 23;
    c.next = NULL;

    struct node *head;
    head = &a;

    printf("%d\n", head->next->next->data);
    printf("%d\n", head->next->data);

    
return 0;
}