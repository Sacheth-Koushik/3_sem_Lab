#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"


//(c)
void insert_before(node ** head, int x, int val)
{
    node * curr = *head;
    
    int i = 0;
    while(curr)
    {
        if ( curr -> data == x)
        {
            insert_at(&(*head), i, val);
            return;
        }
        i += 1;
        curr = curr -> next;
    }
}

// (d)
void insert_after(node ** head, int x, int val)
{
    int i = 0;
    node * curr = *head;

    while(curr)
    {
        if(curr -> data == x)
        {
            insert_at(&(*head), i + 1, val);
            return;
        }
        i += 1;
        curr = curr -> next;
        
    }
}

int main(void)
{
    node * a = NULL;append(&a,1);append(&a,2);append(&a,3);append(&a,4);append(&a,5);append(&a,6);append(&a,7);
    show(a);
    insert_after(&a, 1, 1000);
    insert_before(&a, 3, 2000);
    show(a);
    return 0;
}