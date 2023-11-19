#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"


int main(void)
{
    node * a = NULL;append(&a,1);append(&a,2);//append(&a,3);append(&a,4);append(&a,5);append(&a,6);append(&a,7);
    node * b = NULL;append(&b,1);append(&b,2);append(&b,3);//append(&b,4);append(&b,5);

    node * tmp1 = a;
    node * tmp2 = b;
    show(a);
    show(b);
    while(tmp1)
    {
        tmp2 = b;
        while(tmp2)
        {
            if (tmp1 -> data == tmp2 -> data)
                printf("%d\t", tmp2 -> data);
            tmp2 = tmp2 -> next;
        }
        tmp1 = tmp1 -> next;
    }
    
    return 0;
}