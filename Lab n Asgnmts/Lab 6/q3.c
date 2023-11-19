#include"stack.h"
#include"postfix.h"

void eval(char *c)
{
    stack *s = create(strlen(c));
    int i = 0;
    while(c[i])
    {

        if(isAlnum(c[i]))
            {push(s, c[i] - '0');i++; continue;}
        int y = peek(s);
        pop(s);
        int x = peek(s);
        pop(s);

        push(s, operate(c[i], x, y));
        i++;
    }
    printf("result is %d\n", peek(s));
}