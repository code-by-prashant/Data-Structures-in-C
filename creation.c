#include<stdio.h>
#include<stdlib.h>

/*
    A linked list consists of various nodes, and each node contains two things: 
    One is the data, and the other is the pointer, which will point to the next node.

    | start | ---> | data|next | ---> | data|next | ---> | data|NULL |
    start            first node         second node         last node
    
*/

// we use structures in C programming to create a Linked List,
// it is a user-defined data type that enables us to store the collection of different data types.

struct Node
{
    int data;          	 	    // variable 'data' will store the data elements.

    struct Node *next;     		// pointer 'next' is of a 'structure Node' data type and will hold the
                           		// address of its next node, that will be pointing onto the next node.

}*first = NULL;         	    // declared pointer 'first' and first node of Linked List is initialized as NULL.


// function to create a Linked List.

void create(int arr[], int n)
{
    // pointer 'temp' will help in creation of new nodes,
    // and pointer 'last' will add a new node at the end of the Linked List.

    struct Node *temp, *last;
    

    // dynamically allocating the memory for the first node inside Heap.

    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = arr[0];         	// assigned first element of Array in first node of Linked List.
    first -> next = NULL;       		// linked list with a single node.
    last = first;           			// pointer 'last' pointing to the first node.


    // loop for traversing the Array elements and will create the new nodes of the Linked List.
    
    for (int i = 1; i < n; i++)
    {
        // allocating memory for the new nodes inside Heap.

        temp = (struct Node *)malloc(sizeof(struct Node));  		
        
        temp -> data = arr[i];          // assign  the Array elements in Linked List one-by-one.
                                        // arr[1] , arr[2] , arr[3] , arr[4] , arr[5]
        
        temp -> next = NULL;            // newly created node next's contains NULL.
                                        // arr[1] | ____ , arr[2] | ____ , arr[3] | ____ , arr[4] | ____ , arr[5] | NULL
                                        // blank spaces referring the address of the 'next node'.

        last -> next = temp;            // pointer 'last' will now point onto the temp node's next.
        
        last = temp;                    // 'temp node' will now become the 'last node' of the Linked List.
    }
    
}


// function for traversing the Linked List.
// this function will print the data elements of Linked List starting from given node.

void Display(struct Node *newnode)
{
while (newnode != NULL)         	// if new node is not NULL and contains the address of next node, then enter the loop.
    {
        printf("%d\t", newnode -> data);        	// print the data.
        newnode = newnode -> next;         			// move new node to next node.
    }                                      			// exit the loop.
}


// Recursive function for traversing the Linked List.
/*
    let’s assume a Linked List example for better understanding of Recursive function

    | 100 | ---> | 4|120 | ---> | 6|150 | ---> | 9|200 | ---> | 12|260 | ---> | 42|300 | ---> | 16|NULL | 
    address     data|address
    of next         |of next

    execution:

        newnode(first) = 100 != NULL            (enter the loop)
        
        Step-1: print: newnode's data that is =  4
                
                [now, function 'recDisplay' will call itself]

        Step-2: call: newnode's next that is =  120 
                
                [now, it will repeat step-1 and step-2 until newnode's next becomes NULL]

        Step-1:    print =  6
        Step-2:    call =   150

        Step-1:    print =  9
        Step-2:    call =   200

        Step-1:    print =  12
        Step-2:    call =   260

        Step-1:    print =  42
        Step-2:    call =   300

        Step-1:    print =  16
        Step-2:    call =   0

        newnode =  0(NULL)
                [exit the loop and the call will get terminated]
*/

void recDisplay(struct Node *newnode)
{
    if (newnode != NULL) 
    {
        printf("%d\t", newnode -> data);                // Step-1   print the data
        recDisplay(newnode -> next);                    // Step-2   call the next node's address
    }
    
}


// main function

int main()
{
    int arr[] = {4, 6, 9, 12, 42, 16};          // declared and initialized an Array of size '6' 

    create(arr, 6);         	// calling the create function and passing the Array along with its size as a parameter.

    printf("the data elements of Linked List are: \n");
    
    Display(first);         	 // calling the Display function and passing the 'first' as a pointer,
                                 // the pointer 'first' will become the pointer 'newnode' in Display function.
    
    printf("\n displaying the elements using Recursion: \n");
   
    recDisplay(first);     	    // calling the recursive function and passing the 'first' as a pointer.
    
    return 0;
}
