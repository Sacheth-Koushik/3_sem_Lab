#include"LinkedList.h"

void detectloop(node * head)
{
    node * hare = head;
    node * tor = head;
    
    while(hare && hare -> next && tor)
    {
        tor = tor -> next;
        hare = hare -> next -> next;
        if(tor == hare)
        {
            printf("LOOP DETECTED\n");
            return;
        }
    }
    printf("NO LOOP\n");
}
