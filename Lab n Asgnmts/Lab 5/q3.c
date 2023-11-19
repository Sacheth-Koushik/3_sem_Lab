#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"



node * reverse_iter(node * head)
{
    node * prev = NULL;
    node * curr = head;
    
    while ( curr != NULL)
    {
        node * next = curr -> next; // so that the next node is not lost
        curr -> next = prev; // update the current node
        prev = curr; // the current one becomes the prev for the next one
        curr = next; // move on to the next node
    }
    
    return prev;
    // why is the original list changing to just 1 element after this function is called ?
}


int pop(node ** head)
{
    if(head == NULL)
    {
        printf("THE LIST IS EMPTY\n");
        return 0;
    }
    
    node * tmp = *head;
    *head = (*head)->next;
    return tmp -> data;
}



node * reverse_stack(node * head)
{
    node * a = NULL;
    node * temp = head;
    
    while( temp != NULL )
        insert(&a, pop(&temp));
    
    return a;
}

int main(void)
{
    node * a = NULL;append(&a,1);append(&a,2);append(&a,3);append(&a,4);append(&a,5);append(&a,6);append(&a,7);
    node * b = NULL;append(&b,1);append(&b,2);append(&b,3);append(&b,4);append(&b,5);append(&b,6);append(&b,7);
    
    // (1) reverse array by stack method
    printf("\nBY STACK\n");
    printf("list is\n");
    show(a);
    node * arev_stack = reverse_stack(a);
    show(arev_stack);
    
    // (1) Rverse array by iterative method
    printf("\nBY ITER\n");
    printf("list is\n");
    show(b);
    node * brev_iter = reverse_iter(b);
    show(brev_iter);

    return 0;
}