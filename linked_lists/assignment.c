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

void deleteByKey(struct Node **head, int key);

void deleteByValue(struct Node **head, int value);

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