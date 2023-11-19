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
//    node * temp = malloc(sizeof(node));
//    temp -> data = val;
//    temp -> next = NULL;
//    if(!*head)
//    {
//        *head = temp;
//        return;
//    }
//    node * i = malloc(sizeof(node));
//    i = *head;
//    while(i->next)
//        i = i->next;
//    i-> next = temp;
}

int len(node *a)
{
    node * curr = a;
    int i = 0;
    while(curr)
    {
        curr = curr -> next;
        i++;
    }
    return i;
}

void insert_at(node **a, int val, int index)
{
    if(index < 0 || index >= len(*a))
    {
        printf("INVALID INDEX\n");
        return;
    }
    node * dummy = malloc(sizeof(node));
    node * new = malloc(sizeof(node));
    new -> data = val;
    dummy -> next = *a;
    node * prev = dummy;
    node * curr = *a;
    int i = 0;
    while(curr && i < index)
    {
        prev = curr;
        curr = curr -> next;
        i++;
    }
    new -> next = curr;
    prev -> next = new;
    *a = dummy -> next;
}

void delFront(node **head)
{
    if(!*head)
        return;
    *head = (*head) -> next;
}

void delLast(node **head)
{
    node * curr = *head;
    node * prev = NULL;
    
    while(curr -> next)
    {
        prev = curr;
        curr  = curr -> next;
    }
    
    prev -> next = NULL;
}

void del_at(node **a, int index)
{
    if(index < 0 || index >= len(*a))
    {
        printf("INVALID INDEX\n");
        return;
    }
    
    node * dummy = malloc(sizeof(node));
    dummy -> next = *a;
    node * prev = dummy;
    node * curr = *a;
    int i = 0;
    
    while(curr && i < index)
    {
        prev = curr;
        curr = curr -> next;
        i++;
    }
    prev -> next = curr -> next;
    *a = dummy -> next;
}

void rev(node **head)
{
    node * prev = NULL;
    node * curr = *head;
    node * next = NULL;
    while(curr)
    {
        next = curr -> next;
        curr -> next  = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}


int middle(node *a)
{
    node * hare = a;
    node * tor = a;
    while(hare && hare -> next)
    {
        tor = tor -> next;
        hare = hare -> next -> next;
    }
    return tor -> data;
}

int pop(node **head)
{
    if(!*head)
        return -99999;
    node * temp = *head;
    int data = temp -> data;
    * head = (*head) -> next;
    free(temp);
    return data;
}

node * stck_rev(node *head)
{
    node * res = NULL;
    while(head)
        insert(&res, pop(&head));
    return res;
}


void revbtw(node ** a, int m, int n)
{
    if(m < 0 || n >= len(*a))
    {
        printf("INVALID INDEX\n");
        return;
    }
    
    node * dummy = (node*)malloc(sizeof(node));
    dummy -> next = *a;
    node * revs = *a;     node * revend = NULL;
    node * revprev = dummy;  node * revnext = NULL;
    node * curr = *a;
    int i = 0;
    
    while(curr && i <= n)
    {
        if(i == m - 1)
        {
            revprev = curr;
            revs = curr -> next;
        }
        if(i == n)
        {
            revend = curr;
            revnext = curr -> next;
        }
        curr = curr -> next;
        i++;
    }
    revend -> next  = NULL;
    rev(&revs);
    revprev -> next = revs;
    node * itr  = revs;
    
    while(itr -> next)
        itr = itr -> next;
    
    itr -> next = revnext;
    *a = dummy -> next;
    free(dummy);
}


node * find(node *a, int n)
{
    if(n < 0 || n >= len(a))
    {
        printf("INVALID INDEX\n");
        return NULL;
    }
    int i = 0;
    node * curr = a;
    while(curr && i < n)
    {
        curr = curr -> next;
        i++;
    }
    return curr;
}

node * findFromLast(node *a, int n)
{
    if(n < 0 || n >= len(a))
    {
        printf("INVALID INDEX\n");
        return NULL;
    }
    return find(a, len(a) - n - 1);
}

node * krev(node *a, int k)
{
    node * prev = NULL;
    node * next = NULL;
    node * curr = a;
    
    int cnt = 0;
    while(curr && cnt < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    
    if(a)
        a = curr -> next;
    cnt = 0;
    while(curr && cnt < k)
    {
        curr = curr -> next;
        cnt ++;
    }
    
    if(curr)
        curr -> next = krev(curr -> next, k);
    
    return prev;
    
}


node * merge(node * a, node *b)
{
    node * res = NULL;
    
    if(!a)
        return b;
    else if(!b)
        return a;
    
    if(a -> data < b -> data)
    {
        res = a;
        res -> next = merge(a -> next, b);
    }
    else
    {
        res = b;
        res ->  next = merge(a, b -> next);
    }
    return res;
}

int cnount(node *a, int key)
{
    node * curr = a;
    int cnt = 0;
    while(curr)
    {
        if(curr -> data == key)
            cnt++;
        curr = curr -> next;
    }
    return cnt;
}

void del_all(node **a, int key)
{
    node * curr = *a;
    node * dummy = malloc(sizeof(node));
    dummy -> next = *a;
    node * prev = dummy;
    while(curr)
    {
        if(curr -> data == key)
        {
            prev -> next = curr -> next;
            node * temp = curr;
            curr = curr -> next;
            free(temp);
        }
        else
        {
            prev = curr;
            curr = curr -> next;
        }
    }
    *a = dummy -> next;
}


node * delall(node * head, int key)
{
    if(!head)
        return head;
    
    // move away until key is in start
    while(head && head -> data == key)
        head = head -> next;
    
    
    node * curr = head;
    node * prev = NULL;
    
    while(curr)
    {
        if (curr -> data == key)
            prev -> next = curr -> next;
        else
            prev = curr;
        
        curr = curr -> next;
    }
    
    return head;
}


node * add(node *a, node *b)
{
    rev(&a);
    rev(&b);
    node * res = NULL;
    int carry = 0;
    int x = 0, y = 0;
    int ans = 0;
    while(a || b)
    {
        if(a)
        {
            x = a -> data;
            a = a-> next;
        }
        else
            x = 0;
        if(b)
        {
            y = b -> data;
            b = b -> next;
        }
        else
            y = 0;
        int ans = x + y + carry;
        carry = ans / 10;
        append(&res, ans % 10);
    }
    if(carry)
        append(&res, carry);
    rev(&res);
    return res;
}



int main(void)
{
    node *a = NULL;
    append(&a, 9);append(&a, 2);append(&a, 4);append(&a, 9);
    node * b = NULL;
    append(&b, 4);append(&b, 5);append(&b, 6);
    node * c = add(a, b);
    show(c);
    return 0;
}
