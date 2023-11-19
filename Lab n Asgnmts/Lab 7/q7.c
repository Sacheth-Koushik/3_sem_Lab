// DLL
#include<stdio.h>
#include<stdlib.h>

//DLL
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;


//Prototype
void insert(node ** head, int val);
void insert_at(node ** a, int index, int val);
void append(node ** head, int val);
int get_index(node * a, int target);
void show(node *head);
int get_len(node *a);
void insert_before(node **a, int target, int val);
void insert_after(node **a, int target, int val);
void del_front(node ** a);
void del_last(node **a);
void del_at(node **a, int index);

//

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

int get_len(node *a)
{
    node * curr = a;
    int cnt = 0;
    while(curr)
    {
        curr = curr -> next;
        cnt += 1;
    }
    return cnt;
}

void insert_at(node ** a, int index, int val)
{
    if(index < 0 || index >= get_len(*a))
    {
        printf("INVALID INDEX\n");
        return;
    }
    if(index == 0)
    {
        insert(&(*a), val);
        return;
    }
    int i = 0;
    node * curr = *a;
    while(i < index - 1)
        curr = curr -> next;
    
    node * new = (node*)malloc(sizeof(node));
    new -> data = val;
    new -> prev = curr;
    new -> next = curr -> next;
    
    curr -> next -> prev = new;
    curr -> next = new;
}

void append(node ** head, int val)
{
    node * new = (node*)malloc(sizeof(node));
    
    new -> next = NULL;
    new -> data = val;
    
    node * curr = *head;
    
    if(!*head)
    {
        new -> prev = NULL;
        *head = new;
        return;
    }
    
    while(curr -> next)
        curr = curr -> next;
    
    new -> prev = curr;
    curr -> next = new;
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

int get_index(node * a, int target)
{
    node * curr = a;
    int i = 0;
    while(curr)
    {
        if(curr -> data == target)
            return i;
        i++;
        curr = curr -> next;
    }
    return -1;
}

void insert_after(node **a, int target, int val)
{
    int ind = get_index(*a, target);
    if(ind == -1)
    {
        printf("Target does not exsist\n");
        return;
    }
    
    if(ind == get_len(*a) - 1)
    {
        append(&(*a), val);
        return;
    }
    
    insert_at(&(*a), ind + 1, val);
}

void insert_before(node **a, int target, int val)
{
    int ind = get_index(*a, target);
    if(ind == -1)
    {
        printf("Target does not exsist\n");
        return;
    }
    insert_at(&(*a), ind, val);
}

void del_front(node ** a)
{
    *a = (*a) -> next;
    if(*a)
        (*a) -> prev = NULL;
}

void del_last(node **a)
{
    if(!*a)
        return;
    node * curr = *a;
    if(!curr -> next)
    {
        *a = NULL;
        return;
    }
    while(curr -> next -> next)
        curr = curr -> next;
    
    curr -> next = NULL;
}

void del_at(node **a, int index)
{
    if(index < 0 || index >= get_len(*a))
    {
        printf("INVALID INDEX\n");
        return;
    }
    
    int i = 0;
    node * dummy = (node *)malloc(sizeof(node));
    dummy -> next = *a;
    dummy -> prev = NULL;
    node * previ = dummy;
    node * curr = *a;
    
    while(curr)
    {
        if(i == index)
        {
            previ -> next = curr -> next;
            if(curr -> next)
                curr -> next -> prev = previ;
            *a = dummy -> next;
            return;
        }
        previ = curr;
        curr = curr -> next;
        i++;
    }
}


void delNode(node ** a, node * del)
{
    if(*a == NULL || del == NULL)
        return;
    if(*a == del)
    {
        *a = del -> next;
        if(del -> next)
            del -> next -> prev = NULL;
        return;
    }
    node * dummy = malloc(sizeof(node));
    dummy -> next = *a;
    dummy -> prev = NULL;
    node * curr = *a;
    while(curr != del)
        curr = curr -> next;
    
    curr -> prev -> next = curr -> next;
    if(curr -> next)
        curr -> next -> prev = curr -> prev;
    *a = dummy -> next;
    
}

void reverse(node **head)
{
    node * temp = NULL;
    node * curr = *head;
    
    while(curr)
    {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }
    if(temp)
        *head = temp -> prev;
}

int main(void)
{
    node * a = NULL;
    append(&a, 1);append(&a, 2);append(&a, 3);append(&a, 4);append(&a, 5);append(&a, 6);append(&a, 7);
    show(a);
    reverse(&a);
    show(a);
}
