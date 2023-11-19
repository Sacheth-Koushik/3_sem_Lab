#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

void add(node * a, node * b)
{
    ll n1 = 0, n2 = 0, mod = 1000000007;
    
    while(a || b)
    {
        if(a)
        {
            n1 = (n1 * 10) % mod + a -> data;
            a = a -> next;
        }
        if(b)
        {
            n2 = (n2 * 10) % mod + b -> data;
            b = b -> next;
        }
    }
    
    printf("The numbers are %lld, %lld\n", n1, n2);
    printf("the sum is %lld\n", n1 + n2);
}

int main(void)
{
    node * fst = NULL;
    node * snd = NULL;
    append(&fst, 1);append(&fst, 2);append(&fst, 3);append(&fst, 4);append(&fst, 5);append(&fst, 6);
    append(&snd, 1);append(&snd, 2);append(&snd, 3);
    show(fst);
    show(snd);
    add(fst, snd);
    
    return 0;
}