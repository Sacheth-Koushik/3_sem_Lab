// circular

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
typedef struct node
{
    int data;
    struct node* next;
}node;


void insert(node** head_ref, int data)
{
    node* ptr1 = (node*)malloc(sizeof(node));
    ptr1 -> data = data;
    ptr1 -> next = *head_ref;

    if (*head_ref != NULL)
    {
        node* temp = *head_ref;
        while (temp -> next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

void show(node* head)
{
    node* temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d --> ", temp -> data);
            temp = temp -> next;
        } while (temp != head);
    }
    printf("NULL\n");
}

void deleteNode(node** head, int key)
{

    if (*head == NULL)
        return;

    if ((*head) -> data == key && (*head) -> next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    node *last = *head, *d;

    // If head is to be deleted
    if ((*head)->data == key)
    {

        // Find the last node of the list
        while (last -> next != *head)
            last = last -> next;

        // Point last node to the next of
        // head i.e. the second node
        // of the list
        last -> next = (*head) -> next;
        free(*head);
        *head = last -> next;
        return;
    }

    // Either the node to be deleted is
    // not found or the end of list
    // is not reached
    while (last -> next != *head && last -> next -> data != key)
    {
        last = last->next;
    }

    // If node to be deleted was found
    if (last -> next -> data == key)
    {
        d = last -> next;
        last -> next = d -> next;
        free(d);
    }
    else
        printf("Given node is not found in the list!!!\n");
}


void append(node ** head, int n)
{
    node * temp = malloc(sizeof(node));
    temp -> data = n;
    
    if(*head == NULL)
    {
        temp -> next = temp;
        *head = temp;
        return;
    }
    temp -> next = *head;
    node *i = *head;
    while(i -> next != *head)
        i = i -> next;
    
    i -> next = temp;
}

void middle(node * head)
{
    node * hare = head;
    node * tortoise = head;
    
    
    while(hare && hare -> next != head)
    {
        hare = hare -> next -> next;
        tortoise = tortoise -> next;
    }
    
    printf("The middle element is [ %d ]\n\n", tortoise -> data);
}


int main(void)
{
    // Initialize lists as empty
    struct node* head = NULL;

    // Created linked list will be
    // 2->5->7->8->10
    insert(&head, 2);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 10);

    printf("List Before Deletion: ");
    show(head);

    deleteNode(&head, 7);
    show(head);
    printf("List After Deletion: ");
    append(&head, 1000);
    show(head);
    middle(head);

    return 0;
}
