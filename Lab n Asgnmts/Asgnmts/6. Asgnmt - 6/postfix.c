#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int capacity;
    char *arr;
}stack;

stack * create(int c)
{
    stack * s = malloc(sizeof(stack));
    s -> top = -1;
    s -> capacity = c;
    s -> arr = malloc(c * sizeof(char));
    return s;
}

int isFull(stack * s)
{
    return ( s -> top == s -> capacity );
}


int isEmpty(stack * s)
{
    return ( s-> top == -1);
}

void push(stack * s, char val)
{
    if (isFull(s))
    {
        printf("FULL\n");
        return;
    }
    s -> arr [++ s -> top] = val;
}

char pop(stack * s)
{
    if(isEmpty(s))
    {
        printf("EMPTY\n");
        return '!';
    }
        
    
    return s -> arr[s -> top --];
}

char peek(stack * s)
{
    if(isEmpty(s))
    {
        printf("EMPTY\n");
        return '!';
    }
    return (s -> arr[ s -> top]);
}


int preced(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isop(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


int isalnum(char ch)
{
    (ch >= 65 && ch <= 90) || (ch >= 97 || ch <= 122) ||
}


int main(void)
{
    stack * s = create(100);
    printf("%d\n", 'a');
}
