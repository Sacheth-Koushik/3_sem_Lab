#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include"stack.h"

bool isValid(int n, char *s) 
{
    char stack[n];  // Assuming a maximum string length of 10,000
    int top = -1;

    char mappy[256];
    mappy[')'] = '(';
    mappy[']'] = '[';
    mappy['}'] = '{';

    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') 
        {
            if (top >= 0 && stack[top] == mappy[s[i]]) 
                top--;
            else 
                return false;
        } 
        else 
            stack[++top] = s[i];
    }

    return top == -1;
}


int match(char c1, char c2)
{
    if ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'))
        return 1;
    return 0;
}

int balance(char *s)
{
    int i = 0;
    stack * d = create(strlen(s));
    while(s[i])
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(d, s[i]);
        if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if(!match(peek(d), s[i]))
                return 0;
            if(isempty(d))
                return 1;
            pop(d);
        }
        i++;
    }
    if(isempty(d))
        return 1;
    return 0;
}

int main() 
{
    char s[] = "{()}[]";  // Change the input string as needed
    // bool result = isValid(strlen(s), s);
    bool result = balance(s);

    if (result) 
        printf("The string is valid.\n");
    else 
        printf("The string is not valid.\n");
    
    return 0;
}
