#include<stdio.h>
#include<stdlib.h>

//DLL
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

void insert(node ** head, int val)
{
    node * new = (node*)malloc(sizeof(node));
    new -> data = val;
    new -> prev = NULL;
    new -> next = *head;
    
    if(*head)
        (*head) -> prev = new;
    
    *head = new;
}

void show(node *head)
{
    node * curr = head;
    while(curr)
    {
        printf("%d --> ", curr -> data);
        curr = curr -> next;
    }
    printf("NULL\n");
}

int get_len(node *a)
{
    int l = 0;
    node * curr = a;
    while(curr)
    {
        curr = curr -> next;
        l++;
    }
    return l;
}

void append(node ** head, int val)
{
    node * new = malloc(sizeof(node));
    new -> data = val;
    new -> next = NULL;
    
    if(!*head)
    {
        new -> prev = NULL;
        *head = new;
    }
    node * curr = *head;
    while(curr -> next)
        curr = curr -> next;
    curr -> next = new;
    new -> prev = curr;
    
}


void insert_at(node ** head, int index, int val)
{
    if(index < 0 || index >= get_len(*head))
        return;
    
    if(index == 0)
    {
        insert(&(*head), val);
        return;
    }
    if(index == get_len(*head) - 1)
    {
        append(&(*head), val);
        return;
    }

    int i = 0;
    node * curr = *head;
    
    while(curr && i < index - 1)
    {
        curr = curr -> next;
        i++;
    }
    node * new = malloc(sizeof(node));
    new -> data = val;
    new -> prev = curr;
    new -> next = curr -> next;
    
    curr -> next -> prev = new;
    curr -> next = new;
}

void del_at_front(node **a)
{
    if(!*a)
        return;
    node * temp = *a;
    *a = (*a) -> next;
    (*a) -> prev = NULL;
    free(temp);
}

void del_at(node **a, int index)
{
    if(!*a)
        return;
    if(index < 0 || index >= get_len(*a))
        return;
    if(index == 0)
    {
        del_at_front(&(*a));
        return;
    }
    
    int i = 0;
    node * curr = *a;
    
    while(curr && index != i)
    {
        curr = curr -> next;
        i++;
    }
    
    curr -> prev -> next = curr -> next;
    if(curr -> next)
        curr -> next -> prev = curr -> prev;
    free(curr);
}

void del_last(node **a)
{
    del_at(&(*a), get_len(*a) - 1);
    return;
}


int get_index(node * a, int target)
{
    node * curr = a;
    int i = 0;
    while(curr)
    {
        if (curr -> data == target)
            return i;
        i++;
        curr = curr -> next;
    }
    return -1;
}

void insert_before(node **a, int target, int val)
{
    insert_at(&(*a), get_index(*a, target), val);
    return;
}

void insert_after(node **a, int target, int val)
{
    int i = get_index(*a, target);
    if (i == get_len(*a) - 1)
    {
        append(&(*a), val);
        return;
    }
    insert_at(&(*a), get_index(*a, target) + 1, val);
    return;
}

int main(void)
{
    node * a = NULL;
    node *b = NULL;
    insert(&a, 3);insert(&a, 2);insert(&a, 1);append(&a, 4);
    insert_after(&a, 4, 100);
    show(a);
    del_last(&b);
    show(b);
}
