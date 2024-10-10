// quetion: Write a program in C to insert a new node at the end of a Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node 
{
    int num;                    // Data of the node
    struct node *nextptr;       // Address of the node
}*stnode;                       // Pointer to the starting node

// Function prototypes
void createNodeList(int n);             // Function to create the linked list
void NodeInsertatEnd(int num);          // Function to insert a node at the end of the list
void displayList();                     // Function to display the list

// Main function
int main()
{
    int n, num;

    // Displaying the purpose of the program
    printf("\n\n Linked List : Insert a new node at the end of a Singly Linked List :\n");
    printf("-------------------------------------------------------------------------\n");

    // Inputting the number of nodes for the linked list
    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    // Creating the linked list with n nodes
    createNodeList(n);
    printf("\n Data entered in the list are : \n");
    displayList();

    // Inputting data to insert at the end of the list
    printf("\n Input data to insert at the end of the list : ");
    scanf("%d", &num);
    NodeInsertatEnd(num);
    printf("\n Data after inserted in the list are : \n");
    displayList();

    return 0;
}

// Function to create a linked list with n nodes
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) // Check whether the stnode is NULL and if so, no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        // Reads data for the node through keyboard
        printf(" Input data for node 1 : ");
        scanf("%d", &num);

        stnode-> num = num;      
        stnode-> nextptr = NULL; // Links the address field to NULL
        tmp = stnode;

        // Creates n nodes and adds them to the linked list
        for(i = 2; i <= n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) // Check whether the fnNode is NULL and if so, no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      // Links the num field of fnNode with num
                fnNode->nextptr = NULL; // Links the address field of fnNode with NULL
                tmp->nextptr = fnNode; // Links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
} 

// Function to insert a node at the end of the list
void NodeInsertatEnd(int num)
{
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num;     // Links the data part
        fnNode->nextptr = NULL; 
        tmp = stnode;
        while(tmp->nextptr != NULL)
            tmp = tmp->nextptr;
        tmp->nextptr = fnNode;  // Links the address part
    }
}

// Function to display the linked list
void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // Prints the data of the current node
            tmp = tmp->nextptr;                 // Advances the position of the current node
        }
    }
}
