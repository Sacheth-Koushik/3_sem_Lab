#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

typedef struct node
{
    int data;
    struct node * next;
}node;

void show(node *a)
{
    node * curr = a;
    while(curr)
    {
        printf("%d --> ",  curr -> data);
        curr = curr -> next;
    }
    printf("NULL\n");
}

void insert(node ** head, int val)
{
    node * new = malloc(sizeof(node));
    new -> data = val;
    new -> next = *head;
    *head = new;
}

void append(node ** head, int val)
{
    node * new = malloc(sizeof(node));
    new -> data = val;
    new -> next = NULL;
    if(*head == NULL)
    {
        *head = new;
        return;
    }
    node * curr = *head;
    while(curr -> next)
        curr = curr -> next;
    curr -> next = new;
}

int pop(node ** start)
{
    if(!*start)
        return -99999;
    node * temp  = *start;
    int item = temp -> data;
    *start = temp -> next;
    free(temp);
    return item;
}

node * revstack(node* start)
{
    node * temp = start;
    
}