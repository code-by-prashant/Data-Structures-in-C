#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *newnode, *temp, *prevnode, *nextnode, *ptr;

int count = 0;
int pos;
int i = 1;

// Function to display the nodes of linked list.
void Display(struct Node *ptr)
{
    printf("\n----------Display----------\n");
    printf("The data elements of Linked List are:\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data); // print the data.
        ptr = ptr->next;           // move new node to next node.
    }
    printf("\n");
}

// Length of Linked List / Count number of nodes.
void countNodes()
{
    printf("\n----------Count number of nodes----------\n");
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", count);
}

// Insertion at Beginning, at end, at specific position.
void insertAtBeginning()
{
    printf("\n----------Insertion At Beginning----------\n");
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Node inserted successfully.\n");
}

void insertAtEnd()
{
    printf("\n----------Insertion At End----------\n");
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data you want to insert at the end of the list: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    printf("Node inserted successfully.\n");
}

void insertAtSpecificPosition()
{
    printf("\n----------Insertion At Specific Position----------\n");
    printf("Enter the position where you want to insert the data: ");
    scanf("%d", &pos);

    if (pos > count)
    {
        printf("Invalid position!\n");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Node inserted successfully.\n");
    }
}

// Deletion at Beginning, at end, at specific position
void deleteFromBeginning()
{
    printf("\n----------Deletion At Beginning----------\n");
    temp = head;
    head = head->next;
    free(temp);
    printf("\nFirst node deleted successfully.\n");
}

void deleteFromEnd()
{
    printf("\n----------Deletion At End----------\n");
    temp = head;
    prevnode = head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = 0;
    }
    else
    {
        prevnode->next = 0;
    }
    free(temp);
    printf("\nLast node deleted successfully.\n");
}

void deleteFromSpecificPosition()
{
    printf("\n----------Deletion At Specific Position----------\n");
    printf("Enter the position where you want to delete: ");
    scanf("%d", &pos);

    if (pos > count)
    {
        printf("\nInvalid position!\n");
    }
    else
    {
        temp = head;
        nextnode = head; 
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode = temp->next;
        temp->next = newnode->next;
        free(nextnode);
    }
}



// Main function
int main()
{
    printf("----------Creation----------\n");
    int choice = 1;
    while (choice)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the data:  ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to enter more Nodes?\n"
               "If Yes press 1, else press 0:  ");
        scanf("%d", &choice);
    }
    temp = head;

    Display(head);
    countNodes();
    
    insertAtBeginning();
    insertAtEnd();
    countNodes();
    insertAtSpecificPosition();
    Display(head);
    
    deleteFromBeginning();
    Display(head);
    deleteFromEnd();
    Display(head);
    countNodes();
    deleteFromSpecificPosition();
    Display(head);

    return 0;
}