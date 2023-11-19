#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node* next;
}node;

void show(node* head)
{
    node* temp = head;

    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->pow);
        if(temp -> next)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}


void append (node ** head, node ** tail, int x, int y)
{
    node * new = malloc(sizeof(node));
    new -> coeff = x;
    new -> pow = y;
    new -> next = NULL;
    
    if(!*head)
        *head = new;
    else
        (*tail) -> next = new;
    *tail = new;
}

node * addPoly (node * p1, node * p2)
{
    node * dummy = malloc(sizeof(node));
    dummy -> next = NULL;
    
    node * prev = dummy;
    
    while (p1 && p2)
    {
        if (p1 -> pow < p2 -> pow)
        {
            prev -> next = p2;
            prev = p2;
            p2 = p2 -> next;
        }
        else if (p1 -> pow > p2 -> pow)
        {
            prev -> next = p1;
            prev = p1;
            p1 = p1 -> next;
        }
        else
        {
            p1 -> coeff += p2 -> coeff;
            prev -> next = p1;
            prev = p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
    }
    
    if(p1)
        prev -> next = p1;
    if(p2)
        prev -> next = p2;
    
    return dummy -> next;
}

void delNode(node *head, node * a)
{
    node * dummy = malloc(sizeof(node));
    dummy -> next = head;
    node * curr = head;
    node * prev = dummy;
    
    while(curr)
    {
        
    }
}

void removeDup(node * head)
{
    node * curr = head; node * dup;
    while(curr && curr -> next)
    {
        node * x = curr;
        while(x -> next)
        {
            if(curr -> pow == x -> next -> pow)
            {
                curr -> coeff += x -> next -> coeff;
                dup = x -> next;
                x -> next = x -> next -> next;
                free(dup);
            }
            else
                x = x -> next;
        }
        curr = curr -> next;
    }
}



node * mul(node * p1, node * p2)
{
    node * res = NULL; node * rest = NULL;
    node * c2 = p2;
    
    while(p1)
    {
        while(c2)
        {
            int coef, pow;
            
            coef = p1 -> coeff * c2 -> coeff;
            pow = p1 -> pow + c2 -> pow;
            append(&res, &rest, coef, pow);
            c2 = c2 -> next;
        }
        c2 = p2;
        p1 = p1 -> next;
    }
    removeDup(res);
    return res;
}



int main(void)
{
    node * p1 = NULL; node * t1 = NULL;
    node * p2 = NULL; node * t2 = NULL;
    
    append(&p1, &t1, 5, 2);append(&p1, &t1, 4, 1);append(&p1, &t1, 2, 0);
    
    append(&p2, &t2, 5, 3);append(&p2, &t2, 6, 2);append(&p2, &t2, 7, 3);append(&p2, &t2, 4, 2);append(&p2, &t2, 3, 1);append(&p2, &t2, 5, 0);
    
    show(p1);
    show(p2);
    node * sum = addPoly(p1, p2);
    show(sum);
    node * res = mul(p1, p2);
    show(res);
    
    return 0;
}