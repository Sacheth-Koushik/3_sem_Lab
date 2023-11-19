#include"stack.h"

void enqueue(stack * s1, int n)
{
    if(isfull(s1))
        return;
    push(s1, n);
}

void dequeue(stack * s1, stack * s2)
{
    if(!isempty(s2))
    {
        pop(s2);
        return;
    }
    while(!isempty(s1))
    {
        push(s2, peek(s1));
        pop(s1);
    }
    pop(s2);
}