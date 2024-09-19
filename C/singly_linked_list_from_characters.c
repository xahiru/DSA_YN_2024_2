#include <stdio.h>
#include <stdlib.h>

typedef char datatype;

typedef struct node {
    datatype data;
    struct node *next;
} listnode;

typedef listnode *linklist;

// Function to create a linked list from input characters
linklist createlistf(void) {
    char ch;
    linklist head = NULL;
    listnode *p;
    
    while ((ch = getchar()) != '\n') {
        p = (listnode *)malloc(sizeof(listnode));
        if (p == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        p->data = ch;
        p->next = head;
        head = p;
    }
    
    return head;
}

// Function to traverse and print the linked list
void printList(linklist head) {
    listnode *p = head;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Function to insert a node at a given position
void insert(linklist *head, datatype value, int position) {
    listnode *p = *head, *newNode;
    newNode = (listnode *)malloc(sizeof(listnode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    
    if (position == 0) {  // Insertion at the head
        newNode->next = *head;
        *head = newNode;
    } else {
        int i = 0;
        while (p != NULL && i < position - 1) {  // Traverse to the insertion point
            p = p->next;
            i++;
        }
        if (p == NULL) {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
}

// Function to delete a node at a given position
void deleteNode(linklist *head, int position) {
    listnode *p = *head, *temp;
    
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (position == 0) {  // Deletion at the head
        temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        int i = 0;
        while (p != NULL && i < position - 1) {  // Traverse to the node before the one to delete
            p = p->next;
            i++;
        }
        if (p == NULL || p->next == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
}

int main() {
    linklist myList;
    int pos;
    char value;
    
    printf("Enter characters (end with newline):\n");
    myList = createlistf();
    
    printf("The linked list is: ");
    printList(myList);

    // Insertion example
    printf("Enter a character to insert: ");
    scanf(" %c", &value);
    printf("Enter the position to insert the character: ");
    scanf("%d", &pos);
    insert(&myList, value, pos);
    printf("The linked list after insertion: ");
    printList(myList);

    // Deletion example
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    deleteNode(&myList, pos);
    printf("The linked list after deletion: ");
    printList(myList);
    
    return 0;
}
