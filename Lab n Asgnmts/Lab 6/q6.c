#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// check = 1 for 1st stack
typedef struct tstack
{
    int top;
    int bottom;
    unsigned int capacity;
    int * arr;
} tstack;

tstack * create(int c)
{
    tstack * s = malloc(sizeof(tstack));
    s -> top = -1;
    s -> bottom = c;
    s -> capacity = c;
    s -> arr = malloc(s -> capacity * sizeof(int));
    return s;
}

int isfull(tstack * s)
{
    return s -> bottom - s -> top == 1;
}

int isempty(tstack * s, int check)
{
    if (check == 1)
        return s -> top == -1;
    else
        return s -> bottom == s -> capacity;
}

void push(tstack * s, int n, int check)
{
    if(isfull(s))
    {printf("FULL\n"); return;}
    
    if (check == 1)
        s -> arr [++ s -> top] = n;
    else
        s -> arr [-- s -> bottom] = n;
}

void pop(tstack * s, int check)
{
    if(isempty(s, check))
    {printf("empty\n"); return;}
    if (check)
        s -> top --;
    else
        s -> bottom++;
}

int peek(tstack * s, int check)
{
    if(isempty(s, check))
    {
        printf("EMPTY\n");
        return -99999;
    }

    if (check == 1)
        return s -> arr[s -> top];
    else
        return s -> arr[s -> bottom];
}
