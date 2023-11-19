#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

void middle(node * head)
{
    node * hare = head;
    node * tortoise = head;
    
    
    while(hare && hare -> next)
    {
        hare = hare -> next -> next;
        tortoise = tortoise -> next;
    }
    
    printf("The middle element is [ %d ]\n\n", tortoise -> data);
}

int main(void)
{
    node * f = NULL;append(&f,1);append(&f,2);append(&f,3);append(&f,4);append(&f,5);append(&f,6);append(&f,7);
    //(6) middle of linked list
    printf("\nList is : \n");
    show(f);
    middle(f);
}