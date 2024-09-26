#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert an element at the end of the list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty, the new node becomes the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Insert new node at the end and adjust pointers
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete the first occurrence of an element
void delete(struct Node** head, int data) {
    struct Node* temp = *head;

    // If the list is empty
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    // If the node to be deleted is the head node
    if (temp->data == data) {
        *head = temp->next;  // Move the head to the next node
        if (*head != NULL) {
            (*head)->prev = NULL;  // Update the prev pointer of the new head
        }
        free(temp);
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    // If the node is not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Adjust the previous node's next pointer
    temp->prev->next = temp->next;

    free(temp);  // Free the memory of the deleted node
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

// Function to traverse and print the elements in reverse
void traverse_reverse(struct Node* head) {
    struct Node* temp = head;
    
    // Move to the end of the list
    while (temp && temp->next != NULL) {
        temp = temp->next;
    }

    // Print elements in reverse order
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
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

    // Traverse the list in reverse order
    printf("List in reverse order:\n");
    traverse_reverse(head);

    return 0;
}
