#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

int main(){
    // Create a new linked list
    struct node *head;
    struct node *one= NULL;
    struct node *two= NULL;
    struct node *three= NULL;

    //allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    
    //allocate data
    one-> data = 1;
    two -> data = 2;
    three -> data = 3;

    //connect the nodes
    one-> next = two;
    two -> next = three;
    three-> next = NULL;

    head = one;
    printLinkedlist(head);

    return 0;

    
}
