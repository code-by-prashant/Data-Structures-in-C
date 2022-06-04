#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *newnode, *temp, *prevnode, *nextnode, *ptr;


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
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
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
    int pos;
    int i = 1;
    printf("\n----------Insertion At Specific Position----------\n");
    printf("Enter the position where you want to insert the data: ");
    scanf("%d", &pos);

    if (pos > countNodes(head))
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
    printf("First node deleted successfully.\n");
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
    printf("Last node deleted successfully.\n");
}

void deleteFromSpecificPosition()
{
    int pos;
    int i = 1;
    printf("\n----------Deletion At Specific Position----------\n");
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos > countNodes(head))
    {
        printf("\nInvalid position!\n");
    }
    else
    {
        temp = head;
        nextnode = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
        printf("Node %d deleted successfully.\n", pos);
    }
}


// Function to sort nodes of the list in ascending order
void sortList()
{
    // Node current will point to head
    printf("\n\n----------Sort----------\n");
    struct Node *current = head, *index = 0;
    int temp;

    if (head == 0)
    {
        return;
    }
    else
    {
        while (current != 0)
        {
            // Node index will point to node next to current
            index = current->next;

            while (index != 0)
            {
                // If current node's data is greater than index's node data, swap the data between them
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    printf("Linked List sorted successfully.\n");
}

// Function to search a value in the list.
void search()
{
    printf("\n\n----------Search----------\n");
    int value, i = 0, flag;
    temp = head;
    if (temp == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter value which you want to search: ");
        scanf("%d", &value);
        while (temp != 0)
        {
            if (temp->data == value)
            {
                printf("Value found at index %d \n", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            temp = temp->next;
        }
        if (flag == 1)
        {
            printf("Value not found\n");
        }
    }
}


// Insert a node in such a way that linked list remains sorted
void sortedInsert()
{
    printf("\n----------Insertion in sorted order----------\n");
    temp = head;
    ptr = 0;
    int value;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = 0;

    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        while (temp && temp->data < value)
        {
            ptr = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
    }
    printf("%d inserted successfully in sorted order.\n", value);
}


// Displaying the linked list using Recursive function.
void recDisplay(struct Node *newnode)
{
    if (newnode != NULL)
    {
        printf("%d\t", newnode->data); // Step-1   print the data
        recDisplay(newnode->next);     // Step-2   call the next node's address
    }
}


// Reversing a linked list using Recursion.
void recRevDisplay(struct Node *newnode)
{
    if (newnode != NULL)
    {
        recRevDisplay(newnode->next);  // Step-1   call the next node's address
        printf("%d\t", newnode->data); // Step-2   print the data
    }
}



// Main function
int main()
{
    printf("\n\n");
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
        printf("\nDo you want to enter more Nodes? If Yes press 1, else press 0:  ");
        scanf("%d", &choice);
    }
    temp = head;


    // calling various functions.

    Display(head);

    printf("\nCount of nodes is %d\n", countNodes(head));

    insertAtBeginning();
    insertAtEnd();
    Display(head);

    printf("\nCount of nodes is %d\n", countNodes(head));

    insertAtSpecificPosition(); // ??? new node is being inserting after the position entered

    Display(head);

    printf("\nCount of nodes is %d\n", countNodes(head));

    deleteFromBeginning();
    deleteFromEnd();
    Display(head);

    printf("\nCount of nodes is %d\n", countNodes(head));

    deleteFromSpecificPosition(); // ??? only fix for pos=1 checked for rest positions.
    Display(head);

    sortList();
    Display(head);

    search();
    
    sortedInsert();
    Display(head);

    printf("\nRecursive display of Linked List:\n");
    recDisplay(head);

    printf("\n\n----------Reverse----------\n");
    printf("The data elements of Linked List in reverse order are:\n");
    recRevDisplay(head);

    printf("\n\n");

    return 0;
}
