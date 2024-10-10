#include <stdio.h>
#include <string.h>

#define MAXSIZE 50 // Define the maximum size of the list

// Structure definition for student
struct student {
    int id;           // Student ID
    char name[50];    // Student Name
    int age;          // Age
};

// Structure definition for sqlist
struct sqlist {
    struct student elemlist[MAXSIZE]; // Array to store the list elements
    int size;                         // Current size of the list
};

// Function to initialize the list (set size to 0)
void setnull(struct sqlist *p) {
    p->size = 0;
}

// Function to get the length of the list
int length(struct sqlist *p) {
    return p->size;
}

// Function to get a student at a given index
void get(struct sqlist *p, int i) {
    if (i < 1 || i > p->size) {
        printf("Index out of bounds\n");
    } else {
        struct student s = p->elemlist[i - 1];
        printf("Student at index %d: ID=%d, Name=%s, Age=%d\n", i, s.id, s.name, s.age);
    }
}

// Function to locate the first occurrence of a student by ID
void locate(struct sqlist *p, int id) {
    int i = 0;
    while (i < p->size && p->elemlist[i].id != id) {
        i++;
    }
    if (i == p->size) {
        printf("Student not found\n");
    } else {
        printf("Student found at index: %d\n", i + 1);
    }
}

// Function to insert a student at position i
void insert(struct sqlist *p, int i, struct student s) {
    if (i < 1 || i > p->size + 1 || p->size >= MAXSIZE) {
        printf("Invalid position, cannot insert\n");
    } else {
        for (int j = p->size; j >= i; j--) {
            p->elemlist[j] = p->elemlist[j - 1];
        }
        p->elemlist[i - 1] = s;
        p->size++;
        printf("Student inserted: ID=%d, Name=%s, Age=%d\n", s.id, s.name, s.age);
    }
}

// Function to delete a student at position i
void delete(struct sqlist *p, int i) {
    if (i < 1 || i > p->size) {
        printf("Index out of bounds\n");
    } else {
        for (int j = i - 1; j < p->size - 1; j++) {
            p->elemlist[j] = p->elemlist[j + 1];
        }
        p->size--;
        printf("Student deleted at index %d.\n", i);
    }
}

// Function to display the list
void display(struct sqlist *p) {
    if (p->size == 0) {
        printf("The list is empty\n");
    } else {
        printf("The list of students:\n");
        for (int j = 0; j < p->size; j++) {
            struct student s = p->elemlist[j];
            printf("ID=%d, Name=%s, Age=%d\n", s.id, s.name, s.age);
        }
    }
}

// Main function to test the list operations
int main() {
    struct sqlist l;       // Define the list
    setnull(&l);           // Initialize the list

    // Sample data
    struct student s1 = {20240001, "Micheal", 22};
    struct student s2 = {20240003, "Ismeal", 18};
    struct student s3 = {20240002, "Olaaf", 23};
    struct student s4 = {20240004, "Rishmy", 20};

    // Insert the sample data into the list
    insert(&l, 1, s1);
    insert(&l, 2, s2);
    insert(&l, 3, s3);
    insert(&l, 4, s4);

    // Display the list after insertion
    display(&l);

    int select, i, id;
    struct student s;

    do {
        printf("\nMenu:\n");
        printf("1: Clear the list\n");
        printf("2: Display the length\n");
        printf("3: Get a student by index\n");
        printf("4: Locate a student by ID\n");
        printf("5: Insert a student\n");
        printf("6: Delete a student\n");
        printf("7: Display the list\n");
        printf("0: Exit\n");
        printf("Choose an option (0-7): ");
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
                printf("Enter ID to locate: ");
                scanf("%d", &id);
                locate(&l, id);
                break;
            case 5:
                printf("Enter student ID, Name, and Age: ");
                scanf("%d %s %d", &s.id, s.name, &s.age);
                printf("Enter position to insert: ");
                scanf("%d", &i);
                insert(&l, i, s);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &i);
                delete(&l, i);
                break;
            case 7:
                display(&l);
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please choose between 0-7.\n");
        }
    } while (select != 0);

    return 0;
}
