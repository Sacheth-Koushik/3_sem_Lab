#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack
{
    int top;
    unsigned int capacity;
    char * arr;
} stack;

stack * create(int c)
{
    stack * s = malloc(sizeof(stack));
    s -> top = -1;
    s -> capacity = c;
    s -> arr = malloc(s -> capacity * sizeof(char));
    return s;
}

int isfull(stack * s)
{
    return s -> top == s -> capacity;
}

int isempty(stack * s)
{return s -> top == -1;}

void push(stack * s, char n)
{
    if(isfull(s))
    {printf("FULL\n"); return;}
    
    s -> arr [++ s -> top] = n;
}

void pop(stack * s)
{
    if(isempty(s))
        return;
    s -> top --;
}

char peek(stack * s)
{
    if(isempty(s))
    {
        printf("EMPTY\n");
        return '!';
    }
    return s -> arr[s -> top];
}
