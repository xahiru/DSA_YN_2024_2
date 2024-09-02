#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert an element at the end of the list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete the first occurrence of an element
void delete(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to traverse and print the elements of the list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("List after insertion:\n");
    traverse(head);

    // Delete an element
    delete(&head, 3);
    printf("List after deletion:\n");
    traverse(head);

    return 0;
}
