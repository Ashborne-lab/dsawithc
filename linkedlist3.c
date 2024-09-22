#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node Node;

// Function to insert a node at the beginning of the linked list
void InsertBegSLL(Node **start_ptr, int val)
{
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Node is not created, overflow in the linked list\n");
        return;
    }
    temp->data = val;
    temp->next = *start_ptr;
    *start_ptr = temp;
}

// Function to insert a node at the end of the linked list
void InsertEndSLL(Node **start_ptr, int val)
{
    Node *temp = malloc(sizeof(Node)); // Allocate memory for the new node
    if (temp == NULL)
    {
        printf("Node is not created, overflow in the linked list\n");
        return;
    }
    temp->data = val;
    temp->next = NULL;

    if (*start_ptr == NULL)
    {
        // If the list is empty, insert the first node
        *start_ptr = temp;
        return;
    }

    Node *ptr = *start_ptr;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// Function to delete a node with a given value from the linked list
void DeleteValSLL(Node **start_ptr, int val)
{
    Node *ptr = *start_ptr;
    Node *preptr = NULL;

    // If the list is empty
    if (ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // If the node to be deleted is the head node
    if (ptr->data == val)
    {
        *start_ptr = ptr->next;
        free(ptr); // Free the memory of the deleted node
        return;
    }

    // Traverse the list to find the node with the value to delete
    while (ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    // If the value is not found in the list
    if (ptr == NULL)
    {
        printf("Value %d not found in the list.\n", val);
        return;
    }

    // Remove the node from the list
    preptr->next = ptr->next;
    free(ptr); // Free the memory of the deleted node
}

// Function to print the linked list
void PrintListSLL(Node *head)
{
    Node *ptr = head;
    while (ptr)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    Node *start = NULL;

    // Insert at the end
    InsertEndSLL(&start, 1);
    InsertEndSLL(&start, 7);
    InsertEndSLL(&start, 9);
    InsertEndSLL(&start, 2);
    InsertEndSLL(&start, 4);
    InsertEndSLL(&start, 0);
    InsertEndSLL(&start, 9);
    InsertEndSLL(&start, 1);

    printf("Insertion at end: \n");
    PrintListSLL(start);

    // Delete a value from the list
    DeleteValSLL(&start, 9);
     DeleteValSLL(&start, 9);
    printf("After deletion of value 9: \n");
    PrintListSLL(start);

    // Insert at the beginning
    InsertBegSLL(&start, 7);
    InsertBegSLL(&start, 17);
    InsertBegSLL(&start, -23);
    InsertBegSLL(&start, 89);

    printf("Insertion at beginning:\n");
    PrintListSLL(start);

    return 0;
}
