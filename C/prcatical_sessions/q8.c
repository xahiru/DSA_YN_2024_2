#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a linked list
struct node
{
    int num;                // Data of the node
    struct node *nextptr;   // Pointer to the next node
};

// Declare pointers to the starting node and a temporary node
struct node stnode, *ennode;

// Function to find an element in the linked list and return its position
int FindElement(int);

int main()
{
    int n, i, FindElem, FindPlc;

    // Initialize the starting node's pointer to NULL
    stnode.nextptr = NULL;

    // Point ennode to the starting node
    ennode = &stnode;

    printf("\n\n Linked List : Search an element in a Singly Linked List :\n");
    printf("---------------------------------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    printf("\n");
    // Loop to create the linked list with user input data
    for (i = 0; i < n; i++)
    {
        // Allocate memory for the next node
        ennode->nextptr = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node %d : ", i + 1);
        scanf("%d", &ennode->num);

        ennode = ennode->nextptr;
    }
    ennode->nextptr = NULL;

    printf("\n Data entered in the list are :\n");

    // Reset ennode to the starting node
    ennode = &stnode;

    // Loop to display the data entered in the linked list
    while (ennode->nextptr != NULL)
    {
        printf(" Data = %d\n", ennode->num);
        ennode = ennode->nextptr;
    }

    printf("\n");

    printf(" Input the element to be searched : ");
    scanf("%d", &FindElem);

    // Call FindElement function to search for the element and get its position
    FindPlc = FindElement(FindElem);

    // Display the position of the found element or a message if it doesn't exist
    if (FindPlc <= n)
        printf(" Element found at node %d \n\n", FindPlc);
    else
        printf(" This element does not exist in the linked list.\n\n");
}

// Function to find an element in the linked list and return its position
int FindElement(int FindElem)
{
    int ctr = 1;

    // Reset ennode to the starting node
    ennode = &stnode;

    // Loop to traverse the linked list and find the element
    while (ennode->nextptr != NULL)
    {
        // Check if the element is found at the current node
        if (ennode->num == FindElem)
            break;
        else
        {
            ctr++;
            ennode = ennode->nextptr;
        }
    }
    return ctr; // Return the position of the found element
}
