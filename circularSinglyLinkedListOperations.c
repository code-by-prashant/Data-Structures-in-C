#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL, *tail;

void create(int arr[], int n)
{
    int i;
    struct Node *newnode;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = head;
    tail = head;

    for (i=1; i<n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = arr[i];
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void display(struct Node *ptr)
{
    printf("\n-------------Display-------------\n");
    printf("The data elements of Singly Circular Linked List are:\n");
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

int countNodes(struct Node *head)
{
    printf("\n");
    int count = 0;
    struct Node *newnode = head;
    if (head != 0)
        do
        {
            newnode = newnode->next;
            count++;
        } while (newnode != head);  
    return count;
}


void insertAtBegin()
{
    printf("\n----------Insertion At Beginning----------\n");
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d", &temp->data);
    temp->next = tail->next;
    head = temp;
    tail->next = temp;
    printf("Node inserted successfully.\n");
}

void insertAtEnd()
{
    printf("\n----------Insertion At End----------\n");
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data you want to insert at the end: ");
    scanf("%d", &temp->data);
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    printf("Node inserted successfully.\n");
}

void insertAtSpecificPosition()
{
    int pos;
    int i = 1;
    printf("\n----------Insertion At Specific Position----------\n");
    printf("Enter the position where you want to insert the data: ");
    scanf("%d", &pos);
    struct Node *newnode;
    struct Node *temp;

    if (pos > countNodes(head))
    {
        printf("Invalid position!\n");
    }
    else
    {
        temp = tail->next;
        while (i < pos-1)
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



void deleteFromBeginning()
{
    printf("\n----------Deletion At Beginning----------\n");
    struct Node *temp;
    temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
    printf("First node deleted successfully.\n");
}

void deleteFromEnd()
{
    printf("\n----------Deletion At End----------\n");
    // struct Node *current;
    // struct Node *prev;
    
    // current = tail->next;    
    // while (current->next != tail)
    // {
    //     prev = current;
    //     current = current->next;
    // }
    // prev->next = tail->next;
    // tail = prev;
    // free(current);


    struct Node *temp;
    temp = tail->next;

    // Traverse the list till the second last node
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    // Second last node now contains reference of first node in the list
    temp->next = tail->next;
    tail = temp;

    printf("Last node deleted successfully.\n");
}

void deleteFromSpecificPosition()
{
    int pos;
    int i = 1;
    printf("\n----------Deletion At Specific Position----------\n");
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
    
    struct Node *nextnode;
    struct Node *temp;
    temp = tail->next;

    if (pos > countNodes(head))
    {
        printf("\nInvalid position!\n");
    }
    else if (pos == 1)
    {
        deleteFromBeginning();
    }
    else
    {
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
        while (current != tail)
        {
            // Node index will point to node next to current
            index = current->next;

            while (index != tail)
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


void search()
{
    printf("\n\n----------Search----------\n");
    int value, i = 0, flag=0;
    struct Node *temp;
    temp = head;

    if (temp == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter value which you want to search: ");
        scanf("%d", &value);
        while (temp != tail)
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
    struct Node *temp;
    struct Node *ptr;
    struct Node *newnode;
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
    if (newnode != tail)
    {
        printf("%d\t", newnode->data); // Step-1   print the data
        recDisplay(newnode->next);     // Step-2   call the next node's address
    }
    
    if (newnode == tail)
    {
        printf("%d", newnode->data);
    }

}


// Reversing a linked list using Recursion.
void recRevDisplay(struct Node *newnode)
{
    // do
    // {
    //     recRevDisplay(newnode->next);  
    //     printf("%d\t", newnode->data);
    // } while (newnode != head);
    
    if (newnode != tail)
    {
        recRevDisplay(newnode->next);  // Step-1   call the next node's address
        printf("%d\t", newnode->data); // Step-2   print the data
    }

    if (newnode == tail)
    {
        printf("%d\t", newnode->data);
    }
}



int main(){
    int arr[4] = {5, 7, 4, 9};

    create(arr, 4);
    display(head);
    printf("count is %d", countNodes(head));

    insertAtBegin();
    insertAtEnd();
    insertAtSpecificPosition();
    
    display(head);

    deleteFromBeginning();
    deleteFromEnd();
    deleteFromSpecificPosition();
    
    display(head);

    sortList();
    display(head);

    search();

    sortedInsert();
    display(head);

    printf("\nRecursive display of Linked List:\n");
    recDisplay(head);

    printf("\n\n----------Reverse----------\n");
    printf("The data elements of Linked List in reverse order are:\n");
    recRevDisplay(head);

    printf("\n\n");
    
    return 0;
}
