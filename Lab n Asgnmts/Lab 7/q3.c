#include"stack.h"

void show(stack * s)
{
    int i = 0;
    while(i <= s -> top + 1)
    {
        printf("%d ", s -> arr[i]);
        i++;
    }
    printf("\n");
}

stack * sort(stack * s)
{
    stack * s1 = create(s -> capacity);
    stack * s2 = create(s -> capacity);
    push(s1, peek(s));
    pop(s);
    
    while(!isempty(s))
    {
        if (peek(s) >= peek(s1))
        {
            push(s1, peek(s));
            pop(s);
        }
        else
        {
            while (peek(s1) > peek(s))
            {
                push(s2, peek(s1));
                pop(s1);
            }
            push(s1, peek(s)); pop(s);
            
            while(!isempty(s2))
            {
                push(s1, peek(s2));
                pop(s2);
            }
        }
    }
    return s1;
}



int main(void)
{
    stack * s = create(5);
    push(s, 1);push(s, 4);push(s, 3);push(s, 2);push(s, 5);
    show(s);
    stack * res = sort(s);
    show(res);
    return 0;
}
