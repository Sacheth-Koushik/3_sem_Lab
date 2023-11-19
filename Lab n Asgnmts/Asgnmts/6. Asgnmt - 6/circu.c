#include <stdio.h>
#include <stdlib.h>
  
// Structure for a node
typedef struct node {
    int data;
    struct node* next;
}node;

void show(node *ah)
{
    if(!ah)
    {
        printf("NULL\n");
        return;
    }
    node * curr = ah;
    do {
        printf("%d --> ", curr -> data);
        curr = curr -> next;
    } while (curr -> next != ah);
    printf("NULL\n");
}

void insert(node ** head ,node ** tail,  int val)
{
    node * new = malloc(sizeof(node));
    new -> data = val;
    new -> next = *head;
    
    if(*tail)
        (*tail) -> next = new;
    else
    {
        new -> next = new;
        *tail = new;
    }
    *head = new;
}

void append(node ** ah, node ** at, int val)
{
    node * new = malloc(sizeof(node));
    new -> data = val;
    
//    if(!*ah)
//    {
//        new -> next = new;
//        *ah = new;
//        *at = new;
//        return;
//    }
    new -> next = (*at) -> next;
    (*at) -> next = new;
    *at = new;
}


int main(void)
{
    node *ah = NULL; node *at = NULL;
    insert(&ah,&at, 1);insert(&ah, &at, 2);
    show(ah);
    append(&ah, &at, 100);
    show(ah);
}
