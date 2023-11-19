#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

typedef struct node
{
    int data;
    struct node *next;
}
node;
int get_length(node *head);
void insert(node ** start, int n);
void append(node ** head, int n);
void insert_at(node ** head, int index, int val);

void show(node * start)
{
    node * tmp = start;
    while(tmp != NULL)
    {
        printf("%d -> ", tmp -> data);
        tmp = tmp->next;
    }
    printf("NULL \n");
}

void insert(node ** start, int n)
{
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("NO MEMORY AAVAILABLE\n");
        return;
    }
    temp -> data = n;
    temp -> next = *start;
    *start = temp;
}


void append(node ** head, int n)
{
    node * temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("NO MEMORY AAVAILABLE\n");
        return;
    }
    
    temp -> data = n;
    temp -> next = NULL;
    
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    
    node * it = *head;
    while (it -> next != NULL)
        it = it -> next;
    
    it -> next = temp;
}

void insert_at(node ** head, int index, int val)
{
    if(index == 0)
    {
        insert(&(*head), val);
        return;
    }
    
    int i = 0;
    
    if(index < 0 || index >= get_length(*head))
    {
        printf("INVALID POSITION\n");
        return;
    }
    
    
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("NO MEMORY AAVAILABLE\n");
        return;
    }
    temp -> data = val;
    temp -> next = NULL;
    
    node * curr = *head;
    while(--index)
        curr = curr -> next;
    
    temp -> next = curr -> next;
    curr -> next = temp;
}


int get_length(node *head)
{
    int len = 0;
    while(head)
    {
        head = head -> next;
        len++;
    }
    return len;
}

void delete_at(node ** head, int index)
{
    if(head == NULL)
    {
        printf("THE LIST IS EMPTY\n");
        return;
    }
    
    if(index < 0 || index >= get_length(*head))
    {
        printf("INVALID POSITION\n");
        return;
    }
    node * temp = *head;
    if(index == 0)
    {
        *head = temp -> next;
        return;
    }
    int i = 0;

    while(temp && i < index - 1)
    {
        temp = temp -> next;
        i++;
    }

    if(temp == NULL && temp -> next == NULL)
    {
        return;
    }

    temp -> next = temp -> next -> next;
}

int find_pos(node * head, int target)
{
    int i = 0;
    while(head)
    {
        if(head -> data == target)
            return i;
        i++;
        head = head -> next;
    }
    return -1;
}

void del_num(node ** head, int num)
{
    int pos = find_pos(*head, num);
    if (pos == -1)
        return;
    delete_at(&(*head), pos);
}