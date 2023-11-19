#include"DLL.h"

node * krotate(node *a, int k)
{
    node * dummy = (node*)malloc(sizeof(node));
    dummy -> next = a;
    node * curr = a;
    k %= get_len(a);
    
    if (k == 0)
        return a;
    
    int i = 0;
    while(curr && i < k - 1)
    {
        curr = curr ->  next;
        i++;
    }
    
    node * tail = a;
    while(tail -> next)
        tail = tail -> next;
    
    tail -> next = a;
    a -> prev = tail;
    dummy -> next = curr -> next;
    curr -> next -> prev = NULL;
    curr -> next = NULL;
    return dummy -> next;
}

int main(void)
{
    node * a = NULL;append(&a,1);append(&a,2);append(&a,3);
    node * res = krotate(a, 7);
    show(res);
    
    return 0;
}
