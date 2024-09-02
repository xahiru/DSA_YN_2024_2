#include <iostream>
using namespace std;
/*
In this C++ version:

#include <iostream> is used for input/output operations.
Functions are similar to the C version but adapted for C++ conventions, such as using cout and cin instead of printf and scanf.
The delete function was renamed to del to avoid conflict with the reserved keyword delete in C++.

*/

#define MAXSIZE 50 // Define the maximum size of the list

// Structure definition for sqlist
struct Sqlist {
    int sqlist[MAXSIZE]; // Array to store the list elements
    int size;            // Current size of the list
};

// Function to initialize the list (set size to 0)
void setnull(Sqlist *p) {
    p->size = 0;
}

// Function to get the length of the list
int length(Sqlist *p) {
    return p->size;
}

// Function to get an element at a given index
void get(Sqlist *p, int i) {
    if (i < 1 || i > p->size) {
        cout << "Index out of bounds" << endl;
    } else {
        cout << "Element at index " << i << " is: " << p->sqlist[i - 1] << endl;
    }
}

// Function to locate the first occurrence of an element x
void locate(Sqlist *p, int x) {
    int i = 0;
    while (i < p->size && p->sqlist[i] != x) {
        i++;
    }
    if (i == p->size) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << i + 1 << endl;
    }
}

// Function to insert an element x at position i
void insert(Sqlist *p, int i, int x) {
    if (i < 1 || i > p->size + 1 || p->size >= MAXSIZE) {
        cout << "Invalid position, cannot insert" << endl;
    } else {
        for (int j = p->size; j >= i; j--) {
            p->sqlist[j] = p->sqlist[j - 1];
        }
        p->sqlist[i - 1] = x;
        p->size++;
        cout << "List after insertion: ";
        for (int j = 0; j < p->size; j++) {
            cout << p->sqlist[j] << " -> ";
        }
        cout << endl;
    }
}

// Function to delete an element at position i
void del(Sqlist *p, int i) {
    if (i < 1 || i > p->size) {
        cout << "Index out of bounds" << endl;
    } else {
        for (int j = i - 1; j < p->size - 1; j++) {
            p->sqlist[j] = p->sqlist[j + 1];
        }
        p->size--;
        cout << "List after deletion: ";
        for (int j = 0; j < p->size; j++) {
            cout << p->sqlist[j] << " -> ";
        }
        cout << endl;
    }
}

// Function to perform insertion sort on the list
void insertsort(Sqlist *p) {
    for (int i = 1; i < p->size; i++) {
        int key = p->sqlist[i];
        int j = i - 1;
        while (j >= 0 && p->sqlist[j] > key) {
            p->sqlist[j + 1] = p->sqlist[j];
            j--;
        }
        p->sqlist[j + 1] = key;
    }
    cout << "Sorted list: ";
    for (int i = 0; i < p->size; i++) {
        cout << p->sqlist[i] << " -> ";
    }
    cout << endl;
}

// Function to display the list
void display(Sqlist *p) {
    if (p->size == 0) {
        cout << "The list is empty" << endl;
    } else {
        cout << "The list: ";
        for (int j = 0; j < p->size; j++) {
            cout << p->sqlist[j] << " -> ";
        }
        cout << endl;
    }
}

// Main function to test the list operations
int main() {
    Sqlist l;       // Define the list
    setnull(&l);    // Initialize the list
    int select, i, x;

    cout << "Enter 4 initial elements:\n";
    for (i = 0; i < 4; i++) {
        cin >> x;
        insert(&l, i + 1, x);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1: Clear the list\n";
        cout << "2: Display the length\n";
        cout << "3: Get an element by index\n";
        cout << "4: Locate an element\n";
        cout << "5: Insert an element\n";
        cout << "6: Delete an element\n";
        cout << "7: Sort the list\n";
        cout << "8: Display the list\n";
        cout << "0: Exit\n";
        cout << "Choose an option (0-8): ";
        cin >> select;

        switch (select) {
            case 1:
                setnull(&l);
                cout << "List cleared." << endl;
                break;
            case 2:
                cout << "Length of the list: " << length(&l) << endl;
                break;
            case 3:
                cout << "Enter index to retrieve: ";
                cin >> i;
                get(&l, i);
                break;
            case 4:
                cout << "Enter element to locate: ";
                cin >> x;
                locate(&l, x);
                break;
            case 5:
                cout << "Enter position and element to insert (position element): ";
                cin >> i >> x;
                insert(&l, i, x);
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> i;
                del(&l, i);
                break;
            case 7:
                insertsort(&l);
                break;
            case 8:
                display(&l);
                break;
            case 0:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Please choose between 0-8." << endl;
        }
    } while (select != 0);

    return 0;
}
