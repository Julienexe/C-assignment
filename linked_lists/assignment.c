#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int num){
    //creating a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
    
    if (!newNode) {
        printf("Memory error");
        exit(1);
    }
    newNode->number=num;
    newNode->next=NULL;
    
    return newNode;
};

void printList(struct Node *head){
    while (head != NULL){
        printf("%d\n", head->number);
        head=head->next;
    };
};

void append(struct Node **head, int num){
    struct Node *newNode = createNode(num);
    
    if (*head == NULL){ 
        *head = newNode;
        return;
       }
    else{
        struct Node *lastNode = *head;
    }
    
    while (lastNode ->next == NULL){
        lastNode = lastNode -> next
    } 
    
    lastNode->next = newNode;
        
};

void prepend(struct Node **head, int num){
    struct *newNode = createNode(num);

    newNode -> next = *head;
    *head = newNode;
};

void deleteByKey(struct Node **head, int key){   
    \\check if list is empty
    if (*head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }
    \\find node at specified position 
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    \\assign the previous node a next value       \\before deletion 
    prev->next = temp->next;
    free(temp);
};

void deleteByValue(struct Node **head, int value){
    \\check if list is empty
    if (*head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    \\find node with Value and previous     \\node
    struct Node *temp = * head;
    struct Node *prev = NULL;
    while (temp != NULL){
        if (temp->number != value){
            prev = temp;
            temp = temp->next;
        }
        else{
            \\set a next node for prev then 
            \\ delete 
            prev->next= temp->next;
            free(temp);
        }
    }
    
};

void insertAfterKey(struct Node **head, int key, int value){
    \\create new node
    struct Node *newNode = createNode(value);
    
    \\get the current node that the key 
    \\points at
    struct Node *current = *head;
    for (int i =1; i <= key; i++){
        if (current->next !=NULL){
            current = current->next;
        }
        else{
            printf("Invalid position");
        }
    }
    \\set new node as next node for the 
    \\current node and set current's former 
    \\next as new node next
    newNode -> next = current->next;
    current -> next = newNode;
};

void insertAfterValue(struct Node **head, int searchValue, int newValue){
    \\create a newNode
    struct Node *newNode = createNode(newValue);

    \\get node with same value as search  
    \\value
    struct Node *currentNode = *head;
    while (currentNode != NULL){
        if (currentNode->number != searchValue){
            currentNode = currentNode->next;
        }
        else{
            \\set new node as next node
            newNode->next= currentNode->next;
            currentNode->next = newNode;
        }
    }
};

int main()
{
    struct Node *head = NULL;
    int choice, data;

    while (1)
    {
        printf("Linked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printList(head);
            break;
        }
        else if (choice == 2)
        {
            printf("Enter data to append: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Questions:
// Implement the prototypes defined above.
// Reimplement the main method using a switch and complete the pending steps.