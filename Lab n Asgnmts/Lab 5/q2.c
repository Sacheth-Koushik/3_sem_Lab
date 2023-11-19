#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main(void)
{
    node * a = NULL;append(&a,1);append(&a,2);append(&a,3);append(&a,4);append(&a,5);append(&a,6);append(&a,7);
    show(a);
    delete_at(&a, 1);
    show(a);
    return 0;
}

