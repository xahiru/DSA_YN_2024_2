#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct node {
    int num;
    struct node * preptr; // Pointer to the previous node
    struct node * nextptr; // Pointer to the next node
}*stnode, *ennode; // Pointers for the starting and ending nodes

// Function prototypes
void DlListcreation(int n);
void displayDlList();

int main() {
    int n;
    stnode = NULL; // Initializing starting node to NULL
    ennode = NULL; // Initializing ending node to NULL

    printf("\n\n Doubly Linked List : Create and display a doubly linked list :\n");
    printf("-------------------------------------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    DlListcreation(n); // Function call to create a doubly linked list
    displayDlList(); // Function call to display the doubly linked list

    return 0;
}

// Function to create a doubly linked list
void DlListcreation(int n) {
    int i, num;
    struct node *fnNode;

    if(n >= 1) {
        stnode = (struct node *)malloc(sizeof(struct node));

        if(stnode != NULL) {
            printf(" Input data for node 1 : "); // assigning data in the first node
            scanf("%d", &num);

            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode; // Setting ending node as starting node initially

            // Loop to get input data for rest of the nodes
            for(i = 2; i <= n; i++) {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL) {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode; // New node is linking with the previous node
                    fnNode->nextptr = NULL;

                    ennode->nextptr = fnNode; // Previous node is linking with the new node
                    ennode = fnNode; // Assign new node as last node
                } else {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        } else {
            printf(" Memory can not be allocated.");
        }
    }
}

// Function to display the doubly linked list
void displayDlList() {
    struct node * tmp;
    int node_num = 1; // Variable to count node numbers

    if(stnode == NULL) {
        printf(" No data found in the List yet.");
    } else {
        tmp = stnode;
        printf("\n\n Data entered on the list are :\n");

        while(tmp != NULL) {
            printf(" node %d : %d\n", node_num, tmp->num);
            node_num++;
            tmp = tmp->nextptr; // Current pointer moves to the next node
        }
    }
}
