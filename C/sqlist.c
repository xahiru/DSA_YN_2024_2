#include <stdio.h>

#define MAXSIZE 50 // Define the maximum size of the list

// Structure definition for sqlist
struct sqlist {
    int elemlist[MAXSIZE]; // Array to store the list elements
    int size;            // Current size of the list
};

// Function to initialize the list (set size to 0)
void setnull(struct sqlist *p) {
    p->size = 0;
}

// Function to get the length of the list
int length(struct sqlist *p) {
    return p->size;
}

// Function to get an element at a given index
void get(struct sqlist *p, int i) {
    if (i < 1 || i > p->size) {
        printf("Index out of bounds\n");
    } else {
        printf("Element at index %d is: %d\n", i, p->elemlist[i - 1]);
    }
}

// Function to locate the first occurrence of an element x
void locate(struct sqlist *p, int x) {
    int i = 0;
    while (i < p->size && p->elemlist[i] != x) {
        i++;
    }
    if (i == p->size) {
        printf("Element not found\n");
    } else {
        printf("Element found at index: %d\n", i + 1);
    }
}

// Function to insert an element x at position i
void insert(struct sqlist *p, int i, int x) {
    if (i < 1 || i > p->size + 1 || p->size >= MAXSIZE) {
        printf("Invalid position, cannot insert\n");
    } else {
        for (int j = p->size; j >= i; j--) {
            p->elemlist[j] = p->elemlist[j - 1];
        }
        p->elemlist[i - 1] = x;
        p->size++;
        printf("List after insertion: ");
        for (int j = 0; j < p->size; j++) {
            printf("%d -> ", p->elemlist[j]);
        }
        printf("\n");
    }
}

// Function to delete an element at position i
void delete(struct sqlist *p, int i) {
    if (i < 1 || i > p->size) {
        printf("Index out of bounds\n");
    } else {
        for (int j = i - 1; j < p->size - 1; j++) {
            p->elemlist[j] = p->elemlist[j + 1];
        }
        p->size--;
        printf("List after deletion: ");
        for (int j = 0; j < p->size; j++) {
            printf("%d -> ", p->elemlist[j]);
        }
        printf("\n");
    }
}

// Function to perform insertion sort on the list
void insertsort(struct sqlist *p) {
    for (int i = 1; i < p->size; i++) {
        int key = p->elemlist[i];
        int j = i - 1;
        while (j >= 0 && p->elemlist[j] > key) {
            p->elemlist[j + 1] = p->elemlist[j];
            j--;
        }
        p->elemlist[j + 1] = key;
    }
    printf("Sorted list: ");
    for (int i = 0; i < p->size; i++) {
        printf("%d -> ", p->elemlist[i]);
    }
    printf("\n");
}

//Function to perform bubble sort on the list
void bubblesort(struct sqlist *p) {
    for (int i = 0; i < p->size - 1; i++) {
        for (int j = 0; j < p->size - i - 1; j++) {
            if (p->elemlist[j] > p->elemlist[j + 1]) {
                int temp = p->elemlist[j];
                p->elemlist[j] = p->elemlist[j + 1];
                p->elemlist[j + 1] = temp;
            }
        }
    }
    printf("Sorted list: ");
    for (int i = 0; i < p->size; i++) {
        printf("%d -> ", p->elemlist[i]);
    }
    printf("\n");
}

// Function to display the list
void display(struct sqlist *p) {
    if (p->size == 0) {
        printf("The list is empty\n");
    } else {
        printf("The list: ");
        for (int j = 0; j < p->size; j++) {
            printf("%d -> ", p->elemlist[j]);
        }
        printf("\n");
    }
}

// Main function to test the list operations
int main() {
    struct sqlist l;       // Define the list
    setnull(&l);           // Initialize the list
    int select, i, x;

    printf("Enter 4 initial elements:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &x);
        insert(&l, i + 1, x);
    }

    do {
        printf("\nMenu:\n");
        printf("1: Clear the list\n");
        printf("2: Display the length\n");
        printf("3: Get an element by index\n");
        printf("4: Locate an element\n");
        printf("5: Insert an element\n");
        printf("6: Delete an element\n");
        printf("7: Sort the list\n");
        printf("8: Display the list\n");
        printf("0: Exit\n");
        printf("Choose an option (0-8): ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                setnull(&l);
                printf("List cleared.\n");
                break;
            case 2:
                printf("Length of the list: %d\n", length(&l));
                break;
            case 3:
                printf("Enter index to retrieve: ");
                scanf("%d", &i);
                get(&l, i);
                break;
            case 4:
                printf("Enter element to locate: ");
                scanf("%d", &x);
                locate(&l, x);
                break;
            case 5:
                printf("Enter position and element to insert (position element): ");
                scanf("%d %d", &i, &x);
                insert(&l, i, x);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &i);
                delete(&l, i);
                break;
            case 7:
                insertsort(&l);
                break;
            case 8:
                display(&l);
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please choose between 0-8.\n");
        }
    } while (select != 0);

    return 0;
}
