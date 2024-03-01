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
    int i = 0;
    while (head != NULL){
        printf("Node %d : %d\n",i, head->number);
        head=head->next;
        i++;
    };
};

void append(struct Node **head, int num){
    struct Node *newNode = createNode(num);

    if (*head == NULL){
        *head = newNode;
        return;
       }

        struct Node *lastNode = *head;


    while (lastNode->next != NULL){
        lastNode = lastNode -> next;
    }

    lastNode->next = newNode;

}

void prepend(struct Node **head, int num){
    struct Node *newNode = createNode(num);

    newNode -> next = *head;
    *head = newNode;
}

void deleteByKey(struct Node **head, int key){
    // check if list is empty
    if (*head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }
    //find node at specified position
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->number!=key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    //delete the node with the key
    if(prev==NULL){
        *head=temp->next;
    }else{
        prev->next=temp->next;
    }
    free(temp);
    //assign the previous node a next value       //before deletion
}

void deleteByValue(struct Node **head, int value){
    //check if list is empty
    if (*head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    //find node with Value and previous     \\node
    struct Node *temp = * head;
    struct Node *prev = NULL;
    while (temp != NULL){
        if (temp->number != value){
            prev = temp;
            temp = temp->next;
        }
        else{
            // set a next node for prev then
            // delete
            prev->next= temp->next;
            free(temp);
        }
    }

};

void insertAfterKey(struct Node **head, int key, int value){
    //create new node
    struct Node *newNode = createNode(value);

    // get the current node that the key
    // points at
    struct Node *current = *head;
    for (int i = 0; i <= key; i++){
        if (current->next !=NULL){
            current = current->next;
        }
        else{
        printf("Invalid position");
        }

    }
    newNode -> next = current->next;
    current -> next = newNode;
    //set new node as next node for the
    //current node and set current's former
    //next as new node next
};

void insertAfterValue(struct Node **head, int searchValue, int newValue){
    //create a newNode
    struct Node *newNode = createNode(newValue);

    //get node with same value as search
    //value
    struct Node *currentNode = *head;
    while (currentNode != NULL){
        if (currentNode->number != searchValue){
            currentNode = currentNode->next;
        }
        else{
            //set new node as next node
            newNode->next= currentNode->next;
            currentNode->next = newNode;
        }
    }
};

int main()
{
    struct Node *head = NULL;
    int choice, data, newValue;

    while (1)
    {
        printf("\nLinked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete by key\n");
        printf("5.  Delete by Value \n");
        printf("6. Insert After Key \n");
        printf("7.Insert After Value \n");
        printf("8. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

    switch(choice)
{
    case 1:
        printList(head);
        break;
    case 2:
        printf("Enter the element to be appended: ");
        scanf("%d",&data);
        append(&head, data);
        break;
    case 3:
        printf("Enter data to prepend: ");
        scanf("%d", &data);
        prepend(&head, data);
        break;
    case 4:
      printf("Enter key position to delete: ");
      scanf("%d",&data);
      deleteByKey(&head,data);
      break;
    case 5:
        printf("Enter value to delete: ");
        scanf("%d", &data);
        deleteByValue(&head, data);
        break;
    case 6:
        printf("Enter key position and value to insert: ");
        scanf("%d %d", &data, &data);
        insertAfterKey(&head, data, data);
        break;
    case 7:
        printf("Enter value to search and new value: ");
        scanf("%d %d", &data, &data);
        insertAfterValue(&head, data, data);
        break;
    case 8:
        exit(0);
    default:
        printf("Invalid choice. Please try again.\n");
        }
}
    return 0;
}


// Questions:
// Implement the prototypes defined above.
// Reimplement the main method using a switch and complete the pending steps.
