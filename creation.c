#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;           // variable 'data' will store the data elements.
    struct Node *next;      // pointer 'next' will store the address of its next node,
                            // that will pointing onto the next node.
}*first = NULL;         // first node intialized as NULL.


// function to create a Linked List.

void create(int arr[], int n)
{
    // pointer 'temp' will help in creation of new nodes,
    // and pointer 'last' will add a new node at the end of the Linked List.
    struct Node *temp, *last;
    

    // dynamically allocationg the memory for the first node inside Heap.
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = arr[0];         // assigned first elemnt of Array in first node of Linked List.
    first -> next = NULL;       // linked list with a single node.
    last = first;           // pointer 'last' pointing to the first node.


    // loop for traversing the Array elements and will create the new nodes of the Linked List.
    
    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));  // allocating memory for the new nodes inside Heap.
        
        temp -> data = arr[i];          // assign  the Array elements in Linked List one-by-one.
                                        // arr[1] , arr[2] , arr[3] , arr[4] , arr[5]
        
        temp -> next = NULL;            // newly created node next's contains NULL.
                                        // arr[1] | _____ , arr[2] | _____ , arr[3] | _____ , arr[4] | _____ , arr[5] | NULL
                                        // blank spaces referring the address of the 'next node'.

        last -> next = temp;            // pointer 'last' will now point onto the temp node's next.
        
        last = temp;                    // 'temp node' will now become the 'last node' of the Linked List.
    }
    
}


// function for traversing the Linked List.
// this function will print the data elements of Linked List starting from given node.

void Display(struct Node *newnode)
{
    while (newnode != NULL)         // if new node is not NULL and contains the address of next node, then enter the loop.
    {
        printf("%d\t", newnode -> data);        // print the data.
        newnode = newnode -> next;          // move new node to next node.
    }                                       // exit the loop.
}


int main()
{
    int arr[] = {4, 6, 9, 12, 42, 16};          // declared and intialized an Array of size '6' 

    create(arr, 6);         // calling the create function and passing the Array along with its size as a parameter.

    Display(first);         // calling the Display function and passing the 'first node' as a parameter.

    return 0;
}